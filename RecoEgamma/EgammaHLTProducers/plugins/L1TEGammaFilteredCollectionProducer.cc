#include "DataFormats/L1TCorrelator/interface/TkEm.h"

#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/EventSetupRecord.h"
#include "FWCore/Framework/interface/global/EDProducer.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

class L1TEGammaFilteredCollectionProducer : public edm::global::EDProducer<>  {
public:
  explicit L1TEGammaFilteredCollectionProducer(const edm::ParameterSet&);
  ~L1TEGammaFilteredCollectionProducer() override;
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  void produce(edm::StreamID sid, edm::Event& iEvent, const edm::EventSetup& iSetup) const override; 
  
private:
  edm::InputTag l1EgTag_;  
  typedef BXVector<l1t::EGamma> L1EgCollection;
  edm::EDGetTokenT<L1EgCollection> l1EgToken_; 
  int quality_;       
  bool qualIsMask_;    
  bool applyQual_;    
  
};

L1TEGammaFilteredCollectionProducer::L1TEGammaFilteredCollectionProducer(const edm::ParameterSet& iConfig)
  : l1EgTag_(iConfig.getParameter<edm::InputTag>("inputTag")),
    l1EgToken_(consumes<L1EgCollection>(l1EgTag_)) {
  quality_ = iConfig.getParameter<int>("quality");
  qualIsMask_ = iConfig.getParameter<bool>("qualIsMask");
  applyQual_ = iConfig.getParameter<bool>("applyQual");
  produces<L1EgCollection>();

}

L1TEGammaFilteredCollectionProducer::~L1TEGammaFilteredCollectionProducer() = default;

void L1TEGammaFilteredCollectionProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.add<edm::InputTag>("inputTag", edm::InputTag("L1EGammaClusterEmuProducer"));
  desc.add<int>("quality", 0x2);
  desc.add<bool>("qualIsMask", true);
  desc.add<bool>("applyQual", true);
  descriptions.add("L1TEGammaFilteredCollectionProducer", desc);
}

void L1TEGammaFilteredCollectionProducer::produce(edm::StreamID sid, edm::Event& iEvent,
                              const edm::EventSetup& iSetup) const {

  auto outEgs = std::make_unique<L1EgCollection>();
  auto l1Egs = iEvent.getHandle(l1EgToken_);

  // Loop over all L1 e/gamma objects
  for(const auto& iEg : * l1Egs){
    bool passQuality(false);
    if (applyQual_) {
      if (qualIsMask_)
        passQuality = (iEg.hwQual() & quality_);
      else
        passQuality = (iEg.hwQual() == quality_);
    } else
      passQuality = true;

    // if quality is passed, put the object in filtered collection
    if (passQuality) {
      outEgs->push_back(0,iEg);
    }
  }
 
  iEvent.put(std::move(outEgs));  
}

DEFINE_FWK_MODULE(L1TEGammaFilteredCollectionProducer);
