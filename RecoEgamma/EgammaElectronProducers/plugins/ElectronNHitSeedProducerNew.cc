#include "FWCore/Framework/interface/global/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Framework/interface/ESProducer.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/GeometrySurface/interface/SimpleCylinderBounds.h"
#include "DataFormats/GeometrySurface/interface/SimpleDiskBounds.h"
#include "DataFormats/GeometrySurface/interface/Cylinder.h"
#include "DataFormats/GeometrySurface/interface/BoundCylinder.h"
#include "DataFormats/GeometrySurface/interface/BoundDisk.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/ElectronSeed.h"
#include "DataFormats/EgammaReco/interface/ElectronSeedFwd.h"
#include "DataFormats/TrajectorySeed/interface/TrajectorySeedCollection.h"
#include "DataFormats/TrackerCommon/interface/TrackerTopology.h"
#include "Geometry/Records/interface/TrackerTopologyRcd.h"
#include "TrackingTools/MaterialEffects/interface/PropagatorWithMaterial.h"
#include "DataFormats/TrajectorySeed/interface/PropagationDirection.h"
#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateTransform.h"
#include "TrackingTools/DetLayers/interface/BarrelDetLayer.h"


class ElectronNHitSeedProducerNew : public edm::global::EDProducer<> {
public:
  ElectronNHitSeedProducerNew(const edm::ParameterSet&);
  void produce(edm::StreamID, edm::Event&, const edm::EventSetup&) const final;
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

  static BoundCylinder& barrel();
  static BoundDisk& negativeEtaEndcap();
  static BoundDisk& positiveEtaEndcap();

  static BoundCylinder* initBarrel();
  static BoundDisk* initPositive();
  static BoundDisk* initNegative();

  static const ReferenceCountingPointer<BoundCylinder> theBarrel_;
  static const ReferenceCountingPointer<BoundDisk> theNegativeEtaEndcap_;
  static const ReferenceCountingPointer<BoundDisk> thePositiveEtaEndcap_;

  static constexpr float epsilon = 0.001;
  /** Hard-wired numbers defining the surfaces on which the crystal front faces lie. */
  static constexpr float barrelRadius = 129.f;       // p81, p50, ECAL TDR
  static constexpr float barrelHalfLength = 270.9f;  // p81, p50, ECAL TDR
  static constexpr float endcapRadius = 171.1f;      // fig 3.26, p81, ECAL TDR
  static constexpr float endcapZ = 320.5f;           // fig 3.26, p81, ECAL TDR
  
private:
 
  const edm::EDGetTokenT<TrajectorySeedCollection> initialSeedsToken_;
  edm::ESGetToken<MagneticField, IdealMagneticFieldRecord> magFieldToken_;
  const edm::ESGetToken<TrackerGeometry, TrackerDigiGeometryRecord> geomToken;
  edm::EDGetTokenT<std::vector<reco::SuperClusterRef>> superClustersTokens_;
};

ElectronNHitSeedProducerNew::ElectronNHitSeedProducerNew(const edm::ParameterSet& pset)
  :   initialSeedsToken_(consumes(pset.getParameter<edm::InputTag>("initialSeeds"))),
      magFieldToken_(esConsumes()),
      geomToken(esConsumes())
{
  superClustersTokens_ = consumes(pset.getParameter<edm::InputTag>("superClusters"));
}

BoundCylinder& ElectronNHitSeedProducerNew::barrel() { return *ElectronNHitSeedProducerNew::theBarrel_; }
BoundDisk& ElectronNHitSeedProducerNew::negativeEtaEndcap() { return *ElectronNHitSeedProducerNew::theNegativeEtaEndcap_; }
BoundDisk& ElectronNHitSeedProducerNew::positiveEtaEndcap() { return *ElectronNHitSeedProducerNew::thePositiveEtaEndcap_; }

BoundCylinder* ElectronNHitSeedProducerNew::initBarrel() {
  Surface::RotationType rot;  // unit rotation matrix
  return new Cylinder(
      barrelRadius,
      Surface::PositionType(0, 0, 0),
      rot,
      new SimpleCylinderBounds(barrelRadius - epsilon, barrelRadius + epsilon, -barrelHalfLength, barrelHalfLength));
}

