// -*- C++ -*-
//
// Package:    singleHadEvsLayerStudy
// Class:      singleHadEvsLayerStudy
// 
/**\class singleHadEvsLayerStudy singleHadEvsLayerStudy.cc HGCalHadronAnalysis/singleHadEvsLayerStudy/plugins/singleHadEvsLayerStudy.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  sean kalafut
//         Created:  Wed, 05 Nov 2014 20:09:51 GMT
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


//this GenParticle.h will allow me to call pdgId(), status(), and other methods on reco::GenParticle objects
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

//this PileupSummaryInfo.h will allow me to get PU info from each event
//#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"


#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TMath.h"
#include "TH1.h"
#include "TH2.h"
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

class singleHadEvsLayerStudy : public edm::EDAnalyzer {
   public:
      explicit singleHadEvsLayerStudy(const edm::ParameterSet&);
      ~singleHadEvsLayerStudy();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
	  /// check if histogram was booked
      bool booked(const std::string histName) const { return hists_.find(histName.c_str())!=hists_.end(); };
	  bool bookedTwo(const std::string histName) const { return histsTwo_.find(histName.c_str())!=histsTwo_.end(); };
	  bool bookedThree(const std::string histName) const { return histsThree_.find(histName.c_str())!=histsThree_.end(); };

      /// fill histogram if it had been booked before
      void fill(const std::string histName, double value) const { if(booked(histName.c_str())) hists_.find(histName.c_str())->second->Fill(value); };
	  void fillTwo(const std::string histName, double valX, double valY) const{  if(bookedTwo(histName.c_str())) histsTwo_.find(histName.c_str())->second->Fill(valX, valY); };
	  void fillThree(const std::string histName, double valX, double valY, double valZ) const{  if(bookedThree(histName.c_str())) histsThree_.find(histName.c_str())->second->Fill(valX, valY, valZ); };


	  //this takes three 2D histograms, divides two of them, and places the contents of the two divided histogram into the histo (histNameReturned) that called Divide
	  void divideTwo(const std::string histNameNumerator, const std::string histNameDenominator, const std::string histNameReturned) const{
		  if(bookedTwo(histNameNumerator.c_str()) && bookedTwo(histNameDenominator.c_str()) && bookedTwo(histNameReturned.c_str()) ){
			  //if all three 2D histos have been declared, then call divide on histNameReturned and pass histNameNumerator, histNameDenominator into Divide as arguments
			  histsTwo_.find(histNameReturned.c_str())->second->Divide( histsTwo_.find(histNameNumerator.c_str())->second, histsTwo_.find(histNameDenominator.c_str())->second );

		  }

	  }

	 //this gets the number of X axis bins from a 1D, 2D, or 3D histo
	 int getXBins(const std::string histName) const {
		 if(bookedTwo(histName.c_str()) ){
			 int binsX = histsTwo_.find(histName.c_str() )->second->GetNbinsX();
			 return binsX;
		 }

		 if(booked(histName.c_str()) ){
			 int binsX = hists_.find(histName.c_str() )->second->GetNbinsX();
			 return binsX;
		 }

		 if(bookedThree(histName.c_str()) ){
			 int binsX = histsThree_.find(histName.c_str() )->second->GetNbinsX();
			 return binsX;
		 }


		 int failsafe = 0;
		 return failsafe;
	 }//end getXBins(histName) 

	 //this gets the number of Y axis bins from a 2D or 3D histo
	 int getYBins(const std::string histName) const {
		 if(bookedTwo(histName.c_str()) ){
			 int binsY = histsTwo_.find(histName.c_str() )->second->GetNbinsY();
			 return binsY;
		 }

		 if(bookedThree(histName.c_str()) ){
			 int binsY = histsThree_.find(histName.c_str() )->second->GetNbinsY();
			 return binsY;
		 }


		 int failsafe = 0;
		 return failsafe;
	 }//end getYBins(histName)
	 
	 //this returns the contents of bin (x,y) in a 2D histo
	 double get2DBinContents(const std::string histName, int xBin, int yBin) const {
		 if(bookedTwo(histName.c_str()) ){
			 double binContents = histsTwo_.find(histName.c_str() )->second->GetBinContent(xBin, yBin);
			 return binContents;
		 }

		 double failsafe = 0.;
		 return failsafe;

	 }//end get2DBinContents()

	 //this returns the contents of bin xBin in a 1D histo
	 double get1DBinContents(const std::string histName, int xBin) const {
		 if(booked(histName.c_str()) ){
			 double binContents = hists_.find(histName.c_str() )->second->GetBinContent(xBin);
			 return binContents;
		 }
		 
		 double failsafe = 0.;
		 return failsafe;

	 }//end get1DBinContents()

	 //this returns the upper value (right most) corresponding to the right edge of a bin in a 1D histo
	 double get1DUpperBinEdge(const std::string histName, int xBin) const {
		 if(booked(histName.c_str()) ){
			 double lowerBinEdge = hists_.find(histName.c_str() )->second->GetBinLowEdge(xBin);
			 double binWidth = hists_.find(histName.c_str() )->second->GetBinWidth(xBin);
			 double upperBinEdge = lowerBinEdge + binWidth;
			 return upperBinEdge;
		 }
		 
		 double failsafe = 0.;
		 return failsafe;

	 }//end get1DUpperBinEdge()

	 //this sets the contents of bin xBin in a 1D histo
	 void set1DBinContents(const std::string histName, int xBin, double content) const {
		 if(booked(histName.c_str()) ){
			 hists_.find(histName.c_str() )->second->SetBinContent(xBin, content);
		 }

	 }//end set1DBinContents()


	 void set2DBinContents(const std::string histName, int xBin, int yBin, double content) const {
		 if(bookedTwo(histName.c_str()) ){
			 histsTwo_.find(histName.c_str() )->second->SetBinContent(xBin, yBin, content);
		 }

	 }//end set2DBinContents()

	 double get3DBinContents(const std::string histName, int xBin, int yBin, int zBin) const {
		 if(bookedThree(histName.c_str()) ){
			 double binContents = histsThree_.find(histName.c_str() )->second->GetBinContent(xBin, yBin, zBin);
			 return binContents;
		 }

		 double failsafe = 0.;
		 return failsafe;

	 }//end get3DBinContents()

	 void set3DBinContents(const std::string histName, int xBin, int yBin, int zBin, double content) const {
		 if(bookedThree(histName.c_str()) ){
			 histsThree_.find(histName.c_str() )->second->SetBinContent(xBin, yBin, zBin, content);
		 }

	 }//end set3DBinContents()




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
	      TString longPathName = "/eos/uscms/store/user/skalafut/HGCal/1D_";
	      
		  TH1D * histogram = hists_.find(histName.c_str())->second;
	      TString saveFileType = ".gif";
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

      void makeAndSaveSingle2DHisto(TString title, TString filePostfix, TString canvName, TString legEntry, const std::string histName, bool doLogYAxis){
	      TString longPathName = "/eos/uscms/store/user/skalafut/HGCal/2D_";
	      
		  TH2D * histogram = histsTwo_.find(histName.c_str())->second;
	      TString saveFileType = ".gif";
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

      }//end makeAndSaveSingle2DHisto(...)



      void makeAndSaveSingle3DHisto(TString title, TString filePostfix, TString canvName, TString legEntry, const std::string histName, bool doLogZAxis){
	      TString longPathName = "/eos/uscms/store/user/skalafut/HGCal/3D_";
	      
		  TH3D * histogram = histsThree_.find(histName.c_str())->second;
	      TString saveFileType = ".gif";
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
		  histogram->GetXaxis()->SetTitleOffset(1.6);
		  histogram->GetYaxis()->SetTitleOffset(1.75);
		  histogram->GetZaxis()->SetTitleOffset(1.5);


	      TLegend * leg111 = new TLegend(.8,.27,1,.4);
	      leg111->AddEntry(histogram,legEntry);

	      histogram->Draw("hist");
	      leg111->Draw();

	      c111->SaveAs(longPathName+filePostfix+saveFileType, "recreate");

      }//end makeAndSaveSingle3DHisto(...)

	  // 0 = HGCEE, 1 = HGCHEF, 2 = HGCHEB, 3 = rechit is not in HGC
	  int hgcRegion(const reco::PFRecHitRef& oneRechit){
		  DetId idOfRechit = oneRechit->detId();
		  //if the detId of oneRechit belongs to a forward detector, return an int which indicates the parent detector and sub-detector region (like HGC EE)
		  if(idOfRechit.det() == DetId::Forward){
			  if(idOfRechit.subdetId() == ForwardSubdetector::HGCEE) return 0;
			  if(idOfRechit.subdetId() == ForwardSubdetector::HGCHEF) return 1;
			  if(idOfRechit.subdetId() == ForwardSubdetector::HGCHEB) return 2;

		  }
		  
		  return 3;	//oneRechit does not correspond to any detId in HGC

	  }//end hgcRegion( reco::PFRecHitRef object )

	  int hgcLayerNumber(const reco::PFRecHitRef& oneRechit){
		  //first determine which region of HGC this rechit belongs in - EE, HEF, or HEB
		  int region = hgcRegion(oneRechit);
		  
		  //now return the layer number where the rechit is located in HGC
		  //if the rechit belongs to HEF or HEB, add 30 to the layer number before returning the layer number 
		  if(region == 0){
			  //oneRechit is in EE
			  return HGCEEDetId(oneRechit->detId()).layer();
		  }
		  if(region == 1 || region == 2){
			  //oneRechit is in HEF or HEB
			  return (30 + HGCHEDetId(oneRechit->detId()).layer() );
		  }

		  return -1;	//oneRechit is not in HGC

	  }//end hgcLayerNumber(reco::PFRecHitRef object)

	  std::vector<double> absorberWeights;

	  double calibEERechitEnergy(const reco::PFRecHitRef& oneRechit){
		  //using the rechit ref named oneRechit, compute the true energy of the rechit (taking the absorber weight into account) and return this true energy
		  if(hgcRegion(oneRechit) == 0){
			  //rechit is in HGCEE
			  double eta = (oneRechit->position()).eta();
			  double uncorrMips = (oneRechit->energy())/(0.000055);
			  double effMipsToInvGeV = (82.8)/( 1.0 + std::exp(-(1000000.0) - (1000000.0)*std::cosh(eta) ) );
			  double corrMips =  absorberWeights[hgcLayerNumber(oneRechit)]*uncorrMips;
			  return (corrMips/effMipsToInvGeV);
		  }
		  return 0;

	  }//end calibEERechitEnergy(reco::PFRecHitRef object)

	  double calibHEFRechitEnergy(const reco::PFRecHitRef& oneRechit){
		  //using the rechit reference named oneRechit, compute the true energy of the rechit (taking the absorber weight into account) and return this true energy
		  if(hgcRegion(oneRechit) == 1){
			  //rechit is in HGCHEF
			  double eta = (oneRechit->position()).eta();
			  double uncorrMips = (oneRechit->energy())/(0.000085);
			  double effMipsToInvGeV = (1.0)/( 1.0 + std::exp(-(1000000.0) - (1000000.0)*std::cosh(eta) ) );
			  double corrMips =  absorberWeights[hgcLayerNumber(oneRechit)]*uncorrMips;
			  return (corrMips/effMipsToInvGeV);
		  }
		  return 0;

	  }//end calibHEFRechitEnergy(reco::PFRecHitRef object)


	  double calibHEBRechitEnergy(const reco::PFRecHitRef& oneRechit){
		  //using the rechit reference named oneRechit, compute the true energy of the rechit (taking the absorber weight into account) and return this true energy
		  if(hgcRegion(oneRechit) == 2){
			  //rechit is in HGCHEB
			  double eta = (oneRechit->position()).eta();
			  double uncorrMips = (oneRechit->energy())/(0.001498);
			  double effMipsToInvGeV = (1.0)/( 1.0 + std::exp(-(1000000.0) - (1000000.0)*std::cosh(eta) ) );
			  double corrMips =  absorberWeights[hgcLayerNumber(oneRechit)]*uncorrMips;
			  return (corrMips/effMipsToInvGeV);
		  }
		  return 0;

	  }//end calibHEBRechitEnergy(reco::PFRecHitRef object)

	  double calibRechitPt(const reco::PFRecHitRef& oneRechit){
		  double eta = (oneRechit->position()).eta();
		  int type = hgcRegion(oneRechit);
		  if(type==0) return (calibEERechitEnergy(oneRechit)/std::cosh(eta) );
		  if(type==1) return (calibHEFRechitEnergy(oneRechit)/std::cosh(eta) );
		  if(type==2) return (calibHEBRechitEnergy(oneRechit)/std::cosh(eta) );
		  return 0;

	  }//end calibRechitPt(reco::PFRecHitRef object)


	  std::vector<double> finalEnergyFrxns;  //public
	  std::vector<int> finalEnergyFrxnBinNums;  //public



   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

	  std::map<std::string,TH1D*> hists_;
	  std::map<std::string,TH2D*> histsTwo_;
	  std::map<std::string,TH3D*> histsThree_;
	  

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
singleHadEvsLayerStudy::singleHadEvsLayerStudy(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   edm::Service<TFileService> fs;

   //PFRecHit based plots
   hists_["EnergyFrxnVsLambda"]=fs->make<TH1D>("EnergyFrxnVsLambda","temp Energy fraction vs hadronic interaction length; hadronic int length #lambda; Energy fraction",400,0.,10.9);
   hists_["FinalEnergyFrxnVsLambda"]=fs->make<TH1D>("FinalEnergyFrxnVsLambda","Energy fraction vs hadronic interaction length; hadronic int length #lambda; Energy fraction",400,0.,10.9);

   hists_["EE_PFRecHit_energy"]=fs->make<TH1D>("EE_PFRecHit_energy","Energy of rechits in HGCEE in GeV",100,0.,0.001);  
   hists_["HEF_PFRecHit_energy"]=fs->make<TH1D>("HEF_PFRecHit_energy","Energy of rechits in HGCHEF in GeV",100,0.,0.001);  
   hists_["HEB_PFRecHit_energy"]=fs->make<TH1D>("HEB_PFRecHit_energy","Energy of rechits in HGCHEB in GeV",100,0.,0.01); 
   
   //hists_["RecHitCalib"]=fs->make<TH1D>("RecHitCalib","#DeltaE/E for 200 GeV #pi+ at #eta 2.0 using rechit energies",200,-1.0,1.0);

   hists_["PFRecHit_Z_from_HGCEECluster"]=fs->make<TH1D>("PFRecHit_Z_from_HGCEECluster","Z position of rechits belonging to HGCEE PFClusters",200,300.,360.);

   //these four plots DO NOT pull PFRecHit objects from PFCluster objects, they are simply showing all of the PFRecHit objects as a fxn of Z distance for all events
   /*
   hists_["EE_PFRecHit_z"]=fs->make<TH1D>("EE_PFRecHit_z","Z position of rechits in HGCEE in centimeters",150,300.,360.);  //this histo is made to show the Z distance between each Si layer in HGCEE
   hists_["HEF_PFRecHit_z"]=fs->make<TH1D>("HEF_PFRecHit_z","Z position of rechits in HGCHEF in centimeters",100,350.,460.);  //this histo is made to show the Z distance between each Si layer in HGCHEF
   hists_["HEB_PFRecHit_z"]=fs->make<TH1D>("HEB_PFRecHit_z","Z position of rechits in HGCHEB in centimeters",100,400.,600.);  //this histo is made to show the Z distance between each scintillator layer in HGCHEB
   */

   //hists_["All_PFRecHit_z"]=fs->make<TH1D>("All_PFRecHit_z","Z position of all HGC PFRecHits ; distance from IP (cm);",500,310.,560.);  //this histo is made to show the Z distance between each sensitive layer of HGC (Si or scintillator) 


   //histos needed to compute reconstruction efficiency as a fxn of energy and eta
   hists_["ChgdPiSomeE_1"]=fs->make<TH1D>("ChgdPiSomeE_1","# of events with nonzero reco energy and gen eta near 1.6 versus gen energy",100,0.,501.0);
   hists_["ChgdPiAnyE_1"]=fs->make<TH1D>("ChgdPiAnyE_1","total # of events analyzed with gen eta near 1.6 vs gen energy",100,0.,501.0);
   hists_["ChgdPiEnEfficiency_1"]=fs->make<TH1D>("ChgdPiEnEfficiency_1","Reconstruction efficiency for #pi+ with gen eta near 1.6 versus gen energy",100,0.,501.0);
 
   hists_["ChgdPiSomeE_2"]=fs->make<TH1D>("ChgdPiSomeE_2","# of events with nonzero reco energy and gen eta near 1.9 versus gen energy",100,0.,501.0);
   hists_["ChgdPiAnyE_2"]=fs->make<TH1D>("ChgdPiAnyE_2","total # of events analyzed with gen eta near 1.9 vs gen energy",100,0.,501.0);
   hists_["ChgdPiEnEfficiency_2"]=fs->make<TH1D>("ChgdPiEnEfficiency_2","Reconstruction efficiency for #pi+ with gen eta near 1.9 versus gen energy",100,0.,501.0);
   
   hists_["ChgdPiSomeE_3"]=fs->make<TH1D>("ChgdPiSomeE_3","# of events with nonzero reco energy and gen eta near 2.2 versus gen energy",100,0.,501.0);
   hists_["ChgdPiAnyE_3"]=fs->make<TH1D>("ChgdPiAnyE_3","total # of events analyzed with gen eta near 2.2 vs gen energy",100,0.,501.0);
   hists_["ChgdPiEnEfficiency_3"]=fs->make<TH1D>("ChgdPiEnEfficiency_3","Reconstruction efficiency for #pi+ with gen eta near 2.2 versus gen energy",100,0.,501.0);

   hists_["ChgdPiSomeE_4"]=fs->make<TH1D>("ChgdPiSomeE_4","# of events with nonzero reco energy and gen eta near 2.5 versus gen energy",100,0.,501.0);
   hists_["ChgdPiAnyE_4"]=fs->make<TH1D>("ChgdPiAnyE_4","total # of events analyzed with gen eta near 2.5 vs gen energy",100,0.,501.0);
   hists_["ChgdPiEnEfficiency_4"]=fs->make<TH1D>("ChgdPiEnEfficiency_4","Reconstruction efficiency for #pi+ with gen eta near 2.5 versus gen energy",100,0.,501.0);

   hists_["ChgdPiSomeE_5"]=fs->make<TH1D>("ChgdPiSomeE_5","# of events with nonzero reco energy and gen eta near 2.8 versus gen energy",100,0.,501.0);
   hists_["ChgdPiAnyE_5"]=fs->make<TH1D>("ChgdPiAnyE_5","total # of events analyzed with gen eta near 2.8 vs gen energy",100,0.,501.0);
   hists_["ChgdPiEnEfficiency_5"]=fs->make<TH1D>("ChgdPiEnEfficiency_5","Reconstruction efficiency for #pi+ with gen eta near 2.8 versus gen energy",100,0.,501.0);

   //histos needed to compute reconstruction efficiency as a fxn of pT and eta
 

   /*
   histsThree_["PFClusterSum_HCALovrECAL_gen_eta_energy"]=fs->make<TH3D>("PFClusterSum_HCALovrECAL_gen_eta_energy","Reco E_HCAL/E_ECAL for Pi+ vs gen Pi+ energy and eta", 100, 0., 210., 15, 1.55, 3.0, 30, 0., 15.);

   histsThree_["EEPFCluster_deltaR_energy"]=fs->make<TH3D>("EEPFCluster_deltaR_energy","#Delta#eta and #Delta#phi between EE PFClusters and generator pi+ as a function of PFCluster energy", 632, -3.16, 3.16, 40, -1.5, 1.5, 200, 0., 100.);
 
   histsThree_["HEFPFCluster_deltaR_energy"]=fs->make<TH3D>("HEFPFCluster_deltaR_energy","#Delta#eta and #Delta#phi between HEF PFClusters and generator pi+ as a function of PFCluster energy", 632, -3.16, 3.16, 40, -1.5, 1.5, 200, 0., 100.);

   histsThree_["HEBPFCluster_deltaR_energy"]=fs->make<TH3D>("HEBPFCluster_deltaR_energy","#Delta#eta and #Delta#phi between HEB PFClusters and generator pi+ as a function of PFCluster energy", 632, -3.16, 3.16, 40, -1.5, 1.5, 100, 0., 50.);
 
   histsThree_["MaxEEPFCluster_deltaR_energy"]=fs->make<TH3D>("MaxEEPFCluster_deltaR_energy","#Delta#eta and #Delta#phi between highest energy EE PFClusters and generator pi+ as a function of PFCluster energy", 632, -3.16, 3.16, 40, -1.5, 1.5, 200, 0., 300.);
 
   histsThree_["MaxHEFPFCluster_deltaR_energy"]=fs->make<TH3D>("MaxHEFPFCluster_deltaR_energy","#Delta#eta and #Delta#phi between highest energy HEF PFClusters and generator pi+ as a function of PFCluster energy", 632, -3.16, 3.16, 40, -1.5, 1.5, 200, 0., 300.);

   histsThree_["MaxHEBPFCluster_deltaR_energy"]=fs->make<TH3D>("MaxHEBPFCluster_deltaR_energy","#Delta#eta and #Delta#phi between highest energy HEB PFClusters and generator pi+ as a function of PFCluster energy", 632, -3.16, 3.16, 40, -1.5, 1.5, 100, 0., 300.);

  */ 


}


