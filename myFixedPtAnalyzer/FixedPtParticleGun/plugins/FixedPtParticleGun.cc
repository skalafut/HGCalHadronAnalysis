// -*- C++ -*-
//
// Package:    FixedPtParticleGun
// Class:      FixedPtParticleGun
// 
/**\class FixedPtParticleGun FixedPtParticleGun.cc myFixedPtAnalyzer/FixedPtParticleGun/plugins/FixedPtParticleGun.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  sean kalafut
//         Created:  Thu, 21 Aug 2014 11:02:41 GMT
// $Id$
//
//


// system include files
#include <memory>
#include <map>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <array>


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/GenRunInfoProduct.h"

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"

#include "DataFormats/ParticleFlowReco/interface/PFCluster.h"
#include "DataFormats/ParticleFlowReco/interface/PFClusterFwd.h"
#include "DataFormats/ParticleFlowReco/interface/PFRecHitFraction.h"
#include "DataFormats/ParticleFlowReco/interface/PFLayer.h"

#include "DataFormats/ParticleFlowReco/interface/PFRecHit.h"
#include "DataFormats/ParticleFlowReco/interface/PFRecHitFwd.h"

#include "DataFormats/ForwardDetId/interface/HGCEEDetId.h"
#include "DataFormats/ForwardDetId/interface/HGCHEDetId.h"
//#include "DataFormats/ForwardDetId/interface/HGCalDetId.h"
#include "DataFormats/CaloRecHit/interface/CaloRecHit.h"
#include "DataFormats/HGCRecHit/interface/HGCRecHit.h"
#include "DataFormats/HGCRecHit/interface/HGCRecHitCollections.h"
#include "DataFormats/HGCRecHit/interface/HGCRecHitComparison.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackBase.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"


//this GenParticle.h will allow me to call pdgId(), status(), and other methods on reco::GenParticle objects
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

//this PileupSummaryInfo.h will allow me to get PU info from each event
//#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"


#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TMath.h"
#include "TH1.h"
#include "TH3.h"
#include "TAttFill.h"
#include "TAttMarker.h"
#include <TString.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TROOT.h>



//
// class declaration
//

class FixedPtParticleGun : public edm::EDAnalyzer {
   public:
      explicit FixedPtParticleGun(const edm::ParameterSet&);
      ~FixedPtParticleGun();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

      bool booked(const std::string histName) const { return hists_.find(histName.c_str())!=hists_.end(); };
      bool bookedThree(const std::string histName) const { return histsThree_.find(histName.c_str())!=histsThree_.end(); };

      /// fill histogram if it had been booked before
      void fill(const std::string histName, double value) const { if(booked(histName.c_str())) hists_.find(histName.c_str())->second->Fill(value); };
      void fillThree(const std::string histName, double valX, double valY, double valZ) const{  if(bookedThree(histName.c_str())) histsThree_.find(histName.c_str())->second->Fill(valX, valY, valZ); };

	  /*
      void makeAndSaveSingleHistoAndFit(TString title, TString filePostfix, TString canvName, TString legEntry, const std::string histName, const std::string fitName, bool doLogYAxis){
		  TString longPathName = "/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/analyzed/plots/analyzed_chgdPionGun_PFCandidate_";

	      TH1F * histogram = hists_.find(histName.c_str())->second;
	      TF1 * fitCurve = fits_.find(fitName.c_str())->second;
	      TString saveFileType = ".jpg";
	      TString canvasName = canvName;
	      //std::cout<<"line 143"<<std::endl;

   	      gStyle->SetOptFit(111);

	      TCanvas * c111=new TCanvas(canvasName,canvasName,800,800);
	      c111->cd();
	      if(doLogYAxis==true){
		      c111->SetLogy(1);
		      histogram->SetMinimum(1);
	      }
	      if(doLogYAxis==false){
		      histogram->SetMinimum(0);
	      }

	      histogram->SetLineColor(1);
	      histogram->SetLineWidth(1);
	      histogram->SetTitle(title);

	      TLegend * leg111 = new TLegend(.8,.27,1,.4);
	      leg111->AddEntry(histogram,legEntry);

	      histogram->Draw("hist");
	      fitCurve->Draw("SAME");
	      leg111->Draw();

	      c111->SaveAs(longPathName+filePostfix+saveFileType, "recreate");

      }//end makeAndSaveSingleHistoAndFit(...)

	  */

      void makeAndSaveSingleHisto(TString title, TString filePostfix, TString canvName, TString legEntry, const std::string histName, bool doLogYAxis){
	      TString longPathName = "/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/analyzed/plots/analyzed_chgdPionGun_PFCandidate_";
	      
		  TH1F * histogram = hists_.find(histName.c_str())->second;
	      TString saveFileType = ".jpg";
	      TString canvasName = canvName;

	      TCanvas * c111=new TCanvas(canvasName,canvasName,800,800);
	      c111->cd();
	      if(doLogYAxis==true){
		      c111->SetLogy(1);
		      histogram->SetMinimum(1);
	      }
	      if(doLogYAxis==false){
		      histogram->SetMinimum(0);
	      }


	      histogram->SetLineColor(1);
	      histogram->SetLineWidth(1);
	      histogram->SetTitle(title);

	      TLegend * leg111 = new TLegend(.8,.27,1,.4);
	      leg111->AddEntry(histogram,legEntry);

	      histogram->Draw("hist");
	      leg111->Draw();

	      c111->SaveAs(longPathName+filePostfix+saveFileType, "recreate");

      }//end makeAndSaveSingleHisto(...)


      void makeAndSaveSingle3DHisto(TString title, TString filePostfix, TString canvName, TString legEntry, const std::string histName, bool doLogZAxis){
	      TString longPathName = "/eos/uscms/store/user/skalafut/HGCal/chargedPionGun_PFCands/analyzed/plots/analyzed_chgdPionGun_PFCandidate_";
	      
		  TH3F * histogram = histsThree_.find(histName.c_str())->second;
	      TString saveFileType = ".jpg";
	      TString canvasName = canvName;

	      TCanvas * c111=new TCanvas(canvasName,canvasName,800,800);
	      c111->cd();
	      if(doLogZAxis==true){
		      c111->SetLogz(1);
		      histogram->SetMinimum(1);
	      }
	      if(doLogZAxis==false){
		      histogram->SetMinimum(0);
	      }


	      histogram->SetLineColor(1);
	      histogram->SetLineWidth(1);
	      histogram->SetTitle(title);

	      TLegend * leg111 = new TLegend(.8,.27,1,.4);
	      leg111->AddEntry(histogram,legEntry);

	      histogram->Draw("hist");
	      leg111->Draw();

	      c111->SaveAs(longPathName+filePostfix+saveFileType, "recreate");

      }//end makeAndSaveSingle3DHisto(...)



   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

	  std::map<std::string,TH1F*> hists_;
	  std::map<std::string,TH3F*> histsThree_;


      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
