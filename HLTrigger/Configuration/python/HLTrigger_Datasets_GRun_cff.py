# getDatasets.py

import FWCore.ParameterSet.Config as cms


# dump of the Stream PhysicsCommissioning Datasets defined in the HLT table as Stream A Datasets

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetCommissioning_selector
streamA_datasetCommissioning_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetCommissioning_selector.l1tResults = cms.InputTag('')
streamA_datasetCommissioning_selector.throw      = cms.bool(False)
streamA_datasetCommissioning_selector.triggerConditions = cms.vstring('HLT_DiSC30_18_EIso_AND_HE_Mass70_v5', 
    'HLT_HcalIsolatedbunch_v1', 
    'HLT_IsoTrackHB_v2', 
    'HLT_IsoTrackHE_v2', 
    'HLT_L1BeamGasMinus_v2', 
    'HLT_L1BeamGasPlus_v2', 
    'HLT_L1BptxXOR_v2', 
    'HLT_L1SingleMuOpen_DT_v3')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetHLTPhysics_selector
streamA_datasetHLTPhysics_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetHLTPhysics_selector.l1tResults = cms.InputTag('')
streamA_datasetHLTPhysics_selector.throw      = cms.bool(False)
streamA_datasetHLTPhysics_selector.triggerConditions = cms.vstring('HLT_L1FatEvents_v1', 
    'HLT_Physics_v4')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetHcalHPDNoise_selector
streamA_datasetHcalHPDNoise_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetHcalHPDNoise_selector.l1tResults = cms.InputTag('')
streamA_datasetHcalHPDNoise_selector.throw      = cms.bool(False)
streamA_datasetHcalHPDNoise_selector.triggerConditions = cms.vstring('HLT_GlobalRunHPDNoise_v4')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetHcalNZS_selector
streamA_datasetHcalNZS_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetHcalNZS_selector.l1tResults = cms.InputTag('')
streamA_datasetHcalNZS_selector.throw      = cms.bool(False)
streamA_datasetHcalNZS_selector.triggerConditions = cms.vstring('HLT_HcalNZS_v3', 
    'HLT_HcalPhiSym_v3')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetMonteCarlo_selector
streamA_datasetMonteCarlo_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetMonteCarlo_selector.l1tResults = cms.InputTag('')
streamA_datasetMonteCarlo_selector.throw      = cms.bool(False)
streamA_datasetMonteCarlo_selector.triggerConditions = cms.vstring('MC_AK4CaloJets_v2', 
    'MC_AK4PFJets_v4', 
    'MC_AK8CaloHT_v2', 
    'MC_AK8PFHT_v4', 
    'MC_AK8PFJets_v4', 
    'MC_AK8TrimPFJets_v4', 
    'MC_CaloHT_v2', 
    'MC_CaloMET_JetIdCleaned_v2', 
    'MC_CaloMET_v2', 
    'MC_CaloMHT_v2', 
    'MC_Diphoton10_10_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass10_v5', 
    'MC_DoubleEle5_CaloIdL_GsfTrkIdVL_MW_v5', 
    'MC_DoubleGlbTrkMu_TrkIsoVVL_DZ_v2', 
    'MC_DoubleL1Tau_MediumIsoPFTau32_Trk1_eta2p1_Reg_v3', 
    'MC_DoubleMuNoFiltersNoVtx_v2', 
    'MC_DoubleMu_TrkIsoVVL_DZ_v2', 
    'MC_Ele15_Ele10_CaloIdL_TrackIdL_IsoVL_DZ_v6', 
    'MC_Ele5_WPLoose_Gsf_v7', 
    'MC_IsoMu_v5', 
    'MC_IsoTkMu15_v5', 
    'MC_LooseIsoPFTau20_v3', 
    'MC_LooseIsoPFTau50_Trk30_eta2p1_v2', 
    'MC_PFHT_v4', 
    'MC_PFMET_v4', 
    'MC_PFMHT_v4', 
    'MC_ReducedIterativeTracking_v2')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetNoBPTX_selector
streamA_datasetNoBPTX_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetNoBPTX_selector.l1tResults = cms.InputTag('')
streamA_datasetNoBPTX_selector.throw      = cms.bool(False)
streamA_datasetNoBPTX_selector.triggerConditions = cms.vstring('HLT_JetE30_NoBPTX3BX_v3', 
    'HLT_JetE30_NoBPTX_v3', 
    'HLT_JetE50_NoBPTX3BX_v2', 
    'HLT_JetE70_NoBPTX3BX_v2', 
    'HLT_L2Mu10_NoVertex_NoBPTX3BX_v2', 
    'HLT_L2Mu10_NoVertex_NoBPTX_v3', 
    'HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX_v2', 
    'HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX_v1')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetZeroBias_selector
