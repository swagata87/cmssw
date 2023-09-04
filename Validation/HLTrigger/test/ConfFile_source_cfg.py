import FWCore.ParameterSet.Config as cms

process = cms.Process("HLTGenValSource")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("DQMServices.Core.DQM_cfg")
process.load("DQMServices.Core.DQMStore_cfg")
process.load("DQMServices.Components.DQMEnvironment_cfi")
process.load("DQMServices.Components.MEtoEDMConverter_cff")
from DQMServices.Core.DQMEDHarvester import DQMEDHarvester

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(6000) )

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100


# using: CMSSW_12_3_0_pre4__fullsim_noPU_2021_14TeV-TTbar_14TeV-00001
process.source = cms.Source("PoolSource",
    #fileNames = cms.untracked.vstring("root://cmsxrootd.fnal.gov//store/mc/RunIISummer20UL18RECO/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/AODSIM/106X_upgrade2018_realistic_v11_L1v1-v2/00000/B4A06248-D09E-314A-ACD7-F157B86109E6.root")
    fileNames = cms.untracked.vstring(
        "file:Phase2_HLT.root"
    )
)

ptBins=cms.vdouble(0, 10, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85,90,95 , 100,105,110,115 ,120,125, 130, 135,140,145, 150)
ptBinsHT=cms.vdouble(0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1200, 1300)
ptBinsJet=cms.vdouble(0, 100, 200, 300, 350, 375, 400, 425, 450, 475, 500, 550, 600, 700, 800, 900, 1000)
etaBins=cms.vdouble(-4,-3, -2.5, -2, -1.5, -1, -0.5, 0, 0.5, 1, 1.5, 2, 2.5, 3, 4)

etaCut=cms.PSet(
    rangeVar=cms.string("eta"),
    allowedRanges=cms.vstring("-2.4:2.4")
)
ptCut=cms.PSet(
    rangeVar=cms.string("pt"),
    allowedRanges=cms.vstring("10:9999")
)



process.HLTGenValSourceELE = cms.EDProducer('HLTGenValSource',
    # these are the only one the user needs to specify
    objType = cms.string("ele"),
    hltProcessName = cms.string("HLTX"),
    hltPathsToCheck = cms.vstring(
      "HLT_Ele26_WP70_Unseeded",
      "HLT_Ele26_WP70_L1Seeded",
      "HLT_Ele32_WPTight_Unseeded",
      "HLT_Ele32_WPTight_L1Seeded",

    ),
    binnings = cms.VPSet(
        cms.PSet(
            name = cms.string("ptBinsJet"),
            vsVar = cms.string("pt"),
            binLowEdges = ptBinsJet
        )
    ),
    doOnlyLastFilter = cms.bool(True),
    histConfigs = cms.VPSet(
        cms.PSet(
            vsVar = cms.string("pt"),
            binLowEdges = ptBins,
            #rangeCuts = cms.VPSet(ptCut)
        ),
        cms.PSet(
            vsVar = cms.string("eta"),
            binLowEdges = etaBins,
        ),
    ),
)

process.p = cms.Path(
        process.HLTGenValSourceELE
        )

# the harvester
process.harvester = DQMEDHarvester("HLTGenValClient",
    outputFileName = cms.untracked.string('output_validation.root'),
    subDirs        = cms.untracked.vstring("HLTGenVal"),
)

process.outpath = cms.EndPath(process.harvester)
