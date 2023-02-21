#ifndef EgammaReco_SuperClusterSoA_h
#define EgammaReco_SuperClusterSoA_h

#include <cstdint>
//#include "HeterogeneousCore/CUDAUtilities/interface/cudaCompat.h"
#include "DataFormats/SoATemplate/interface/SoACommon.h"
#include "DataFormats/SoATemplate/interface/SoALayout.h"
#include "DataFormats/SoATemplate/interface/SoAView.h"

//#include "DataFormats/EgammaReco/interface/SuperCluster.h"

namespace portableSuperclusterSoA {

  // SoA layout for supercluster
  GENERATE_SOA_LAYOUT(SuperClusterSoALayout,
                      // columns: one value per element
                      SOA_COLUMN(double, scSeedTheta),
                      SOA_COLUMN(double, scPhi),
                      SOA_COLUMN(double, scR),
                      SOA_COLUMN(double, scEnergy),
                      SOA_COLUMN(int32_t, id),
		      SOA_SCALAR(double, r))

  using SuperClusterSoA = SuperClusterSoALayout<>;

}  // namespace portableSuperclusterSoA 

#endif