streamA_datasetZeroBias_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetZeroBias_selector.l1tResults = cms.InputTag('')
streamA_datasetZeroBias_selector.throw      = cms.bool(False)
streamA_datasetZeroBias_selector.triggerConditions = cms.vstring('HLT_Random_v2', 
    'HLT_ZeroBias_FirstBXAfterTrain_v1', 
    'HLT_ZeroBias_FirstCollisionAfterAbortGap_copy_v1', 
    'HLT_ZeroBias_FirstCollisionAfterAbortGap_v3', 
    'HLT_ZeroBias_FirstCollisionInTrain_v1', 
    'HLT_ZeroBias_IsolatedBunches_v3', 
    'HLT_ZeroBias_v4')


# dump of the Stream PhysicsEGamma Datasets defined in the HLT table as Stream A Datasets

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetDoubleEG_selector
streamA_datasetDoubleEG_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetDoubleEG_selector.l1tResults = cms.InputTag('')
streamA_datasetDoubleEG_selector.throw      = cms.bool(False)
streamA_datasetDoubleEG_selector.triggerConditions = cms.vstring('HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6', 
    'HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6', 
    'HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v6', 
    'HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v6', 
    'HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v6', 
    'HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v7', 
    'HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v9', 
    'HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v8', 
    'HLT_DoubleEle33_CaloIdL_MW_v7', 
    'HLT_DoubleEle33_CaloIdL_v6', 
    'HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v6', 
    'HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v5', 
    'HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v8', 
    'HLT_DoublePhoton60_v6', 
    'HLT_DoublePhoton85_v7', 
    'HLT_ECALHT800_v4', 
    'HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v5', 
    'HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v7', 
    'HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v7', 
    'HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v7', 
    'HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v7', 
    'HLT_Ele17_CaloIdL_GsfTrkIdVL_v5', 
    'HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v5', 
    'HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v6', 
    'HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v5', 
    'HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8', 
    'HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v8', 
    'HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v7', 
    'HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v7', 
    'HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v7', 
    'HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v2', 
    'HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8', 
    'HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8', 
    'HLT_Ele27_HighEta_Ele20_Mass55_v6', 
    'HLT_Ele30WP60_Ele8_Mass55_v7', 
    'HLT_Ele30WP60_SC4_Mass55_v8', 
    'HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v5', 
    'HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v7', 
    'HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v7', 
    'HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v7', 
    'HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v7')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetSingleElectron_selector
