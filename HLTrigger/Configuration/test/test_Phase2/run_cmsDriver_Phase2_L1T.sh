#!/bin/bash

cmsDriver.py step1 \
--conditions auto:phase2_realistic_T21 \
-n 20 \
--era Phase2C17I13M9 \
--eventcontent FEVTDEBUGHLT \
-s RAW2DIGI,L1:RUNP2GT \
--datatier GEN-SIM-DIGI-RAW-MINIAOD \
--fileout file:test.root \
--customise SLHCUpgradeSimulations/Configuration/aging.customise_aging_1000,Configuration/DataProcessing/Utils.addMonitoring,L1Trigger/Configuration/customisePhase2.addHcalTriggerPrimitives,L1Trigger/Configuration/customisePhase2FEVTDEBUGHLT.customisePhase2FEVTDEBUGHLT \
--geometry Extended2026D95 \
--nThreads 1 \
--filein /store/mc/Phase2Spring23DIGIRECOMiniAOD/TT_TuneCP5_14TeV-powheg-pythia8/GEN-SIM-DIGI-RAW-MINIAOD/noPU_131X_mcRun4_realistic_v5-v1/2520000/00674431-77d6-4dce-9dad-41b6d0ff1d6f.root \
--mc \
--inputCommands='keep *, drop l1tPFJets_*_*_*' \
--outputCommands='keep *P2GT*_*_*_*, drop l1tPFJets_*_*_*' \
--python_filename rerunL1_only_cfg.py \
--no_exec
