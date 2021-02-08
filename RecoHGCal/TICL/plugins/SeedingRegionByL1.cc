/*  TICL is currently seeded by tracks, or just globally. 
 *  Here, adding option to seed TICL by L1 e/gamma objects (L1 TkEm).
 *  This is important for HLT.  
 */

#include <algorithm>
#include <set>
#include <vector>

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "SeedingRegionByL1.h"

using namespace ticl;

SeedingRegionByL1::SeedingRegionByL1(const edm::ParameterSet &conf, edm::ConsumesCollector &sumes)
    : SeedingRegionAlgoBase(conf, sumes),
      l1tkems_token_(sumes.consumes<std::vector<l1t::TkEm>>(conf.getParameter<edm::InputTag>("l1tkems"))),
      minpt_(conf.getParameter<double>("minpt")),
      minabseta_(conf.getParameter<double>("minabseta")),
      maxabseta_(conf.getParameter<double>("maxabseta")),
      endcapScalings_(conf.getParameter<std::vector<double> >("endcapScalings")),
      quality_(conf.getParameter<int>("quality")) {}

SeedingRegionByL1::~SeedingRegionByL1() {}

void SeedingRegionByL1::makeRegions(const edm::Event &ev,
                                        const edm::EventSetup &es,
                                        std::vector<TICLSeedingRegion> &result) {

  edm::Handle<std::vector<l1t::TkEm>> l1tkems_h;
  ev.getByToken(l1tkems_token_, l1tkems_h);
  edm::ProductID l1tkemsId = l1tkems_h.id();

  auto atrkEms(l1tkems_h->begin());
  auto otrkEms(l1tkems_h->end());
  std::vector<l1t::TkEm>::const_iterator itkEm;
  int indx=0;
  for (itkEm = atrkEms; itkEm != otrkEms; itkEm++) {
    double offlinePt = this->TkEmOfflineEt(itkEm->pt(), itkEm->eta());
    if ( (offlinePt<minpt_) || (std::abs(itkEm->eta())<minabseta_) || (std::abs(itkEm->eta())>maxabseta_) || (itkEm->EGRef()->hwQual() != quality_) ) {
      continue;
    }

    int iSide = int(itkEm->eta() > 0);
    result.emplace_back( GlobalPoint(itkEm->p4().X(),itkEm->p4().Y(),itkEm->p4().Z()), GlobalVector(itkEm->px(),itkEm->py(),itkEm->pz()) , iSide, indx, l1tkemsId ) ;
    indx++;
  }
  
  std::sort(result.begin(), result.end(), [](const TICLSeedingRegion &a, const TICLSeedingRegion &b) {
      return a.directionAtOrigin.perp2() > b.directionAtOrigin.perp2();
    });
  
}

double SeedingRegionByL1::TkEmOfflineEt(double Et, double Eta) const {
    return (endcapScalings_.at(0) + Et * endcapScalings_.at(1) + Et * Et * endcapScalings_.at(2));
}