streamA_datasetSingleElectron_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetSingleElectron_selector.l1tResults = cms.InputTag('')
streamA_datasetSingleElectron_selector.throw      = cms.bool(False)
streamA_datasetSingleElectron_selector.triggerConditions = cms.vstring('HLT_Ele105_CaloIdVT_GsfTrkIdT_v7', 
    'HLT_Ele115_CaloIdVT_GsfTrkIdT_v6', 
    'HLT_Ele15_IsoVVVL_BTagCSV_p067_PFHT400_v5', 
    'HLT_Ele15_IsoVVVL_PFHT350_PFMET50_v6', 
    'HLT_Ele15_IsoVVVL_PFHT350_v6', 
    'HLT_Ele15_IsoVVVL_PFHT400_PFMET50_v4', 
    'HLT_Ele15_IsoVVVL_PFHT400_v4', 
    'HLT_Ele15_IsoVVVL_PFHT600_v7', 
    'HLT_Ele20_eta2p1_WPLoose_Gsf_LooseIsoPFTau28_v1', 
    'HLT_Ele22_eta2p1_WPLoose_Gsf_LooseIsoPFTau29_v1', 
    'HLT_Ele22_eta2p1_WPLoose_Gsf_v8', 
    'HLT_Ele23_WPLoose_Gsf_WHbbBoost_v7', 
    'HLT_Ele23_WPLoose_Gsf_v8', 
    'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_v2', 
    'HLT_Ele24_eta2p1_WPLoose_Gsf_v6', 
    'HLT_Ele250_CaloIdVT_GsfTrkIdT_v5', 
    'HLT_Ele25_WPTight_Gsf_v6', 
    'HLT_Ele25_eta2p1_WPLoose_Gsf_v6', 
    'HLT_Ele25_eta2p1_WPTight_Gsf_v6', 
    'HLT_Ele27_WPLoose_Gsf_WHbbBoost_v7', 
    'HLT_Ele27_WPLoose_Gsf_v6', 
    'HLT_Ele27_WPTight_Gsf_L1JetTauSeeded_v3', 
    'HLT_Ele27_WPTight_Gsf_v6', 
    'HLT_Ele27_eta2p1_WPLoose_Gsf_DoubleMediumIsoPFTau32_Trk1_eta2p1_Reg_v6', 
    'HLT_Ele27_eta2p1_WPLoose_Gsf_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v7', 
    'HLT_Ele27_eta2p1_WPLoose_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v8', 
    'HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v7', 
    'HLT_Ele27_eta2p1_WPLoose_Gsf_v7', 
    'HLT_Ele27_eta2p1_WPTight_Gsf_v7', 
    'HLT_Ele300_CaloIdVT_GsfTrkIdT_v5', 
    'HLT_Ele30_WPTight_Gsf_v1', 
    'HLT_Ele30_eta2p1_WPLoose_Gsf_v1', 
    'HLT_Ele30_eta2p1_WPTight_Gsf_v1', 
    'HLT_Ele32_WPTight_Gsf_v1', 
    'HLT_Ele32_eta2p1_WPLoose_Gsf_v1', 
    'HLT_Ele32_eta2p1_WPTight_Gsf_v7', 
    'HLT_Ele35_CaloIdVT_GsfTrkIdT_PFJet150_PFJet50_v5', 
    'HLT_Ele35_WPLoose_Gsf_v6', 
    'HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_v1', 
    'HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v7', 
    'HLT_Ele45_WPLoose_Gsf_L1JetTauSeeded_v3', 
    'HLT_Ele45_WPLoose_Gsf_v6', 
    'HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet140_v5', 
    'HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_v5', 
    'HLT_Ele50_IsoVVVL_PFHT400_v4')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetSinglePhoton_selector
streamA_datasetSinglePhoton_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetSinglePhoton_selector.l1tResults = cms.InputTag('')
streamA_datasetSinglePhoton_selector.throw      = cms.bool(False)
streamA_datasetSinglePhoton_selector.triggerConditions = cms.vstring('HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7', 
    'HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v6', 
    'HLT_Photon120_R9Id90_HE10_IsoM_v7', 
    'HLT_Photon120_v6', 
    'HLT_Photon135_PFMET100_v6', 
    'HLT_Photon165_HE10_v7', 
    'HLT_Photon165_R9Id90_HE10_IsoM_v8', 
    'HLT_Photon175_v7', 
    'HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7', 
    'HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v6', 
    'HLT_Photon22_R9Id90_HE10_IsoM_v6', 
    'HLT_Photon22_v5', 
    'HLT_Photon250_NoHE_v6', 
    'HLT_Photon300_NoHE_v6', 
    'HLT_Photon30_R9Id90_HE10_IsoM_v7', 
    'HLT_Photon30_v6', 
    'HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7', 
    'HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v7', 
    'HLT_Photon36_R9Id90_HE10_IsoM_v7', 
    'HLT_Photon36_v6', 
    'HLT_Photon500_v5', 
    'HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7', 
    'HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v6', 
    'HLT_Photon50_R9Id90_HE10_IsoM_v7', 
    'HLT_Photon50_v6', 
    'HLT_Photon600_v5', 
    'HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7', 
    'HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v6', 
    'HLT_Photon75_R9Id90_HE10_IsoM_v7', 
    'HLT_Photon75_v6', 
    'HLT_Photon90_CaloIdL_PFHT600_v6', 
    'HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7', 
    'HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v6', 
    'HLT_Photon90_R9Id90_HE10_IsoM_v7', 
    'HLT_Photon90_v6')


