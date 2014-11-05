#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <TMath.h>
#include <TVector.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TF1.h>
#include <TString.h>
#include <TPaveText.h>
#include <TStyle.h>



//std::cout<<"about to initialize RooDataSet * dataSet"<<std::endl;
RooDataSet* dataSet(0);
gSystem->Load("libRooFit") ;
using namespace RooFit;


void forNeutralKaons_EnergyResolutionFit() 
{        

  unsigned int numEnergyBins = 9;
  float Energymin=0.0,Energymax=1100.0;  
  float deltaEmin=-1.0,deltaEmax=1.0; 

  std::string inputFileDir = "energyResoMacroInputFiles/";
  std::string partialNoTrackInputFileName = "refinedNoTrackNeutralKLongGun_EGenBin";

  //vectors for resolution curves
  TVectorT<float> withoutTrackerFitSigmasFirstEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitSigmaErrorsFirstEtaBin(numEnergyBins);

  TVectorT<float> withoutTrackerFitSigmasSecondEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitSigmaErrorsSecondEtaBin(numEnergyBins);
  
  TVectorT<float> withoutTrackerFitSigmasThirdEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitSigmaErrorsThirdEtaBin(numEnergyBins);
  
  TVectorT<float> withoutTrackerFitSigmasFourthEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitSigmaErrorsFourthEtaBin(numEnergyBins);
   
  TVectorT<float> withoutTrackerFitSigmasFifthEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitSigmaErrorsFifthEtaBin(numEnergyBins);

  //vectors for linearity plot
  TVectorT<float> withoutTrackerFitMeansFirstEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitMeanErrorsFirstEtaBin(numEnergyBins);

  TVectorT<float> withoutTrackerFitMeansSecondEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitMeanErrorsSecondEtaBin(numEnergyBins);
  
  TVectorT<float> withoutTrackerFitMeansThirdEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitMeanErrorsThirdEtaBin(numEnergyBins);
  
  TVectorT<float> withoutTrackerFitMeansFourthEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitMeanErrorsFourthEtaBin(numEnergyBins);
   
  TVectorT<float> withoutTrackerFitMeansFifthEtaBin(numEnergyBins);
  TVectorT<float> withoutTrackerFitMeanErrorsFifthEtaBin(numEnergyBins);



  std::string outputPlotDir = "plotsFromEnergyResoFit/";
  std::string partialNoTrackESpreadOutputPlotName = "EnergySpread_NoTrack";
  std::string partialNoTrackGenEnergyOutput = "GenEnergy_NoTrack_EGenBin";

  std::vector<std::string> etaVals;
  etaVals.push_back("1.5");
  etaVals.push_back("1.75");
  etaVals.push_back("2");
  etaVals.push_back("2.25");
  etaVals.push_back("2.5");
  etaVals.push_back("2.9");

  std::vector<std::string> etaBins;
  etaBins.push_back("0");
  etaBins.push_back("1");
  etaBins.push_back("2");
  etaBins.push_back("3");
  etaBins.push_back("4");
  etaBins.push_back("5");

  std::vector<std::string> genEnergyBins;
  genEnergyBins.push_back("0");
  genEnergyBins.push_back("1");
  genEnergyBins.push_back("2");
  genEnergyBins.push_back("3");
  genEnergyBins.push_back("4");
  genEnergyBins.push_back("5");
  genEnergyBins.push_back("6");
  genEnergyBins.push_back("7");
  genEnergyBins.push_back("8");

  std::vector<std::string> genEnergyVals;
  genEnergyVals.push_back("2GeV");
  genEnergyVals.push_back("5GeV");
  genEnergyVals.push_back("10GeV");
  genEnergyVals.push_back("20GeV");
  genEnergyVals.push_back("40GeV");
  genEnergyVals.push_back("100GeV");
  genEnergyVals.push_back("200GeV");
  genEnergyVals.push_back("500GeV");
  genEnergyVals.push_back("1000GeV");


  std::string deltaEBeginning = "deltaE", eleEnergyBeginning = "eleEnergy", meanDeltaEBeginning = "meanDeltaE/genE", sigmaDeltaEBeginning = "sigmaDeltaE/genE", nMuMuXBeginning = "nMuMuX", alphaMuMuXBeginning = "alphaMuMuX", pdfX1Beginning = "pdfX1", nCanddidateBeginning = "nCanddidate", extendpdf1Beginning = "extendpdf1", totalPdfBeginning = "totPdf";
  //std::string c1Beginning = "c1", c2Beginning = "c2", BkgXPdfBeginning = "BkgXpdf";

  for(unsigned int j=1; j<6; j++){

	  //TCanvas * cEnergySpreads = new TCanvas("cES","cES",1600,1100);
	  //cEnergySpreads.Divide(3,3);

	  for(unsigned int i=1; i<numEnergyBins; i++){

		  std::string deltaEName = deltaEBeginning + genEnergyBins[i];
		  std::string eleEName = eleEnergyBeginning + genEnergyBins[i];
		  std::string meanDeltaEName = meanDeltaEBeginning + genEnergyBins[i];
		  std::string sigmaDeltaEName = sigmaDeltaEBeginning + genEnergyBins[i];
		  std::string nMuMuXName = nMuMuXBeginning + genEnergyBins[i];
		  std::string alphaMuMuXName = alphaMuMuXBeginning + genEnergyBins[i];
		  std::string pdfX1Name = pdfX1Beginning + genEnergyBins[i];
		  //std::string c1Name = c1Beginning + genEnergyBins[i];
		  //std::string c2Name = c2Beginning + genEnergyBins[i];
		  //std::string BkgXPdfName = BkgXPdfBeginning + genEnergyBins[i];
		  std::string nCanddidateName = nCanddidateBeginning + genEnergyBins[i];
		  std::string extendpdf1Name = extendpdf1Beginning + genEnergyBins[i];
		  std::string totalPdfName = totalPdfBeginning + genEnergyBins[i];


		  //std::cout<<"about to declare a RooRealVar object called deltaE"<<std::endl;
		  RooRealVar deltaE(deltaEName.c_str(), "#Delta E/gen E ", deltaEmin,  deltaEmax) ;
		  RooRealVar eleEnergy(eleEName.c_str(), "neutral K long generator E GeV", Energymin,  Energymax) ;


		  //////////////////Double Gaussian X////////////////////////////////
		  //RooRealVar meanDeltaE ("meanDeltaE" ,"meanDeltaE"  , 0,-5, 5 );

		  Double_t initialMeanDeltaEGuess = -0.1;
		  Double_t initialSigmaDeltaEGuess = 0.8;


		  RooRealVar meanDeltaE (meanDeltaEName.c_str(), meanDeltaEName.c_str(), initialMeanDeltaEGuess, -0.9, 0.4);
		  RooRealVar sigmaDeltaE (sigmaDeltaEName.c_str(), sigmaDeltaEName.c_str(),initialSigmaDeltaEGuess, 0.001, 1.5);
		  //RooAbsPdf* pdfX1 = new RooGaussian( pdfX1Name.c_str(),"", deltaE , meanDeltaE, sigmaDeltaE);

		  Double_t initialAlphaMuMuGuess = -0.8;
		  Double_t initialNMuMuGuess = 1.;
		  Double_t maxNMuMuVal = 25.0;

		  //RooAbsPdf* pdfX1;
		  RooAbsPdf* pdfX1 = new RooGaussian( pdfX1Name.c_str(),"", deltaE , meanDeltaE, sigmaDeltaE);
		  RooRealVar nMuMuX(nMuMuXName.c_str(),"",initialNMuMuGuess,0.0,maxNMuMuVal);
		  RooRealVar alphaMuMuX(alphaMuMuXName.c_str(),"",initialAlphaMuMuGuess,-2.5,0.);
		  //ORIGINAL RooAbsPdf *pdfX1 = new RooCBShape(pdfX1Name.c_str(),"",deltaE,meanDeltaE,sigmaDeltaE,nMuMuX,alphaMuMuX);
		  //RooAbsPdf *pdfX1 = new RooCBShape(pdfX1Name.c_str(),"",deltaE,meanDeltaE,sigmaDeltaE,alphaMuMuX,nMuMuX);
		  ////////////////////////////////////////////////////////////////////////////


		  //std::cout<<"about to declare a RooRealVar called c1"<<std::endl;
		  ///////////////////////Chebishyev Bkg Polynomial for X//////////////////////
		  //RooRealVar c1(c1Name.c_str(), c1Name.c_str(),-2.30439e-01,  -1.0, 1.0); //org
		  //RooRealVar c2(c2Name.c_str(), c2Name.c_str(),2.90495e-01 ,  -1.0, 1.0); //org
		  //RooAbsPdf *  BkgXPdf = new RooChebychev(BkgXPdfName.c_str(), BkgXPdfName.c_str(),deltaE,RooArgSet(c1,c2));
		  ///////////////////////////////////////////////////////////////////////////


		  //////////////////// Composite Pdfs ////////////////////////////////////////
		  //RooAbsPdf* pdf1 = new RooProdPdf( "pdf1", "pdf1", *pdfX1, *pdfY1 ) ;  
		  //RooAbsPdf* pdf2 = new RooProdPdf( "pdf2", "pdf2", *BkgXPdf, *pdfY1 ) ;
		  //RooAbsPdf* pdf3 = new RooProdPdf( "pdf3", "pdf3", *pdfX1, *BkgYPdf ) ;


		  RooRealVar nCanddidate(nCanddidateName.c_str(), "Number of signal 1 candidates ", 100,  0.0, 5000.0); 

		  RooExtendPdf *  extendpdf1 = new RooExtendPdf(extendpdf1Name.c_str(),"Signal 1 PDF",*pdfX1, nCanddidate);

		  RooAddPdf totalPdf(totalPdfName.c_str(), totalPdfName.c_str(), RooArgList(*extendpdf1 ), RooArgList(nCanddidate) ) ;


		  //make the complete no track input file name (with path)
		  std::string completeNoTrackInputFileName = inputFileDir + partialNoTrackInputFileName + genEnergyBins[i] + "_EtaBin" + etaBins[j] + "_FixedEAndEta.txt";

		  //std::string completeWithTrackInputFileName = inputFileDir + partialWithTrackInputFileName + genEnergyBins[i] + "_EtaBin" + etaBins[j] + "_FixedEAndEta.txt"; 
		  //std::cout<<"about to declare a pointer to the input .txt file"<<std::endl;
		  RooDataSet * dataSet= &(RooDataSet::read(completeNoTrackInputFileName.c_str(), RooArgSet(eleEnergy,deltaE),"Q"));
		  //RooDataSet * dataSet= &(RooDataSet::read(completeWithTrackInputFileName.c_str(), RooArgSet(eleEnergy,deltaE),"Q"));


		  //std::cout<<"about to fit a crystal ball function to the delta E data points"<<std::endl;
		  //RooFitResult * myfitresult=totalPdf.fitTo(*dataSet,"mer",Range(deltaEmin,deltaEmax) );	//constrains the range of the fit 

		  RooFitResult * myfitresult;
		  
		  if(j != 5){

			  if(i==1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.9,0.1));
			  } 

			  if(i==2){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.9,0.1));
			  } 

			  if(i==3 && j==1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.7,-0.05));
			  } 

			  if(i==3 && j==2 ){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.65,0.));
			  } 

			  if(i==3 && j==3 ){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.7,0.));
			  } 

			  if(i==3 && j==4 ){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.7,-0.05));
			  } 

			  if(i==4 && j==1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.5,0.05));
			  } 

			  if(i==4 && j==2){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.55,0.));
			  } 

			  if(i==4 && j==3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.6,0.05));
			  } 

			  if(i==4 && j==4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.6,0.));
			  } 

			  if(i==5 && j != 4 && j != 3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.45,0.05));
			  } 

			  if(i==5 && j==3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.45,0.05));
			  } 

			  if(i==5 && j==4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.5,0.05));
			  } 

			  if(i==6 && j != 3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.4,0.1));
			  } 

			  if(i==6 && j==3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.35,0.02));
			  } 

			  if(i==7 && j != 4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.3,0.1));
			  }
	
			  if(i==7 && j==4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.2,0.));
			  }
		  
			  if(i==8 && j != 4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.2,0.05));
			  }
		  
			  if(i==8 && j==4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.2,0.));
			  }

		  }

		  if(j==5){

			  //don't worry about i=1 (gen E=5 GeV) or 2 (gen E=10 GeV)
			  //i=3 needs more stats
	
			  if(i==1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.85,0.1));
			  } 

			  if(i==2){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.8,0.2));
			  } 

			  if(i==3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.9,0.4));
			  } 

			  if(i==4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.7,-0.05));
			  } 

			  if(i==5){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.5,-0.1));
			  } 

			  if(i==6){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.45,-0.05));
			  } 

			  if(i==7){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.35,-0.07));
			  } 

			  if(i==8){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.3,-0.07));
			  }

		  }


		  Double_t fitSigma = sigmaDeltaE.getVal();
		  Double_t fitSigmaError = sigmaDeltaE.getError();

		  Double_t fitMean = meanDeltaE.getVal();
		  Double_t fitMeanError = meanDeltaE.getError();

		  std::cout<<"fitSigma "<< fitSigma <<std::endl;
		  std::cout<<"fitSigmaError "<< fitSigmaError <<std::endl;
  
		  if(j==1){
			  withoutTrackerFitSigmasFirstEtaBin[i] += fitSigma;
			  withoutTrackerFitSigmaErrorsFirstEtaBin[i] += fitSigmaError;

			  withoutTrackerFitMeansFirstEtaBin[i] += fitMean;
			  withoutTrackerFitMeanErrorsFirstEtaBin[i] += fitMeanError;

		  }
  
		  if(j==2){
			  withoutTrackerFitSigmasSecondEtaBin[i] += fitSigma;
			  withoutTrackerFitSigmaErrorsSecondEtaBin[i] += fitSigmaError;

			  withoutTrackerFitMeansSecondEtaBin[i] += fitMean;
			  withoutTrackerFitMeanErrorsSecondEtaBin[i] += fitMeanError;

		  }

		  if(j==3){
			  withoutTrackerFitSigmasThirdEtaBin[i] += fitSigma;
			  withoutTrackerFitSigmaErrorsThirdEtaBin[i] += fitSigmaError;

			  withoutTrackerFitMeansThirdEtaBin[i] += fitMean;
			  withoutTrackerFitMeanErrorsThirdEtaBin[i] += fitMeanError;

		  }
 
		  if(j==4){
			  withoutTrackerFitSigmasFourthEtaBin[i] += fitSigma;
			  withoutTrackerFitSigmaErrorsFourthEtaBin[i] += fitSigmaError;

			  withoutTrackerFitMeansFourthEtaBin[i] += fitMean;
			  withoutTrackerFitMeanErrorsFourthEtaBin[i] += fitMeanError;

		  }
 
		  if(j==5){
			  withoutTrackerFitSigmasFifthEtaBin[i] += fitSigma;
			  withoutTrackerFitSigmaErrorsFifthEtaBin[i] += fitSigmaError;

			  withoutTrackerFitMeansFifthEtaBin[i] += fitMean;
			  withoutTrackerFitMeanErrorsFifthEtaBin[i] += fitMeanError;

		  }



		  /*
		  gROOT->SetStyle("Plain");

		  //std::string canvXName = "cx" + genEnergyBins[i];
		  std::string noTrackEnergySpreadTitle = "Neutral K_long E_reco - E_gen / E_gen  gen energy " + genEnergyVals[i] + " gen eta " + etaVals[j]; 
		  //TCanvas * cx=new TCanvas(canvXName.c_str(), canvXName.c_str(),800,600);
		  cEnergySpreads->cd(i);
		  RooPlot *frame = deltaE.frame(100);
		  frame->SetTitle(noTrackEnergySpreadTitle.c_str());
		  frame->GetXaxis()->SetTitleSize(0.04);
		  frame->GetXaxis()->SetTitleOffset(1.12);
		  frame->GetYaxis()->SetTitleSize(0.04);
		  frame->GetYaxis()->SetTitleOffset(1.15);
		  frame->GetYaxis()->SetLabelSize(0.035);
		  dataSet->plotOn(frame,Name("dataX"));
		  totalPdf.plotOn(frame);
		  totalPdf.paramOn(frame,Parameters(RooArgSet (meanDeltaE,sigmaDeltaE)));
		  frame->Draw();
		  */

		  /*
		  if(i== (numEnergyBins-1) ){
			  std::string completeNoTrackESpreadOutputFileName = outputPlotDir + partialNoTrackESpreadOutputPlotName + "_neutralKLong" + "_EtaBin" + etaBins[j] + ".gif";
			  cEnergySpreads->SaveAs(completeNoTrackESpreadOutputFileName.c_str(), "recreate");

		  }
		  */



		  /*
		  std::string canvYName = "cy" + genEnergyBins[i];
		  std::string noTrackGenEnergyTitle = "Energy of generator pi+  " + " gen eta " + etaVals[j];
		  TCanvas * cy=new TCanvas(canvYName.c_str(), canvYName.c_str(),800,600);
		  RooPlot *framey = eleEnergy.frame(50,250,200);
		  framey->SetTitle(noTrackGenEnergyTitle.c_str());
		  framey->GetXaxis()->SetTitleSize(0.04);
		  framey->GetXaxis()->SetTitleOffset(1.12);
		  framey->GetYaxis()->SetTitleSize(0.04);
		  framey->GetYaxis()->SetTitleOffset(1.15);
		  framey->GetYaxis()->SetLabelSize(0.035);
		  dataSet->plotOn(framey,Name("dataY"));
		  //totalPdf.plotOn(framey);
		  framey->Draw();

		  std::string noTrackGenE = outputPlotDir+partialNoTrackGenEnergyOutput+genEnergyBins[i] + "_EtaBin" + etaBins[j] + ".gif";
		  cy->SaveAs(noTrackGenE.c_str(), "recreate");
		  */

	  }

  }


  /**/
  TVectorT<float> genEnergyMeans(numEnergyBins);
  TVectorT<float> genEnergyMeanErrors(numEnergyBins);
  float genEngs[] = {2,5,10,20,40,100,200,500,1000};

  TVectorT<float> meanERecoFirstEtaBin(numEnergyBins);
  TVectorT<float> meanERecoErrorFirstEtaBin(numEnergyBins);
 
  TVectorT<float> meanERecoSecondEtaBin(numEnergyBins);
  TVectorT<float> meanERecoErrorSecondEtaBin(numEnergyBins);
 
  TVectorT<float> meanERecoThirdEtaBin(numEnergyBins);
  TVectorT<float> meanERecoErrorThirdEtaBin(numEnergyBins);
 
  TVectorT<float> meanERecoFourthEtaBin(numEnergyBins);
  TVectorT<float> meanERecoErrorFourthEtaBin(numEnergyBins);
 
  TVectorT<float> meanERecoFifthEtaBin(numEnergyBins);
  TVectorT<float> meanERecoErrorFifthEtaBin(numEnergyBins);
  
  float one = 1.0;
  
  for(unsigned int i=0; i<numEnergyBins ; i++){
	  genEnergyMeanErrors[i] += 0.0;
	  genEnergyMeans[i] += genEngs[i];

	  meanERecoFirstEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeansFirstEtaBin[i]+one);
	  meanERecoErrorFirstEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeanErrorsFirstEtaBin[i]);
	
	  meanERecoSecondEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeansSecondEtaBin[i]+one);
	  meanERecoErrorSecondEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeanErrorsSecondEtaBin[i]);
		
	  meanERecoThirdEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeansThirdEtaBin[i]+one);
	  meanERecoErrorThirdEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeanErrorsThirdEtaBin[i]);
		
	  meanERecoFourthEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeansFourthEtaBin[i]+one);
	  meanERecoErrorFourthEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeanErrorsFourthEtaBin[i]);
		
	  meanERecoFifthEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeansFifthEtaBin[i]+one);
	  meanERecoErrorFifthEtaBin[i] += (genEnergyMeans[i])*(withoutTrackerFitMeanErrorsFifthEtaBin[i]);
	
  }


  gStyle->SetOptFit(111);

  TCanvas * cFirst = new TCanvas("cFirst","cFirst",800,800);
  cFirst->cd();

  TF1 * fitToEtaBinOneResolution = new TF1("fitToEtaBinOneResolution","([0]/TMath::Sqrt(x))+[1]",19,501);
  TGraphErrors * neutralKLongEResoNoTrackFirstEtaBin = new TGraphErrors(genEnergyMeans, withoutTrackerFitSigmasFirstEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsFirstEtaBin);
  neutralKLongEResoNoTrackFirstEtaBin->SetTitle("K0L Energy Resolution #eta_{gen} = 1.75; E_{gen} (GeV);#sigma of #DeltaE/E");
  neutralKLongEResoNoTrackFirstEtaBin->SetFillStyle(0);
  neutralKLongEResoNoTrackFirstEtaBin->SetMarkerStyle(20);
  neutralKLongEResoNoTrackFirstEtaBin->SetMarkerColor(1);
  neutralKLongEResoNoTrackFirstEtaBin->SetMarkerSize(1.5);
  neutralKLongEResoNoTrackFirstEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackFirstEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackFirstEtaBin->Fit("fitToEtaBinOneResolution","R");

  neutralKLongEResoNoTrackFirstEtaBin->Draw("AP");

  std::string outFirstGraphName = outputPlotDir + "neutralKLongEResoNoTrackFirstEtaBin.gif"; 
  cFirst->SaveAs(outFirstGraphName.c_str(),"recreate");


  TCanvas * cNine = new TCanvas("cNine","cNine",800,800);
  cNine->cd();
  cNine->SetLogx(1);
  cNine->SetLogy(1);
  
  TF1 * fitToEtaBinOneLinearity = new TF1("fitToEtaBinOneLinearity","[0]*x+[1]",19,501);
 
  TGraphErrors * neutralKLongELinearityNoTrackFirstEtaBin = new TGraphErrors(genEnergyMeans, meanERecoFirstEtaBin, genEnergyMeanErrors, meanERecoErrorFirstEtaBin);
  neutralKLongELinearityNoTrackFirstEtaBin->SetTitle("K0L Energy Linearity #eta_{gen} = 1.75; E_{gen} (GeV);E_{reco} (GEV)");
  neutralKLongELinearityNoTrackFirstEtaBin->SetFillStyle(0);
  neutralKLongELinearityNoTrackFirstEtaBin->SetMarkerStyle(20);
  neutralKLongELinearityNoTrackFirstEtaBin->SetMarkerColor(2);
  neutralKLongELinearityNoTrackFirstEtaBin->SetMarkerSize(1.5);
  neutralKLongELinearityNoTrackFirstEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackFirstEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackFirstEtaBin->Fit("fitToEtaBinOneLinearity","MR");

  neutralKLongELinearityNoTrackFirstEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "neutralKLongELinearityNoTrackFirstEtaBin.gif"; 
  cNine->SaveAs(outSecondGraphName.c_str(),"recreate");


 
  TCanvas * cSecond = new TCanvas("cSecond","cSecond",800,800);
  cSecond->cd();

  TF1 * fitToEtaBinTwoResolution = new TF1("fitToEtaBinTwoResolution","([0]/TMath::Sqrt(x))+[1]",19,1001);
 
  TGraphErrors * neutralKLongEResoNoTrackSecondEtaBin = new TGraphErrors(genEnergyMeans, withoutTrackerFitSigmasSecondEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsSecondEtaBin);
  neutralKLongEResoNoTrackSecondEtaBin->SetTitle("K0L Energy Resolution #eta_{gen} = 2.0; E_{gen} (GeV);#sigma of #DeltaE/E");
  neutralKLongEResoNoTrackSecondEtaBin->SetFillStyle(0);
  neutralKLongEResoNoTrackSecondEtaBin->SetMarkerStyle(20);
  neutralKLongEResoNoTrackSecondEtaBin->SetMarkerColor(2);
  neutralKLongEResoNoTrackSecondEtaBin->SetMarkerSize(1.5);
  neutralKLongEResoNoTrackSecondEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackSecondEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackSecondEtaBin->Fit("fitToEtaBinTwoResolution","MR");
 
  neutralKLongEResoNoTrackSecondEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "neutralKLongEResoNoTrackSecondEtaBin.gif"; 
  cSecond->SaveAs(outSecondGraphName.c_str(),"recreate");
 


  TCanvas * cTen = new TCanvas("cTen","cTen",800,800);
  cTen->cd();
  cTen->SetLogx(1);
  cTen->SetLogy(1);
  
  TF1 * fitToEtaBinTwoLinearity = new TF1("fitToEtaBinTwoLinearity","[0]*x+[1]",19,1001);
 
  TGraphErrors * neutralKLongELinearityNoTrackSecondEtaBin = new TGraphErrors(genEnergyMeans, meanERecoSecondEtaBin, genEnergyMeanErrors, meanERecoErrorSecondEtaBin);
  neutralKLongELinearityNoTrackSecondEtaBin->SetTitle("K0L Energy Linearity #eta_{gen} = 2.0; E_{gen} (GeV);E_{reco} (GEV)");
  neutralKLongELinearityNoTrackSecondEtaBin->SetFillStyle(0);
  neutralKLongELinearityNoTrackSecondEtaBin->SetMarkerStyle(20);
  neutralKLongELinearityNoTrackSecondEtaBin->SetMarkerColor(2);
  neutralKLongELinearityNoTrackSecondEtaBin->SetMarkerSize(1.5);
  neutralKLongELinearityNoTrackSecondEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackSecondEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackSecondEtaBin->Fit("fitToEtaBinTwoLinearity","MR");
 
  neutralKLongELinearityNoTrackSecondEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "neutralKLongELinearityNoTrackSecondEtaBin.gif"; 
  cTen->SaveAs(outSecondGraphName.c_str(),"recreate");



  TCanvas * cThird = new TCanvas("cThird","cThird",800,800);
  cThird->cd();

  TF1 * fitToEtaBinThreeResolution = new TF1("fitToEtaBinThreeResolution","([0]/TMath::Sqrt(x))+[1]",19,501);

  TGraphErrors * neutralKLongEResoNoTrackThirdEtaBin = new TGraphErrors(genEnergyMeans, withoutTrackerFitSigmasThirdEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsThirdEtaBin);
  neutralKLongEResoNoTrackThirdEtaBin->SetTitle("K0L Energy Resolution #eta_{gen} = 2.25; E_{gen} (GeV);#sigma of #DeltaE/E");
  neutralKLongEResoNoTrackThirdEtaBin->SetFillStyle(0);
  neutralKLongEResoNoTrackThirdEtaBin->SetMarkerStyle(20);
  neutralKLongEResoNoTrackThirdEtaBin->SetMarkerColor(4);
  neutralKLongEResoNoTrackThirdEtaBin->SetMarkerSize(1.5);
  neutralKLongEResoNoTrackThirdEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackThirdEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackThirdEtaBin->Fit("fitToEtaBinThreeResolution","R");
  
  neutralKLongEResoNoTrackThirdEtaBin->Draw("AP");

  std::string outThirdGraphName = outputPlotDir + "neutralKLongEResoNoTrackThirdEtaBin.gif"; 
  cThird->SaveAs(outThirdGraphName.c_str(),"recreate");


  TCanvas * cEleven = new TCanvas("cEleven","cEleven",800,800);
  cEleven->cd();
  cEleven->SetLogx(1);
  cEleven->SetLogy(1);
  
  TF1 * fitToEtaBinThreeLinearity = new TF1("fitToEtaBinThreeLinearity","[0]*x+[1]",19,501);
 
  TGraphErrors * neutralKLongELinearityNoTrackThirdEtaBin = new TGraphErrors(genEnergyMeans, meanERecoThirdEtaBin, genEnergyMeanErrors, meanERecoErrorThirdEtaBin);
  neutralKLongELinearityNoTrackThirdEtaBin->SetTitle("K0L Energy Linearity #eta_{gen} = 2.25; E_{gen} (GeV);E_{reco} (GEV)");
  neutralKLongELinearityNoTrackThirdEtaBin->SetFillStyle(0);
  neutralKLongELinearityNoTrackThirdEtaBin->SetMarkerStyle(20);
  neutralKLongELinearityNoTrackThirdEtaBin->SetMarkerColor(2);
  neutralKLongELinearityNoTrackThirdEtaBin->SetMarkerSize(1.5);
  neutralKLongELinearityNoTrackThirdEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackThirdEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackThirdEtaBin->Fit("fitToEtaBinThreeLinearity","MR");
 
  neutralKLongELinearityNoTrackThirdEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "neutralKLongELinearityNoTrackThirdEtaBin.gif"; 
  cEleven->SaveAs(outSecondGraphName.c_str(),"recreate");



  TCanvas * cFourth = new TCanvas("cFourth","cFourth",800,800);
  cFourth->cd();

  TF1 * fitToEtaBinFourResolution = new TF1("fitToEtaBinFourResolution","([0]/TMath::Sqrt(x))+[1]",19,1001);

  TGraphErrors * neutralKLongEResoNoTrackFourthEtaBin = new TGraphErrors(genEnergyMeans, withoutTrackerFitSigmasFourthEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsFourthEtaBin);
  neutralKLongEResoNoTrackFourthEtaBin->SetTitle("K0L Energy Resolution #eta_{gen} = 2.5; E_{gen} (GeV);#sigma of #DeltaE/E");
  neutralKLongEResoNoTrackFourthEtaBin->SetFillStyle(0);
  neutralKLongEResoNoTrackFourthEtaBin->SetMarkerStyle(20);
  neutralKLongEResoNoTrackFourthEtaBin->SetMarkerColor(8);
  neutralKLongEResoNoTrackFourthEtaBin->SetMarkerSize(1.5);
  neutralKLongEResoNoTrackFourthEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackFourthEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackFourthEtaBin->Fit("fitToEtaBinFourResolution","R");
 
  neutralKLongEResoNoTrackFourthEtaBin->Draw("AP");

  std::string outFourthGraphName = outputPlotDir + "neutralKLongEResoNoTrackFourthEtaBin.gif"; 
  cFourth->SaveAs(outFourthGraphName.c_str(),"recreate");


  TCanvas * cTwelve = new TCanvas("cTwelve","cTwelve",800,800);
  cTwelve->cd();
  cTwelve->SetLogx(1);
  cTwelve->SetLogy(1);
  
  TF1 * fitToEtaBinFourLinearity = new TF1("fitToEtaBinFourLinearity","[0]*x+[1]",19,1001);
 
  TGraphErrors * neutralKLongELinearityNoTrackFourthEtaBin = new TGraphErrors(genEnergyMeans, meanERecoFourthEtaBin, genEnergyMeanErrors, meanERecoErrorFourthEtaBin);
  neutralKLongELinearityNoTrackFourthEtaBin->SetTitle("K0L Energy Linearity #eta_{gen} = 2.5; E_{gen} (GeV);E_{reco} (GEV)");
  neutralKLongELinearityNoTrackFourthEtaBin->SetFillStyle(0);
  neutralKLongELinearityNoTrackFourthEtaBin->SetMarkerStyle(20);
  neutralKLongELinearityNoTrackFourthEtaBin->SetMarkerColor(2);
  neutralKLongELinearityNoTrackFourthEtaBin->SetMarkerSize(1.5);
  neutralKLongELinearityNoTrackFourthEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackFourthEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackFourthEtaBin->Fit("fitToEtaBinFourLinearity","MR");
 
  neutralKLongELinearityNoTrackFourthEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "neutralKLongELinearityNoTrackFourthEtaBin.gif"; 
  cTwelve->SaveAs(outSecondGraphName.c_str(),"recreate");




  TCanvas * cFifth = new TCanvas("cFifth","cFifth",800,800);
  cFifth->cd();

  TF1 * fitToEtaBinFiveResolution = new TF1("fitToEtaBinFiveResolution","([0]/TMath::Sqrt(x))+[1]",9,1001);

  TGraphErrors * neutralKLongEResoNoTrackFifthEtaBin = new TGraphErrors(genEnergyMeans, withoutTrackerFitSigmasFifthEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsFifthEtaBin);
  neutralKLongEResoNoTrackFifthEtaBin->SetTitle("K0L Energy Resolution #eta_{gen} = 2.9; E_{gen} (GeV);#sigma of #DeltaE/E");
  neutralKLongEResoNoTrackFifthEtaBin->SetFillStyle(0);
  neutralKLongEResoNoTrackFifthEtaBin->SetMarkerStyle(20);
  neutralKLongEResoNoTrackFifthEtaBin->SetMarkerColor(8);
  neutralKLongEResoNoTrackFifthEtaBin->SetMarkerSize(1.5);
  neutralKLongEResoNoTrackFifthEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackFifthEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongEResoNoTrackFifthEtaBin->Fit("fitToEtaBinFiveResolution","R");
 
  neutralKLongEResoNoTrackFifthEtaBin->Draw("AP");

  std::string outFifthGraphName = outputPlotDir + "neutralKLongEResoNoTrackFifthEtaBin.gif"; 
  cFifth->SaveAs(outFifthGraphName.c_str(),"recreate");


  TCanvas * cThirteen = new TCanvas("cThirteen","cThirteen",800,800);
  cThirteen->cd();
  cThirteen->SetLogx(1);
  cThirteen->SetLogy(1);
  
  TF1 * fitToEtaBinFiveLinearity = new TF1("fitToEtaBinFiveLinearity","[0]*x+[1]",9,1001);
 
  TGraphErrors * neutralKLongELinearityNoTrackFifthEtaBin = new TGraphErrors(genEnergyMeans, meanERecoFifthEtaBin, genEnergyMeanErrors, meanERecoErrorFifthEtaBin);
  neutralKLongELinearityNoTrackFifthEtaBin->SetTitle("K0L Energy Linearity #eta_{gen} = 2.9; E_{gen} (GeV);E_{reco} (GEV)");
  neutralKLongELinearityNoTrackFifthEtaBin->SetFillStyle(0);
  neutralKLongELinearityNoTrackFifthEtaBin->SetMarkerStyle(20);
  neutralKLongELinearityNoTrackFifthEtaBin->SetMarkerColor(2);
  neutralKLongELinearityNoTrackFifthEtaBin->SetMarkerSize(1.5);
  neutralKLongELinearityNoTrackFifthEtaBin->GetYaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackFifthEtaBin->GetXaxis()->SetTitleOffset(1.4);
  neutralKLongELinearityNoTrackFifthEtaBin->Fit("fitToEtaBinFiveLinearity","MR");
 
  neutralKLongELinearityNoTrackFifthEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "neutralKLongELinearityNoTrackFifthEtaBin.gif"; 
  cThirteen->SaveAs(outSecondGraphName.c_str(),"recreate");




  TCanvas * c3 = new TCanvas("c3","c3",800,800);
  c3->cd();

  TLegend * leg3 = new TLegend(0.65, 0.65, 1, 0.85);
  leg3->AddEntry( neutralKLongEResoNoTrackFifthEtaBin, "#eta_{gen} 2.9");
  //leg3->AddEntry( neutralKLongEResoNoTrackFourthEtaBin, "#eta_{gen} 2.5");
  leg3->AddEntry( neutralKLongEResoNoTrackThirdEtaBin, "#eta_{gen} 2.25");
  leg3->AddEntry( neutralKLongEResoNoTrackSecondEtaBin, "#eta_{gen} 2.0");
  leg3->AddEntry( neutralKLongEResoNoTrackFirstEtaBin, "#eta_{gen} 1.75");

  TMultiGraph * neutralKaonEnergyResolution = new TMultiGraph();
  neutralKaonEnergyResolution->SetTitle("K0L Energy Resolution; E_{gen} (GeV);#sigma of #DeltaE/E");
  neutralKaonEnergyResolution->Add(neutralKLongEResoNoTrackFifthEtaBin);
  //neutralKaonEnergyResolution->Add(neutralKLongEResoNoTrackFourthEtaBin);
  neutralKaonEnergyResolution->Add(neutralKLongEResoNoTrackThirdEtaBin);
  neutralKaonEnergyResolution->Add(neutralKLongEResoNoTrackSecondEtaBin);
  neutralKaonEnergyResolution->Add(neutralKLongEResoNoTrackFirstEtaBin);
  
  neutralKaonEnergyResolution->Draw("AP");
  leg3->Draw();

  std::string outMultiGraphName = outputPlotDir + "neutralKLongEnergyResolutionOverlayGraphs.gif";
  c3->SaveAs(outMultiGraphName.c_str(),"recreate");

  /**/


  
}

