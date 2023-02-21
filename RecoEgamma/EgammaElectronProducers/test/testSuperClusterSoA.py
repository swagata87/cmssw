import FWCore.ParameterSet.Config as cms

from Configuration.Eras.Era_Run3_cff import Run3
process = cms.Process("testSoA")

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.Services_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.EventContent.EventContent_cff")

process.load('Configuration.StandardSequences.Accelerators_cff')
process.load('HeterogeneousCore.AlpakaCore.ProcessAcceleratorAlpaka_cfi')

process.testSoA = cms.EDProducer( "SuperclusterCopyToDeviceProducer@alpaka",
    size = cms.int32( 42 ),
    getsuperclus = cms.InputTag("particleFlowSuperClusterECAL","particleFlowSuperClusterECALBarrel"),
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source( "PoolSource",
    fileNames = cms.untracked.vstring(
      '/store/relval/CMSSW_13_0_0_pre4/RelValTTbar_14TeV/GEN-SIM-RECO/130X_mcRun3_2022_realistic_v2-v1/00000/278c88ca-57aa-4f1c-8251-5c3e034c69cf.root',
    ),
    inputCommands = cms.untracked.vstring(
        'keep *'
    )
)

process.p = cms.Path(process.testSoA)
