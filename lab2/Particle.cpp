#include "Particle.hpp"

int Particle::FindParticle(const char *Name_)
{
    auto Index = std::find(fParticleType[0], fParticleType[fMaxNumParticleType], Name_);
    int Position = std::distance(fParticleType[0], Index);

    return Position;
}

Particle::Particle(char *Name_, double fPx_, double fPy_, double fPz_)
    : fIndex{FindParticle(Name_)},
      fPx{fPx_},
      fPy{fPy_},
      fPz{fPz_}
{
    if (FindParticle(Name_) == fMaxNumParticleType + 1)
    {
        std::cout << "No corrispondence find for the particle name " << '\n';
    };
}

void Particle::AddParticleType(char *Name_, double Mass_, double Charge_, double Width_)
{
    if ((FindParticle(Name_) != fMaxNumParticleType + 1) && (fNParticleType <= fMaxNumParticleType))
    {
        auto NewParticleType = &ParticleType(Name_, Mass_, Charge_);
        fParticleType[fNParticleType + 1] = NewParticleType;
    };
}

void Particle::Set_fIndex(int i){
    if(fParticleType[i]!=0){};

}

void Particle::Set_fIndex(char* Name_){

}
void Particle::Print_ParticleType(){
    auto Print_=[](const char* n){std::cout <<n<<" ";};
    std::for_each(fParticleType[0],fParticleType[fMaxNumParticleType],Print_);
    std::cout<<'\n';
}

void Particle::Print_Index(){
    std::cout<<fIndex<<'\n';
}