FixedPtParticleGun::FixedPtParticleGun(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   edm::Service<TFileService> fs;

   hists_["Track_multiplicity"]=fs->make<TH1F>("Track_multiplicity","Number of tracks with 1.5 <= eta <= 3.0",11,0.,10.);
   histsThree_["Track_deltaR_deltaE"]=fs->make<TH3F>("Track_deltaR_deltaE","Delta Eta, Delta Phi, and Delta E between gen pi+ and reco tracks pointing to HGC", 630, -3.15, 3.15, 30, -1.5, 1.5, 400, -20., 20.);

   //suggestions from Shervin: plot of pdgId for all gen particles, plot of PFCandidate energy and ET
   //suggestions from Roger: make a 3D plot of delta eta (x axis) and delta phi (y axis) btwn the gen lvl pi+ and the reconstructed PFCandidates
   //the z axis on the 3D plot should be the energy of the PFCandidate objects

   hists_["GenParticle_pdgId"]=fs->make<TH1F>("GenParticle_pdgId","PdgId of all generator particles",501,-250.,250.);
   hists_["PFCandidate_energy"]=fs->make<TH1F>("PFCandidate_energy","Energy of all PFCandidates",200,0.0,100.0);
   hists_["PFCandidate_PT"]=fs->make<TH1F>("PFCandidate_PT","PT of all PFCandidates",45,0.0,15.0);

   histsThree_["PFCandidate_deltaR_energy"]=fs->make<TH3F>("PFCandidate_deltaR_energy","Delta Eta and Phi separation between PFCandidates and generator pi+ as a function of PFCandidate energy", 1258, -6.29, 6.29, 40, -2., 2., 700, 0., 700.);
  
   hists_["GenParticle_num"]=fs->make<TH1F>("GenParticle_num","Number of generator particles in each event",11,0.,10.);


   hists_["GenEnergy_all"]=fs->make<TH1F>("GenEnergy_all","Energy (GeV) of pi+ particles at GEN level",830,0,830);
   hists_["PFCandidate_allPdgId"]=fs->make<TH1F>("PFCandidate_allPdgId","PdgId of PFCandidate objects in single pi+ gun events",601,-300,300);
   hists_["PFCandidate_highestE_PdgId"]=fs->make<TH1F>("PFCandidate_highestE_PdgId","PdgId of highest energy PFCandidate in single pi+ gun events",601,-300,300);
   hists_["PFCandidate_highestE_eta"]=fs->make<TH1F>("PFCandidate_highestE_eta","Eta of highest energy PFCandidate in single pi+ gun events",130,1.6,2.9);

   hists_["PFCandidate_highestE_no_hcalE_eta"]=fs->make<TH1F>("PFCandidate_highestE_no_hcalE_eta","Eta of highest energy PFCandidate with hcalE=0 in single pi+ gun events",130,1.6,2.9);

   hists_["PFCandidate_highestE_no_hcalE_pt"]=fs->make<TH1F>("PFCandidate_highestE_no_hcalE_pt","PT of highest energy PFCandidate with hcalE=0 in single pi+ gun events",300,0.0,150.0);

   hists_["PFCandidate_highestE_no_hcalE_PdgId"]=fs->make<TH1F>("PFCandidate_highestE_no_hcalE_PdgId","PdgId of highest energy PFCandidate with hcalE=0 in single pi+ gun events",501,-250.,250.);




   hists_["PFCandidate_highestE_ECALoverHCAL"]=fs->make<TH1F>("PFCandidate_highestE_ECALoverHCAL","ECAL E/HCAL E of highest energy PFCandidate in single pi+ gun events",1000,0.,1000.);
   hists_["PFCandidate_highestE_eta_for_genE_above_230"]=fs->make<TH1F>("PFCandidate_highestE_eta_for_genE_above_230","Eta of highest energy PFCandidate in single pi+ gun events with gen E >= 230 GeV",130,1.6,2.9);

   hists_["PFCandidate_highestE_ECALoverTotalCaloE"]=fs->make<TH1F>("PFCandidate_highestE_ECALoverTotalCaloE","ECAL E/(ECAL + HCAL E) of highest energy PFCandidate in single pi+ gun events",100,0.,1.);

   hists_["PFCandidate_chgdPionPdgId_ECALoverTotalCaloE"]=fs->make<TH1F>("PFCandidate_chgdPionPdgId_ECALoverTotalCaloE","ECAL E/(ECAL + HCAL E) of PFCandidate with PdgId = 211 in single pi+ gun events",100,0.,1.);

   hists_["PFCandidate_sum_ECALoverTotalCaloE"]=fs->make<TH1F>("PFCandidate_sum_ECALoverTotalCaloE","sum ECAL E/(ECAL + HCAL E) of all PFCandidates in single pi+ gun events",100,0.,1.);



   hists_["PFCandidate_highestE_hcalE_cut_PdgId"]=fs->make<TH1F>("PFCandidate_highestE_hcalE_cut_PdgId","PdgId of highest energy PFCandidate with hcalE>0 in single pi+ gun events",601,-300,300);
   hists_["PFCandidate_highestE_hcalE_cut_eta"]=fs->make<TH1F>("PFCandidate_highestE_hcalE_cut_eta","Eta of highest energy PFCandidate with hcalE>0 in single pi+ gun events",130,1.6,2.9);
   hists_["PFCandidate_highestE_hcalE_cut_ECALoverHCAL"]=fs->make<TH1F>("PFCandidate_highestE_hcalE_cut_ECALoverHCAL","ECAL E/HCAL E of highest energy PFCandidate with hcalE>0 in single pi+ gun events",1000,0.,1000.);
   hists_["PFCandidate_highestE_hcalE_cut_eta_for_genE_above_230"]=fs->make<TH1F>("PFCandidate_highestE_hcalE_cut_eta_for_genE_above_230","Eta of highest energy PFCandidate with hcalE>0 in single pi+ gun events with gen E >= 230 GeV",130,1.6,2.9);



   /*
   unsigned int numberOfBins = 9;
   std::vector<std::string> binList;

 
   for(unsigned int i=1; i<(numberOfBins+1) ; i++){
      binList.push_back( std::to_string(i) );
   }


   for(unsigned int i=0; i<numberOfBins ; i++){

	//this works!
	char genEnergyHistoName[] = "GenEnergy_";
	char energySpreadWithTrackerHistoName[] = "PFCandidateEnergySpreadWithTracker_";
  	//char energySpreadWithTrackerFitName[] = "fittingPFCandidateEnergySpreadWithTracker_"; 
	
	char energySpreadWithoutTrackerHistoName[] = "PFCandidateEnergySpreadWithoutTracker_"; 
	//char energySpreadWithoutTrackerFitName[] = "fittingPFCandidateEnergySpreadWithoutTracker_"; 
	
	strcat(genEnergyHistoName, binList[i].c_str() );
	strcat(energySpreadWithTrackerHistoName, binList[i].c_str() );
	//strcat(energySpreadWithTrackerFitName, binList[i].c_str() );

	strcat(energySpreadWithoutTrackerHistoName, binList[i].c_str() );
	//strcat(energySpreadWithoutTrackerFitName, binList[i].c_str() );

	hists_["GenEnergy_"+binList[i] ]=fs->make<TH1F>(genEnergyHistoName,"Energy (GeV) of pi+ particles at GEN level",511,0.,510.);
	hists_["PFCandidateEnergySpreadWithTracker_"+binList[i] ]=fs->make<TH1F>(energySpreadWithTrackerHistoName,"Energy spread of pi+ particles reconstructed as PFCandidates using tracker energy",100,-1.,1.);
	//fits_["fittingPFCandidateEnergySpreadWithTracker_"+binList[i] ] = fs->make<TF1>(energySpreadWithTrackerFitName,"gaus",-0.3,0.3); 
	
	hists_["PFCandidateEnergySpreadWithoutTracker_"+binList[i] ]=fs->make<TH1F>(energySpreadWithoutTrackerHistoName,"Energy spread of pi+ particles reconstructed as PFCandidates ignoring tracker energy",100,-1.,1.);
	//fits_["fittingPFCandidateEnergySpreadWithoutTracker_"+binList[i] ] = fs->make<TF1>(energySpreadWithoutTrackerFitName,"[0]*exp((-0.5)*((x-[1])/[2])**2)*exp((-1)*[3]*x+[4])",-0.6,0.4); 

 
   }

   */



}


