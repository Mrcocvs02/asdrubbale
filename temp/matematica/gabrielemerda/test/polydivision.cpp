#include <iostream>
#include <vector>
#include <math.h>
  void print (std::vector <long double> polynom,int c){
    int exponent; 
    int position=0;
        switch(c){
            case 1:
                std::cout <<"Your result is: ";
                break;
            case 2:
                std::cout<<"your rest is: ";
            default:
                break;
        }
        for (exponent = polynom.size()-1;exponent>=0; exponent--){
            if (exponent >=2){
                if(polynom[position+1]>0 && position==0){
                    std::cout << polynom[position] <<"X^" << exponent << " + ";
                }
                else if (polynom[position+1]<0 && position==0) {
                    std::cout << polynom[position] <<"X^" << exponent << " - ";
                }
                else if (polynom[position+1]>0 && position!=0){
                    std::cout << fabs(polynom[position]) <<"X^" << exponent << " + ";
                }
                else if (polynom[position+1]<0 && position!=0) {
                    std::cout << fabs(polynom[position]) <<"X^" << exponent << " - ";
                }                
            }
            else if (exponent ==1){
                if(polynom[position+1]>0){
                    std::cout << fabs(polynom[position]) <<"X^" << exponent << " + ";
                }
                else {
                    std::cout << fabs(polynom[position]) <<"X^" << exponent << " - ";
                }
            }
            else if (exponent ==0){
                std::cout << fabs(polynom[position]) << '\n';
            }
            else {
                break;
            }
            position++;
        }
        position=0;
    }
    std::vector <long double> division (std::vector <long double> dividend, std::vector <long double>divisor, int c){
        std::vector<long double> partial_subtructor;
        std::vector<long double> result;
        std::vector<long double> k;
        long double multiplier;   
            while(dividend.size()>=divisor.size()){
                partial_subtructor.clear();
                multiplier = dividend[0]/divisor[0]; 
                for (int i=0; i< divisor.size(); i++){
                    partial_subtructor.push_back(divisor[i]*multiplier);
                }
                for (int i=0; i<partial_subtructor.size(); i++){
                    dividend[i]= (dividend[i] - partial_subtructor[i]);
                }
                std::cout <<"multiplier: "<<multiplier<<'\n';
                print(divisor,0);
                std::cout <<"partial_subtructor: "<<partial_subtructor[0]<<'\n';
                print(dividend,0);
                dividend.erase(dividend.begin());
                result.push_back(multiplier);
            };
            switch (c){
                case 1:
                    k = result;
                    break;
                case 2:
                    k= dividend; 
                    break;
                default:
                    break;
            }
    return k;
    };
     std::vector <long double> structure (long int n){
        std::vector <long double> v;
        long int i =0; 
        v.erase(v.begin(), v.end());       
        for(int i=0; i<=n;i++) {
            long double value;
            std::cin >> value;
            v.push_back(value);
        }
        return v;
    };
int main () {
    std::vector<long double> u1=structure(7);
    print(u1,0);
    std::vector<long double> u2=structure(3);
    print(u2,0);
    std::vector<long double> result;
    int a=1;
    result = division(u1,u2,a);


    print (result,1);
}