# dump of the Stream PhysicsHadronsTaus Datasets defined in the HLT table as Stream A Datasets

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetBTagCSV_selector
streamA_datasetBTagCSV_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetBTagCSV_selector.l1tResults = cms.InputTag('')
streamA_datasetBTagCSV_selector.throw      = cms.bool(False)
streamA_datasetBTagCSV_selector.triggerConditions = cms.vstring('HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v3', 
    'HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v3', 
    'HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v3', 
    'HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v3', 
    'HLT_DoubleJetsC100_SingleBTagCSV_p014_SinglePFJetC350_v3', 
    'HLT_DoubleJetsC100_SingleBTagCSV_p014_v2', 
    'HLT_DoubleJetsC100_SingleBTagCSV_p026_SinglePFJetC350_v3', 
    'HLT_DoubleJetsC100_SingleBTagCSV_p026_v2', 
    'HLT_DoubleJetsC112_DoubleBTagCSV_p014_DoublePFJetsC112MaxDeta1p6_v3', 
    'HLT_DoubleJetsC112_DoubleBTagCSV_p026_DoublePFJetsC172_v3', 
    'HLT_QuadJet45_DoubleBTagCSV_p087_v4', 
    'HLT_QuadJet45_TripleBTagCSV_p087_v4', 
    'HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v3', 
    'HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v3', 
    'HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v3', 
    'HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v3', 
    'HLT_Rsq0p02_MR400_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200_v1', 
    'HLT_Rsq0p02_MR450_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200_v1')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetBTagMu_selector
streamA_datasetBTagMu_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetBTagMu_selector.l1tResults = cms.InputTag('')
streamA_datasetBTagMu_selector.throw      = cms.bool(False)
streamA_datasetBTagMu_selector.triggerConditions = cms.vstring('HLT_BTagMu_AK8Jet300_Mu5_v2', 
    'HLT_BTagMu_DiJet110_Mu5_v3', 
    'HLT_BTagMu_DiJet170_Mu5_v2', 
    'HLT_BTagMu_DiJet20_Mu5_v3', 
    'HLT_BTagMu_DiJet40_Mu5_v3', 
    'HLT_BTagMu_DiJet70_Mu5_v3', 
    'HLT_BTagMu_Jet300_Mu5_v3')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetDisplacedJet_selector
streamA_datasetDisplacedJet_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetDisplacedJet_selector.l1tResults = cms.InputTag('')
streamA_datasetDisplacedJet_selector.throw      = cms.bool(False)
streamA_datasetDisplacedJet_selector.triggerConditions = cms.vstring('HLT_HT200_DisplacedDijet40_DisplacedTrack_v3', 
    'HLT_HT200_v3', 
    'HLT_HT250_DisplacedDijet40_DisplacedTrack_v4', 
    'HLT_HT275_v3', 
    'HLT_HT325_v3', 
    'HLT_HT350_DisplacedDijet40_DisplacedTrack_v4', 
    'HLT_HT350_DisplacedDijet40_Inclusive_v3', 
    'HLT_HT350_DisplacedDijet80_DisplacedTrack_v4', 
    'HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v4', 
    'HLT_HT400_DisplacedDijet40_Inclusive_v4', 
    'HLT_HT425_v3', 
    'HLT_HT500_DisplacedDijet40_Inclusive_v4', 
    'HLT_HT550_DisplacedDijet40_Inclusive_v4', 
    'HLT_HT550_DisplacedDijet80_Inclusive_v1', 
    'HLT_HT575_v3', 
    'HLT_HT650_DisplacedDijet80_Inclusive_v4', 
    'HLT_HT750_DisplacedDijet80_Inclusive_v4', 
    'HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v3', 
    'HLT_VBF_DisplacedJet40_DisplacedTrack_v3', 
    'HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v3', 
    'HLT_VBF_DisplacedJet40_Hadronic_v3', 
    'HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v3', 
    'HLT_VBF_DisplacedJet40_TightID_Hadronic_v3', 
    'HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v3', 
    'HLT_VBF_DisplacedJet40_VTightID_Hadronic_v3', 
    'HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v3', 
    'HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v3')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetHTMHT_selector
streamA_datasetHTMHT_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetHTMHT_selector.l1tResults = cms.InputTag('')
streamA_datasetHTMHT_selector.throw      = cms.bool(False)
streamA_datasetHTMHT_selector.triggerConditions = cms.vstring('HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v3', 
    'HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v3', 
    'HLT_PFHT200_DiPFJetAve90_PFAlphaT0p57_v5', 
    'HLT_PFHT200_DiPFJetAve90_PFAlphaT0p63_v5', 
    'HLT_PFHT200_PFAlphaT0p51_v5', 
    'HLT_PFHT250_DiPFJetAve90_PFAlphaT0p58_v5', 
    'HLT_PFHT300_DiPFJetAve90_PFAlphaT0p54_v5', 
    'HLT_PFHT300_PFMET110_v4', 
    'HLT_PFHT350_DiPFJetAve90_PFAlphaT0p53_v5', 
    'HLT_PFHT400_DiPFJetAve90_PFAlphaT0p52_v5', 
    'HLT_Rsq0p25_v4', 
    'HLT_Rsq0p30_v4', 
    'HLT_RsqMR270_Rsq0p09_MR200_4jet_v4', 
    'HLT_RsqMR270_Rsq0p09_MR200_v4')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetJetHT_selector
