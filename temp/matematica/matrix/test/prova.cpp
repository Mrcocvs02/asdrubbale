#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    long double p=124.34;
    std::string r;
    long int c=(p*100000);
    while (c%10==0){
        c=c/10;
    }
    r= std::to_string(c);
    std::cout<<r.size();
} 

