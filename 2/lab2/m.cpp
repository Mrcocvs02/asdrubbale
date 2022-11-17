#include "Particle.hpp"
#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TRandom.h"
#include <vector>
void MainModule()
{
    
    std::vector<Particle> EventParticles;
std::vector<Particle> Resonance;
    std::vector<Particle> Decay;
    char *P = new char('P');
    char *p = new char('p');
    char *K = new char('K');
    char *k = new char('k');
    char *D = new char('D');
    char *d = new char('d');
    char *N = new char('N');
    Particle::AddParticleType(P, 0.13957, 1);        // positive pion
    Particle::AddParticleType(p, 0.13957, -1);       // negative pion
    Particle::AddParticleType(K, 0.49267, 1);        // positive Kaon
    Particle::AddParticleType(k, 0.49367, -1);       // negative Kaon
    Particle::AddParticleType(D, 0.93827, 1);        // positive proton
    Particle::AddParticleType(d, 0.93827, -1);       // negative proton
    Particle::AddParticleType(N, 0.89166, 0, 0.050); // K

    gRandom->SetSeed();
    TH1F *h1 = new TH1F("h1", "type Distribution", 7, 0, 7); // types of generated particles

    TH2F *h2 = new TH2F("h2", "Angle distribution", 100, 0, 2 * TMath::Pi(), 100, 0, TMath::Pi()); // angle distribution

    TH1F *h3 = new TH1F("h3", "Impulse Distribution", 1000, 0, 5);
    TH1F *h4 = new TH1F("h4", "Trasverse Impulse Distribution", 1000, 0, 5);
    TH1F *h5 = new TH1F("h5", "Energy Distribution", 1000, 0, 10);
    TH1F *h6 = new TH1F("h6", "Invariant mass", 1000, 0, 8);
    // h6->Sumw2();

    TH1F *h7 =
        new TH1F("h7", "Invariant mass between discord charge", 1000, 0, 8);
    // h7->Sumw2();
    TH1F *h8 = new TH1F("h8", "Invariant mass between same charge particles",
                        1000, 0, 8);
    // h8->Sumw2();
    TH1F *h9 = new TH1F("h9", "Invariant mass between specific particles (1)",
                        1000, 0, 8);
    // h9->Sumw2();
    TH1F *h10 = new TH1F("h10", "Invariant mass between specific particles (2)",
                         1000, 0, 8);
    // h10->Sumw2();
    TH1F *h11 =
        new TH1F("h11", "Invariant mass between decayed products", 1000, 0.5, 1.2);
    // h11->Sumw2();

    // same histos with different ranges for fitting
    TH1F *h12 = new TH1F("h12", "Invariant mass between discord charge new range", 100, 0.7, 1.05);
    TH1F *h13 = new TH1F("h13", "Invariant mass between same charge particles new range", 100, 0.7, 1.05);
    h12->Sumw2();
    h13->Sumw2();
    TH1F *h14 = new TH1F("h14", "Invariant mass between specific particles (1) new range", 100, 0, 2);
    TH1F *h15 = new TH1F("h15", "Invariant mass between specific particles (2) new range", 100, 0, 2);
    h14->Sumw2();
    h15->Sumw2();

    TH1 *HTOT[15] = {h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15};
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

    TCanvas *CTOT[15] = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15};

    for (int i{5

         };
         i < 11; ++i)
    {
        HTOT[i]->GetXaxis()->SetTitle("Invariant Mass (GeV/c^2)");
        HTOT[i]->SetTitleSize(0.05, "x");
        HTOT[i]->GetYaxis()->SetTitle("entries");
        HTOT[i]->SetTitleSize(0.05, "y");
        HTOT[i]->SetLineColor(kBlack);
        HTOT[i]->SetFillColor(kGray);
    };

    double x = 0;
    for (int i{0}; i < 1E5; ++i)
    {
        for (int j{0}; j < 100; ++j)
        {
            double Phi = gRandom->Rndm() * 2 * TMath::Pi(); // azimuthal coordinate
            double Theta = gRandom->Rndm() * TMath::Pi();   // polar coordinate
            double m = gRandom->Exp(1);                     // impulse
            h2->Fill(Phi, Theta);

            h3->Fill(m);
            double Px = m * sin(Theta) * cos(Phi); // polar coordinates to cartesian
            double Py = m * sin(Theta) * sin(Phi);
            double Pz = m * cos(Theta);
            h4->Fill(sqrt((Px * Px) + (Py * Py)));
            x = gRandom->Rndm();

            if (x < 0.4)
            {
                Particle a = Particle(P, Px, Py, Pz);

                EventParticles.push_back(a);
            }
            else if (x >= 0.4 && x < 0.8)
            {
                Particle a = Particle(p, Px, Py, Pz);

                EventParticles.push_back(a);
            }
            else if (x >= 0.8 && x < 0.85)
            {
                Particle a = Particle(K, Px, Py, Pz);

                EventParticles.push_back(a);
            }
            else if (x >= 0.85 && x < 0.9)
            {
                Particle a = Particle(k, Px, Py, Pz);

                EventParticles.push_back(a);
            }
            else if (x >= 0.9 && x < 0.945)
            {
                Particle a = Particle(D, Px, Py, Pz);

                EventParticles.push_back(a);
            }
            else if (x >= 0.945 && x < 0.99)
            {
                Particle a = Particle(d, Px, Py, Pz);

                EventParticles.push_back(a);
            }
            else if (x >= 0.99 && x < 0.995)
            {
                Particle temp = Particle(N, Px, Py, Pz);
                Particle A = Particle(p);
                Particle B = Particle(K);

                temp.Decay2body(A, B);
                Decay.push_back(temp);
                Resonance.push_back(A);
                Resonance.push_back(B);
                h11->Fill(A.GetInvariantMass(B));
            }
            else
            {
                Particle temp = Particle(N, Px, Py, Pz);
                Particle A = Particle(P);
                Particle B = Particle(k);

                temp.Decay2body(A, B);
                Decay.push_back(temp);
                Resonance.push_back(A);
                Resonance.push_back(B);
                h11->Fill(A.GetInvariantMass(B));
            }
        }

        for (auto k : EventParticles)
        {
            h1->Fill(k.GetfIndex());
            h5->Fill(k.GetEnergy());
        }

        for (auto k : Decay)
        {
            h1->Fill(k.GetfIndex());
            h5->Fill(k.GetEnergy());
        }

        for (auto k : Resonance)
        {
            EventParticles.push_back(k);
        }

        int size = EventParticles.size();

        for (int i = 0; i < size - 1; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                Particle a = EventParticles[i];
                Particle b = EventParticles[j];
                double GetInvariantMass = a.GetInvariantMass(b);
                h6->Fill(GetInvariantMass);
                if (a.getPCharge() != b.getPCharge())
                {
                    h7->Fill(GetInvariantMass);
                    h12->Fill(GetInvariantMass);
                }
                if (a.getPCharge() == b.getPCharge())
                {
                    h8->Fill(GetInvariantMass);
                    h13->Fill(GetInvariantMass);
                }
                if ((a.GetfIndex() == 0 && b.GetfIndex() == 3) ||
                    (a.GetfIndex() == 1 && b.GetfIndex() == 2))
                {
                    h9->Fill(GetInvariantMass);
                    h14->Fill(GetInvariantMass);
                }
                if ((a.GetfIndex() == 0 && b.GetfIndex() == 2) ||
                    (a.GetfIndex() == 1 && b.GetfIndex() == 3))
                {
                    h10->Fill(GetInvariantMass);
                    h15->Fill(GetInvariantMass);
                }
            }
        }

        EventParticles.clear();
        Resonance.clear();
        Decay.clear();
    }

    TFile *Analize = new TFile("Data.root", "RECREATE");

    for (int i = 0; i < 15; ++i)
    {

        if (i == 1)
        {
            CTOT[i]->cd();
            HTOT[i]->DrawCopy("LEGO");
            HTOT[i]->Write();
        }
        else
        {
            CTOT[i]->cd();
            HTOT[i]->DrawCopy();
            HTOT[i]->Write();
        }
    }
    // Analize->Write();

    Analize->Close();
};