singleHadEvsLayerStudy::~singleHadEvsLayerStudy()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
singleHadEvsLayerStudy::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   //using namespace edm;
   unsigned int numberOfBins = 9;
   std::vector<float> binVals;
   std::vector<std::string> binList;

   //float multiplier = 20.0;
   //float start = 30.0;
   binVals.push_back(9.98);
   binVals.push_back(29.98);
   binVals.push_back(49.98);
   binVals.push_back(79.98);
   binVals.push_back(99.98);
   binVals.push_back(149.98);
   binVals.push_back(199.98);
   binVals.push_back(299.98);
   binVals.push_back(499.9);
   binVals.push_back(501.0);
  
   
   for(unsigned int i=1; i<(numberOfBins+1) ; i++){
      binList.push_back( std::to_string(i) );
      //binVals.push_back(start + i*multiplier);
   }

   for(int q=0; q<54; q++){
	   //fill the absorberWeights vector with the correct weights
	   if(q==0) absorberWeights.push_back(0.010);
	   if(q >= 1 && q <= 10) absorberWeights.push_back(0.036);
	   if(q >= 11 && q <= 20) absorberWeights.push_back(0.043);
	   if(q >= 21 && q <= 29) absorberWeights.push_back(0.056);
	   if(q==30) absorberWeights.push_back(0.338);
	   if(q >= 31 && q <= 41) absorberWeights.push_back(0.273);
	   if( q >= 42 && q <= 53) absorberWeights.push_back(0.475);
   }

   //////////////////////////////////////////////////////////////////////////
   //get the energy of the generator lvl pi+
   //plot E_gen
   //at the end of the run store the mean of the E_gen histogram 
   /////////////////////////////////////////////////////////////////////////

   edm::Handle<std::vector<reco::GenParticle> > genPart;
   iEvent.getByLabel("genParticles",genPart);
 
   double gEn =0;	//energy of a generator chgd pion
   float gEta = 0;
   //float gPhi = 0;	//eta and phi of generator chgd pion
   double gPt = 0;
   //int numGenParticles = 0;	//keeps track of the total number of gen lvl particles in the event

   for(std::vector<reco::GenParticle>::const_iterator genIt=genPart->begin(); genIt != genPart->end(); genIt++){
	   //numGenParticles++;
	   if(genIt->pdgId() == 211){
		  //if the genIt pdgId is +211 then the particle is a pi+
		  gEta = genIt->eta();
		  //gPhi = genIt->phi();
		  gEn = (genIt->pt())*(TMath::CosH(genIt->eta()));
		  gPt = genIt->pt();
	   }

   }//end loop over GenParticle


   edm::Handle<std::vector<reco::PFCluster> > PFClustersEE;
   iEvent.getByLabel("particleFlowClusterHGCEE","",PFClustersEE);
   if(!PFClustersEE.isValid() ){
	   std::cout<<"no PFCluster collection found with label particleFlowClusterHGCEE" <<std::endl;
   }

   /*
	* don't use these collections while the new HGC clustering algorithm is being retuned, and all PFClusters are
	* being saved into the collection particleFlowClusterHGCEE
   edm::Handle<std::vector<reco::PFCluster> > PFClustersHEF;
   iEvent.getByLabel("particleFlowClusterHGCHEF","",PFClustersHEF);
   if(!PFClustersHEF.isValid() ){
	   std::cout<<"no PFCluster collection found with label particleFlowClusterHGCHEF" <<std::endl;
   }

   edm::Handle<std::vector<reco::PFCluster> > PFClustersHEB;
   iEvent.getByLabel("particleFlowClusterHGCHEB","",PFClustersHEB);
   if(!PFClustersHEB.isValid() ){
	   std::cout<<"no PFCluster collection found with label particleFlowClusterHGCHEB" <<std::endl;
   }
   */


   //FORGET about calculating delta p_T/p_T for now
   
   //double totalTrackAndCaloEnergy = 0.;
   double totalCaloEnergy = 0.;
   double totalCaloPt = 0.;
   double minEnergy = 0.10;   //in GeV
   //double boostHEBEnergy = 0.;  //energy threshold for PFClusters in HEB
   //double totalEME = 0.;
   //double totalEMPt = 0.;
   //double totalHcalE = 0.;
   //double totalHcalPt = 0.;
   //double HEBEnergy = 0.;

   double firstEME = 0;	//EM energy which has been weighted according to the amount of absorber material in front of each sensitive layer
   double secondEME = 0;	//EM energy which has been weighted based on absorber material, and rescaled based on EM shower energy

   double firstHEFE = 0;	//HEF energy which has been weighted according to the amount of absorber material in front of each sensitive layer
   double secondHEFE = 0;	//HEF energy which has been weighted based on absorber material, and rescaled based on EM shower energy

   double firstHEBE = 0;	//HEB energy which has been weighted according to the amount of absorber material in front of each sensitive layer
   double secondHEBE = 0;	//HEB energy which has been weighted based on absorber material, and rescaled based on EM shower energy



   //(PFCluster object).pt() and (PFCluster object).energy() both return
   //double values
   //pt() calculates the cluster PT assuming the particle that deposited the
   //energy is massless (so pT = energy/cosh(eta) )
   //energy() returns the cluster energy that has been calibrated using
   //Pedro's regressions (HGCEE calibrated with electrons, HGCHE calibrated
   //with neutral K_longs)

   //use these to find the highest energy PFCluster from each subdetector in each event
   //double maxHEBEnergy = 0;
   //double maxEEEnergy = 0;
   //double maxHEFEnergy = 0;

   //double calibEERechitEnergy(const reco::PFRecHitRef& oneRechit)
   //double calibHEFRechitEnergy(const reco::PFRecHitRef& oneRechit)
   //double calibHEBRechitEnergy(const reco::PFRecHitRef& oneRechit)
  
   for(std::vector<reco::PFCluster>::const_iterator clstEE=PFClustersEE->begin(); clstEE != PFClustersEE->end(); clstEE++){
	   if(clstEE->energy() <= minEnergy) continue;
	   const std::vector<reco::PFRecHitFraction> pfRechitFractions = clstEE->recHitFractions();
	   for(unsigned int i=0; i<pfRechitFractions.size() ;i++){
		   //I can freely call calibEERechitEnergy(ref), calibHEFRechitEnergy(ref), calibHEBRechitEnergy(ref) because these functions will return
		   //zero if the rechit does not belong to the corresponding HGC subdetector
		   firstEME += (pfRechitFractions[i].fraction() )*calibEERechitEnergy(pfRechitFractions[i].recHitRef() );
		   firstHEFE += (pfRechitFractions[i].fraction() )*calibHEFRechitEnergy(pfRechitFractions[i].recHitRef() );
		   firstHEBE += (pfRechitFractions[i].fraction() )*calibHEBRechitEnergy(pfRechitFractions[i].recHitRef() );

	   }//end loop over pfRechitFractions

   }//end loop over all PFClusters in the event

   double rescaledEME = ( (0.2372)*(firstEME) - 0.2215 );
   double rescaledHEFE = ( (0.1847)*(firstHEFE) + 0.0818 );
   double rescaledHEBE = ( (0.2429)*(firstHEBE) + 0.58 );
   if(rescaledEME > 0 ){
	   secondEME += rescaledEME;
   }
   if(rescaledHEFE > 0 ){
	   secondHEFE += rescaledHEFE;
   }
   if(rescaledHEBE > 0 ){
	   secondHEBE += rescaledHEBE;
   }

   totalCaloEnergy += secondEME + (1.258)*(secondHEFE + (1.101)*(secondHEBE) );
   absorberWeights.clear();	//clears all contents out of absorberWeights vector, resets # of elements to zero

   /*
   for(std::vector<reco::PFCluster>::const_iterator clstEE=PFClustersEE->begin(); clstEE != PFClustersEE->end(); clstEE++){
	   if(clstEE->energy() <= minEnergy ) continue;  //for analysis of fixed pT variable eta events
	   //now get the PFRecHitFraction objects associated with the PFCluster
	   const std::vector<reco::PFRecHitFraction> EEPFRecHitFractions = clstEE->recHitFractions();
	   for(unsigned int i=0; i< EEPFRecHitFractions.size() ; i++){
		   //loop over PFRecHitFraction objects associated with the PFCluster, and add PFRecHit energy to 54 element array of floats and totalCaloRecHitEnergy var
		   fill("PFRecHit_Z_from_HGCEECluster",((EEPFRecHitFractions[i].recHitRef())->position()).Z());

	   }//loop over PFRecHitFraction objects

   }//loop over HGCEE PFClusters


   for(std::vector<reco::PFCluster>::const_iterator clstEE=PFClustersEE->begin(); clstEE != PFClustersEE->end(); clstEE++){
	   if(clstEE->energy() == maxEEEnergy){
		   //fillThree("MaxEEPFCluster_deltaR_energy", clstEE->phi() - gPhi, clstEE->eta() - gEta, clstEE->energy() );
	   }
   }
   */


   /*
   for(std::vector<reco::PFCluster>::const_iterator clstHEF=PFClustersHEF->begin(); clstHEF != PFClustersHEF->end(); clstHEF++){
	   if(clstHEF->energy() <= minEnergy) continue;
	   totalHcalE += clstHEF->energy();
	   //fillThree("HEFPFCluster_deltaR_energy", clstHEF->phi() - gPhi, clstHEF->eta() - gEta, clstHEF->energy() );
	   if(clstHEF->energy() > maxHEFEnergy){
		   maxHEFEnergy = 0;
		   maxHEFEnergy += clstHEF->energy();
	   }
   }

   for(std::vector<reco::PFCluster>::const_iterator clstHEF=PFClustersHEF->begin(); clstHEF != PFClustersHEF->end(); clstHEF++){
	   if(clstHEF->energy() == maxHEFEnergy){
		   //fillThree("MaxHEFPFCluster_deltaR_energy", clstHEF->phi() - gPhi, clstHEF->eta() - gEta, clstHEF->energy() );
	   }
   }


   for(std::vector<reco::PFCluster>::const_iterator clstHEB=PFClustersHEB->begin(); clstHEB != PFClustersHEB->end(); clstHEB++){
	   if(clstHEB->energy() <= (minEnergy + boostHEBEnergy) ) continue;
	   totalHcalE += clstHEB->energy();
	   HEBEnergy += clstHEB->energy();
	   //fillThree("HEBPFCluster_deltaR_energy", clstHEB->phi() - gPhi, clstHEB->eta() - gEta, clstHEB->energy() );
	   if(clstHEB->energy() > maxHEBEnergy){
		   maxHEBEnergy = 0;
		   maxHEBEnergy += clstHEB->energy();
	   }
   }
 
   for(std::vector<reco::PFCluster>::const_iterator clstHEB=PFClustersHEB->begin(); clstHEB != PFClustersHEB->end(); clstHEB++){
	   if(clstHEB->energy() == maxHEBEnergy){
		   //fillThree("MaxHEBPFCluster_deltaR_energy", clstHEB->phi() - gPhi, clstHEB->eta() - gEta, clstHEB->energy() );
	   }
   }
   */


   //if( gEn > 3.0 && gEta > 1.6 && gEn < 210.) //fillThree("PFClusterSum_HCALovrECAL_gen_eta_energy", gEn, gEta, (totalHcalE/totalEME) );
   

   //std::cout<<"total PFCluster energy equals "<< totalCaloEnergy <<std::endl;



   //This code checks that a plot of PFRecHit z position shows a few mm gap between Si layers in HGCEE and HEF, and between scintillator layers in HEB

   /*
   edm::Handle<std::vector<reco::PFRecHit>> EEPFRecHits;
   iEvent.getByLabel("particleFlowRecHitHGCEE","", EEPFRecHits);

   for(std::vector<reco::PFRecHit>::const_iterator EEPFRecHitIt = EEPFRecHits->begin(); EEPFRecHitIt != EEPFRecHits->end(); EEPFRecHitIt++){
	   //fill("EE_PFRecHit_z",(EEPFRecHitIt->position()).Z() );
	   //fill("All_PFRecHit_z",(EEPFRecHitIt->position()).Z() );
	   fill("EE_PFRecHit_energy", EEPFRecHitIt->energy() );
   }//end loop over PFRecHit objects in EE 


   edm::Handle<std::vector<reco::PFRecHit>> HEFPFRecHits;
   iEvent.getByLabel("particleFlowRecHitHGCHEF","", HEFPFRecHits);
   
   for(std::vector<reco::PFRecHit>::const_iterator HEFPFRecHitIt = HEFPFRecHits->begin(); HEFPFRecHitIt != HEFPFRecHits->end(); HEFPFRecHitIt++){
	   //fill("HEF_PFRecHit_z",(HEFPFRecHitIt->position()).Z() );
	   //fill("All_PFRecHit_z",(HEFPFRecHitIt->position()).Z() );
	   fill("HEF_PFRecHit_energy", HEFPFRecHitIt->energy() );
   }//end loop over PFRecHit objects in HEF 


   edm::Handle<std::vector<reco::PFRecHit>> HEBPFRecHits;
   iEvent.getByLabel("particleFlowRecHitHGCHEB","", HEBPFRecHits);

   for(std::vector<reco::PFRecHit>::const_iterator HEBPFRecHitIt = HEBPFRecHits->begin(); HEBPFRecHitIt != HEBPFRecHits->end(); HEBPFRecHitIt++){
	   //fill("HEB_PFRecHit_z",(HEBPFRecHitIt->position()).Z() );
	   //fill("All_PFRecHit_z",(HEBPFRecHitIt->position()).Z() );
   	   fill("HEB_PFRecHit_energy", HEBPFRecHitIt->energy() );
   }//end loop over PFRecHit objects in HEB 

   */



   //////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //HGC PFRecHit work
   //need the x, y, and z position of rechits within selected PFClusters
   //PFCluster selection is:
   //1. skip events where generator pi+ eta is not between 1.7 and 2.8.
   //2. make a cone with radius delta R = 0.4 around generator pi+ trajectory
   //3. select PFClusters with E > 0.1 GeV, and eta btwn 1.55 and 2.95
   //4. PFClusters that pass these cuts are the "selected" PFClusters
   //5. use the PFRecHits associated with these PFClusters to determine the event energy fraction as a function of lambda
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////

   /*
   //factors to convert rechit energy in GeV to a number of MIPs
   double MipsToGeV_EE = 0.000055;
   double MipsToGeV_HEF = 0.000085;
   double MipsToGeV_HEB = 0.001498;
   double EEInverseMipToGeVCorrection = 82.8;
   double HEFInverseMipToGeVCorrection = 1.0;
   double HEBInverseMipToGeVCorrection = 1.0;


   //UPDATE THIS!! there are an additional 12 layers due to segmentation of HEB
   double HGCLayerBoundaries[] = {320.5,321.5,322.5,323.5,324,325,325.5,326.5,327.5,328.5,329,330,331,332,333,334,334.5,336,336.5,337.5,338.5,339.5,340.5,342,343,344,345.5,346.5,347.5,348.5,355,360,364.5,369.5,374,379,384,388.5,393.5,398,403,408,421.5,426,430.5,434.5,439,443.5,445,447.5,452,456.5,461,465,469.5,474,478,482.5,487,491,495.5,500,504.5,508.5,513,517.5,521.5};    //approximate distance in cm between IP and face of each sensitive layer which is furthest from IP 
   
   double HGCLambdaBoundaries[54] = {0.01,0.06,0.1,0.12,0.16,0.18,0.22,0.24,0.28,0.3,0.34,0.37,0.42,0.47,0.5,0.53,0.58,0.61,0.66,0.69,0.74,0.79,0.85,0.9,0.96,1.01,1.07,1.12,1.18,1.23,1.57,1.82,2.07,2.32,2.57,2.82,3.07,3.32,3.57,3.82,4.07,4.32,4.53,4.74,4.95,5.16,5.37,5.58,5.79,6,6.21,6.42,6.63,6.84};       //amount of material in front of every sensitive layer of HGC in terms of hadronic interaction lengths 
   double totalCaloRecHitEnergy = 0.0;

   //caloRecHitEnergyVsLayer has one element for each sensitive layer in HGC
   std::vector<double> caloRecHitEnergyVsLayer;
   std::vector<double> energyFrxnVsLayer;

   //vector storing energy reweighting factors which are optimized to give the best hadronic energy resolution
   //see Pedro's presentation from October 24 2014
   //these weights are also stored in particleFlowClusterHGCEE_cfi.py (for EE portion) and particleFlowClusterHGCHEF_cfi.py (for HEF and HEB portions)
   std::vector<double> reWeightingFactors;

   //UPDATE THIS!! this should run from i=0 up to i=65
   //See Maksat's presentation in LPC phase 2 meeting for correct HGCEE weighting factors
   for(unsigned int i=0; i<54 ; i++){
	   caloRecHitEnergyVsLayer.push_back(0.0);
	   energyFrxnVsLayer.push_back(0.0);
	   if(i == 0) reWeightingFactors.push_back(0.0179);
	   if(i > 0 && i <= 10) reWeightingFactors.push_back(0.0105);
	   if(i > 10 && i <= 20) reWeightingFactors.push_back(0.0096);
	   if(i > 20 && i <= 29) reWeightingFactors.push_back(0.0169);
	   if(i == 30) reWeightingFactors.push_back(0.0464);
	   if(i > 30 && i <= 41) reWeightingFactors.push_back(0.0474);
	   if(i > 41) reWeightingFactors.push_back(0.1215);
   }


   for(std::vector<reco::PFCluster>::const_iterator clstEE=PFClustersEE->begin(); clstEE != PFClustersEE->end(); clstEE++){
	   double deltaEta = (clstEE->eta() - gEta);
	   double deltaPhi = (clstEE->phi() - gPhi);
	   double deltaR = TMath::Sqrt(TMath::Power(deltaEta,2)+TMath::Power(deltaPhi,2));
	   if(clstEE->energy() <= minEnergy || gEta <= 1.7 || gEta >= 2.8 || clstEE->eta() <= 1.5 || clstEE->eta() >= 3.0 || deltaR > 5) continue;  //for analysis of fixed pT variable eta events
	   //if(clstEE->energy() <= minEnergy) continue;  //for analysis of fixed E and eta, 0 PU events 
	   //now get the PFRecHitFraction objects associated with the PFCluster
	   const std::vector<reco::PFRecHitFraction> EEPFRecHitFractions = clstEE->recHitFractions();
	   for(unsigned int i=0; i< EEPFRecHitFractions.size() ; i++){
		   //loop over PFRecHitFraction objects associated with the PFCluster, and add PFRecHit energy to 54 element array of floats and totalCaloRecHitEnergy var

		   for(unsigned int k=0; k< 54; k++){
			   if( ((EEPFRecHitFractions[i].recHitRef())->position()).Z() <= HGCLayerBoundaries[k] ){
				   //look at layer 0, then work way up towards layer 54
				   //apply energy reweighting factor here which depends on the layer to which the rechit belongs
				   double tempEn = ( ( EEPFRecHitFractions[i].fraction() )*(EEPFRecHitFractions[i].recHitRef())->energy());
				   double tempEta = (EEPFRecHitFractions[i].recHitRef())->position().eta();
				   caloRecHitEnergyVsLayer[k] += calibrateRecHitEnergy(tempEta, tempEn, reWeightingFactors[k], MipsToGeV_EE, EEInverseMipToGeVCorrection);
				   totalCaloRecHitEnergy += calibrateRecHitEnergy(tempEta, tempEn, reWeightingFactors[k], MipsToGeV_EE, EEInverseMipToGeVCorrection);
				   break;
			   }
		   }//loop over layers of HGC 

	   }//loop over PFRecHitFraction objects

   }//loop over HGCEE PFClusters

   //std::cout<<"about to analyze HEF PFClusters"<<std::endl;
   
   for(std::vector<reco::PFCluster>::const_iterator clstHEF=PFClustersHEF->begin(); clstHEF != PFClustersHEF->end(); clstHEF++){
	   double deltaEta = (clstHEF->eta() - gEta);
	   double deltaPhi = (clstHEF->phi() - gPhi);
	   double deltaR = TMath::Sqrt(TMath::Power(deltaEta,2)+TMath::Power(deltaPhi,2));
	   if(clstHEF->energy() <= minEnergy || gEta <= 1.7 || gEta >= 2.8 || clstHEF->eta() <= 1.5 || clstHEF->eta() >= 3.0 || deltaR > 5) continue;
	   //if(clstHEF->energy() <= minEnergy) continue;  //for analysis of fixed E and eta, 0 PU events
	   //now get the PFRecHitFraction objects associated with the PFCluster
	   const std::vector<reco::PFRecHitFraction> HEFPFRecHitFractions = clstHEF->recHitFractions();
	   for(unsigned int i=0; i< HEFPFRecHitFractions.size() ; i++){
		   //loop over PFRecHitFraction objects associated with the PFCluster, and add PFRecHit energy to 54 element array of floats and totalCaloRecHitEnergy var

		   for(unsigned int k=0; k< 54; k++){
			   if( ((HEFPFRecHitFractions[i].recHitRef())->position()).Z() <= HGCLayerBoundaries[k] ){
				   //look at layer 0, then work way up towards layer 54
				   //apply energy reweighting factor here which depends on the layer to which the rechit belongs
				   double tempEn = ( ( HEFPFRecHitFractions[i].fraction() )*(HEFPFRecHitFractions[i].recHitRef())->energy());
				   double tempEta = (HEFPFRecHitFractions[i].recHitRef())->position().eta();
				   caloRecHitEnergyVsLayer[k] += calibrateRecHitEnergy(tempEta, tempEn, reWeightingFactors[k], MipsToGeV_HEF, HEFInverseMipToGeVCorrection);
				   totalCaloRecHitEnergy += calibrateRecHitEnergy(tempEta, tempEn, reWeightingFactors[k], MipsToGeV_HEF, HEFInverseMipToGeVCorrection);
	
				   break;
			   }
		   }//loop over layers of HGC 

	   }//loop over PFRecHitFraction objects

   }//loop over HGCHEF PFClusters

   for(std::vector<reco::PFCluster>::const_iterator clstHEB=PFClustersHEB->begin(); clstHEB != PFClustersHEB->end(); clstHEB++){
	   double deltaEta = (clstHEB->eta() - gEta);
	   double deltaPhi = (clstHEB->phi() - gPhi);
	   double deltaR = TMath::Sqrt(TMath::Power(deltaEta,2)+TMath::Power(deltaPhi,2));
	   if(clstHEB->energy() <= minEnergy || gEta <= 1.7 || gEta >= 2.8 || clstHEB->eta() <= 1.5 || clstHEB->eta() >= 3.0 || deltaR > 5) continue;
	   //if(clstHEB->energy() <= minEnergy) continue;  //for analysis of fixed E and eta, 0 PU events
	   //now get the PFRecHitFraction objects associated with the PFCluster
	   const std::vector<reco::PFRecHitFraction> HEBPFRecHitFractions = clstHEB->recHitFractions();
	   for(unsigned int i=0; i< HEBPFRecHitFractions.size() ; i++){
		   //loop over PFRecHitFraction objects associated with the PFCluster, and add PFRecHit energy to 54 element array of floats and totalCaloRecHitEnergy var

		   for(unsigned int k=0; k< 54; k++){
			   if( ((HEBPFRecHitFractions[i].recHitRef())->position()).Z() <= HGCLayerBoundaries[k] ){
				   //look at layer 0, then work way up towards layer 54
				   double tempEn = ( ( HEBPFRecHitFractions[i].fraction() )*(HEBPFRecHitFractions[i].recHitRef())->energy());
				   double tempEta = (HEBPFRecHitFractions[i].recHitRef())->position().eta();
				   caloRecHitEnergyVsLayer[k] += calibrateRecHitEnergy(tempEta, tempEn, reWeightingFactors[k], MipsToGeV_HEB, HEBInverseMipToGeVCorrection);
				   totalCaloRecHitEnergy += calibrateRecHitEnergy(tempEta, tempEn, reWeightingFactors[k], MipsToGeV_HEB, HEBInverseMipToGeVCorrection);
	
//				   caloRecHitEnergyVsLayer[k] += ( ( HEBPFRecHitFractions[i].fraction() )*(HEBPFRecHitFractions[i].recHitRef())->energy())*reWeightingFactors[k];
//				   totalCaloRecHitEnergy += ( ( HEBPFRecHitFractions[i].fraction() )*(HEBPFRecHitFractions[i].recHitRef())->energy() )*reWeightingFactors[k];
				   break;
			   }
		   }//loop over layers of HGC 

	   }//loop over PFRecHitFraction objects

   }//loop over HGCHEB PFClusters

   //std::cout<<"total rechit energy equals "<< totalCaloRecHitEnergy << " GeV" <<std::endl;

   //fill("RecHitCalib", (totalCaloRecHitEnergy - gEn)/gEn);

   for(int i=0; i<54; i++){
	   //fill energyFrxnVsLayer vector 
	   energyFrxnVsLayer[i] += (caloRecHitEnergyVsLayer[i]/totalCaloRecHitEnergy);
	   //std::cout<<"energyFrxnVsLayer element # "<<i<<" contains "<<energyFrxnVsLayer[i]<<std::endl;
   }

   while(finalEnergyFrxns.size() < 54){
	   finalEnergyFrxns.push_back(0.0);
	   finalEnergyFrxnBinNums.push_back(0.0); 
   }


   bool allEmpty=true;
   for(int j=1; j<= getXBins("EnergyFrxnVsLambda") ; j++){
	   if(get1DBinContents("EnergyFrxnVsLambda",j) != 0){
		   allEmpty = false;
		   break;
	   }
   }
   
   if(allEmpty){
	   //if EnergyFrxnVsLambda is empty, then set the bin contents equal to energyFrxnVsLayer
	   for(int j=0;j<54;j++){ //loop over entries of HGCLambdaBoundaries
		   
		   for(int i=1;i<=getXBins("EnergyFrxnVsLambda"); i++){

	
			   //std::cout<<"HGCLambdaBoundaries element # "<<j<<" contains "<< HGCLambdaBoundaries[j] <<std::endl;
			   //std::cout<<"get1DUpperBinEdge(EnergyFrxnVsLambda,i) returns "<< get1DUpperBinEdge("EnergyFrxnVsLambda",i) <<std::endl;
			   if(HGCLambdaBoundaries[j] <=  get1DUpperBinEdge("EnergyFrxnVsLambda",i) ){
				   set1DBinContents("EnergyFrxnVsLambda",i,energyFrxnVsLayer[j]);
				   finalEnergyFrxns[j] = energyFrxnVsLayer[j];
				   finalEnergyFrxnBinNums[j] = i;
				   break; //breaks out of loop over EnergyFrxnVsLambda bins
			   }

		   }//end loop over EnergyFrxnVsLambda bins

	   }//end loop over HGCLambdaBoundaries elements 

   }

   if(!allEmpty){
	   for(int j=0; j<54;j++){
		   //loop over all elements of finalEnergyFrxns[]
		   for(int i=1; i<=getXBins("EnergyFrxnVsLambda");i++){
			   //loop over all bins of EnergyFrxnVsLambda histo
			   if(get1DBinContents("EnergyFrxnVsLambda",i) > 0){
				   double temp = ( (finalEnergyFrxns[j] + get1DBinContents("EnergyFrxnVsLambda",i) )/2);
				   finalEnergyFrxns[j] = temp;
			   }//end if(bin contents > 0)

		   }//end loop over all bins of EnergyFrxnVsLambda histo

	   }//end loop over all elements of finalEnergyFrxns[]

   }//end if(!allEmpty)

   //now set EnergyFrxnVsLambda bin contents to 0
   for(int i=1; i<=getXBins("EnergyFrxnVsLambda");i++){
	   set1DBinContents("EnergyFrxnVsLambda",i,0);
   }


   energyFrxnVsLayer.clear();
   caloRecHitEnergyVsLayer.clear();
   totalCaloRecHitEnergy = 0;

   */



   double zeroExact = 0.0;

   //this code prints out the numerical values needed to make plots of energy and pT resolution and linearity 
   for(unsigned int i=0; i< binList.size() ; i++){
	   int m = i+1;

	   if(gEn >= binVals[i] && gEn <= binVals[m]){
 
		   // USE THIS for fixed energy and eta chgd pion gun samples
		   /**/
		   if(gEta < 1.52){
			   std::cout<<"KEEP NO ETABIN_"<< 0 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalCaloEnergy - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP PT ETABIN_"<< 0 << " EGENBIN_" << i << " " << gPt <<" "<< ( (totalCaloPt - gPt )/gPt) <<std::endl;

			   //std::cout<<"KEEP YES ETABIN_"<< 0 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalTrackAndCaloEnergy  - gEn )/gEn) <<std::endl;

		   }

		   /**/
		   if(gEta > 1.52 && gEta < 1.63){
			   std::cout<<"KEEP NO ETABIN_"<< 1 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalCaloEnergy - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP PT ETABIN_"<< 1 << " EGENBIN_" << i << " " << gPt <<" "<< ( (totalCaloPt - gPt )/gPt) <<std::endl;
			   fill("ChgdPiAnyE_1", gEn);
			   if(totalCaloEnergy > zeroExact) fill("ChgdPiSomeE_1", gEn);

			   //std::cout<<"KEEP YES ETABIN_"<< 1 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalTrackAndCaloEnergy - gEn )/gEn) <<std::endl;

		   }

		   if(gEta > 1.63 && gEta < 1.93){
			   std::cout<<"KEEP NO ETABIN_"<< 2 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalCaloEnergy - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP PT ETABIN_"<< 2 << " EGENBIN_" << i << " " << gPt <<" "<< ( (totalCaloPt - gPt )/gPt) <<std::endl;
			   fill("ChgdPiAnyE_2", gEn);
			   if(totalCaloEnergy > zeroExact) fill("ChgdPiSomeE_2", gEn);



			   //std::cout<<"KEEP YES ETABIN_"<< 2 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalTrackAndCaloEnergy - gEn )/gEn) <<std::endl;

		   }

		   if(gEta > 1.93 && gEta < 2.23){
			   std::cout<<"KEEP NO ETABIN_"<< 3 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalCaloEnergy - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP PT ETABIN_"<< 3 << " EGENBIN_" << i << " " << gPt <<" "<< ( (totalCaloPt - gPt )/gPt) <<std::endl;
			   fill("ChgdPiAnyE_3", gEn);
			   if(totalCaloEnergy > zeroExact) fill("ChgdPiSomeE_3", gEn);


			   //std::cout<<"KEEP YES ETABIN_"<< 3 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalTrackAndCaloEnergy - gEn )/gEn) <<std::endl;

		   }

		   if(gEta > 2.23 && gEta < 2.53){
			   std::cout<<"KEEP NO ETABIN_"<< 4 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalCaloEnergy - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP PT ETABIN_"<< 4 << " EGENBIN_" << i << " " << gPt <<" "<< ( (totalCaloPt - gPt )/gPt) <<std::endl;
			   fill("ChgdPiAnyE_4", gEn);
			   if(totalCaloEnergy > zeroExact) fill("ChgdPiSomeE_4", gEn);


			   //std::cout<<"KEEP YES ETABIN_"<< 4 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalTrackAndCaloEnergy - gEn )/gEn) <<std::endl;

		   }

		   if(gEta > 2.53 && gEta < 2.83){
			   std::cout<<"KEEP NO ETABIN_"<< 5 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalCaloEnergy - gEn )/gEn) <<std::endl;
			   std::cout<<"KEEP PT ETABIN_"<< 5 << " EGENBIN_" << i << " " << gPt <<" "<< ( (totalCaloPt - gPt )/gPt) <<std::endl;
			   fill("ChgdPiAnyE_5", gEn);
			   if(totalCaloEnergy > zeroExact) fill("ChgdPiSomeE_5", gEn);


			   //std::cout<<"KEEP YES ETABIN_"<< 5 << " EGENBIN_" << i << " " << gEn <<" "<< ( (totalTrackAndCaloEnergy - gEn )/gEn) <<std::endl;

		   }
		   /**/

		   break;	//leave for loop over unsigned int i
	   }//end if(gEn)

   }//end for(i)





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
singleHadEvsLayerStudy::beginJob()
{

}

