

#ifndef PARTICLETYPE_HPP
#define PARTICLETYPE_HPP

#include <iostream>

class ParticleType
{
    const char* fName;
    const double fMass;
    const int fCharge;

public:
    ParticleType(char* fName_, double fMass_, int fCharge_);

    const char* Get_fName() const { return fName; };
    double Get_fCharge() const { return fCharge; };
    double Get_fMass() const { return fMass; };
    virtual double Get_Width() const{return 0;};

    virtual void Print() const;
};

#endif