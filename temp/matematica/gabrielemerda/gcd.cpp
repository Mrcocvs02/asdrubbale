#include <iostream>
long int gcd(long int a,long int b){
    if (b==0){
        return a;
    }
    a = a % b;
    return gcd (b,a);
};
int main(){
    long int a;
    long int b;
    long int c;
    std::cin >>a >>b;
    c = gcd (a,b);
    std::cout<<c<<'\n';
}