#include "Particle.hpp"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH3F.h"
#include "TMath.h"
#include "TRandom.h"

R__LOAD_LIBRARY( Particle_cpp.so );
R__LOAD_LIBRARY( ParticleType_cpp.so );
R__LOAD_LIBRARY( ResonanceType_cpp.so );

void data(){
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

    TH1F* h1=new TH1F  ("Type", "Type Distribution", 7, 0, 1);
TH3F *h2 = new TH3F("h2", "Angle distribution", 100, -1, 1, 100, -1, 1, 100, -1, 1);
    TH1F*  h3=new TH1F  ("Impulse", "Impulse", 1000, 0, 5);
    TH1F*  h4=new TH1F  ("Trasvers Impulse", "Trasverse Impulse", 1000, 0, 5);
    TH1F*  h5=new TH1F  ("Energy", "Energy Distribution", 1000, 0, 30);
    TH1F*  h6=new TH1F  ("Mass Invariant", "Mass Invariant", 1000, 0, 30);
    TH1F*  h7=new TH1F  ("Mass Invariant Opposite Charge", "Mass Invariant Of Opposite Charge", 1000, 0, 30);
    TH1F*  h8=new TH1F  ("Mass Invariant Same Charge", "Mass Invariant Of Same Charge", 1000, 0, 30);
    TH1F*  h9=new TH1F  ("Mass Invariant Same Charge(K,P)", "Mass Invariant Of Same Charge (K,P)", 1000, 0, 30); 
    TH1F*  h10=new TH1F  ("Mass Invariant Oppsoite Charge(K,P)", "Mass Invariant Of Oppsoite Charge (K,P)", 1000, 0, 30);    
     TH1F*  h11=new TH1F  ("Mass Invariant Resonance", "Mass Invariant Resonance", 1000, 0, 30);
    


    for(int i=0; i<1E5;i++){
        std::vector <Particle> resonance;
        for (int j=0; j<100; j++){
            double phi= gRandom->Uniform(0,2*M_PI);
            double theta= gRandom->Uniform(0, M_PI);

            h2->Fill(cos(theta) * sin(phi), sin(theta) * sin(phi), cos(phi)); //angle

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
                Particle A{pionem};
                Particle B{Kaonep};
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

                for(long unsigned int k=0; k< EventParticles.size();k++){
                    for (long unsigned int h=k; h<EventParticles.size();h++){
                        double m = EventParticles[k].Mass_Invariant(EventParticles[h]);
                        h6->Fill (m);    //mass invariant
                        if((EventParticles[k].Get_P_charge() * EventParticles[h].Get_P_charge())<0){
                            h10->Fill(m);    //mass invariant opposite charge
                        }
                        else if((EventParticles[k].Get_P_charge() * EventParticles[h].Get_P_charge())>0) {
                            h8->Fill(m);          //mass invariant same charge
                        }  
                        int pp = Particle{pionep}.Get_fIndex();
                        int pm = Particle{pionem}.Get_fIndex();
                        int kp = Particle{Kaonep}.Get_fIndex();
                        int km = Particle{Kaonem}.Get_fIndex();

                        int k_index=EventParticles[k].Get_fIndex();
                        int h_index=EventParticles[h].Get_fIndex();
                        if((k_index==pp && h_index==km)||(k_index==pm && h_index==kp)||(k_index==km && h_index==pp)||(k_index==kp && h_index==pm)){
                            h10->Fill(m); //mass invariant opposite charge k p
                        }
                        else if ((k_index==pp && h_index==kp)||(k_index==pm && h_index==km)||(k_index==km && h_index==pm)||(k_index==kp && h_index==pp)){
                            h9->Fill(m);       //mass invariant same charge k p
                        }
                    }
                }
            }

        }
    }


