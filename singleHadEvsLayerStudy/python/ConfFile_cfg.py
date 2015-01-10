import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

inputFiles = cms.untracked.vstring()

inputFiles.extend( [
	#100 GeV
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta1.9_NoPU_9_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_1_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_2_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_3_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_4_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_5_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_6_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_7_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_8_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.2_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E100_Eta2.8_NoPU_9_1500evts.root',
    
	#10 GeV
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta1.9_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.2_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E10_Eta2.8_NoPU_9_1500evts.root',
    
	#E 150 GeV
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta1.9_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.2_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E150_Eta2.8_NoPU_9_1500evts.root',
    
	#E 200 GeV
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta1.9_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.2_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E200_Eta2.8_NoPU_9_1500evts.root',
    
	#E 300 GeV
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta1.9_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.2_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E300_Eta2.8_NoPU_9_1500evts.root',
    
	#E 30 GeV
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta1.9_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.2_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E30_Eta2.8_NoPU_9_1500evts.root',
    
	#E 500 GeV
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta1.9_NoPU_9_1500evts.root',
    
	
	
	
	
	'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_1_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_2_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_3_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_4_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_5_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_6_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_7_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_8_1500evts.root',
    'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.2_NoPU_9_1500evts.root',
    
	
	
	
	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E500_Eta2.8_NoPU_9_1500evts.root',
    
	#E 50 GeV
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta1.9_NoPU_9_1500evts.root',
    



	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.2_NoPU_9_1500evts.root',
    
	



	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E50_Eta2.8_NoPU_9_1500evts.root',
    
	#E 80 GeV
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.3_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.6_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta1.9_NoPU_9_1500evts.root',
    



	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.2_NoPU_9_1500evts.root',



	
	#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.5_NoPU_9_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_1_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_2_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_3_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_4_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_5_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_6_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_7_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_8_1500evts.root',
    #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/step3_chgdPionGun_E80_Eta2.8_NoPU_9_1500evts.root'
])



process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = inputFiles 
)

process.demo = cms.EDAnalyzer('singleHadEvsLayerStudy'
)

process.TFileService = cms.Service("TFileService",
	#fileName = cms.string('/eos/uscms/store/user/skalafut/HGCal/analyzed_step3_chargedPiPt500_NoPU_withPFRecHits_1000evts_with_DR4_cut.root')
	#fileName = cms.string('checkingLindseysCodeWasIncluded.root')
	#fileName = cms.string('/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chgdPionFixedEAndEta_SLHC21_chgdHadron_clustering_from_Dec_10_with_SimHits_NoPU/analyzed/analyzed_step3_chgdPionAllEnergies_Eta2p2.root')
	fileName = cms.string('trial.root')
	
)

process.p = cms.Path(process.demo)