streamA_datasetJetHT_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetJetHT_selector.l1tResults = cms.InputTag('')
streamA_datasetJetHT_selector.throw      = cms.bool(False)
streamA_datasetJetHT_selector.triggerConditions = cms.vstring('HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v3', 
    'HLT_AK8DiPFJet250_200_TrimMass30_v3', 
    'HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v3', 
    'HLT_AK8DiPFJet280_200_TrimMass30_v3', 
    'HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v4', 
    'HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v5', 
    'HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v6', 
    'HLT_AK8PFJet140_v2', 
    'HLT_AK8PFJet200_v2', 
    'HLT_AK8PFJet260_v3', 
    'HLT_AK8PFJet320_v3', 
    'HLT_AK8PFJet360_TrimMass30_v5', 
    'HLT_AK8PFJet400_v3', 
    'HLT_AK8PFJet40_v3', 
    'HLT_AK8PFJet450_v3', 
    'HLT_AK8PFJet500_v3', 
    'HLT_AK8PFJet60_v2', 
    'HLT_AK8PFJet80_v2', 
    'HLT_CaloJet500_NoJetID_v4', 
    'HLT_DiCentralPFJet170_CFMax0p1_v3', 
    'HLT_DiCentralPFJet170_v3', 
    'HLT_DiCentralPFJet220_CFMax0p3_v3', 
    'HLT_DiCentralPFJet330_CFMax0p5_v3', 
    'HLT_DiCentralPFJet430_v3', 
    'HLT_DiPFJetAve100_HFJEC_v6', 
    'HLT_DiPFJetAve140_v5', 
    'HLT_DiPFJetAve160_HFJEC_v6', 
    'HLT_DiPFJetAve200_v5', 
    'HLT_DiPFJetAve220_HFJEC_v7', 
    'HLT_DiPFJetAve260_v6', 
    'HLT_DiPFJetAve300_HFJEC_v7', 
    'HLT_DiPFJetAve320_v6', 
    'HLT_DiPFJetAve400_v6', 
    'HLT_DiPFJetAve40_v6', 
    'HLT_DiPFJetAve500_v6', 
    'HLT_DiPFJetAve60_HFJEC_v6', 
    'HLT_DiPFJetAve60_v6', 
    'HLT_DiPFJetAve80_HFJEC_v6', 
    'HLT_DiPFJetAve80_v5', 
    'HLT_HT2000_v3', 
    'HLT_HT2500_v3', 
    'HLT_L1_TripleJet_VBF_v5', 
    'HLT_PFHT125_v3', 
    'HLT_PFHT200_v4', 
    'HLT_PFHT250_v4', 
    'HLT_PFHT300_v5', 
    'HLT_PFHT350_v6', 
    'HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v3', 
    'HLT_PFHT400_SixJet30_v5', 
    'HLT_PFHT400_v5', 
    'HLT_PFHT450_SixJet40_BTagCSV_p056_v3', 
    'HLT_PFHT450_SixJet40_v5', 
    'HLT_PFHT475_v5', 
    'HLT_PFHT550_4JetPt50_v4', 
    'HLT_PFHT600_v6', 
    'HLT_PFHT650_4JetPt50_v4', 
    'HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6', 
    'HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6', 
    'HLT_PFHT650_v6', 
    'HLT_PFHT750_4JetPt70_v1', 
    'HLT_PFHT750_4JetPt80_v1', 
    'HLT_PFHT800_4JetPt50_v1', 
    'HLT_PFHT850_4JetPt50_v1', 
    'HLT_PFHT900_v4', 
    'HLT_PFJet140_v6', 
    'HLT_PFJet200_v6', 
    'HLT_PFJet260_v7', 
    'HLT_PFJet320_v7', 
    'HLT_PFJet400_v7', 
    'HLT_PFJet40_v7', 
    'HLT_PFJet450_v7', 
    'HLT_PFJet500_v7', 
    'HLT_PFJet60_v7', 
    'HLT_PFJet80_v6', 
    'HLT_QuadPFJet_VBF_v6', 
    'HLT_SingleCentralPFJet170_CFMax0p1_v3')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetMET_selector