BoundDisk* ElectronNHitSeedProducerNew::initPositive() {
  Surface::RotationType rot;  // unit rotation matrix
  return new BoundDisk(
      Surface::PositionType(0, 0, endcapZ),
      rot,
      new SimpleDiskBounds(0, endcapRadius, -epsilon, epsilon));
}


BoundDisk* ElectronNHitSeedProducerNew::initNegative() {
  Surface::RotationType rot;  // unit rotation matrix
  return new BoundDisk(
      Surface::PositionType(0, 0, -endcapZ),
      rot,
      new SimpleDiskBounds(0, endcapRadius, -epsilon, epsilon));
}

const ReferenceCountingPointer<BoundCylinder>  ElectronNHitSeedProducerNew::theBarrel_ = initBarrel(); 
const ReferenceCountingPointer<BoundDisk> ElectronNHitSeedProducerNew::thePositiveEtaEndcap_ = initPositive();
const ReferenceCountingPointer<BoundDisk> ElectronNHitSeedProducerNew::theNegativeEtaEndcap_ = initNegative();   

void ElectronNHitSeedProducerNew::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.add<edm::InputTag>("initialSeeds", {"hltElePixelSeedsCombined"});
  desc.add<edm::InputTag>("superClusters", {"hltEgammaSuperClustersToPixelMatch"});
  descriptions.add("electronNHitSeedProducerNew", desc);
}

