
#include <iostream>
int lcm (int a, int b){
    int c = a;
    int n = 1;
    while (c % b !=0){
        ++n;
        c = n*a;
    }
    return c;
}
int main ()
 {
int a;
int b;
std::cin>> a >> b;
int res = lcm(a, b);
std::cout << res << '\n';
}