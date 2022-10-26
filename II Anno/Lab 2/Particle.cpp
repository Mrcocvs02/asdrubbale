#include "Particle.hpp"

int Particle::fNParticleType=0;
std::array<ParticleType*,10> Particle::fParticleType{};

int Particle::FindParticle(char *Name_)
{
    auto check=[Name_](auto temp){ return (temp.get_fName()==Name_);};
    auto Index = std::find_if(fParticleType[0], fParticleType[fMaxNumParticleType], check );
    int Position = std::distance(fParticleType[0], Index);

    return Position;
}

Particle::Particle(char *Name_, double fPx_, double fPy_, double fPz_)
    : fPx{fPx_},
      fPy{fPy_},
      fPz{fPz_}
{
    if (FindParticle(Name_) == fMaxNumParticleType+1)
    {
        std::cout << "No corrispondence found for the particle name " << '\n';
    }
    else {fIndex=FindParticle(Name_);};
}
Particle::Particle( char* Name_):
fPx{0},
      fPy{0},
      fPz{0}{
    if (FindParticle(Name_) == fMaxNumParticleType)
    {
        std::cout << "No corrispondence found for the particle name " << '\n';
    }
    else {fIndex=FindParticle(Name_);};
}

void Particle::AddParticleType(char *Name_, double Mass_, double Charge_)
{
    if ((FindParticle(Name_) != fMaxNumParticleType) && (fNParticleType < fMaxNumParticleType))
    {
        auto NewParticleType =new ParticleType(Name_, Mass_, Charge_);
        fParticleType[fNParticleType] = NewParticleType;
    };
}
void  Particle::AddParticleType(char* Name_,double Mass_, double Charge_, double Width_){
        if ((FindParticle(Name_) != fMaxNumParticleType) && (fNParticleType < fMaxNumParticleType))
    {
        auto NewParticleType =new ResonanceType(Name_, Mass_, Charge_, Width_);
        fParticleType[fNParticleType] = NewParticleType;
    };
}

void Particle::Set_fIndex(char* Name_){
    fIndex = FindParticle(Name_);
}

void Particle::Print_ParticleType(){
    auto Print=[](ParticleType temp){temp.Print();};
    std::for_each(fParticleType[0],fParticleType[fMaxNumParticleType],Print);
}

void Particle::Print_Index()const{
    std::cout<<fIndex<<'\n';
}
double Particle::Get_Mass()const{
    return fParticleType[fIndex]->get_fMass();
}

double Particle::Get_Energy()const{
    double Energy=sqrt(pow(Get_Mass(),2)+pow(Get_fPx(),2)+pow(Get_fPy(),2)+pow(Get_fPz(),2));
    return Energy;
}

double Particle::Mass_Invariant(Particle& p) const{
    double Mass_Invariant_=sqrt(pow(Get_Energy()+p.Get_Energy(),2)-(pow(fPx+p.Get_fPx(),2)+pow(fPy+p.Get_fPy(),2)+pow(fPz+p.Get_fPz(),2)));
    return Mass_Invariant_;
}
void Particle::Set_P(double Px_,double Py_,double Pz_){
    fPx=Px_;
    fPy=Py_;
    fPz=Pz_;
}

void Particle::Print_particle(){
    std::cout <<fIndex <<", "<<fParticleType[fIndex]->get_fName()<<", "<<fPx<<", "<<fPy<<", "<<fPz<<'\n';
}