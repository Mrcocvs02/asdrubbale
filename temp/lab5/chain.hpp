#include <iostream>
#include <vector>
#include <cmath>
struct PPState{
    double m{};
    double x{};
    double v{};
};
class Hooke{
        double m_k;
        double m_l;

    public:
        Hooke (double k, double l): m_k {k}, m_l {l} {};
        double operator()(PPState const& p1, PPState const& p2) const{
            double force = (abs(p2.x-p1.x)-m_l)*m_k;
            //std::cout<< force <<'\n';
            return force;
        }
};

class Chain {
  Hooke m_inter;
  std::vector<PPState> m_ppses;

  public:

  Chain(Hooke const& inter): m_inter{inter}{};

  void push_back(PPState const& pps){
    m_ppses.push_back(pps);
  };

  int size() const{
      return m_ppses.size();
  };

  void evolve(double delta_t){
      std::vector<PPState> temp = m_ppses;
      for(int i=0;i<size();i++){
          if (i==0){
            double a_i = m_inter(m_ppses[i],m_ppses[i+1])/m_ppses[i].m;
              temp[i].v += a_i*delta_t;  
              temp[i].x += m_ppses[i].v*delta_t + 0.5*a_i*delta_t*delta_t;
          }
          
          else if(i!=0 && i!=(size()-1)){
              double a_i = (-m_inter(m_ppses[i-1],m_ppses[i])+m_inter(m_ppses[i],m_ppses[i+1]))/m_ppses[i].m;
              temp[i].v += a_i*delta_t;  
              temp[i].x += m_ppses[i].v*delta_t + 0.5*a_i*delta_t*delta_t;  
          }
          
          else if (i==size()-1){
            double a_i = -m_inter(m_ppses[i-1],m_ppses[i])/m_ppses[i].m;
              temp[i].v += a_i*delta_t;  
              temp[i].x += m_ppses[i].v*delta_t + 0.5*a_i*delta_t*delta_t;
          }
      }
      m_ppses = temp;
  };

  std::vector<PPState> const& state() const{
      return m_ppses;
  };  
};
/*int main(){
    Chain c{Hooke{0.1, 2.}};
c.push_back({1., 0., 0.5});
c.push_back({1., 2., 0.});
c.push_back({1., 4., 0.});
const auto state_i = c.state();
c.evolve(1.0);
const auto state_f = c.state();
std::cout <<state_f[0].x<<"-"<<state_f[0].v<<"-"<<state_f[1].x<<"-"<<state_f[1].v<<"-"<<state_f[2].x<<"-"<<state_f[2].v<<"-"<<'\n';
c.evolve(1.0);
std::cout <<state_f[0].x<<"-"<<state_f[0].v<<"-"<<state_f[1].x<<"-"<<state_f[1].v<<"-"<<state_f[2].x<<"-"<<state_f[2].v<<"-"<<'\n';

}*/