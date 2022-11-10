#include <iostream>
bool is_prime(long int a){
    bool ans = true ;
    for (long int i = 2; i < a; ++i) {
        long int b = a % i;
        if (b == 0){
           ans = false;
        }
    }
    return ans;
}
int main ()
 {
long int a;
std::cin>> a;
if( bool res = is_prime(a)==1){
    std::cout << "suca" << '\n';
}
else{
    std::cout << "800A" << '\n';
}
}