import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
		#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_140PU_3_100evts.root',
		#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_140PU_4_100evts.root',
        #
		#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_10_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_1_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_2_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_3_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_4_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_5_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_6_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_7_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_8_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt1000_NoPU_9_100evts.root',
       
		#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_140PU_3_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_140PU_4_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_10_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_1_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_2_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_3_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_4_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_5_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_6_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_7_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_8_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt100_NoPU_9_100evts.root',
        #
		#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_140PU_3_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_140PU_4_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_10_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_1_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_2_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_3_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_4_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_5_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_6_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_7_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_8_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt200_NoPU_9_100evts.root',
        #
		#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_140PU_3_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_140PU_4_100evts.root',
        
		'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_10_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_1_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_2_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_3_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_4_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_5_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_6_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_7_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_8_100evts.root',
        'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt500_NoPU_9_100evts.root',
        
		#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_140PU_3_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_140PU_4_100evts.root',
        
		#'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_10_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_1_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_2_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_3_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_4_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_5_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_6_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_7_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_8_100evts.root',
        #'file:/eos/uscms/store/user/lpchgcal/HGCAL_Samples/chargedPiFixedPt_withPFRecHits_SLHC20_V5Geom/step3_chargedPiGun_Pt50_NoPU_9_100evts.root',

    )
)

process.demo = cms.EDAnalyzer('singleHadEvsLayerStudy'
)

process.TFileService = cms.Service("TFileService",
	fileName = cms.string('/eos/uscms/store/user/skalafut/HGCal/analyzed_step3_chargedPiPt500_NoPU_withPFRecHits_1000evts_with_DR4_cut.root')

)

process.p = cms.Path(process.demo)
