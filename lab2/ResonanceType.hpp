#include "ParticleType.hpp"

#ifndef RESONANCETYPE_HPP
#define RESONANCETYPE_HPP

class ResonanceType : public ParticleType{
    const  double fWidth;
    public:
    ResonanceType(char* fName_, double fMass_, int fCharge_, double fWidth_);
    double get_fWidth() const{return fWidth;};
    void Print()const;

};

#endif