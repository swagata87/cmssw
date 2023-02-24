#include "FWCore/Framework/interface/global/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Framework/interface/ESProducer.h"

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
  TrajectoryStateOnSurface stateAtECAL_;

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

BoundCylinder& ElectronNHitSeedProducerNew::barrel() {
  static const ReferenceCountingPointer<BoundCylinder> theBarrel_;
  return *theBarrel_;
}

BoundDisk& ElectronNHitSeedProducerNew::negativeEtaEndcap() {
  static const ReferenceCountingPointer<BoundDisk> theNegativeEtaEndcap_;
  return *theNegativeEtaEndcap_;
}

BoundDisk& ElectronNHitSeedProducerNew::positiveEtaEndcap() {
  static const ReferenceCountingPointer<BoundDisk> thePositiveEtaEndcap_;
  return *thePositiveEtaEndcap_;
}

  
void ElectronNHitSeedProducerNew::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.add<edm::InputTag>("initialSeeds", {"hltElePixelSeedsCombined"});
  desc.add<edm::InputTag>("superClusters", {"hltEgammaSuperClustersToPixelMatch"});
  descriptions.add("electronNHitSeedProducerNew", desc);
}

void ElectronNHitSeedProducerNew::produce(edm::StreamID, edm::Event& iEvent, const edm::EventSetup& iSetup) const {

  auto const& magField = iSetup.getData(magFieldToken_);
  const TrackerGeometry* theG = &iSetup.getData(geomToken);

  GlobalPoint center(0.0, 0.0, 0.0);
  float theMagField = magField.inTesla(center).mag();
  std::cout << "theMagField = " << theMagField << std::endl;

  PropagatorWithMaterial forwardPropagator_ =  PropagatorWithMaterial(alongMomentum, 0.000511, &magField);

 
  for (auto& initialSeedRef : iEvent.get(initialSeedsToken_)) {
    std::cout << "nhit in seed " << initialSeedRef.nHits() << std::endl;
    int nHitInSeed=initialSeedRef.nHits();
    PTrajectoryStateOnDet state1 = initialSeedRef.startingState();
    DetId detId1(state1.detId());
    const TrajectoryStateOnSurface tsos1 =
          trajectoryStateTransform::transientState(state1, &(theG->idToDet(detId1)->surface()), &iSetup.getData(magFieldToken_));

    std::cout << "tsos valid? " << tsos1.isValid() << std::endl;
    //stateAtECAL_ =
    //   std::cout << " propagated state valid? " <<   (forwardPropagator_.propagate(tsos1, barrel())).isValid() << std::endl;

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
