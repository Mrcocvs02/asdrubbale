#include "ParticleType.hpp"
#include "ResonanceType.hpp"

#include <array>
#include <algorithm>
#include <iostream>

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
    static ParticleType *fParticleType[11];
    static const int fMaxNumParticleType=10;
    static int fNParticleType;
    int fIndex;

    double fPx;
    double fPy;
    double fPz;
    
    int static FindParticle(const char* Name_);
public:
    Particle( char* Name_, double fPx_, double fPy_, double fPz_ );
    void static AddParticleType(char* Name_,double Mass_, double Charge_, double Width_);
    void Set_fIndex(int i);
    void Set_fIndex(char* Name_);
    void static Print_ParticleType();
    void Print_Index();
    double const Print_fPx(){return fPx;};
    double const Print_fPy(){return fPy;};
    double const Print_fPz(){return fPz;};
};

#endif
