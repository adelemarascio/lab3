#include <cmath>
#include <iostream>
#include <fstream>

#include "TFile.h"
#include "TH1D.h"
#include "TF1.h"
#include "TMath.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TLegend.h"


void insieme(){

  //gROOT->SetStyle("Plain");
  //gStyle->SetPalette(57);
  gStyle->SetFitFormat("3.3g");

  
  TCanvas *canvas = new TCanvas("c", "Base comune",200,10,700,500);

  TGraphErrors * graph1 = new TGraphErrors("100err.txt","%lg %*lg %lg %lg");
  
  graph1->SetTitle("Configurazione a base comune"); 
  graph1->SetMarkerStyle(20);
  graph1->SetMarkerSize(0.5);
  graph1->SetMarkerColor(kRed);
  graph1->SetLineColor(kRed);
  graph1->GetXaxis()->SetTitle("Potenziale -V_{CE} (V)");
  graph1->GetXaxis()->SetTitleOffset(1.2);
  graph1->GetYaxis()->SetTitle("Corrente -I_{C} (A)");
  graph1->SetMinimum(0);
  graph1->SetMinimum(40);
    
  graph1->Draw("APE");

  TGraphErrors * graph2 = new TGraphErrors("200err.txt","%lg %*lg %lg %lg");
  
  graph2->SetMarkerStyle(20);
  graph2->SetMarkerSize(0.5);
  graph2->SetMarkerColor(kBlue);
  graph2->SetLineColor(kBlue);
 
    
  graph2->Draw("PE");


  TLegend *leg=new TLegend(.1,.7,.3,.9,"Legenda");
  leg->SetFillColor(0);
  //leg->SetTextSize(15);
  leg->AddEntry(graph1,"I_{B} = 0.1A");
  leg->AddEntry(graph2,"I_{B} = 0.2A");
  leg->Draw("Same");
} 