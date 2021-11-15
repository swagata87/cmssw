#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "fastjet/tools/GridMedianBackgroundEstimator.hh"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/View.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "TLorentzVector.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHcalIsolation.h"
#include "CondFormats/EcalObjects/interface/EcalPFRecHitThresholds.h"
#include "CondFormats/DataRecord/interface/EcalPFRecHitThresholdsRcd.h"

class FixedGridRhoProducerFastjetFromRecHit : public edm::stream::EDProducer<> {
public:
  explicit FixedGridRhoProducerFastjetFromRecHit(const edm::ParameterSet& iConfig);
  ~FixedGridRhoProducerFastjetFromRecHit() override;

private:
  void produce(edm::Event&, const edm::EventSetup&) override;
  void getHitP4(const DetId &detId, float hitE, TLorentzVector &hitp4, const CaloGeometry &caloGeometry) ;
  bool passedHcalNoiseCut(const HBHERecHit &hit);
  bool passedEcalNoiseCut(const EcalRecHit &hit,const EcalPFRecHitThresholds *thresholds) ;

  fastjet::GridMedianBackgroundEstimator bge_;
  edm::EDGetTokenT<HBHERecHitCollection> hbheRecHitsTag_;
  edm::EDGetTokenT<EcalRecHitCollection> ebRecHitsTag_;
  edm::EDGetTokenT<EcalRecHitCollection> eeRecHitsTag_;

  const EgammaHcalIsolation::arrayHB eThresHB_;
  const EgammaHcalIsolation::arrayHE eThresHE_;

  bool skipHCAL_;
  bool skipECAL_;

  const edm::ESGetToken<EcalPFRecHitThresholds, EcalPFRecHitThresholdsRcd> ecalPFRechitThresholdsToken_;
  const edm::ESGetToken<CaloGeometry, CaloGeometryRecord> caloGeometryToken_;
};

//using namespace std;

FixedGridRhoProducerFastjetFromRecHit::FixedGridRhoProducerFastjetFromRecHit(const edm::ParameterSet& iConfig) : 
  bge_(iConfig.getParameter<double>("maxRapidity"), iConfig.getParameter<double>("gridSpacing")), 
  hbheRecHitsTag_(consumes(iConfig.getParameter<edm::InputTag>("hbheRecHitsTag"))),
  ebRecHitsTag_(consumes(iConfig.getParameter<edm::InputTag>("ebRecHitsTag"))),
  eeRecHitsTag_(consumes(iConfig.getParameter<edm::InputTag>("eeRecHitsTag"))),
  eThresHB_(iConfig.getParameter<EgammaHcalIsolation::arrayHB>("eThresHB")),
  eThresHE_(iConfig.getParameter<EgammaHcalIsolation::arrayHE>("eThresHE")),
  skipHCAL_(iConfig.getParameter<bool>("skipHCAL")),
  skipECAL_(iConfig.getParameter<bool>("skipECAL")),
  ecalPFRechitThresholdsToken_{esConsumes()},
  caloGeometryToken_{esConsumes()} {
  produces<double>();
}

FixedGridRhoProducerFastjetFromRecHit::~FixedGridRhoProducerFastjetFromRecHit() {}

void FixedGridRhoProducerFastjetFromRecHit::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {

  std::vector<fastjet::PseudoJet> inputs;
  auto const& thresholds = iSetup.getData(ecalPFRechitThresholdsToken_);

  if (skipHCAL_ && skipECAL_) {
    throw cms::Exception("FixedGridRhoProducerFastjetFromRecHit")
      << "skipHCAL and skipECAL both can't be True. Make at least one of them False.";
  }

  if ( !skipHCAL_ ) {
    for (const auto &hit : iEvent.get(hbheRecHitsTag_) ) {
      if (passedHcalNoiseCut(hit) ) {
	TLorentzVector hitp4(0,0,0,0);
	getHitP4(hit.id(), hit.energy(), hitp4, iSetup.getData(caloGeometryToken_)) ;
	inputs.push_back(fastjet::PseudoJet(hitp4.Px(), hitp4.Py(), hitp4.Pz(), hitp4.E()));
      }
    }
  }

  if ( !skipECAL_ ) {
    for (const auto &hit : iEvent.get(ebRecHitsTag_) ) {
      if ( passedEcalNoiseCut(hit, &thresholds) ) {
	TLorentzVector hitp4(0,0,0,0);
	getHitP4(hit.id(), hit.energy(), hitp4, iSetup.getData(caloGeometryToken_)) ;
	inputs.push_back(fastjet::PseudoJet(hitp4.Px(), hitp4.Py(), hitp4.Pz(), hitp4.E()));
      }
    }
  
    for (const auto &hit : iEvent.get(eeRecHitsTag_) ) {
      if ( passedEcalNoiseCut(hit, &thresholds) ) {
	TLorentzVector hitp4(0,0,0,0);
	getHitP4(hit.id(), hit.energy(), hitp4, iSetup.getData(caloGeometryToken_)) ;
	inputs.push_back(fastjet::PseudoJet(hitp4.Px(), hitp4.Py(), hitp4.Pz(), hitp4.E()));
      }
    }
  }

  bge_.set_particles(inputs);
  iEvent.put(std::make_unique<double>(bge_.rho()));
  std::cout << "new rho from recHits " << bge_.rho() << std::endl;
}

void FixedGridRhoProducerFastjetFromRecHit::getHitP4(const DetId &detId, float hitE, TLorentzVector &hitp4, const CaloGeometry &caloGeometry) {

  const CaloSubdetectorGeometry* subDetGeom = caloGeometry.getSubdetectorGeometry(detId);
  std::shared_ptr<const CaloCellGeometry> cellGeom = subDetGeom!=nullptr ? subDetGeom->getGeometry(detId) : std::shared_ptr<const CaloCellGeometry>();
  if(cellGeom!=nullptr){
    // use repPos() from cached memory instead of getPosition() to save CPU time
    const auto &gpPos = cellGeom->repPos();
    double thispt=hitE/cosh(gpPos.eta());
    hitp4.SetPtEtaPhiE(thispt,gpPos.eta(),gpPos.phi(),hitE);
  }else{
    if(detId.rawId()!=0) edm::LogInfo("FixedGridRhoProducerFastjetFromRecHit") <<"Warning : Geometry not found for a calo hit, setting p4 as (0,0,0,0)" << std::endl;
    hitp4.SetPtEtaPhiE(0,0,0,0);
  }
}

bool FixedGridRhoProducerFastjetFromRecHit::passedHcalNoiseCut(const HBHERecHit &hit) {
  bool passed=false;
  const HcalDetId thisDetId(hit.detid());
  const int thisDepth = thisDetId.depth();
  if ( (thisDetId.subdet() == HcalBarrel) &&  (hit.energy() > eThresHB_[thisDepth-1]) ) passed=true;
  else if ( (thisDetId.subdet() == HcalEndcap) &&  (hit.energy() > eThresHE_[thisDepth-1]) ) passed=true;
  return passed;
}

bool FixedGridRhoProducerFastjetFromRecHit::passedEcalNoiseCut(const EcalRecHit &hit,const EcalPFRecHitThresholds *thresholds) {
  bool passed=false;
  if ( hit.energy() > (*thresholds)[hit.detid()]) passed=true;
  return passed;
}

DEFINE_FWK_MODULE(FixedGridRhoProducerFastjetFromRecHit);
