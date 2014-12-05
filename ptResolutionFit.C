#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <TVector.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TCanvas.h>



//std::cout<<"about to initialize RooDataSet * dataSet"<<std::endl;
RooDataSet* dataSet(0);
gSystem->Load("libRooFit") ;
using namespace RooFit;


void ptResolutionFit() 
{        

  unsigned int numEnergyBins = 9;
  float Energymin=0.0,Energymax=600.0;  
  float deltaEmin=-1.0,deltaEmax=1.0; 

  std::string inputFileDir = "../ptResoMacroInputFiles/";
  std::string partialNoTrackInputFileName = "refinedNoTrackChgdPionGun_EGenBin";
  std::string partialWithTrackInputFileName = "refinedWithTrackChgdPionGun_EGenBin";

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



  std::string outputPlotDir = "../plotsFromPtResoFit/";
  std::string partialNoTrackESpreadOutputPlotName = "PtSpread_NoTrack";
  std::string partialNoTrackGenEnergyOutput = "GenPt_NoTrack_PtGenBin";

  std::vector<std::string> etaVals;
  etaVals.push_back("1.3");
  etaVals.push_back("1.6");
  etaVals.push_back("1.9");
  etaVals.push_back("2.2");
  etaVals.push_back("2.5");
  etaVals.push_back("2.8");

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
  genEnergyVals.push_back("10GeV");
  genEnergyVals.push_back("30GeV");
  genEnergyVals.push_back("50GeV");
  genEnergyVals.push_back("80GeV");
  genEnergyVals.push_back("100GeV");
  genEnergyVals.push_back("150GeV");
  genEnergyVals.push_back("200GeV");
  genEnergyVals.push_back("300GeV");
  genEnergyVals.push_back("500GeV");
  

  std::string deltaEBeginning = "deltaE", eleEnergyBeginning = "eleEnergy", meanDeltaEBeginning = "meanDeltaP_{T}/P_{T,gen}", sigmaDeltaEBeginning = "sigmaDeltaP_{T}/P_{T,gen}", nMuMuXBeginning = "nMuMuX", alphaMuMuXBeginning = "alphaMuMuX", pdfX1Beginning = "pdfX1", nCanddidateBeginning = "nCanddidate", extendpdf1Beginning = "extendpdf1", totalPdfBeginning = "totPdf";
  //std::string c1Beginning = "c1", c2Beginning = "c2", BkgXPdfBeginning = "BkgXpdf";

  for(unsigned int j=1; j<6; j++){

	  //TCanvas * cEnergySpreads = new TCanvas("cES","cES",1500,1100);
	  //cEnergySpreads.Divide(3,3,0.01,0.01);

	  for(unsigned int i=0; i<numEnergyBins; i++){

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
		  RooRealVar deltaE(deltaEName.c_str(), "#Delta p_{T}/gen p_{T} ", deltaEmin,  deltaEmax) ;
		  RooRealVar eleEnergy(eleEName.c_str(), "chgd pion generator p_{T} GeV", Energymin,  Energymax) ;


		  //////////////////Double Gaussian X////////////////////////////////
		  //RooRealVar meanDeltaE ("meanDeltaE" ,"meanDeltaE"  , 0,-5, 5 );

		  Double_t initialMeanDeltaEGuess = -0.2;	//original value was -0.1
		  Double_t initialSigmaDeltaEGuess = 0.8;


		  RooRealVar meanDeltaE (meanDeltaEName.c_str(), meanDeltaEName.c_str(), initialMeanDeltaEGuess, -0.9, 0.4);
		  RooRealVar sigmaDeltaE (sigmaDeltaEName.c_str(), sigmaDeltaEName.c_str(),initialSigmaDeltaEGuess, 0.001, 1.5);

		  /**/
		  Double_t initialAlphaMuMuGuess = -0.8;
		  Double_t initialNMuMuGuess = 1.;
		  Double_t maxNMuMuVal = 25.0;

		  RooAbsPdf* pdfX1;
		  //RooAbsPdf* pdfX1 = new RooGaussian( pdfX1Name.c_str(),"", deltaE , meanDeltaE, sigmaDeltaE);
		  RooRealVar nMuMuX(nMuMuXName.c_str(),"",initialNMuMuGuess,0.0,maxNMuMuVal);
		  RooRealVar alphaMuMuX(alphaMuMuXName.c_str(),"",initialAlphaMuMuGuess,-2.5,0.);
		  //ORIGINAL RooAbsPdf *pdfX1 = new RooCBShape(pdfX1Name.c_str(),"",deltaE,meanDeltaE,sigmaDeltaE,nMuMuX,alphaMuMuX);
		  //RooAbsPdf *pdfX1 = new RooCBShape(pdfX1Name.c_str(),"",deltaE,meanDeltaE,sigmaDeltaE,alphaMuMuX,nMuMuX);
		  ////////////////////////////////////////////////////////////////////////////

		  //events where genE = 10 appear to be good candidates for crystal ball fits with negative alpha
		  //events where genE >= 30 appear to be good candidates for gaussian fits

		  if(i==0){
			  pdfX1 = new RooCBShape(pdfX1Name.c_str(),"",deltaE,meanDeltaE,sigmaDeltaE,alphaMuMuX,nMuMuX);
		  }
		  else{
			  pdfX1 = new RooGaussian( pdfX1Name.c_str(),"", deltaE , meanDeltaE, sigmaDeltaE);
		  }

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
		  std::string completeNoTrackInputFileName = inputFileDir + partialNoTrackInputFileName + genEnergyBins[i] + "_EtaBin" + etaBins[j] + "_FixedPtAndEta.txt";

		  //std::string completeWithTrackInputFileName = inputFileDir + partialWithTrackInputFileName + genEnergyBins[i] + "_EtaBin" + etaBins[j] + "_FixedPtAndEta.txt"; 
		  //std::cout<<"about to declare a pointer to the input .txt file"<<std::endl;
		  RooDataSet * dataSet= &(RooDataSet::read(completeNoTrackInputFileName.c_str(), RooArgSet(eleEnergy,deltaE),"Q"));
		  //RooDataSet * dataSet= &(RooDataSet::read(completeWithTrackInputFileName.c_str(), RooArgSet(eleEnergy,deltaE),"Q"));


		  //std::cout<<"about to fit a crystal ball function to the delta E data points"<<std::endl;
		  //RooFitResult * myfitresult=totalPdf.fitTo(*dataSet,"mer",Range(deltaEmin,deltaEmax) );	//constrains the range of the fit 

		  
		  //RooFitResult * myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.8,0.6) );

		  //totalPdf.fitTo(*dataSet,Minos(kTRUE), Range(-0.4,0.3) );

		  RooFitResult * myfitresult;

		  if(i==0){
			  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.95,-0.1));

		  }
		  else{
			  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.8,0.1));

		  }

	  /*	  
		  if(j != 5){

			  if(i==1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.9,0.1));
			  } 

			  if(i==2){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.8,0.7));
			  } 

			  if(i==3 && j != 1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.7,0.8));
			  } 

			  if(i==3 && j==1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.8,0.2));
			  } 

			  if(i==4 && j != 1 && j != 4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.6,0.05));
			  } 

			  if(i==4 && j==1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.55,0.05));
			  } 

			  if(i==4 && j==4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.55,0.));
			  } 


			  if(i==5 && j != 3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.45,0.05));
			  } 

			  if(i==5 && j==3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.45,0.05));
			  } 

			  if(i==6){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.45,0.05));
			  } 

			  if(i==7 && j != 2 && j != 1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.3,0.05));
			  }
			  
			  if(i==7 && (j==2 || j==1) ){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.2,0.04));
			  }

			  if(i==8){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.2,0.02));
			  }

		  }

		  if(j==5){

			  if(i==1){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.9,0.1));
			  } 

			  if(i==2){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.9,0.2));
			  } 

			  if(i==3){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.9,0.4));
			  } 

			  if(i==4){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.8,-0.1));
			  } 

			  if(i==5){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.7,0.));
			  } 

			  if(i==6){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.5,0.));
			  } 

			  if(i==7){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.4,0.));
			  } 

			  if(i==8){
				  myfitresult = totalPdf.fitTo(*dataSet, Minos(kTRUE), Range(-0.35,0.));
			  }

		  }

	  */

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
		  std::string noTrackEnergySpreadTitle = "No Track P_{T,reco} - P_{T,gen} / P_{T,gen}   gen E " + genEnergyVals[i] + " gen eta " + etaVals[j]; 
		  //TCanvas * cx=new TCanvas(canvXName.c_str(), canvXName.c_str(),800,600);
		  cEnergySpreads->cd(i+1);	//need i+1 when initial i = 0.  the first grid is accessed by calling cEnergySpreads->cd(1).
		  //calling cEnergySpreads->cd(0) ignores the fact that the TCanvas has been divided into a 3x3 grid!
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
			  std::string completeNoTrackESpreadOutputFileName = outputPlotDir + partialNoTrackESpreadOutputPlotName + "_chgdPion" + "_EtaBin" + etaBins[j] + ".gif";
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
  float genEngs[] = {10,30,50,80,100,150,200,300,500};

  float convToGenPt[] = {(1/TMath::CosH(1.6)), (1/TMath::CosH(1.9)), (1/TMath::CosH(2.2)), (1/TMath::CosH(2.5)), (1/TMath::CosH(2.8))};
  
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

  TVectorT<float> genPtFirstEtaBin(numEnergyBins);
  TVectorT<float> genPtSecondEtaBin(numEnergyBins);
  TVectorT<float> genPtThirdEtaBin(numEnergyBins);
  TVectorT<float> genPtFourthEtaBin(numEnergyBins);
  TVectorT<float> genPtFifthEtaBin(numEnergyBins);

  float one = 1.0;
  
  for(unsigned int i=0; i<numEnergyBins ; i++){
	  genEnergyMeanErrors[i] += 0.0;
	  genEnergyMeans[i] += genEngs[i];

	  meanERecoFirstEtaBin[i] += (genEnergyMeans[i])*convToGenPt[0]*(withoutTrackerFitMeansFirstEtaBin[i]+one);
	  meanERecoErrorFirstEtaBin[i] += (genEnergyMeans[i])*convToGenPt[0]*(withoutTrackerFitMeanErrorsFirstEtaBin[i]);
	  genPtFirstEtaBin[i] += (genEnergyMeans[i])*convToGenPt[0];
	
	  meanERecoSecondEtaBin[i] += (genEnergyMeans[i])*convToGenPt[1]*(withoutTrackerFitMeansSecondEtaBin[i]+one);
	  meanERecoErrorSecondEtaBin[i] += (genEnergyMeans[i])*convToGenPt[1]*(withoutTrackerFitMeanErrorsSecondEtaBin[i]);
	  genPtSecondEtaBin[i] += (genEnergyMeans[i])*convToGenPt[1];
		
	  meanERecoThirdEtaBin[i] += (genEnergyMeans[i])*convToGenPt[2]*(withoutTrackerFitMeansThirdEtaBin[i]+one);
	  meanERecoErrorThirdEtaBin[i] += (genEnergyMeans[i])*convToGenPt[2]*(withoutTrackerFitMeanErrorsThirdEtaBin[i]);
	  genPtThirdEtaBin[i] += (genEnergyMeans[i])*convToGenPt[2];
		
	  meanERecoFourthEtaBin[i] += (genEnergyMeans[i])*convToGenPt[3]*(withoutTrackerFitMeansFourthEtaBin[i]+one);
	  meanERecoErrorFourthEtaBin[i] += (genEnergyMeans[i])*convToGenPt[3]*(withoutTrackerFitMeanErrorsFourthEtaBin[i]);
	  genPtFourthEtaBin[i] += (genEnergyMeans[i])*convToGenPt[3];
		
	  meanERecoFifthEtaBin[i] += (genEnergyMeans[i])*convToGenPt[4]*(withoutTrackerFitMeansFifthEtaBin[i]+one);
	  meanERecoErrorFifthEtaBin[i] += (genEnergyMeans[i])*convToGenPt[4]*(withoutTrackerFitMeanErrorsFifthEtaBin[i]);
	  genPtFifthEtaBin[i] += (genEnergyMeans[i])*convToGenPt[4];
	
  }


  gStyle->SetOptFit(111);

  TCanvas * cFirst = new TCanvas("cFirst","cFirst",1000,1000);
  cFirst->cd();


  TF1 * fitToEtaBinOneResolution = new TF1("fitToEtaBinOneResolution","([0]/TMath::Sqrt(x))+[1]",11.2,200);
  TGraphErrors * chgdPionEResoNoTrackFirstEtaBin = new TGraphErrors(genPtFirstEtaBin, withoutTrackerFitSigmasFirstEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsFirstEtaBin);
  chgdPionEResoNoTrackFirstEtaBin->SetTitle("#pi+ P_{T} Resolution #eta_{gen} = 1.6; P_{T,gen} (GeV); #sigma of #DeltaP_{T}/P_{T}");
  chgdPionEResoNoTrackFirstEtaBin->SetFillStyle(0);
  chgdPionEResoNoTrackFirstEtaBin->SetMarkerStyle(20);
  chgdPionEResoNoTrackFirstEtaBin->SetMarkerColor(1);
  chgdPionEResoNoTrackFirstEtaBin->SetMarkerSize(1.5);
  chgdPionEResoNoTrackFirstEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackFirstEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackFirstEtaBin->Fit("fitToEtaBinOneResolution","R");

  chgdPionEResoNoTrackFirstEtaBin->Draw("AP");

  std::string outFirstGraphName = outputPlotDir + "chgdPionPTResoNoTrackFirstEtaBin.gif"; 
  cFirst->SaveAs(outFirstGraphName.c_str(),"recreate");


  TCanvas * cNine = new TCanvas("cNine","cNine",1000,1000);
  cNine->cd();
  cNine->SetLogx(1);
  cNine->SetLogy(1);
 
  
  TF1 * fitToEtaBinOneLinearity = new TF1("fitToEtaBinOneLinearity","[0]*x+[1]",11.2,200);
 
  TGraphErrors * chgdPionELinearityNoTrackFirstEtaBin = new TGraphErrors(genPtFirstEtaBin, meanERecoFirstEtaBin, genEnergyMeanErrors, meanERecoErrorFirstEtaBin);
  chgdPionELinearityNoTrackFirstEtaBin->SetTitle("#pi+ P_{T} Linearity #eta_{gen} = 1.6; P_{T,gen} (GeV); P_{T,reco} (GeV)");
  chgdPionELinearityNoTrackFirstEtaBin->SetFillStyle(0);
  chgdPionELinearityNoTrackFirstEtaBin->SetMarkerStyle(20);
  chgdPionELinearityNoTrackFirstEtaBin->SetMarkerColor(2);
  chgdPionELinearityNoTrackFirstEtaBin->SetMarkerSize(1.5);
  chgdPionELinearityNoTrackFirstEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackFirstEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackFirstEtaBin->Fit("fitToEtaBinOneLinearity","MR");
 
  chgdPionELinearityNoTrackFirstEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "chgdPionPTLinearityNoTrackFirstEtaBin.gif"; 
  cNine->SaveAs(outSecondGraphName.c_str(),"recreate");



  TCanvas * cSecond = new TCanvas("cSecond","cSecond",1000,1000);
  cSecond->cd();

  TF1 * fitToEtaBinTwoResolution = new TF1("fitToEtaBinTwoResolution","([0]/TMath::Sqrt(x))+[1]",8.4,200);
 

  TGraphErrors * chgdPionEResoNoTrackSecondEtaBin = new TGraphErrors(genPtSecondEtaBin, withoutTrackerFitSigmasSecondEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsSecondEtaBin);
  chgdPionEResoNoTrackSecondEtaBin->SetTitle("#pi+ P_{T} Resolution #eta_{gen} = 1.9; P_{T,gen} (GeV); #sigma of #DeltaP_{T}/P_{T}");
  chgdPionEResoNoTrackSecondEtaBin->SetFillStyle(0);
  chgdPionEResoNoTrackSecondEtaBin->SetMarkerStyle(20);
  chgdPionEResoNoTrackSecondEtaBin->SetMarkerColor(2);
  chgdPionEResoNoTrackSecondEtaBin->SetMarkerSize(1.5);
  chgdPionEResoNoTrackSecondEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackSecondEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackSecondEtaBin->Fit("fitToEtaBinTwoResolution","R");
 
  chgdPionEResoNoTrackSecondEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "chgdPionPTResoNoTrackSecondEtaBin.gif"; 
  cSecond->SaveAs(outSecondGraphName.c_str(),"recreate");

  TCanvas * cTen = new TCanvas("cTen","cTen",1000,1000);
  cTen->cd();
  cTen->SetLogx(1);
  cTen->SetLogy(1);
  
  TF1 * fitToEtaBinTwoLinearity = new TF1("fitToEtaBinTwoLinearity","[0]*x+[1]",8.4,200);
 
  TGraphErrors * chgdPionELinearityNoTrackSecondEtaBin = new TGraphErrors(genPtSecondEtaBin, meanERecoSecondEtaBin, genEnergyMeanErrors, meanERecoErrorSecondEtaBin);
  chgdPionELinearityNoTrackSecondEtaBin->SetTitle("#pi+ P_{T} Linearity #eta_{gen} = 1.9; P_{T,gen} (GeV); P_{T,reco} (GeV)");
  chgdPionELinearityNoTrackSecondEtaBin->SetFillStyle(0);
  chgdPionELinearityNoTrackSecondEtaBin->SetMarkerStyle(20);
  chgdPionELinearityNoTrackSecondEtaBin->SetMarkerColor(2);
  chgdPionELinearityNoTrackSecondEtaBin->SetMarkerSize(1.5);
  chgdPionELinearityNoTrackSecondEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackSecondEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackSecondEtaBin->Fit("fitToEtaBinTwoLinearity","MR");
 
  chgdPionELinearityNoTrackSecondEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "chgdPionPTLinearityNoTrackSecondEtaBin.gif"; 
  cTen->SaveAs(outSecondGraphName.c_str(),"recreate");


  TCanvas * cThird = new TCanvas("cThird","cThird",1000,1000);
  cThird->cd();

  TF1 * fitToEtaBinThreeResolution = new TF1("fitToEtaBinThreeResolution","([0]/TMath::Sqrt(x))+[1]",6.3,200);


  TGraphErrors * chgdPionEResoNoTrackThirdEtaBin = new TGraphErrors(genPtThirdEtaBin, withoutTrackerFitSigmasThirdEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsThirdEtaBin);
  chgdPionEResoNoTrackThirdEtaBin->SetTitle("#pi+ P_{T} Resolution #eta_{gen} = 2.2; P_{T,gen} (GeV); #sigma of #DeltaP_{T}/P_{T}");
  chgdPionEResoNoTrackThirdEtaBin->SetFillStyle(0);
  chgdPionEResoNoTrackThirdEtaBin->SetMarkerStyle(20);
  chgdPionEResoNoTrackThirdEtaBin->SetMarkerColor(4);
  chgdPionEResoNoTrackThirdEtaBin->SetMarkerSize(1.5);
  chgdPionEResoNoTrackThirdEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackThirdEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackThirdEtaBin->Fit("fitToEtaBinThreeResolution","R");
  
  chgdPionEResoNoTrackThirdEtaBin->Draw("AP");

  std::string outThirdGraphName = outputPlotDir + "chgdPionPTResoNoTrackThirdEtaBin.gif"; 
  cThird->SaveAs(outThirdGraphName.c_str(),"recreate");

  TCanvas * cEleven = new TCanvas("cEleven","cEleven",1000,1000);
  cEleven->cd();
  cEleven->SetLogx(1);
  cEleven->SetLogy(1);

  TF1 * fitToEtaBinThreeLinearity = new TF1("fitToEtaBinThreeLinearity","[0]*x+[1]",6.3,200);
 
  TGraphErrors * chgdPionELinearityNoTrackThirdEtaBin = new TGraphErrors(genPtThirdEtaBin, meanERecoThirdEtaBin, genEnergyMeanErrors, meanERecoErrorThirdEtaBin);
  chgdPionELinearityNoTrackThirdEtaBin->SetTitle("#pi+ P_{T} Linearity #eta_{gen} = 2.2; P_{T,gen} (GeV); P_{T,reco} (GeV)");
  chgdPionELinearityNoTrackThirdEtaBin->SetFillStyle(0);
  chgdPionELinearityNoTrackThirdEtaBin->SetMarkerStyle(20);
  chgdPionELinearityNoTrackThirdEtaBin->SetMarkerColor(2);
  chgdPionELinearityNoTrackThirdEtaBin->SetMarkerSize(1.5);
  chgdPionELinearityNoTrackThirdEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackThirdEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackThirdEtaBin->Fit("fitToEtaBinThreeLinearity","MR");
 
  chgdPionELinearityNoTrackThirdEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "chgdPionPTLinearityNoTrackThirdEtaBin.gif"; 
  cEleven->SaveAs(outSecondGraphName.c_str(),"recreate");


  TCanvas * cFourth = new TCanvas("cFourth","cFourth",1000,1000);
  cFourth->cd();

  TF1 * fitToEtaBinFourResolution = new TF1("fitToEtaBinFourResolution","([0]/TMath::Sqrt(x))+[1]",4.7,200);


  TGraphErrors * chgdPionEResoNoTrackFourthEtaBin = new TGraphErrors(genPtFourthEtaBin, withoutTrackerFitSigmasFourthEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsFourthEtaBin);
  chgdPionEResoNoTrackFourthEtaBin->SetTitle("#pi+ P_{T} Resolution #eta_{gen} = 2.5; P_{T,gen} (GeV); #sigma of #DeltaP_{T}/P_{T}");
  chgdPionEResoNoTrackFourthEtaBin->SetFillStyle(0);
  chgdPionEResoNoTrackFourthEtaBin->SetMarkerStyle(20);
  chgdPionEResoNoTrackFourthEtaBin->SetMarkerColor(8);
  chgdPionEResoNoTrackFourthEtaBin->SetMarkerSize(1.5);
  chgdPionEResoNoTrackFourthEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackFourthEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackFourthEtaBin->Fit("fitToEtaBinFourResolution","R");
 
  chgdPionEResoNoTrackFourthEtaBin->Draw("AP");

  std::string outFourthGraphName = outputPlotDir + "chgdPionPTResoNoTrackFourthEtaBin.gif"; 
  cFourth->SaveAs(outFourthGraphName.c_str(),"recreate");


  TCanvas * cTwelve = new TCanvas("cTwelve","cTwelve",1000,1000);
  cTwelve->cd();
  cTwelve->SetLogx(1);
  cTwelve->SetLogy(1);

  TF1 * fitToEtaBinFourLinearity = new TF1("fitToEtaBinFourLinearity","[0]*x+[1]",4.7,200);
 
  TGraphErrors * chgdPionELinearityNoTrackFourthEtaBin = new TGraphErrors(genPtFourthEtaBin, meanERecoFourthEtaBin, genEnergyMeanErrors, meanERecoErrorFourthEtaBin);
  chgdPionELinearityNoTrackFourthEtaBin->SetTitle("#pi+ P_{T} Linearity #eta_{gen} = 2.5; P_{T,gen} (GeV); P_{T,reco} (GeV)");
  chgdPionELinearityNoTrackFourthEtaBin->SetFillStyle(0);
  chgdPionELinearityNoTrackFourthEtaBin->SetMarkerStyle(20);
  chgdPionELinearityNoTrackFourthEtaBin->SetMarkerColor(2);
  chgdPionELinearityNoTrackFourthEtaBin->SetMarkerSize(1.5);
  chgdPionELinearityNoTrackFourthEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackFourthEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackFourthEtaBin->Fit("fitToEtaBinFourLinearity","MR");
 
  chgdPionELinearityNoTrackFourthEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "chgdPionPTLinearityNoTrackFourthEtaBin.gif"; 
  cTwelve->SaveAs(outSecondGraphName.c_str(),"recreate");


  TCanvas * cFifth = new TCanvas("cFifth","cFifth",1000,1000);
  cFifth->cd();

  TF1 * fitToEtaBinFiveResolution = new TF1("fitToEtaBinFiveResolution","([0]/TMath::Sqrt(x))+[1]",3.5,200);


  TGraphErrors * chgdPionEResoNoTrackFifthEtaBin = new TGraphErrors(genPtFifthEtaBin, withoutTrackerFitSigmasFifthEtaBin, genEnergyMeanErrors, withoutTrackerFitSigmaErrorsFifthEtaBin);
  chgdPionEResoNoTrackFifthEtaBin->SetTitle("#pi+ P_{T} Resolution #eta_{gen} = 2.8; P_{T,gen} (GeV); #sigma of #DeltaP_{T}/P_{T}");
  chgdPionEResoNoTrackFifthEtaBin->SetFillStyle(0);
  chgdPionEResoNoTrackFifthEtaBin->SetMarkerStyle(20);
  chgdPionEResoNoTrackFifthEtaBin->SetMarkerColor(8);
  chgdPionEResoNoTrackFifthEtaBin->SetMarkerSize(1.5);
  chgdPionEResoNoTrackFifthEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackFifthEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionEResoNoTrackFifthEtaBin->Fit("fitToEtaBinFiveResolution","R");
 
  chgdPionEResoNoTrackFifthEtaBin->Draw("AP");

  std::string outFifthGraphName = outputPlotDir + "chgdPionPTResoNoTrackFifthEtaBin.gif"; 
  cFifth->SaveAs(outFifthGraphName.c_str(),"recreate");

  TCanvas * cThirteen = new TCanvas("cThirteen","cThirteen",1000,1000);
  cThirteen->cd();
  cThirteen->SetLogx(1);
  cThirteen->SetLogy(1);
  
  TF1 * fitToEtaBinFiveLinearity = new TF1("fitToEtaBinFiveLinearity","[0]*x+[1]",3.5,200);
 
  TGraphErrors * chgdPionELinearityNoTrackFifthEtaBin = new TGraphErrors(genPtFifthEtaBin, meanERecoFifthEtaBin, genEnergyMeanErrors, meanERecoErrorFifthEtaBin);
  chgdPionELinearityNoTrackFifthEtaBin->SetTitle("#pi+ P_{T} Linearity #eta_{gen} = 2.8; P_{T,gen} (GeV); P_{T,reco} (GeV)");
  chgdPionELinearityNoTrackFifthEtaBin->SetFillStyle(0);
  chgdPionELinearityNoTrackFifthEtaBin->SetMarkerStyle(20);
  chgdPionELinearityNoTrackFifthEtaBin->SetMarkerColor(2);
  chgdPionELinearityNoTrackFifthEtaBin->SetMarkerSize(1.5);
  chgdPionELinearityNoTrackFifthEtaBin->GetYaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackFifthEtaBin->GetXaxis()->SetTitleOffset(1.4);
  chgdPionELinearityNoTrackFifthEtaBin->Fit("fitToEtaBinFiveLinearity","MR");
 
  chgdPionELinearityNoTrackFifthEtaBin->Draw("AP");

  std::string outSecondGraphName = outputPlotDir + "chgdPionPTLinearityNoTrackFifthEtaBin.gif"; 
  cThirteen->SaveAs(outSecondGraphName.c_str(),"recreate");

  /**/



  /*
  TCanvas * c3 = new TCanvas("c3","c3",1000,1000);
  c3->cd();

  TLegend * leg3 = new TLegend(0.65, 0.65, 1, 0.85);
  leg3->AddEntry( chgdPionEResoNoTrackFifthEtaBin, "#eta_{gen} 2.8");
  //leg3->AddEntry( chgdPionEResoNoTrackFourthEtaBin, "#eta_{gen} 2.5");
  leg3->AddEntry( chgdPionEResoNoTrackThirdEtaBin, "#eta_{gen} 2.2");
  leg3->AddEntry( chgdPionEResoNoTrackSecondEtaBin, "#eta_{gen} 1.9");
  leg3->AddEntry( chgdPionEResoNoTrackFirstEtaBin, "#eta_{gen} 1.6");

  TMultiGraph * chgdPionEnergyResolution = new TMultiGraph();
  chgdPionEnergyResolution->SetTitle("#pi+ P_{T} Resolution; gen p_{T} (GeV);");
  chgdPionEnergyResolution->Add(chgdPionEResoNoTrackFifthEtaBin);
  //chgdPionEnergyResolution->Add(chgdPionEResoNoTrackFourthEtaBin);
  chgdPionEnergyResolution->Add(chgdPionEResoNoTrackThirdEtaBin);
  chgdPionEnergyResolution->Add(chgdPionEResoNoTrackSecondEtaBin);
  chgdPionEnergyResolution->Add(chgdPionEResoNoTrackFirstEtaBin);
  
  chgdPionEnergyResolution->Draw("AP");
  leg3->Draw();

  std::string outMultiGraphName = outputPlotDir + "chgdPionPtResolutionOverlayGraphs.gif";
  c3->SaveAs(outMultiGraphName.c_str(),"recreate");

  */



}