FixedPtParticleGun::~FixedPtParticleGun()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
FixedPtParticleGun::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   //using namespace edm;
   unsigned int numberOfBins = 14;
   std::vector<float> binVals;
   std::vector<std::string> binList;

   float multiplier = 20.0;
   float start = 30.0;
   binVals.push_back(start);
  
   
   for(unsigned int i=1; i<(numberOfBins+1) ; i++){
      binList.push_back( std::to_string(i) );
      binVals.push_back(start + i*multiplier);
   }

   edm::Handle<std::vector<reco::GenParticle> > genPart;
   iEvent.getByLabel("genParticles",genPart);
 
   float gEn =0;	//energy of a generator chgd pion
   float gEta = 0;
   float gPhi = 0;	//eta and phi of generator chgd pion
   int numGenParticles = 0;	//keeps track of the total number of gen lvl particles in the event

   for(std::vector<reco::GenParticle>::const_iterator genIt=genPart->begin(); genIt != genPart->end(); genIt++){
	   numGenParticles++;
	   fill("GenParticle_pdgId", genIt->pdgId());
	   if(genIt->pdgId() == 211){
		  //if the genIt pdgId is +211 then the particle is a pi+
		  gEta = genIt->eta();
		  gPhi = genIt->phi();
		  gEn = (genIt->pt())*(TMath::CosH(genIt->eta()));
		  //std::cout<<"gEn is "<<gEn<<" GeV"<<std::endl;
		  fill("GenEnergy_all", gEn);
		  //break;
	   }

   }//end loop over GenParticle

   //confirmation for Shervin, Roger, Bryan that simulation is doing what I expect at GEN level
   fill("GenParticle_num", numGenParticles);

   edm::Handle<std::vector<reco::Track> > recoTracks;
   iEvent.getByLabel("generalTracks", "", recoTracks);
   if(!recoTracks.isValid() ){
	   std::cout<<"did not find a collection of reco::Track objects with label generalTracks"<<std::endl;
   }

   const reco::TrackCollection trackObjs = *( recoTracks.product() );

   int numTracks = 0;
   for(reco::TrackCollection::const_iterator trackIt = trackObjs.begin(); trackIt != trackObjs.end() ; trackIt++ ){

	   if(trackIt->outerEta() <= 3.0 && trackIt->outerEta() >= 1.5){

		   float dEta = gEta - trackIt->outerEta();
		   float dPhi = gPhi - trackIt->outerPhi();
		   float dEnergy = gEn - trackIt->outerP();
		   fillThree("Track_deltaR_deltaE", dPhi, dEta, dEnergy);

		   numTracks++;
	   }
   
   }
   //std::cout<<"there are "<< numTracks<<" tracks heading towards HGC in this event"<<std::endl;
   //std::cout<<" "<<std::endl;

   fill("Track_multiplicity", numTracks);



   edm::Handle<std::vector<reco::PFCandidate> > PFParticles;
   iEvent.getByLabel("particleFlow","",PFParticles);
   if(!PFParticles.isValid() ){
	   //std::cout<<"no PFCandidate collection found with label particleFlow" <<std::endl;
   }

   const reco::PFCandidateCollection pfCandObjs = *( PFParticles.product() );

   //maxE must be of type double!!
   double maxE = 0;

   for(reco::PFCandidateConstIterator pfCandIt = pfCandObjs.begin() ; pfCandIt != pfCandObjs.end() ; pfCandIt++){
	   //this loop examines every PFCandidate object in an event in an effort to find the highest energy PFCandidate object
	   //in addition, this loop fills the PFCandidate_energy and _PT histograms
	   if(pfCandIt->energy() < 0.1) continue;

	   fill("PFCandidate_energy", (pfCandIt->pt() )*(TMath::CosH( pfCandIt->eta() ) ) );
	   fill("PFCandidate_PT", pfCandIt->pt() );
	   fillThree("PFCandidate_deltaR_energy", (pfCandIt->phi() - gPhi) , (pfCandIt->eta() - gEta) , (pfCandIt->pt() )*(TMath::CosH( pfCandIt->eta() ) ) );
	   if( (pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) > maxE ){
		   maxE = 0;
		   maxE += (pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) );
	   }
	  
	   if(gEn >= 28. && gEn <= 310){
		   fill("PFCandidate_allPdgId", pfCandIt->pdgId() );
	   }
   
   }//end loop over PFCandidate objects

   //std::cout<<"max PFCandidate energy is "<<maxE<<std::endl;



   float hcalE =0;
   float emE =0;
   float zero = 0.;

   for(reco::PFCandidateConstIterator pfCandIt = pfCandObjs.begin() ; pfCandIt != pfCandObjs.end() ; pfCandIt++){
	   if( pfCandIt->pdgId() == 211){
		   hcalE = pfCandIt->rawHcalEnergy();
		   emE = pfCandIt->rawEcalEnergy();
		   fill("PFCandidate_chgdPionPdgId_ECALoverTotalCaloE", (emE/(emE + hcalE)) );
	   }

	   hcalE = 0;
	   emE = 0;
	   
	   if( (pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) == maxE ){
		   hcalE = pfCandIt->rawHcalEnergy();
		   emE = pfCandIt->rawEcalEnergy();

		   if( (hcalE + emE) > zero){
			   fill("PFCandidate_highestE_ECALoverTotalCaloE", (emE/(emE + hcalE)) );

		   }

	   }
	

   }

   for(reco::PFCandidateConstIterator pfCandIt = pfCandObjs.begin() ; pfCandIt != pfCandObjs.end() ; pfCandIt++){

	   /*
	   if( (pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) == maxE && !( pfCandIt->hcalEnergy()>0 ) ){
		   //explore attributes of the highest energy PFCandidate objects in different events that leave no energy in hcal portion of HGC
		   fill("PFCandidate_highestE_no_hcalE_eta", pfCandIt->eta());
		   fill("PFCandidate_highestE_no_hcalE_pt", pfCandIt->pt());
		   fill("PFCandidate_highestE_no_hcalE_PdgId", pfCandIt->pdgId());
		   std::cout<<"found an event where the highest energy PFCandidate has hcalE=0"<<std::endl;

	   }
	   */


	   if( (pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) == maxE ){
		   //std::cout<<"found the highest energy PFCandidate"<<std::endl;
		   fill("PFCandidate_highestE_PdgId", pfCandIt->pdgId() );
		   fill("PFCandidate_highestE_eta", pfCandIt->eta() );
		   if(pfCandIt->hcalEnergy() == 0){
			   fill("PFCandidate_highestE_ECALoverHCAL", 1000.);
		   }
		   if(pfCandIt->hcalEnergy() > 0){
			   fill("PFCandidate_highestE_ECALoverHCAL", (pfCandIt->ecalEnergy())/(pfCandIt->hcalEnergy()) );
			   fill("PFCandidate_highestE_hcalE_cut_PdgId", pfCandIt->pdgId() );
			   fill("PFCandidate_highestE_hcalE_cut_eta", pfCandIt->eta() );
			   fill("PFCandidate_highestE_hcalE_cut_ECALoverHCAL", (pfCandIt->ecalEnergy())/(pfCandIt->hcalEnergy()) );
	
		   }
		   if(gEn >= 230){
			   fill("PFCandidate_highestE_eta_for_genE_above_230", pfCandIt->eta() );
			   if(pfCandIt->rawHcalEnergy() > 0){
				   fill("PFCandidate_highestE_hcalE_cut_eta_for_genE_above_230", pfCandIt->eta() );
			   }
		   }
		   
  		   break;//only want the highest energy PFCandidate in each event

	   }
 
   }//end loop over PFCandidate objects

   double totalTrackAndCaloEnergy = 0.;
   double totalCaloEnergy = 0.;
   double minPT = 0.1;   //in GeV
   double totalEME = 0.;
   double totalHcalE = 0.;

   for(reco::PFCandidateConstIterator pfCandIt = pfCandObjs.begin() ; pfCandIt != pfCandObjs.end() ; pfCandIt++){
	   //skip the PFCandidate if it has pT below 0.1 GeV, and pdgId btwn -10 and 10
	   //the only objects I care about in the event have abs(pdgId) = 22, 130, or 211 
	   if( pfCandIt->pt() <= minPT) continue;
	   if( pfCandIt->pdgId() <= 10 && pfCandIt->pdgId() >= -10 ) continue;
	   //std::cout<<"found a PFCandidate above the "<< minPT << " GeV pT threshold"<<std::endl;
	   //sum the calorimeter energy of all PFCandidate objects in each event, for PFCand objects with pT > 0.1 GeV
	   totalCaloEnergy += ( pfCandIt->rawEcalEnergy() + pfCandIt->rawHcalEnergy() );
	   totalEME += pfCandIt->rawEcalEnergy();
	   totalHcalE += pfCandIt->rawHcalEnergy();

	   //FOR NOW:
	   //to compute the reco energy of the pi+ using track and calo information, I should simply use pT * cosh(eta) of
	   //the highest energy particle in the event
	   //if I do an energy sum over all PFCandidates, then any event where the pi+ experiences a nuclear interaction in
	   //the tracker will mess up the energy resolution
	   //in the past I found this approach to work well
	   //totalTrackAndCaloEnergy += (pfCandIt->pt() )*(TMath::CosH(pfCandIt->eta() ) );

   }

   //maxE is calculated through pT * cosh(eta), where pT and eta should both come from the tracker
   totalTrackAndCaloEnergy += maxE;

   fill("PFCandidate_sum_ECALoverTotalCaloE", (totalEME/(totalEME + totalHcalE)) );
	
   //std::cout<<"total calo energy is "<<totalCaloEnergy<<std::endl;
   //std::cout<<"total track+calo energy is "<< totalTrackAndCaloEnergy <<std::endl;
   //std::cout<<"gen pi+ energy is "<< gEn << std::endl;
   //std::cout<<" "<<std::endl;

   for(unsigned int i=0; i< binList.size() ; i++){
	   int m = i+1;
	   //std::cout<<"lower energy limit is "<< binVals[i] <<" GeV"<<std::endl;
	   //std::cout<<"upper energy limit is "<< binVals[m] <<" GeV"<<std::endl;

	   if(gEn >= binVals[i] && gEn <= binVals[m]){
		   //for each PFCandidate that makes it to here, filter the PFCandidates into one of three eta bins, and print out
		   //statements that indicate the reco eta bin, gEn bin, gEn value, and deltaE/E_gen value with and without tracker info
		   //for example
		   //KEEP NO ETABIN_2 EGENBIN_1 60.12 -0.25
		   //KEEP YES ETABIN_2 EGENBIN_1 60.12 -0.05
		   //the first line would indicate an event where the selected PFCandidate object has eta that falls in to the third eta bin, the pi+ gen energy
		   //corresponds to the second gen energy bin (50 - 70 GeV), the pi+ gen energy is 60.12 GeV, deltaE/E_gen is calculated to be -0.25, and no
		   //tracker info was used in calculating deltaE/E_gen
		   //the second line corresponds to the same event, but tracker info is used in calculating deltaE/E_gen

		   /*
		   // USE this for fixed pT, variable eta chgd pion gun samples 
		   if(pfCandIt->eta() < 2.1){
			   std::cout<<"KEEP NO ETABIN_"<< 0 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP YES ETABIN_"<< 0 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

		   }
		   if(pfCandIt->eta() >= 2.1 && pfCandIt->eta() < 2.45){
			   std::cout<<"KEEP NO ETABIN_"<< 1 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP YES ETABIN_"<< 1 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

		   }
		   if(pfCandIt->eta() >= 2.45){
			   std::cout<<"KEEP NO ETABIN_"<< 2 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP YES ETABIN_"<< 2 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

		   }
		   */



		   //fill("GenEnergy_"+binList[i], gEn);
		   //fill("PFCandidateEnergySpreadWithTracker_"+binList[i], ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) )- gEn)/gEn  );
		   //fill("PFCandidateEnergySpreadWithoutTracker_"+binList[i], (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn  );
		   break;	//leave for loop over unsigned int i
	   }//end if(gEn)

   }//end for(i)



