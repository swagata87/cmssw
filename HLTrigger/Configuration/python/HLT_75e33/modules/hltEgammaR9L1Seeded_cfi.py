import FWCore.ParameterSet.Config as cms

hltEgammaR9L1Seeded  = cms.EDProducer( "EgammaHLTR9IDProducer",
                                       ecalRechitEB = cms.InputTag( "hltEcalRecHit:EcalRecHitsEB" ),
                                       ecalRechitEE = cms.InputTag( "hltEcalRecHit:EcalRecHitsEE" ),
                                       recoEcalCandidateProducer = cms.InputTag( "hltEgammaCandidatesL1Seeded" )
)
