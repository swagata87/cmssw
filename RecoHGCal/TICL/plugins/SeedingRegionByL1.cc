/*  TICL is currently seeded by tracks, or just globally. 
 *  Here, adding option to seed TICL by L1 e/gamma objects (L1 TkEm).
 *  This is important for HLT.  
 */

#include <algorithm>
#include <set>
#include <vector>

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "SeedingRegionByL1.h"

ticl::SeedingRegionByL1::SeedingRegionByL1(const edm::ParameterSet &conf, edm::ConsumesCollector &sumes)
    : SeedingRegionAlgoBase(conf, sumes),
      l1TkEmsToken_(sumes.consumes<std::vector<l1t::TkEm>>(conf.getParameter<edm::InputTag>("l1TkEms"))),
      minPt_(conf.getParameter<double>("minPt")),
      minAbsEta_(conf.getParameter<double>("minAbsEta")),
      maxAbsEta_(conf.getParameter<double>("maxAbsEta")),
      endcapScalings_(conf.getParameter<std::vector<double> >("endcapScalings")),
      quality_(conf.getParameter<int>("quality")) {}

ticl::SeedingRegionByL1::~SeedingRegionByL1() {}

void ticl::SeedingRegionByL1::makeRegions(const edm::Event &ev,
                                        const edm::EventSetup &es,
                                        std::vector<TICLSeedingRegion> &result) {

  auto l1TrkEms = ev.getHandle(l1TkEmsToken_);
  edm::ProductID l1tkemsId = l1TrkEms.id();

  for(size_t indx=0;indx<(*l1TrkEms).size();indx++){
    const auto& l1TrkEm = (*l1TrkEms)[indx];
    double offlinePt = this->TkEmOfflineEt(l1TrkEm.pt(), l1TrkEm.eta());
    if ( (offlinePt<minPt_) || (std::abs(l1TrkEm.eta())<minAbsEta_) || (std::abs(l1TrkEm.eta())>maxAbsEta_) || (l1TrkEm.EGRef()->hwQual() != quality_) ) {
      continue;
    }

    int iSide = int(l1TrkEm.eta() > 0);
    result.emplace_back(GlobalPoint(l1TrkEm.p4().X(),l1TrkEm.p4().Y(),l1TrkEm.p4().Z()), GlobalVector(l1TrkEm.px(),l1TrkEm.py(),l1TrkEm.pz()), iSide, indx, l1tkemsId );
    indx++;
  }
  
  std::sort(result.begin(), result.end(), [](const TICLSeedingRegion &a, const TICLSeedingRegion &b) {
      return a.directionAtOrigin.perp2() > b.directionAtOrigin.perp2();
    });
  
}

double ticl::SeedingRegionByL1::TkEmOfflineEt(double Et, double Eta) const {
    return (endcapScalings_.at(0) + Et * endcapScalings_.at(1) + Et * Et * endcapScalings_.at(2));
}

void ticl::SeedingRegionByL1::fillPSetDescription(edm::ParameterSetDescription& desc)
{
  desc.add<edm::InputTag>("l1tkems", edm::InputTag("L1TkPhotonsHGC","EG"));
  desc.add<double>("minpt", 10); 
  desc.add<double>("minabseta", 1.479);
  desc.add<double>("maxabseta", 4.0);
  desc.add<std::vector<double>>("endcapScalings", {3.17445,1.13219,0.0});
  desc.add<int>("quality", 5);
}

edm::ParameterSetDescription ticl::SeedingRegionByL1::makePSetDescription(){
  edm::ParameterSetDescription desc;
  fillPSetDescription(desc);
  return desc;
}
