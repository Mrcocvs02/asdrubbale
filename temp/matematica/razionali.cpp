#include <iostream>
#include <iomanip>
#include <cmath> 
#include <vector>

long int gcd(long int a, long int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
};

std::vector <long int> conversion (long double a,long int b){
    std::vector <long int> k;
    long int mcd;
    long double s = a*b; 
    long int y= (int)(s);
    mcd= gcd(y, b);
    long int num = y/mcd;
    long int den = b/mcd;
    k.push_back(num);
    k.push_back(den);
    return k;
};

int main (){
    long double rational;
    long int n;
    std::vector <long int> fraction;
    std::cin>> rational >> n;
    long int f= pow(10,n);
    fraction= conversion (rational, f);
    std::cout << fraction[0] << " " << fraction [1] <<'\n';
}