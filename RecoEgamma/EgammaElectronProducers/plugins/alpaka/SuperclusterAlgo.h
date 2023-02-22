#ifndef RecoEgamma_EgammaElectronProducers_plugins_alpaka_SuperclusterAlgo_h
#define RecoEgamma_EgammaElectronProducers_plugins_alpaka_SuperclusterAlgo_h

#include "DataFormats/PortableTestObjects/interface/alpaka/TestDeviceCollection.h"
#include "DataFormats/EgammaReco/interface/alpaka/SuperclusterDeviceCollection.h"
#include "HeterogeneousCore/AlpakaInterface/interface/config.h"

namespace ALPAKA_ACCELERATOR_NAMESPACE {

  class SuperclusterAlgo {
  public:
    void print(Queue& queue, portableSuperclusterSoA::SuperclusterDeviceCollection& collection) const;
  };

}  // namespace ALPAKA_ACCELERATOR_NAMESPACE

#endif  
