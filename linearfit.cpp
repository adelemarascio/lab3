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


void linearfit(){

  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetFitFormat("3.3g");

  const int n_points=16;
    double x_vals[n_points]={0.049,0.099,0.147,0.198,0.248,0.294,
      0.343,0.395,0.443,0.492,0.539,0.589,0.629,0.708,0.749,0.788};
    double y_vals[n_points]={0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,
      0.5,0.55,0.6,0.65,0.7,0.75,0.8};
    double y_errs[n_points]={0.00150333,0.003001666,0.004527693,0.006020797,0.007516648,0.009055385,
      0.010547512,0.012041595,0.013647344,0.015132746,0.01662077,0.01811077,0.019602296,0.021095023,0.022588714,0.024083189};
  
  TCanvas *calibrazione = new TCanvas("c", "Calibrazione",200,10,700,500);

  TGraphErrors * graph =new TGraphErrors(n_points,x_vals,y_vals,0,y_errs);
  //TGraphErrors * graph =new TGraphErrors("calibrazione.txt","%lg %lg %*lg %lg");
  
  graph->SetTitle("Calibrazione della DDP"); 
  graph->SetMarkerStyle(kOpenCircle);
  graph->SetMarkerColor(kBlue);
  graph->SetLineColor(kBlue);
  graph->GetXaxis()->SetTitle("Multimetro(V)");
  graph->GetYaxis()->SetTitle("Oscilloscopio(V)");
    
  graph->Draw("AP");

  graph->Fit("pol1"); 
  TF1 *f = graph->GetFunction("pol1");
  f->SetParName(0, "a");
  f->SetParName(1, "b");
  f->SetLineColor(kRed);
  f->SetLineStyle(1); 
  graph->Fit(f);

  gStyle->SetOptFit(111);
  
  cout << "x and y measurements correlation ="<< graph->GetCorrelationFactor()<<endl;
  cout << "The Chisquare of the fit = "<< graph->Chisquare(f)<<endl;
  cout << "From function  "<<f->GetChisquare()<<endl ;
  cout << "DOF:  "<<f->GetNDF()<<endl ;

  TLegend *leg=new TLegend(.1,.7,.3,.9,"Legenda");
  leg->SetFillColor(0);
  graph->SetFillColor(0);
  leg->AddEntry(graph,"Punti Sperimentali");
  leg->AddEntry(f,"Fit Lineare");
  leg->Draw("Same");
  calibrazione->Print("Calibrazione.jpj");
} 