streamA_datasetMET_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetMET_selector.l1tResults = cms.InputTag('')
streamA_datasetMET_selector.throw      = cms.bool(False)
streamA_datasetMET_selector.triggerConditions = cms.vstring('HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v4', 
    'HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v5', 
    'HLT_DoubleMu3_PFMET50_v3', 
    'HLT_MET200_v3', 
    'HLT_MET250_v3', 
    'HLT_MET300_v3', 
    'HLT_MET600_v3', 
    'HLT_MET60_IsoTrk35_Loose_v2', 
    'HLT_MET700_v3', 
    'HLT_MET75_IsoTrk50_v4', 
    'HLT_MET90_IsoTrk50_v4', 
    'HLT_MonoCentralPFJet80_PFMETNoMu100_PFMHTNoMu100_IDTight_v5', 
    'HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight_v5', 
    'HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v5', 
    'HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v5', 
    'HLT_Mu14er_PFMET100_v3', 
    'HLT_Mu6_PFHT200_PFMET100_v3', 
    'HLT_PFMET100_PFMHT100_IDTight_BeamHaloCleaned_v2', 
    'HLT_PFMET100_PFMHT100_IDTight_v5', 
    'HLT_PFMET110_PFMHT110_IDTight_v5', 
    'HLT_PFMET120_Mu5_v4', 
    'HLT_PFMET120_PFMHT120_IDTight_v5', 
    'HLT_PFMET170_BeamHaloCleaned_v4', 
    'HLT_PFMET170_HBHECleaned_v6', 
    'HLT_PFMET170_HBHE_BeamHaloCleaned_v2', 
    'HLT_PFMET170_NotCleaned_v5', 
    'HLT_PFMET300_v4', 
    'HLT_PFMET400_v4', 
    'HLT_PFMET500_v4', 
    'HLT_PFMET600_v4', 
    'HLT_PFMET90_PFMHT90_IDTight_v5', 
    'HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v5', 
    'HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v5', 
    'HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v5', 
    'HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v5', 
    'HLT_PFMETTypeOne190_HBHE_BeamHaloCleaned_v2')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetTau_selector
streamA_datasetTau_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetTau_selector.l1tResults = cms.InputTag('')
streamA_datasetTau_selector.throw      = cms.bool(False)
streamA_datasetTau_selector.triggerConditions = cms.vstring('HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v5', 
    'HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v7', 
    'HLT_LooseIsoPFTau50_Trk30_eta2p1_MET110_v3', 
    'HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v3', 
    'HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v3', 
    'HLT_LooseIsoPFTau50_Trk30_eta2p1_MET90_v3', 
    'HLT_LooseIsoPFTau50_Trk30_eta2p1_v5', 
    'HLT_PFTau120_eta2p1_v3', 
    'HLT_PFTau140_eta2p1_v3', 
    'HLT_VLooseIsoPFTau120_Trk50_eta2p1_v3', 
    'HLT_VLooseIsoPFTau140_Trk50_eta2p1_v3')


# dump of the Stream PhysicsMuons Datasets defined in the HLT table as Stream A Datasets

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetCharmonium_selector
streamA_datasetCharmonium_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetCharmonium_selector.l1tResults = cms.InputTag('')
streamA_datasetCharmonium_selector.throw      = cms.bool(False)
streamA_datasetCharmonium_selector.triggerConditions = cms.vstring('HLT_Dimuon0_Jpsi_Muon_v4', 
    'HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v3', 
    'HLT_Dimuon0er16_Jpsi_NoVertexing_v3', 
    'HLT_Dimuon10_Jpsi_Barrel_v5', 
    'HLT_Dimuon13_PsiPrime_v4', 
    'HLT_Dimuon16_Jpsi_v4', 
    'HLT_Dimuon20_Jpsi_v4', 
    'HLT_Dimuon6_Jpsi_NoVertexing_v3', 
    'HLT_Dimuon8_PsiPrime_Barrel_v5', 
    'HLT_DoubleMu4_3_Bs_v5', 
    'HLT_DoubleMu4_3_Jpsi_Displaced_v5', 
    'HLT_DoubleMu4_JpsiTrk_Displaced_v5', 
    'HLT_DoubleMu4_PsiPrimeTrk_Displaced_v5', 
    'HLT_Mu7p5_L2Mu2_Jpsi_v3', 
    'HLT_Mu7p5_Track2_Jpsi_v3', 
    'HLT_Mu7p5_Track3p5_Jpsi_v3', 
    'HLT_Mu7p5_Track7_Jpsi_v3', 
    'HLT_QuadMuon0_Dimuon0_Jpsi_v3')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetDoubleMuon_selector