// ------------ method called once each job just after ending the event loop  ------------
void 
singleHadEvsLayerStudy::endJob() 
{

	/*
	for(unsigned int j=0; j<finalEnergyFrxns.size();j++){
		//std::cout<<"finalEnergyFrxnBinNums element # "<<j<<" equals "<< finalEnergyFrxnBinNums[j] <<std::endl;
		//std::cout<<"finalEnergyFrxns element # "<<j<<" equals "<< finalEnergyFrxns[j] <<std::endl;
		set1DBinContents("FinalEnergyFrxnVsLambda", finalEnergyFrxnBinNums[j], finalEnergyFrxns[j]);
	}
	*/

	/*
	for(int e=0; e<getXBins("All_PFRecHit_z") ; e++){
		if(get1DBinContents("All_PFRecHit_z",e) > 0.0 ){
			std::cout<< get1DUpperBinEdge("All_PFRecHit_z",e) << std::endl;
		}

	}
	*/



	///////////////////////////////////////////////////////
	//code to make charged pion reconstruction efficiency plots
	//execute the same set of code 5 times for 5 different gen eta values
	/**/
	std::vector<std::string> etaBins;
	etaBins.push_back("1");
	etaBins.push_back("2");
	etaBins.push_back("3");
	etaBins.push_back("4");
	etaBins.push_back("5");

	for(unsigned int g=0; g<etaBins.size() ; g++){
		//code that determines the pi+ reco efficiency for events with one particular gen eta value, like 1.6 or 1.9 (approx)
		std::vector<int> genEnergyBins;		//tracks the gen energy bins with nonzero bin contents in ChgdPiSomeE and ChgdPiAnyE
		std::vector<double> someE;			//ith entry in this vector corresponds to the ith element in genEnergyBins
		std::vector<double> anyE;			//ith entry in this vector corresponds to the ith element in genEnergyBins

		double zero = 0.0;
		std::string anyEHistoName = "ChgdPiAnyE_"+etaBins[g];
		std::cout<<"anyEHistoName contains "<< anyEHistoName << std::endl;
		std::string someEHistoName = "ChgdPiSomeE_"+etaBins[g];
		int numBinsX = getXBins(anyEHistoName);
		for(int n=1; n <= numBinsX; n++){
			//loop over all x axis bins, which correspond to the generator pi+ energy in each event
			//find bins with at least 1 entry in "ChgdPiAnyE_NUM", and save the bin content to the appropriate vector

			if( get1DBinContents(anyEHistoName, n) > zero ){
				genEnergyBins.push_back(n);

				//for any element i anyE[i] >= someE[i]
				anyE.push_back( get1DBinContents(anyEHistoName, n) );
				someE.push_back( get1DBinContents(someEHistoName, n) );
			}

		}//end loop over bins in ChgdPiAnyE_NUM

		std::string chgdPiEnEffHistoName = "ChgdPiEnEfficiency_"+etaBins[g];
		std::cout<<"chgdPiEnEffHistoName contains "<< chgdPiEnEffHistoName << std::endl;
		for(unsigned int j=0; j< genEnergyBins.size() ; j++){
			//loop over all elements in genEnergyBins, set ChgdPiEnEfficiency_NUM bin contents
			double recoEnEff = ( someE[j]/anyE[j] );
			set1DBinContents(chgdPiEnEffHistoName, genEnergyBins[j], recoEnEff);

		}//end loop over elements in genEnergyBins vector 

		anyE.clear();
		someE.clear();
		genEnergyBins.clear();

	}//end loop over etaBins
	/**/






	//makeAndSaveSingle3DHisto("#Delta #eta and #Delta #phi between PFCandidate objects and gen pi+ objects as fxn of PFCandidate energy; #Delta #phi (rad); #Delta #eta; PFCand energy (GeV)","chgdPi_pT50_NoPU_deltaR_btwn_PFCand_and_gen_chgd_pion_vs_PFCand_energy","24","","PFCandidate_deltaR_energy", false);


	/*
	makeAndSaveSingle3DHisto("#Delta #eta and #Delta #phi between EE PFClusters and generator pi+ as fxn of PFCluster energy;#Delta #phi (rad); #Delta #eta; PFCluster energy (GeV)","chgdPi_pT50_NoPU_deltaR_btwn_EEPFClust_and_gen_chgd_pion_vs_EEPFClust_energy","31","","EEPFCluster_deltaR_energy", false);
   
	makeAndSaveSingle3DHisto("#Delta #eta and #Delta #phi between HEF PFClusters and generator pi+ as fxn of PFCluster energy;#Delta #phi (rad); #Delta #eta; PFCluster energy (GeV)","chgdPi_pT50_NoPU_deltaR_btwn_HEFPFClust_and_gen_chgd_pion_vs_HEFPFClust_energy","32","","HEFPFCluster_deltaR_energy", false);

	makeAndSaveSingle3DHisto("#Delta #eta and #Delta #phi between HEB PFClusters and generator pi+ as fxn of PFCluster energy;#Delta #phi (rad); #Delta #eta; PFCluster energy (GeV)","chgdPi_pT50_NoPU_deltaR_btwn_HEBPFClust_and_gen_chgd_pion_vs_HEBPFClust_energy","33","","HEBPFCluster_deltaR_energy", false);
 
	makeAndSaveSingle3DHisto("#Delta #eta and #Delta #phi between highest energy EE PFClusters and generator pi+ as fxn of PFCluster energy;#Delta #phi (rad); #Delta #eta; PFCluster energy (GeV)","chgdPi_pT50_NoPU_deltaR_btwn_max_energy_EEPFClust_and_gen_chgd_pion_vs_EEPFClust_energy","34","","MaxEEPFCluster_deltaR_energy", false);
   
	makeAndSaveSingle3DHisto("#Delta #eta and #Delta #phi between highest energy HEF PFClusters and generator pi+ as fxn of PFCluster energy;#Delta #phi (rad); #Delta #eta; PFCluster energy (GeV)","chgdPi_pT50_NoPU_deltaR_btwn_max_energy_HEFPFClust_and_gen_chgd_pion_vs_HEFPFClust_energy","35","","MaxHEFPFCluster_deltaR_energy", false);

	makeAndSaveSingle3DHisto("#Delta #eta and #Delta #phi between highest energy HEB PFClusters and generator pi+ as fxn of PFCluster energy;#Delta #phi (rad); #Delta #eta; PFCluster energy (GeV)","chgdPi_pT50_NoPU_deltaR_btwn_max_energy_HEBPFClust_and_gen_chgd_pion_vs_HEBPFClust_energy","36","","MaxHEBPFCluster_deltaR_energy", false);
	*/
 


}

// ------------ method called when starting to processes a run  ------------
/*
void 
singleHadEvsLayerStudy::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
singleHadEvsLayerStudy::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
singleHadEvsLayerStudy::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
singleHadEvsLayerStudy::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
singleHadEvsLayerStudy::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(singleHadEvsLayerStudy);
