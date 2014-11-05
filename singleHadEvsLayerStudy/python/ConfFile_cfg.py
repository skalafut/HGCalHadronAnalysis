import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'file:/eos/uscms/store/user/skalafut/HGCal/singleHadronPUStudySamples_SLHC19/step3_chargedPiPt50_NoPU_withPFRecHits_100evts.root'


    )
)

process.demo = cms.EDAnalyzer('singleHadEvsLayerStudy'
)

process.TFileService = cms.Service("TFileService",
	#fileName = cms.string('/eos/uscms/store/user/skalafut/HGCal/singleHadronPUStudySamples_SLHC19/chgdPion/analyzed_step3_chargedPiPt50_140PU_withPFRecHits_100evts_with_DR4_cut_and_MIPs.root')
	fileName = cms.string('/eos/uscms/store/user/skalafut/HGCal/singleHadronPUStudySamples_SLHC19/chgdPion/analyzed_step3_chargedPiPt50_NoPU_withPFRecHits_100evts_with_DR4_cut_and_MIPs.root')

)

process.p = cms.Path(process.demo)
