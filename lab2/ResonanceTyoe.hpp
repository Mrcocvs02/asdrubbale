#include "ParticleType.hpp"

class ResonanceType : ParticleType{
    const  double fWidth;
    public:
    double get_fWidth() const{return fWidth;}
    void Print()const;

}