#ifndef DataFormats_EgammaReco_interface_SuperclusterHostCollection_h
#define DataFormats_EgammaReco_interface_SuperclusterHostCollection_h

#include "DataFormats/Portable/interface/PortableHostCollection.h"
#include "DataFormats/PortableTestObjects/interface/TestSoA.h"
#include "DataFormats/EgammaReco/interface/SuperClusterSoA.h"

namespace portableSuperclusterSoA {

  // SoA with x, y, z, id fields in host memory
  using SuperclusterHostCollection = PortableHostCollection<SuperClusterSoA>;
  
}  // namespace portableSuperclusterSoA

#endif  // DataFormats_PortableTestObjects_interface_TestHostCollection_h
