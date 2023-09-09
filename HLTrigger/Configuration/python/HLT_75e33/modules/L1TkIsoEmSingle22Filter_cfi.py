import FWCore.ParameterSet.Config as cms

l1tTkIsoEmSingle22Filter = cms.EDFilter("L1TTkEmFilter",
    ApplyQual1 = cms.bool(True),
    ApplyQual2 = cms.bool(True),
    EtaBinsForIsolation = cms.vdouble(0.0, 1.479, 2.4),
    MaxAbsEta1 = cms.double(1.479),
    MinAbsEta1 = cms.double(0.0),
    MaxAbsEta2 = cms.double(5.0),
    MinAbsEta2 = cms.double(1.479),
    MinN = cms.int32(1),
    MinPt = cms.double(22.0),
    Qual1IsMask = cms.bool(True),
    Qual2IsMask = cms.bool(True),
    Quality1 = cms.int32(2),
    Quality2 = cms.int32(4),
    Scalings = cms.PSet(
        barrel = cms.vdouble(2.54255, 1.08749, 0.0),
        endcap = cms.vdouble(2.11186, 1.15524, 0.0)
    ),
    TrkIsolation = cms.vdouble(0.35, 0.28),
    inputTag1 = cms.InputTag("l1tLayer2EG","L1CtTkEm"),
    inputTag2 = cms.InputTag("l1tLayer2EG","L1CtTkEm"),
    saveTags = cms.bool(True)
)
