#include <iostream>
class Complex {
    private:
        double r;
        double i;
    public:
        Complex (double x, double y) : r{x}, i{y} {}
        double real() { return r; }
        double imag() { return i; }
};
double norm (Complex c) {
        return c.real() * c.real() + c.imag() * c.imag();
    }
Complex operator+ (Complex c1, Complex c2){
        return Complex {c1.real() + c2.real() , c1.imag() + c2.imag()};
    }
Complex operator- (Complex c1, Complex c2){
        return Complex {c1.real() - c2.real() , c1.imag() - c2.imag()};
    }
Complex operator* (Complex c1, Complex c2){
        return Complex {c1.real() * c2.real() - c1.imag() * c2.imag() , c1.imag() * c2.real() + c2.imag() * c1.real()};
    }
Complex operator/ (Complex c1, Complex c2){
        return Complex {(c1.real() * c2.real() + c1.imag() * c2.imag())/(c2.real() * c2.real() + c2.imag() * c2.imag()) ,( c1.imag() * c2.real() - c2.imag() * c1.real())/(c2.real() * c2.real() + c2.imag() * c2.imag())};
    }
int main() {
    double a;
    double b;
    double c;
    double d;
    char o;
    std::cin >> a  >> b >> o >> c >> d;
    switch (o){
        case '+': {
            Complex c1 {a, b};
            Complex c2 {c, d};
            Complex res = c1 + c2;
             double A = res.real();
             double B = res.imag();
             std::cout << 'A' << "+" << B << 'i' << '\n';
             break;
        }
        case '-':{
            Complex c1 {a, b};
            Complex c2 {c, d};
            Complex res = c1 - c2;
            double A = res.real();
            double B = res.imag();
            std::cout << A << "+" << B << 'i' << '\n';
            break;
        }
        case '*':{
            Complex c1 {a, b};
            Complex c2 {c, d};
            Complex res = c1 * c2;
            double A = res.real();
            double B = res.imag();
            std::cout << A << "*" << B << 'i' << '\n';
            break;
        }
        case '/':{
            Complex c1 {a, b};
            Complex c2 {c, d};
            Complex res = c1 / c2;
            double A = res.real();
            double B = res.imag();
            std::cout << A << "/" << B << 'i' << '\n';
            break;
        }
        default:
            std::cout << "invalid values" << '\n';
            break;
    }
}