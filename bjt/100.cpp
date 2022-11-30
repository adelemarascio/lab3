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


void cento(){

  //gROOT->SetStyle("Plain");
  //gStyle->SetPalette(57);
  gStyle->SetFitFormat("3.3g");
  gStyle->SetOptStat(2200);
  gStyle->SetOptFit(1111);

  
  TCanvas *canvas = new TCanvas("c", "fit",200,10,700,500);

  TGraphErrors * graph1 = new TGraphErrors("prova.txt","%lg %*lg %lg %lg");
  
  graph1->SetTitle("Base 0.1A"); 
  graph1->SetMarkerStyle(20);
  graph1->SetMarkerSize(0.5);
  graph1->SetMarkerColor(kBlack);
  graph1->SetLineColor(kBlack);
  graph1->GetXaxis()->SetTitle("Potenziale -V_{CE} (V)");
  graph1->GetXaxis()->SetTitleOffset(1.2);
  graph1->GetYaxis()->SetTitle("Corrente -I_{C} (A)");
    
  graph1->Draw("APE");

  graph1->Fit("pol1"); //[0]+[1]*x
  TF1 *fit = graph1->GetFunction("pol1");
  fit->SetRange(0.8,3);
  fit->SetParName(0, "a");
  fit->SetParName(1, "b");


  TLegend *leg = new TLegend(.1, .7, .3, .9 );
  leg->SetFillColor(0);
  leg->SetHeader("Legenda","C");
  leg->AddEntry(graph1, "Punti sperimentali");
  leg->AddEntry(fit, "Fit Lineare");
  leg->Draw("S");
} 