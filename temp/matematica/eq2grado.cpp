#include <iostream>
#include <cmath>
#include <vector>
std::vector <double> function (double a, double b, double c){
    double res1 = 0;
    double res2 = 0;
    double d = sqrt((b*b)-(4*a*c));
    std::vector <double> v{0, 0};
    if (a=0)
    {
        res1 = -(c/b);
        v[0]= res1;
        return v;
    }
    else if (d<0){
        return v;
    }
    else {
        res1 = (-b - d)/(2*a);
        res2 = (-b + d)/(2*a);
        v[0] = res1 ;
        v[1] = res2 ; 
        return v;
    }
}
int main() {
    double a;
    double b;
    double c;

    std::cin>> a  >> b >> c;
    std::vector <double> u{0,0};
    u = function (a, b, c);
    std::cout << u[0] << u[1] << '\n';
} 