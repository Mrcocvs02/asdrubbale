#include <iostream>
int pow (int a, int b)
{
    int c = 1;
    int d = a;
    while (c < b) {
        d = d * a;
        ++c;
    }
    return d;
}
/*int main ()
 {
int a;
int b;
std::cin>> a >> b;
int res = pow(a, b);
std::cout << res << '\n';
}
*/