streamA_datasetDoubleMuon_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetDoubleMuon_selector.l1tResults = cms.InputTag('')
streamA_datasetDoubleMuon_selector.throw      = cms.bool(False)
streamA_datasetDoubleMuon_selector.triggerConditions = cms.vstring('HLT_DoubleMu0_v1', 
    'HLT_DoubleMu18NoFiltersNoVtx_v3', 
    'HLT_DoubleMu23NoFiltersNoVtxDisplaced_v3', 
    'HLT_DoubleMu28NoFiltersNoVtxDisplaced_v3', 
    'HLT_DoubleMu33NoFiltersNoVtx_v3', 
    'HLT_DoubleMu38NoFiltersNoVtx_v3', 
    'HLT_DoubleMu8_Mass8_PFHT250_v4', 
    'HLT_DoubleMu8_Mass8_PFHT300_v7', 
    'HLT_L2DoubleMu23_NoVertex_v4', 
    'HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v4', 
    'HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v4', 
    'HLT_Mu10_CentralPFJet30_BTagCSV_p13_v3', 
    'HLT_Mu17_Mu8_DZ_v4', 
    'HLT_Mu17_Mu8_SameSign_DZ_v3', 
    'HLT_Mu17_Mu8_SameSign_v3', 
    'HLT_Mu17_Mu8_v3', 
    'HLT_Mu17_TkMu8_DZ_v3', 
    'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v4', 
    'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v4', 
    'HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v3', 
    'HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v3', 
    'HLT_Mu17_TrkIsoVVL_v3', 
    'HLT_Mu17_v3', 
    'HLT_Mu20_Mu10_DZ_v3', 
    'HLT_Mu20_Mu10_SameSign_DZ_v3', 
    'HLT_Mu20_Mu10_SameSign_v2', 
    'HLT_Mu20_Mu10_v3', 
    'HLT_Mu27_TkMu8_v3', 
    'HLT_Mu30_TkMu11_v3', 
    'HLT_Mu3_PFJet40_v4', 
    'HLT_Mu40_TkMu11_v3', 
    'HLT_Mu8_TrkIsoVVL_v4', 
    'HLT_Mu8_v4', 
    'HLT_TripleMu_12_10_5_v3', 
    'HLT_TripleMu_5_3_3_v2', 
    'HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v4', 
    'HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx_v4')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetDoubleMuonLowMass_selector
streamA_datasetDoubleMuonLowMass_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetDoubleMuonLowMass_selector.l1tResults = cms.InputTag('')
streamA_datasetDoubleMuonLowMass_selector.throw      = cms.bool(False)
streamA_datasetDoubleMuonLowMass_selector.triggerConditions = cms.vstring('HLT_DoubleMu3_Trk_Tau3mu_v3', 
    'HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v5')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetMuOnia_selector
streamA_datasetMuOnia_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetMuOnia_selector.l1tResults = cms.InputTag('')
streamA_datasetMuOnia_selector.throw      = cms.bool(False)
streamA_datasetMuOnia_selector.triggerConditions = cms.vstring('HLT_Dimuon0_Phi_Barrel_v5', 
    'HLT_Dimuon0_Upsilon_Muon_v4', 
    'HLT_Dimuon13_Upsilon_v4', 
    'HLT_Dimuon8_Upsilon_Barrel_v5', 
    'HLT_Mu16_TkMu0_dEta18_Onia_v3', 
    'HLT_Mu16_TkMu0_dEta18_Phi_v3', 
    'HLT_Mu25_TkMu0_dEta18_Onia_v4', 
    'HLT_Mu7p5_L2Mu2_Upsilon_v3', 
    'HLT_Mu7p5_Track2_Upsilon_v3', 
    'HLT_Mu7p5_Track3p5_Upsilon_v3', 
    'HLT_Mu7p5_Track7_Upsilon_v3', 
    'HLT_QuadMuon0_Dimuon0_Upsilon_v3')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetMuonEG_selector
