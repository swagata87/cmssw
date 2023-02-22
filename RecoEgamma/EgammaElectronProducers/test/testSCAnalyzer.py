import FWCore.ParameterSet.Config as cms

process = cms.Process('Reader')

# read the products from a 'test.root' file
process.source = cms.Source('PoolSource',
    fileNames = cms.untracked.vstring('file:electronsoa.root')
)

# enable logging for the TestAlpakaAnalyzer
process.MessageLogger.TestAlpakaAnalyzer = cms.untracked.PSet()

# analyse the first product
process.testAnalyzer = cms.EDAnalyzer('SuperclusterAlpakaAnalyzer',
    source = cms.InputTag('testSoA')
)

# analyse the second product
#process.testAnalyzerSerial = cms.EDAnalyzer('TestAlpakaAnalyzer',
#    source = cms.InputTag('testProducerSerial')
#)

process.cuda_path = cms.Path(process.testAnalyzer)

#process.serial_path = cms.Path(process.testAnalyzerSerial)

process.maxEvents.input = -1
