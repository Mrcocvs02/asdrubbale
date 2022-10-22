#include <iostream>
#include <vector>
#include <math.h>       
       
        long int gcd(long int a,long int b){
            if (b==0){
                return a;
            }
            a = a % b;
            return gcd (b,a);
        };
        long int conversion (long double a,long int b, int c){
            long int e = a*b;
            long int h = gcd(e,b);
            long int num = e/h;
            long int den = b/h;
            long int k;
                switch(c){
                    case 1:
                        k = num;
                        break;
                    case 2:
                        k = den;
                        break;
                }           
            return k;
        }
int main(){
    int d;
    long double a;
    long double c= pow(0.260620460100,2);
    std::cin>>d >>a;
    long int f = pow(10,d);
    long int i = f * c;
    std::cout << i <<'\n';
    long int num = conversion (a, i,1);
    long int den = conversion (a,i,2);
    std::cout << num <<'\n'<< den <<'\n';
}