streamA_datasetMuonEG_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetMuonEG_selector.l1tResults = cms.InputTag('')
streamA_datasetMuonEG_selector.throw      = cms.bool(False)
streamA_datasetMuonEG_selector.triggerConditions = cms.vstring('HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v6', 
    'HLT_Mu12_Photon25_CaloIdL_L1ISO_v6', 
    'HLT_Mu12_Photon25_CaloIdL_L1OR_v6', 
    'HLT_Mu12_Photon25_CaloIdL_v6', 
    'HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v1', 
    'HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1', 
    'HLT_Mu17_Photon30_CaloIdL_L1ISO_v7', 
    'HLT_Mu17_Photon35_CaloIdL_L1ISO_v7', 
    'HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v7', 
    'HLT_Mu23NoFiltersNoVtx_Photon23_CaloIdL_v5', 
    'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1', 
    'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v7', 
    'HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v5', 
    'HLT_Mu27_Ele37_CaloIdL_GsfTrkIdVL_v4', 
    'HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v5', 
    'HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v6', 
    'HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v5', 
    'HLT_Mu33_Ele33_CaloIdL_GsfTrkIdVL_v1', 
    'HLT_Mu37_Ele27_CaloIdL_GsfTrkIdVL_v4', 
    'HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v5', 
    'HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v5', 
    'HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v6', 
    'HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT250_v5', 
    'HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v8', 
    'HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v7', 
    'HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v1', 
    'HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v7')

from HLTrigger.HLTfilters.triggerResultsFilter_cfi import triggerResultsFilter as streamA_datasetSingleMuon_selector
streamA_datasetSingleMuon_selector.hltResults = cms.InputTag('TriggerResults', '', 'HLT')
streamA_datasetSingleMuon_selector.l1tResults = cms.InputTag('')
streamA_datasetSingleMuon_selector.throw      = cms.bool(False)
streamA_datasetSingleMuon_selector.triggerConditions = cms.vstring('HLT_DoubleIsoMu17_eta2p1_noDzCut_v2', 
    'HLT_DoubleIsoMu17_eta2p1_v4', 
    'HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v3', 
    'HLT_IsoMu16_eta2p1_MET30_v2', 
    'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v6', 
    'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v6', 
    'HLT_IsoMu18_v3', 
    'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v3', 
    'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v3', 
    'HLT_IsoMu19_eta2p1_MediumIsoPFTau32_Trk1_eta2p1_Reg_v3', 
    'HLT_IsoMu20_v4', 
    'HLT_IsoMu21_eta2p1_LooseIsoPFTau20_SingleL1_v3', 
    'HLT_IsoMu21_eta2p1_LooseIsoPFTau50_Trk30_eta2p1_SingleL1_v2', 
    'HLT_IsoMu21_eta2p1_MediumIsoPFTau32_Trk1_eta2p1_Reg_v3', 
    'HLT_IsoMu22_eta2p1_v2', 
    'HLT_IsoMu22_v3', 
    'HLT_IsoMu24_v2', 
    'HLT_IsoMu27_v5', 
    'HLT_IsoTkMu18_v4', 
    'HLT_IsoTkMu20_v6', 
    'HLT_IsoTkMu22_eta2p1_v3', 
    'HLT_IsoTkMu22_v4', 
    'HLT_IsoTkMu24_v3', 
    'HLT_IsoTkMu27_v6', 
    'HLT_L1SingleMu18_v1', 
    'HLT_L1SingleMuOpen_v3', 
    'HLT_L2Mu10_v2', 
    'HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v3', 
    'HLT_Mu15_IsoVVVL_BTagCSV_p067_PFHT400_v4', 
    'HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v5', 
    'HLT_Mu15_IsoVVVL_PFHT350_v5', 
    'HLT_Mu15_IsoVVVL_PFHT400_PFMET50_v3', 
    'HLT_Mu15_IsoVVVL_PFHT400_v3', 
    'HLT_Mu15_IsoVVVL_PFHT600_v6', 
    'HLT_Mu16_eta2p1_MET30_v2', 
    'HLT_Mu20_v3', 
    'HLT_Mu24_eta2p1_v4', 
    'HLT_Mu27_v4', 
    'HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v3', 
    'HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v3', 
    'HLT_Mu300_v2', 
    'HLT_Mu30_eta2p1_PFJet150_PFJet50_v3', 
    'HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v3', 
    'HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v3', 
    'HLT_Mu350_v2', 
    'HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v3', 
    'HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v3', 
    'HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v3', 
    'HLT_Mu40_eta2p1_PFJet200_PFJet50_v5', 
    'HLT_Mu45_eta2p1_v4', 
    'HLT_Mu50_IsoVVVL_PFHT400_v3', 
    'HLT_Mu50_v4', 
    'HLT_Mu55_v3', 
    'HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60_v2', 
    'HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1', 
    'HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1', 
    'HLT_TkMu17_v1', 
    'HLT_TkMu20_v4', 
    'HLT_TkMu24_eta2p1_v5', 
    'HLT_TkMu27_v5', 
    'HLT_TkMu50_v3')