/*   
   for(reco::PFCandidateConstIterator pfCandIt = pfCandObjs.begin() ; pfCandIt != pfCandObjs.end() ; pfCandIt++){
	   //std::cout<<"PFCandidate energy is "<< (pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) <<" GeV"<<std::endl;
	   if(gEn >= 28 && gEn <= 310){
		   //std::cout<<"found the highest energy PFCandidate"<<std::endl; 
		   //fill("PFCandidate_highestPt_PdgId",pfCandIt->pdgId());
		   //binVals has one more element than binList
		   for(unsigned int i=0; i< binList.size() ; i++){
			   int m = i+1;
			   //std::cout<<"lower energy limit is "<< binVals[i] <<" GeV"<<std::endl;
 			   //std::cout<<"upper energy limit is "<< binVals[m] <<" GeV"<<std::endl;

			   if(gEn >= binVals[i] && gEn <= binVals[m]){
				   //for each PFCandidate that makes it to here, filter the PFCandidates into one of three eta bins, and print out
				   //statements that indicate the reco eta bin, gEn bin, gEn value, and deltaE/E_gen value with and without tracker info
				   //for example
				   //KEEP NO ETABIN_2 EGENBIN_1 60.12 -0.25
				   //KEEP YES ETABIN_2 EGENBIN_1 60.12 -0.05
				   //the first line would indicate an event where the selected PFCandidate object has eta that falls in to the third eta bin, the pi+ gen energy
				   //corresponds to the second gen energy bin (50 - 70 GeV), the pi+ gen energy is 60.12 GeV, deltaE/E_gen is calculated to be -0.25, and no
				   //tracker info was used in calculating deltaE/E_gen
				   //the second line corresponds to the same event, but tracker info is used in calculating deltaE/E_gen
			  	  
				   // USE this for fixed pT, variable eta chgd pion gun samples 
				   if(pfCandIt->eta() < 2.1){
					   std::cout<<"KEEP NO ETABIN_"<< 0 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 0 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }
				   if(pfCandIt->eta() >= 2.1 && pfCandIt->eta() < 2.45){
					   std::cout<<"KEEP NO ETABIN_"<< 1 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 1 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }
				   if(pfCandIt->eta() >= 2.45){
					   std::cout<<"KEEP NO ETABIN_"<< 2 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 2 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }

				  
				   // USE THIS for fixed energy and eta chgd pion gun samples
				   if(gEta < 1.52){
					   std::cout<<"KEEP NO ETABIN_"<< 0 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 0 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }

				   if(gEta > 1.52 && gEta < 1.77){
					   std::cout<<"KEEP NO ETABIN_"<< 1 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 1 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }

				   if(gEta > 1.77 && gEta < 2.02){
					   std::cout<<"KEEP NO ETABIN_"<< 2 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 2 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }


				   if(gEta > 2.02 && gEta < 2.27){
					   std::cout<<"KEEP NO ETABIN_"<< 3 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 3 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }


				   if(gEta > 2.27 && gEta < 2.52){
					   std::cout<<"KEEP NO ETABIN_"<< 4 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 4 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }


				   if(gEta > 2.52 && gEta < 2.92){
					   std::cout<<"KEEP NO ETABIN_"<< 5 << " EGENBIN_" << i << " " << gEn <<" "<< ( (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn) <<std::endl;
					   std::cout<<"KEEP YES ETABIN_"<< 5 << " EGENBIN_" << i << " " << gEn <<" "<< ( ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) ) - gEn )/gEn) <<std::endl;

				   }
				   
				   
				   //fill("GenEnergy_"+binList[i], gEn);
				   //fill("PFCandidateEnergySpreadWithTracker_"+binList[i], ((pfCandIt->pt())*(TMath::CosH(pfCandIt->eta() ) )- gEn)/gEn  );
				   //fill("PFCandidateEnergySpreadWithoutTracker_"+binList[i], (pfCandIt->ecalEnergy() + pfCandIt->hcalEnergy() - gEn )/gEn  );
				   break;	//leave for loop over unsigned int i
			   }//end if(gEn)

		   }//end for(i)
		   break;	//leave for loop over PFCandidates
			   
	   }//end trivial cut on generator energy, cut on PFCandidate reco energy and hcal energy 


   }//end loop over PFCandidate objects
*/






