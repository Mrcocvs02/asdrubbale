#include "Particle.hpp"
#include "ParticleType.hpp"
#include "ResonanceType.hpp"

int main(){
    char* name=new char {'g'};
    char* name1=new char {'j'};
    char* name2=new char {'h'};
     char* name3=new char {'l'};
    Particle gino = Particle(name,4,3,5);
    Particle giulio_gay = Particle(name2,1,7,6);
    Particle f = Particle(name1,2,3,8);
    Particle::Print_ParticleType();
    Particle giulio_gay2 = Particle(name2,1,7,6);
    Particle::Print_ParticleType();
    Particle::AddParticleType(name3,12,5);
    Particle::Print_ParticleType();
    std::cout <<f.Mass_Invariant(gino)<<'\n';
    std::cout <<f.Get_Energy()<<'\n';
    f.Print_particle();


}
