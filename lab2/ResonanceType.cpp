#include "ResonanceType.hpp"

ResonanceType::ResonanceType(char* fName_, double fMass_, int fCharge_, double fWidth_):
ParticleType(fName_, fMass_, fCharge_),
fWidth{fWidth_}{}

