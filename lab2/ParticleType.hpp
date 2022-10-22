#include <iostream>
class ParticleType
{
    const char* fName;
    const double fMass;
    const int fCharge;

public:
ParticleType(char* fName_, double fMass_, int fCharge_);

char* get_fName() const{return fName;};
double get_fCharge() const{return fCharge;};
int get_fMass() const{return fMass;};

void Print()const;


};