#include "ParticleType.hpp"

class ResonanceType : ParticleType{
    const  double fWidth;
    public:
    ResonanceType(double fWidth_);
    double get_fWidth() const{return fWidth;};
    void Print()const;

};