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


void bjt(){
    gStyle->SetOptStat(2210);
    gStyle->SetOptFit(111);
    gStyle->SetFitFormat("4.3g");

    TGraphErrors *graph = new TGraphErrors("200.txt", "%lg %lg %*lg %*lg"); 

    TCanvas *c1 = new TCanvas("c1","Grafico I-V");

    /*TF1 *f = new TF1("f", "[0]*(exp(x/[1])-1)", 80, 230);
    f->SetParameter(0, 1*exp(-6));
    //f->SetParLimits(0, 0.99E-6, 1.01E-6);
    f->SetParameter(1, 50);
    //f->SetParLimits(1, 49.99, 50.01);
    f->SetLineColor(kRed);
    f->SetLineStyle(1);

    c1->SetLogy();*/

    graph->SetMarkerStyle(7);
    graph->SetMarkerColor(kBlue);
    graph->GetXaxis()->SetTitle("Potenziale (mV)");
    graph->GetXaxis()->SetTitleOffset(1.0);
    graph->GetXaxis()->SetRangeUser(50, 400);
    graph->GetYaxis()->SetTitle("Corrente (mA)");
    graph->GetYaxis()->SetTitleOffset(0.7);
    graph->SetTitle("Grafico I-V Germanio");
   
   // graph->Fit("f", "R");
    graph->Draw("APE");

    /*TLegend *leg = new TLegend (.1, .7, .3, .9, "Legenda");
    leg->SetFillColor(0);
    leg->AddEntry(graph,"Punti");
    leg->AddEntry(f,"Fit Globale");
    leg->AddEntry(s,"Diffrazione");
    leg->Draw("SAME");*/
}