#include "ParticleType.hpp"

ParticleType::ParticleType(char *fName_, double fMass_, int fCharge_)
    : fName{fName_},
      fMass{fMass_},
      fCharge{fCharge_} {}

void ParticleType::Print() const
{
    std::cout << Get_fName() << " of mass " << Get_fMass() << " of charge " << Get_fCharge() << "." << '\n';
}