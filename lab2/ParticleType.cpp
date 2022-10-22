# include "ParticleType.hpp"

ParticleType::ParticleType(char* fName_, double fMass_, int fCharge_){
    fName{fName_},
    fMass{fMass_},
    fCharge{fCharge_}{}
}

void ParticleType::Print() const{
    std::cout<< get_fName()<<" of mass " << get_fMass() <<" of charge "<< get_fCharge()<<"."<<'\n';
}