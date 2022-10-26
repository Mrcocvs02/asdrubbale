#include "ParticleType.hpp"
#include "ResonanceType.hpp"

#include <array>
#include <algorithm>
#include <iostream>
#include <cmath>

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
    static std::array<ParticleType*,10> fParticleType;
    static const int fMaxNumParticleType=10;
    static int fNParticleType;
    int fIndex;

    double fPx;
    double fPy;
    double fPz;
    
    int static FindParticle( char* Name_);
public:
    Particle( char* Name_, double fPx_, double fPy_, double fPz_ );
    Particle( char* Name_);
    void static AddParticleType(char* Name_,double Mass_, double Charge_, double Width_);
    void static AddParticleType(char* Name_,double Mass_, double Charge_);
    void Set_fIndex(int i){fIndex=i;};
    void Set_fIndex(char* Name_);
    void static Print_ParticleType();
    void Print_Index()const;
    void Print_particle();
    double  Get_fPx()const{return fPx;};
    double  Get_fPy()const{return fPy;};
    double  Get_fPz()const{return fPz;};
    double Get_Mass()const ;
    double Get_Energy()const;
    double Mass_Invariant(Particle& p)const;
    void Set_P(double Px_,double Py_,double Pz_);
};

#endif