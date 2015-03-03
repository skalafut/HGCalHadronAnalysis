import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt10.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt20.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt30.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_1.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_2.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_3.root',
        #BAD'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_4.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_5.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_6.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_7.root',
        #BAD'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_8.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_9.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt40_1000evts_10.root',
		'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_1.root',
        #BAD'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_2.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_3.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_4.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_5.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_6.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_7.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_8.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_9.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt50_1000evts_10.root',
        ##
		'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_1.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_2.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_3.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_4.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_5.root',
        #BAD'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_6.root',
        #BAD'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_7.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_8.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_9.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt60_1000evts_10.root',
		##
		'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_1.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_2.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_3.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_4.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_5.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_6.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_7.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_8.root',
        #BAD'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_9.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt70_1000evts_10.root',
		##
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_1.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_2.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_3.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_4.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_5.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_6.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_7.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_8.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_9.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt80_1000evts_10.root',
		##
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_1.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_2.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_3.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_4.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_5.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_6.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_7.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_8.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_9.root',
        'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt90_1000evts_10.root',
#		###
#		##'file:/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/step3_chargedPionGunPt100_1000evts_1.root',

	)
)

process.demo = cms.EDAnalyzer('FixedPtParticleGun'
)

process.TFileService = cms.Service("TFileService",
	#fileName = cms.string('/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/analyzed/analyzed_step3_chargedPionGunPt20_highestE_PFCand_hcalE_cut_from_7_23_0200_release.root')
	fileName = cms.string('/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/analyzed/analyzed_step3_chargedPionGunPt10_track_study.root')

)



process.p = cms.Path(process.demo)
