#include "DataFormats/Portable/interface/Product.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterSoA.h"
#include "DataFormats/PortableTestObjects/interface/alpaka/TestDeviceCollection.h"
#include "DataFormats/EgammaReco/interface/alpaka/SuperclusterDeviceCollection.h"
#include "DataFormats/EgammaReco/interface/SuperclusterHostCollection.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Utilities/interface/StreamID.h"
#include "HeterogeneousCore/AlpakaCore/interface/ScopedContext.h"
#include "HeterogeneousCore/AlpakaInterface/interface/config.h"
#include "HeterogeneousCore/AlpakaServices/interface/alpaka/AlpakaService.h"
#include "HeterogeneousCore/AlpakaCore/interface/alpaka/global/EDProducer.h"

#include "SuperclusterAlgo.h"

namespace ALPAKA_ACCELERATOR_NAMESPACE {
  class SuperclusterCopyToDeviceProducer : public global::EDProducer<> {
  public:
    SuperclusterCopyToDeviceProducer(edm::ParameterSet const& config)
        : deviceToken_{produces()}, size_{config.getParameter<int32_t>("size")} {}

    void produce(edm::StreamID sid, device::Event& event, device::EventSetup const&) const override {

      portableSuperclusterSoA::SuperclusterHostCollection hostProduct{size_, event.queue()};
      portableSuperclusterSoA::SuperclusterDeviceCollection deviceProduct{size_, event.queue()};

      auto& view = hostProduct.view();

      int i=0;
      for (auto& superClusRef : event.get(superClustersTokens_)) {
	view[i].scSeedTheta() =  superClusRef->seed()->position().theta();
	view[i].scPhi() = superClusRef->position().phi();
	view[i].scR() = superClusRef->position().r();
	view[i].scEnergy() = superClusRef->energy();
	i++;
      }
     
      event.emplace(deviceToken_, std::move(deviceProduct));
    }

    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
      edm::ParameterSetDescription desc;
      desc.add<int32_t>("size");
      descriptions.addWithDefaultLabel(desc);
    }

  private:

     const device::EDPutToken<portableSuperclusterSoA::SuperclusterDeviceCollection> deviceToken_;
    const int32_t size_;
    edm::EDGetTokenT<std::vector<reco::SuperClusterRef>> superClustersTokens_;

    // implementation of the algorithm
    //    SuperclusterAlgo algo_;
  };

}  // namespace ALPAKA_ACCELERATOR_NAMESPACE

#include "HeterogeneousCore/AlpakaCore/interface/MakerMacros.h"
DEFINE_FWK_ALPAKA_MODULE(SuperclusterCopyToDeviceProducer);
