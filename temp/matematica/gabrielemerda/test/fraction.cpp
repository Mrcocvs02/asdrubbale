#include <iostream>
#include <vector>

class polynom {
    public:
    std::vector <double> u1;
    std::vector <double> u2;
        void structure (int n, int a){
            switch (a) {
                case 1:
                    for (int i=0; i<=n; i++) {
                        double value;
                        std::cin >> value;
                        u1.push_back(value);
                    };
                case 2:
                     for (int i=0; i<=n; i++)  {
                        double value;
                        std::cin >> value;
                        u2.push_back(value);
                    };
            }
        };        
        std::vector<double> extract ( int a, int n) {
             std::vector<double> k(n);
                switch (a) {
                    case 1:
                        for (int i = 0; i = u1.size()-1; i++){
                            k.push_back(u1[i]);
                        }
                    case 2:
                        for (int i = 0; i = u2.size()-1; i++){
                            k.push_back(u2[i]);
                        }
                }
                return k;
        };
        void stampa (std::vector <double> u){
            int exponent; 
            int order=0;
                for (exponent = u.size()-1;exponent>=0; exponent--){
                    if (exponent >=2){
                    std::cout << u[order] <<"X^" << exponent << " + ";
                    }
                    else if (exponent ==1){
                    std::cout << u[order] <<"X" << " + ";
                    }
                    else if (exponent ==0){
                        std::cout << u[order] << '\n';
                    }
                    else {
                        break;
                    }
                    order++;
                }
            order=0;
        };
};

std::vector<double> division (std::vector<double> v1, std::vector<double> v2, bool c){
    double multiplier = v1[0]/v2[0];
    int n1= v1.size();
    int n2= v2.size();
    std::vector<double> partial_result;
    std::vector<double> partial_rest;
    std::vector<double> result;    
        while(v1.size()>=v2.size()){
            for (int i=0; i<=n2;i++){
                partial_result.push_back(multiplier*v2[i]);
            };
            for (int i=0; i<=n1;i++){
                partial_rest.push_back(v1[i]-partial_result[i]);
            };
            for (int i=0; i<=n1;i++){
                v1[i]=partial_rest[i];
            };
        };
        switch (c){
            case true : 
                return partial_result; 
            case false :
                return partial_rest;
        }         
};

int main () {
    int n1; 
    int n2;
    std::vector <double> v1;    
    std::vector <double> v2;
    polynom eq;

    std::cout <<"insert the degree of the second polynom (smallest degree) "<<'\n';
    std::cin >> n2;    
    std::cout <<"insert the coefficients of the second polynom of degree "<< n2 <<'\n';
    eq.structure(n2, 2);
    std::cout <<"your second polynom is:" <<'\n';    
    v2 = eq.extract(2, n2);
    eq.stampa(v2);

    std::cout <<"insert the degree of the first polynom (greatest degree) "<<'\n';
    std::cin >> n1;
    std::cout <<"insert the coefficients of the first polynom of degree "<< n1 <<'\n';
    eq.structure(n1, 1);
    std::cout <<"your first polynom is:" <<'\n';
    v1 = eq.extract(1, n1);
    eq.stampa(v1);






}