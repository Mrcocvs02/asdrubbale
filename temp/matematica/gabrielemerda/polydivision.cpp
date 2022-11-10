#include <iostream>
#include <vector>
#include <math.h>

class polynom{
    public:
    long double insert_value(void){
        long double a;
        std::cin >>a;
         while(std::cin.fail()) {
            std::cout << "Gabriele Merda non fare il biricchino" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> a;
        }
        return a;
    };

    std::vector <long double> structure (long int n){
        std::vector <long double> v;
        long int i =0; 
        v.erase(v.begin(), v.end());       
        for(int i=0; i<=n;i++) {
            long double value;
            value = insert_value();
            v.push_back(value);
        }
        return v;
    }
    void print (std::vector <long double> equation,int c){
    int exponent; 
    int correct=0;
    std::vector <long double> empty;
        switch(c){
            case 1:
                std::cout <<"Your result is: ";
                break;
            case 2:
                std::cout<<"your rest is: ";
            default:
                break;
        }
        if (empty==equation){
            std::cout<<"0"<<'\n';
        }
        for (exponent = equation.size()-1;exponent>=0; exponent--){
            if (exponent >=2){
                if(equation[correct+1]>0 && correct==0){
                    std::cout << equation[correct] <<"X^" << exponent << " + ";
                }
                else if (equation[correct+1]<0 && correct==0) {
                    std::cout << equation[correct] <<"X^" << exponent << " - ";
                }
                else if (equation[correct+1]>0 && correct!=0){
                    std::cout << fabs(equation[correct]) <<"X^" << exponent << " + ";
                }
                else if (equation[correct+1]<0 && correct!=0) {
                    std::cout << fabs(equation[correct]) <<"X^" << exponent << " - ";
                }                
            }
            else if (exponent ==1){
                if(equation[correct+1]>0){
                    std::cout << fabs(equation[correct]) <<"X^" << exponent << " + ";
                }
                else {
                    std::cout << fabs(equation[correct]) <<"X^" << exponent << " - ";
                }
            }
            else if (exponent ==0){
                std::cout << fabs(equation[correct]) << '\n';
            }
            else {
                break;
            }
            correct++;
        }
        correct=0;
    }
    std::vector <long double> division (std::vector <long double> v1, std::vector <long double>v2, int c){
        std::vector<long double> divisor;
        std::vector<long double> partial_subtructor;
        std::vector<long double> result;
        std::vector<long double> k;
        int q=0;
        divisor = v1;
        long double multiplier;   
            while(divisor.size()>=v2.size()){
                partial_subtructor.clear();
                multiplier = divisor[0]/v2[0]; 
                for (int i=0; i< v2.size(); i++){
                    partial_subtructor.push_back(v2[i]*multiplier);
                }
                for (int i=0; i<partial_subtructor.size(); i++){
                    divisor[i]= (divisor[i] - partial_subtructor[i]);
                }        
                divisor.erase(divisor.begin());
                result.push_back(multiplier);
            };
            switch (c){
                case 1:
                    k = result;
                    break;
                case 2:
                    k= divisor; 
                    break;
                default:
                    break;
            }
            for (int i=0; i<k.size();i++){
                if(k[i]!=0){
                    q++;
                }             
            }
            if (q==0){
                k.clear();
            }
    return k;
    };
};
class fractional{
    public:
        long int gcd(long int a,long int b){
            if (b==0){
                return a;
            }
            a = a % b;
            return gcd (b,a);
        };
        long int conversion (long double a, int b, int c){
            long double q = pow(0.260620460100,2);
            long int mcd;
            long int d = pow(10,b);
            long int f = d * q;
            long int e = a * f;
            long int h = gcd(e,f);
            long int num = e/h;
            long int den = f/h;
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

        };
        void print_fraction (std::vector <long int> equation_num,std::vector <long int> equation_den, int c){
        int exponent; 
        int correct=0;
        std::vector <long int> empty;
            switch(c){
                case 1:
                    std::cout <<"Your result is: ";
                    break;
                case 2:
                    std::cout<<"your rest is: ";
                default:
                    break;
            }
            if (empty==equation_num){
                std::cout<<"0"<<'\n';
            }
            for (exponent = equation_num.size()-1;exponent>=0; exponent--){
                if (exponent >=2){
                    if(equation_num[correct+1]/equation_den[correct+1]>0 && correct==0){
                        std::cout << equation_num[correct]<<"/"<< equation_den[correct]<<"X^" << exponent << " + ";
                    }
                    else if (equation_num[correct+1]/equation_den[correct+1]<0 && correct==0) {
                        std::cout <<  equation_num[correct]<<"/"<< equation_den[correct] <<"X^" << exponent << " - ";
                    }
                    else if (equation_num[correct+1]/equation_den[correct+1]>0 && correct!=0){
                        std::cout << fabs (equation_num[correct])<<"/"<< fabs(equation_den[correct]) <<"X^" << exponent << " + ";
                    }
                    else if (equation_num[correct+1]/equation_den[correct+1]<0 && correct!=0) {
                        std::cout << fabs( equation_num[correct])<<"/"<< fabs(equation_den[correct]) <<"X^" << exponent << " - ";
                    }                
                }
                else if (exponent ==1){
                    if(equation_num[correct+1]>0){
                        std::cout << fabs( equation_num[correct])<<"/"<< fabs(equation_den[correct]) <<"X^" << exponent << " + ";
                    }
                    else {
                        std::cout << fabs( equation_num[correct])<<"/"<< fabs(equation_den[correct]) <<"X^" << exponent << " - ";
                    }
                }
                else if (exponent ==0){
                    std::cout << fabs(equation_num[correct])<<"/"<< fabs(equation_den[correct]) << '\n';
                }
                else {
                    break;
                }
                correct++;
            }
            correct=0;
        };
};

