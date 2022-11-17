#include "Particle.hpp"
#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TRandom.h"

R__LOAD_LIBRARY( Particle_cpp.so );
R__LOAD_LIBRARY( ParticleType_cpp.so );
R__LOAD_LIBRARY( ResonanceType_cpp.so );

void Main(){
      gRandom->SetSeed(); 
    char* pionep=new char('P');
char* pionem=new char('p');
    char* Kaonep=new char('K');
    char* Kaonem=new char('k');
    char* protonep=new char('P');
    char* protonem=new char('p');
    char* K=new char('K');
    Particle::AddParticleType(pionep,0.13957,1);
    Particle::AddParticleType(pionem,0.13957,-1);
    Particle::AddParticleType(Kaonep,0.49367,1);
    Particle::AddParticleType(Kaonem,0.49367,-1);
    Particle::AddParticleType(protonep,0.93827,1);
    Particle::AddParticleType(protonem,0.93827,-1);
    Particle::AddParticleType(K,0.89166,0,0.050);

    std::vector<Particle> EventParticles;

    TH1F *h1=new TH1F  ("h1", "Type Distribution", 7, 0, 7);
    TH2F *h2 = new TH2F("h2", "Angle distribution", 100, 0,(2*M_PI), 100, 0,M_PI);
    TH1F*  h3=new TH1F  ("h3", "Impulse", 1000, 0, 5);
    TH1F*  h4=new TH1F  ("h4", "Trasverse Impulse", 1000, 0, 5);
    TH1F*  h5=new TH1F  ("h5", "Energy Distribution", 1000, 0, 10);
    TH1F*  h6=new TH1F  ("h6", "Mass Invariant", 1000, 0, 8);
    TH1F*  h7=new TH1F  ("h7", "Mass Invariant Of Opposite Charge", 1000, 0, 8);
    TH1F*  h8=new TH1F  ("h8","Mass Invariant Of Same Charge", 1000, 0, 8);
    TH1F*  h9=new TH1F  ("h9", "Mass Invariant Of Oppsoite Charge (K,P)", 1000, 0, 8);    
    TH1F*  h10=new TH1F  ("h10", "Mass Invariant Of Same Charge (K,P)", 1000, 0, 8); 
     TH1F*  h11=new TH1F  ("h11", "Mass Invariant Resonance", 1000, 0, 8);
    
    TH1F *h12 = new TH1F("h12", "Invariant mass between opposite charge for fitting", 100, 0.7, 1.05);
    TH1F *h13 = new TH1F("h13", "Invariant mass between same charge particles for fitting", 100, 0.7, 1.05);
    h12->Sumw2();
    h13->Sumw2();
    TH1F *h14 = new TH1F("h14", "Mass Invariant Same Charge(K,P) for fitting", 100, 0, 2);
    TH1F *h15 = new TH1F("h15", "Mass Invariant Of Same Charge (K,P) for fitting", 100, 0, 2);
    h14->Sumw2();
    h15->Sumw2();

    TH1 *Histos[15] = {h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15};

    TCanvas *c1 = new TCanvas("c1", "Type distribution", 200, 10, 600, 400);
    TCanvas *c2 = new TCanvas("c2", "Angle distribution", 200, 10, 600, 400);
    TCanvas *c3 = new TCanvas("c3", "Impulse distribution", 200, 10, 600, 400);
    TCanvas *c4 =
        new TCanvas("c4", "Trasverse impulse distribution", 200, 10, 600, 400);
    TCanvas *c5 = new TCanvas("c5", "Energy distribution", 200, 10, 600, 400);
    TCanvas *c6 = new TCanvas("c6", "Invariant mass", 200, 10, 600, 400);
    TCanvas *c7 = new TCanvas("c7", "Invariant mass between discord charge", 200,
                              10, 600, 400);
    TCanvas *c8 = new TCanvas(
        "c8", "Invariant mass between same charge particles", 200, 10, 600, 400);
    TCanvas *c9 = new TCanvas(
        "c9", "Invariant mass between specific particles (1)", 200, 10, 600, 400);
    TCanvas *c10 =
        new TCanvas("c10", "Invariant mass between specific particles (2)", 200,
                    10, 600, 400);
    TCanvas *c11 = new TCanvas("c11", "Invariant mass between decayed products",
                               200, 10, 600, 400);

    TCanvas *c12 = new TCanvas("c12", "Invariant mass between discord charge new range",
                               200, 10, 600, 400);
    TCanvas *c13 = new TCanvas("c13", "Invariant mass between same charge particles new rang",
                               200, 10, 600, 400);
    TCanvas *c14 = new TCanvas("c14", "Invariant mass between specific particles (1) new range",
                               200, 10, 600, 400);
    TCanvas *c15 = new TCanvas("c15", "Invariant mass between specific particles (2) new range",
                               200, 10, 600, 400);

    TCanvas *Canvases[15] = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15};

        for (int i{5

         };
         i < 11; ++i)
    {
        Histos[i]->GetXaxis()->SetTitle("Invariant Mass (GeV/c^2)");
        Histos[i]->SetTitleSize(0.05, "x");
        Histos[i]->GetYaxis()->SetTitle("entries");
        Histos[i]->SetTitleSize(0.05, "y");
        Histos[i]->SetLineColor(kBlack);
        Histos[i]->SetFillColor(kGray);
    };

    for(int i=0; i<1E5;i++){
        std::vector <Particle> resonance;
        for (int j=0; j<100; j++){
            double phi= gRandom->Uniform(0,2*M_PI);
            double theta= gRandom->Uniform(0, M_PI);

           h2->Fill(phi, theta); //angle

            double P_= gRandom->Exp(1);

            h3->Fill(P_); //impulse

            double x=cos(phi)*sin(theta)*P_;
            double y= sin(phi)*sin(theta)*P_;
            double z=cos(theta)*P_;
            h4->Fill(sqrt(pow(x,2)+pow(y,2)));     //trasvers impulse
            double Prob=gRandom->Rndm();
            if(Prob<0.4){EventParticles.push_back(Particle(pionep,x,y,z));}
            else if (Prob>=0.4 && Prob<0.8){EventParticles.push_back(Particle(pionem,x,y,z));}
            else if (Prob>=0.8 && Prob<0.85){EventParticles.push_back(Particle(Kaonep,x,y,z));}
            else if (Prob>=0.85 && Prob<0.9){EventParticles.push_back(Particle(Kaonem,x,y,z));}
            else if (Prob>=0.9 && Prob<0.945){EventParticles.push_back(Particle(protonep,x,y,z));}
            else if (Prob>=0.945 && Prob<0.99){EventParticles.push_back(Particle(protonem,x,y,z));}
            else if (Prob>=0.99 && Prob<0.995){
                Particle temp{K,x,y,z};
                Particle A{pionep};
                Particle B{Kaonem};
                temp.Decay2body(A,B);
                resonance.push_back(A);
                resonance.push_back(B);
                double m=A.Mass_Invariant(B);
                h11->Fill(m);    //mass invariant resonance
                }
            else if (Prob>=0.995 && Prob<=1){
                Particle temp{K,x,y,z};
                Particle A{pionem,0,0,0};
                Particle B{Kaonep,0,0,0};
                temp.Decay2body(A,B);
                resonance.push_back(A);
                resonance.push_back(B);
                double m=A.Mass_Invariant(B);
                h11->Fill(m);   //mass invariant resonance
                }
                for (auto k:EventParticles){
                h1->Fill(k.Get_fIndex());    //type distribution
                h5->Fill(k.Get_Energy());   //Energy
                }
                for (auto k:resonance){EventParticles.push_back(k);};

                int size = EventParticles.size();

                for(int k=0; k< size;k++){
                    for (int h=k+1; h<size ;h++){
                        double m = EventParticles[k].Mass_Invariant(EventParticles[h]);
                        h6->Fill (m);    //mass invariant
                        if((EventParticles[k].Get_P_charge() * EventParticles[h].Get_P_charge())<0){
                            h7->Fill(m);    //mass invariant opposite charge
                            h12->Fill(m);
                        }
                        else if((EventParticles[k].Get_P_charge() * EventParticles[h].Get_P_charge())>0) {
                            h8->Fill(m);          //mass invariant same charge
                            h13->Fill(m);
                        }  

                        int k_index=EventParticles[k].Get_fIndex();
                        int h_index=EventParticles[h].Get_fIndex();
                        if((k_index==0 && h_index==3)||(k_index==1 && h_index==2)||(k_index==3 && h_index==0)||(k_index==2 && h_index==1)){
                            h10->Fill(m); //mass invariant opposite charge k p
                            h15->Fill(m);
                        }
                        else if ((k_index==0 && h_index==2)||(k_index==1 && h_index==3)||(k_index==3 && h_index==1)||(k_index==2 && h_index==0)){
                            h9->Fill(m);       //mass invariant same charge k p
                            h14->Fill(m);
                        }
                    
                }
            }

        }
        EventParticles.clear();
        resonance.clear();

    }
TFile *Analize = new TFile("Data.root", "RECREATE");

    for (int i = 0; i < 15; ++i)
    {

        if (i == 1)
        {
            Canvases[i]->cd();
            Histos[i]->DrawCopy("LEGO");
            Histos[i]->Write();
        }
        else
        {
            Canvases[i]->cd();
            Histos[i]->DrawCopy();
            Histos[i]->Write();
        }
    }
     Analize->Write();

    Analize->Close();
};