void ElectronNHitSeedProducerNew::produce(edm::StreamID, edm::Event& iEvent, const edm::EventSetup& iSetup) const {

  std::cout << "\n\n This event has following SCs \n";
  for (auto& superClusRef : iEvent.get(superClustersTokens_)) {
    std::cout << "SC et " << superClusRef->energy() / std::cosh(superClusRef->position().eta() ) << " eta " << superClusRef->position().eta() << std::endl;  
  }
  auto const& magField = iSetup.getData(magFieldToken_);
  const TrackerGeometry* theG = &iSetup.getData(geomToken);

  GlobalPoint center(0.0, 0.0, 0.0);
  float theMagField = magField.inTesla(center).mag();
  //  std::cout << "theMagField = " << theMagField << std::endl;

  PropagatorWithMaterial forwardPropagator_ =  PropagatorWithMaterial(alongMomentum, 0.000511, &magField);

  std::cout << " ** this event has " << iEvent.get(initialSeedsToken_).size() << " initial seeds \n";
  std::cout << " and " << iEvent.get(superClustersTokens_).size() << " superclusters \n";

  //LOOP on initial seeds
  int iseed=0; 
  for (auto& initialSeedRef : iEvent.get(initialSeedsToken_)) {
    iseed++;
    //    std::cout << "nhit in seed " << initialSeedRef.nHits() << std::endl;
    int nHitInSeed=initialSeedRef.nHits();
    PTrajectoryStateOnDet state1 = initialSeedRef.startingState();
    DetId detId1(state1.detId());
    TrajectoryStateOnSurface tsos1 =
          trajectoryStateTransform::transientState(state1, &(theG->idToDet(detId1)->surface()), &iSetup.getData(magFieldToken_));

    //std::cout << "tsos valid? " << tsos1.isValid() << std::endl;
    TrajectoryStateOnSurface stateAtECAL_ = forwardPropagator_.propagate(tsos1, ElectronNHitSeedProducerNew::barrel());
    //    std::cout << " propagated state valid? " <<   (forwardPropagator_.propagate(tsos1, ElectronNHitSeedProducerNew::initBarrel())).isValid() << std::endl;

    if (!stateAtECAL_.isValid() || (stateAtECAL_.isValid() && fabs(stateAtECAL_.globalPosition().eta()) > 1.479)) {
      if (tsos1.globalPosition().eta() > 0.) {
        stateAtECAL_ = forwardPropagator_.propagate(tsos1, positiveEtaEndcap());

      } else {
        stateAtECAL_ = forwardPropagator_.propagate(tsos1, negativeEtaEndcap());
      }
    }
    
    if (!stateAtECAL_.isValid()) continue;
    //     std::cout << "stateAtECAL_ not valid!!!!!!!!!" << std::endl;
      //std::cout << "stateAtECAL eta" << stateAtECAL_.globalPosition().eta() << std::endl;
    //}
    else {
      //     std::cout << "\n\ntsos1 eta/phi/pt " << tsos1.globalPosition().eta() << " / " << tsos1.globalPosition().phi()
      //	<< " / " << tsos1.globalMomentum().perp() << std::endl;

      //std::cout << "ecal_ eta/phi/pt " << stateAtECAL_.globalPosition().eta() << " / " << stateAtECAL_.globalPosition().phi()
      //	<< " / " << stateAtECAL_.globalMomentum().perp() << std::endl;


      
      //std::cout << "stateAtECAL VALID :-) the eta is " << stateAtECAL_.globalPosition().eta() << std::endl;
      int isc=0;
      for (auto& superClusRef : iEvent.get(superClustersTokens_)) {
	isc++;
	//std::cout << "\n\n SC et " << superClusRef->energy() / std::cosh(superClusRef->position().eta() ) << " eta " << superClusRef->position().eta() << std::endl;
	float deltar2 =
	  reco::deltaR2(stateAtECAL_.globalPosition().eta(), stateAtECAL_.globalPosition().phi(), superClusRef->seed()->position().eta(), superClusRef->position().phi());	float pTratio= superClusRef->energy() / std::cosh(superClusRef->position().eta() ) / stateAtECAL_.globalMomentum().perp();

	// SC pt<50 GeV -> eventually these will go to config file, just testing now..
	if (superClusRef->energy() / std::cosh(superClusRef->position().eta()) < 50.0) {
	  if (deltar2<0.0005 && pTratio>0.5 && pTratio<1.6) { // these cuts need optimisation
	    std::cout << "the seed of indx " << iseed <<
	      " match a SC with indx " << isc << " and pt " << superClusRef->energy() / std::cosh(superClusRef->position().eta() ) << " with dR2=" << deltar2
		      << " and pTratio=" << pTratio << std::endl;
	    //std::cout << "Seed eta/phi at ECAL surface " << stateAtECAL_.globalPosition().eta()
	    //	    << " / " << stateAtECAL_.globalPosition().phi() << std::endl;
	    //std::cout << "SC eta/phi " << superClusRef->position().eta() << " / " << superClusRef->position().phi() << std::endl;
	    //std::cout << "SC ET = " << superClusRef->energy() / std::cosh(superClusRef->position().eta() ) << " seed ET=" <<
	    //  stateAtECAL_.globalMomentum().perp() << std::endl;
	  }
	} // low pt ends
	else { // high pt starts
	  // no pTratio cut for high pT
	  if (deltar2<0.0001) {
            std::cout << "the seed of indx " << iseed <<
              " match a SC with indx " << isc << " and pt " << superClusRef->energy() / std::cosh(superClusRef->position().eta() ) << " with dR2=" << deltar2
                      << " and pTratio=" << pTratio << std::endl;
            //std::cout << "Seed eta/phi at ECAL surface " << stateAtECAL_.globalPosition().eta()
	    //      << " / " << stateAtECAL_.globalPosition().phi() << std::endl;
	    //std::cout << "SC eta/phi " << superClusRef->position().eta() << " / " << superClusRef->position().phi() << std::endl;
	    //std::cout << "SC ET = " << superClusRef->energy() / std::cosh(superClusRef->position().eta() ) << " seed ET=" <<                                          
           //  stateAtECAL_.globalMomentum().perp() << std::endl;                                                                                                          
          }
	}
      }
    }

    // Would we need individual hit info from the initial seeds?
    //for (int i=0; i<nHitInSeed; i++) {
    //auto const& recHit = *(initialSeedRef.recHits().begin() + i);
    //std::cout << "hit valid? " <<  recHit.isValid() << std::endl;
    //std::cout << "hit " << i << " pos X "  << recHit.globalPosition().x()
    //	<< std::endl;  
    //}
  }
  //  iEvent.emplace(putToken_, std::move(eleSeeds));
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(ElectronNHitSeedProducerNew);