#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
FixedPtParticleGun::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
FixedPtParticleGun::endJob() 
{

	//makeAndSaveSingleHisto("PdgId of highest energy PFCandidate 2<= eta <= 2.5 in single pi+ gun events; pdgId;","Pt10_to_100_highest_E_reco_eta_cut_PFCand_pdgId","nine","pdgId","PFCandidate_highestE_PdgId",false);
   //makeAndSaveSingleHisto("Eta of highest energy PFCandidate 2<= eta <= 2.5 in single pi+ gun events; eta;","Pt10_to_100_highest_E_reco_eta_cut_PFCand_eta","ten","eta","PFCandidate_highestE_eta",false);
   //makeAndSaveSingleHisto("Eta of highest energy PFCandidate 2<= eta <= 2.5 in single pi+ gun events with gen energy >= 230 GeV; eta;","Pt10_to_100_highest_E_reco_eta_cut_PFCand_eta_for_genE_above_230","eleven","eta","PFCandidate_highestE_eta_for_genE_above_230",false);
   //makeAndSaveSingleHisto("ECAL E/HCAL E of highest energy PFCandidate 2<= eta <= 2.5 in single pi+ gun events; ECAL E/HCAL E;","Pt10_to_100_highest_E_reco_eta_cut_PFCand_ECALoverHCAL","twelve","ECALoverHCAL","PFCandidate_highestE_ECALoverHCAL",false);
 
   //makeAndSaveSingleHisto("PdgId of highest energy PFCandidate 2<= eta <= 2.5 with hcalE>0 2<= eta <= 2.5 in single pi+ gun events; pdgId;","Pt10_to_100_highest_E_hcalE_cut_reco_eta_cut_PFCand_pdgId","13","pdgId","PFCandidate_highestE_hcalE_cut_PdgId",false);
   //makeAndSaveSingleHisto("Eta of highest energy PFCandidate 2<= eta <= 2.5 with hcalE>0 2<= eta <= 2.5 in single pi+ gun events; eta;","Pt10_to_100_highest_E_hcalE_cut_reco_eta_cut_PFCand_eta","14","eta","PFCandidate_highestE_hcalE_cut_eta",false);
   //makeAndSaveSingleHisto("Eta of highest energy PFCandidate 2<= eta <= 2.5 with hcalE>0 2<= eta <= 2.5 in single pi+ gun events with gen energy >= 230 GeV; eta;","Pt10_to_100_highest_E_hcalE_cut_reco_eta_cut_PFCand_eta_for_genE_above_230","15","eta","PFCandidate_highestE_hcalE_cut_eta_for_genE_above_230",false);
   //makeAndSaveSingleHisto("ECAL E/HCAL E of highest energy PFCandidate 2<= eta <= 2.5 with hcalE>0 2<= eta <= 2.5 in single pi+ gun events; ECAL E/HCAL E;","Pt10_to_100_highest_E_hcalE_cut_reco_eta_cut_PFCand_ECALoverHCAL","16","ECALoverHCAL","PFCandidate_highestE_hcalE_cut_ECALoverHCAL",false);

   /*	
   makeAndSaveSingleHisto("Eta of highest energy PFCandidate with hcalE=0 in single pi+ gun events; eta;","Pt20_highest_E_no_hcalE_PFCand_eta","17","eta","PFCandidate_highestE_no_hcalE_eta",false);
 
   makeAndSaveSingleHisto("PT of highest energy PFCandidate with hcalE=0 in single pi+ gun events; pt (GeV);","Pt20_highest_E_no_hcalE_PFCand_pt","18","pt","PFCandidate_highestE_no_hcalE_pt",false);
  
   makeAndSaveSingleHisto("PdgId of highest energy PFCandidate with hcalE=0 in single pi+ gun events; PdgId;","Pt20_highest_E_no_hcalE_PFCand_PdgId","19","PdgId","PFCandidate_highestE_no_hcalE_PdgId",false);

   */


   //makeAndSaveSingleHisto("ECAL E/(ECAL E + HCAL E) of PFCandidate with pdgId=211; ; # of events","E2_to_1000_pdgId_cut_PFCand_ECALE_over_TotalCaloE","21","","PFCandidate_chgdPionPdgId_ECALoverTotalCaloE",false);

   //makeAndSaveSingleHisto("ECAL E/(ECAL E + HCAL E) of highest energy PFCandidate; ; # of events","E2_to_1000_highest_E_caloE_cut_PFCand_ECALE_over_TotalCaloE","20","","PFCandidate_highestE_ECALoverTotalCaloE",false);

   //makeAndSaveSingleHisto("Sum ECAL E/(ECAL E + HCAL E) of all PFCandidates with pT > 0.1 GeV; ; # of events","E2_to_1000_sum_PFCand_ECALE_over_TotalCaloE","22","","PFCandidate_sum_ECALoverTotalCaloE",true);



	/*
	makeAndSaveSingleHisto("PdgId of all generator particles; pdgId; # of events","Pt10_all_genParticle_pdgId","20","pdgId","GenParticle_pdgId",false);

	makeAndSaveSingleHisto("Number of generator particles in each event; number of gen particles; # of events","Pt10_genParticle_multiplicity","21","multiplicity","GenParticle_num",false);

	makeAndSaveSingleHisto("Energy of all PFCandidate objects; E (GeV); # of events","Pt10_all_PFCand_energy","22","energy","PFCandidate_energy",true);

	makeAndSaveSingleHisto("PT of all PFCandidate objects; pt (GeV); # of events","Pt10_all_PFCand_PT","23","pt","PFCandidate_PT",true);

	makeAndSaveSingle3DHisto("Delta eta and phi separation between PFCandidate objects and gen pi+ objects as a function of PFCandidate energy;delta phi (rad); delta eta; PFCandidate energy (GeV)","Pt10_deltaR_btwn_PFCand_and_gen_chgd_pion_vs_PFCand_energy","24","","PFCandidate_deltaR_energy", false);

	*/

	makeAndSaveSingleHisto("# of RECO tracks with 1.5 <= eta <= 3.0; # of tracks in event; # of events","Pt10_track_multiplicity","23","","Track_multiplicity",false);

	makeAndSaveSingle3DHisto("Delta eta, delta phi, and delta E between gen pi+ and all RECO tracks pointing towards HGC; delta phi (rad); delta eta; delta energy (GeV)","Pt10_deltaR_deltaE_btwn_reco_track_and_gen_chgd_pion","24","","Track_deltaR_deltaE", false);


	return;


}

// ------------ method called when starting to processes a run  ------------
/*
void 
FixedPtParticleGun::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
FixedPtParticleGun::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
FixedPtParticleGun::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
FixedPtParticleGun::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
FixedPtParticleGun::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(FixedPtParticleGun);
