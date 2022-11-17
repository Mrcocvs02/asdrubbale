#include "ResonanceType.hpp"
#include "ParticleType.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
    static std::vector<ParticleType*> fParticleType;
    static const int fMaxNumParticleType=10;
    static int fNParticleType;
    int fIndex;

    double fPx;
    double fPy;
    double fPz;
    
    int static FindParticle( char* Name_);

    
  void Boost(double bx, double by, double bz);
public:
    Particle( char* Name_, double fPx_, double fPy_, double fPz_ );
     Particle( char* Name_);
    void static AddParticleType(char* Name,double Mass, int Charge, double Width);
    void static AddParticleType(char* Name,double Mass, int Charge);
    void Set_fIndex(int i);
    void Set_fIndex(char* Name_);
    int Get_fIndex()const;
    void static Print_ParticleType();
    void Print_Index()const;
    void Print_particle()const;
    double  Get_fPx()const;
    double  Get_fPy()const;
    double  Get_fPz()const;
    double Get_Mass()const ;
    double Get_Energy()const;
    double Mass_Invariant(Particle& p)const;
    void Set_P(double Px_,double Py_,double Pz_);
      int Decay2body(Particle &dau1,Particle &dau2) const;
      double Get_P_charge()const;
};

#endif