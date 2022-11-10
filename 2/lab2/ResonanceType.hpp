#include "ParticleType.hpp"


#ifndef RESONANCETYPE_HPP
#define RESONANCETYPE_HPP



class ResonanceType : public ParticleType{
    const double fWidth;
    public:
    ResonanceType(char* fName_, double fMass_, int fCharge_, double fWidth_);
    ~ResonanceType();
    double Get_Width() const override{return fWidth;};
    void Print()const override;

};

#endif