#include "ResonanceType.hpp"
ResonanceType::ResonanceType(char* fName_, double fMass_, int fCharge_, double fWidth_):
ParticleType{fName_, fMass_, fCharge_},
fWidth{fWidth_}{}
void ResonanceType::Print() const
{
    std::cout << Get_fName() << " of mass " << Get_fMass() << " of charge " << Get_fCharge() << " " <<Get_Width() << "."<< '\n';
}