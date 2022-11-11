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

#include "calibrazione.dat"


void setStyle(){
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}

void grafico(){

    TGraphErrors * graph =new TGraphErrors("calibrazione.dat","%lg %lg *%lg *%lg");
    graph->SetTitle("Calibrazione della DDP; Oscilloscopio (V); Multimetro (V)");
    
    graph->SetMarkerStyle(kOpenCircle);
    graph->SetMarkerColor(kBlue);
    graph->SetLineColor(kBlue);
    
    TCanvas *calibrazione = new TCanvas();

    graph->Fit("pol1"); 
    TF1 *f = graph->GetFunction("pol1");
    f->SetParName(0, "q");
    f->SetParName(1, "n1/n2");
    f->SetLineColor(kRed);
    f->SetLineStyle(2);
    
    graph->Fit(f);

    gStyle->SetOptFit(111);
    graph->Draw("APE");
    cout << "x and y measurements correlation ="<< graph->GetCorrelationFactor()<<endl;
    cout << "The Chisquare of the fit = "<< graph->Chisquare(f)<<endl;
    cout << "From function  "<<f->GetChisquare() << endl ;
    cout << "From function  "<<f->GetNDF() << endl ;

    TLegend *leg=new TLegend(.1,.7,.3,.9,"Prova di Laboratorio");
    leg->SetFillColor(0);
    graph->SetFillColor(0);
    leg->AddEntry(graph,"Punti Sperimentali");
    leg->AddEntry(f,"Fit Lineare");
    leg->Draw("Same");
    calibrazione->Print("LeggeDiOhm.gif");

} 