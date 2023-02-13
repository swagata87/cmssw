import FWCore.ParameterSet.Config as cms

from RecoParticleFlow.PFClusterProducer.particleFlowRecHitHBHE_cfi import _thresholdsHBphase1, _thresholdsHEphase1, _thresholdsHBphase1_2023

egammaHBHERecHit = cms.PSet(
    hbheRecHits = cms.InputTag('hbhereco'),
    recHitEThresholdHB = _thresholdsHBphase1,
    recHitEThresholdHE = _thresholdsHEphase1,
    maxHcalRecHitSeverity = cms.int32(9),
)

egammaHBHERecHit_2023 = egammaHBHERecHit.clone(
    recHitEThresholdHB = _thresholdsHBphase1_2023
)

from Configuration.Eras.Modifier_run3_2023_egamma_cff import run3_2023_egamma
run3_2023_egamma.toReplaceWith(egammaHBHERecHit,egammaHBHERecHit_2023)
