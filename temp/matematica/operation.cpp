#include "pow.cpp"
#include <iostream>
double operation(double a, char o, double b)
{
    double c; 
    if (o == '+'){
         c = a + b;
    }
    else if (o == '-'){
         c = a - b;
    }
    else if (o == '*'){
         c = a * b;
    }    
    else if (o == '/'){
         c = a / b;
    }
    else if (o =='^'){
         c = pow (a, b); 
    }
    else {
        c = 0;
    }
    return c;
}
int main () {
    double a;
    double b;
    char o;
    std:: cin>> a >> o >> b;
    double res = operation (a, o, b);
    std::cout << res << '\n';
}