int main () {
    fractional fr;
    polynom po;
    int n1;
    int n2;
    std::string p;
    std::vector<long double> u1;
    std::vector<long double> u2;
    std::cout <<"insert the degree of the first polynom (rational values are gonna be trunced)"<<'\n';
    n1 = po.insert_value(); 
    std::cout <<"insert the degree of the second polynom (rational values are gonna be trunced)"<<'\n';
    n2 = po.insert_value(); 
    std::cout <<"insert the coefficients of the first polynom of degree "<< n1 <<'\n';
    u1= po.structure (n1);
    std::cout <<"your first polynom is:" <<'\n';
    po.print(u1,0);
    std::cout <<"insert the coefficients of the second polynom of degree "<< n2 <<'\n';
    u2= po.structure (n2);
    po.print(u2,0);
    std::vector<long double> final_result;
    std::vector<long double> final_rest;
    final_result = po.division(u1,u2,1);
    final_rest = po.division (u1,u2,2);
    po.print(final_result,1);
    po.print(final_rest,2);


    std::cout <<"Do you want the fractional approximation of the coefficients?(y for yes, n for no)" <<'\n';
    std::cin >> p;
    int rounding_precision;
    std::vector <long int> result_num(final_result.size());
    std::vector <long int> result_den(final_result.size());
    std::vector <long int> rest_num(final_rest.size());
    std::vector <long int> rest_den(final_rest.size());
        if (p!="y" && p!="n"){
            while(p!="y" && p!="n") {
            std::cout <<"ho detto y o n brutta testa di cazzo"<<'\n';
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> p;
            }
        }
        if(p=="y"){
            std::cout <<"how many decimal palcese do yuo want to preserv when rounding?"<<'\n';
            rounding_precision = po.insert_value();
            for (int i=0; i<final_result.size();i++){
                result_num[i]= fr.conversion(final_result[i], rounding_precision, 1);
                result_den[i]= fr.conversion(final_result[i], rounding_precision, 2);
            }   
            for (int i=0; i<final_rest.size();i++){
                rest_num[i]= fr.conversion(final_rest[i], rounding_precision, 1);
                rest_den[i]= fr.conversion(final_rest[i], rounding_precision, 2);
            }    
            fr.print_fraction(result_num, result_den, 1);
            fr.print_fraction(rest_num, rest_den, 2);
        }
        else if (p=="n"){
            std::cout<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<< "Grazie per il pacco di tic tac bro"<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<"<Gabriele merda"<<'\n';
        }        
}