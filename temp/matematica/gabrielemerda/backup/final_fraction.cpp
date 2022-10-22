#include <iostream>
#include <vector>


class polynom {
    public:
    std::vector <double> v;
    void structure (int n){
        int i =0; 
        v.erase(v.begin(), v.end());       
        while (i<=n)  {
            double value;
            std::cin >> value;
            v.push_back(value);
            i++;
        };
    }
    std::vector <double> extract (){
        return v;
    }

};
void stampa (std::vector <double> equation){
    int exponent; 
    int correct=0;
        for (exponent = equation.size()-1;exponent>=0; exponent--){
            if (exponent >=2){
            std::cout << equation[correct] <<"X^" << exponent << " + ";
            }
            else if (exponent ==1){
            std::cout << equation[correct] <<"X" << " + ";
            }
            else if (exponent ==0){
                std::cout << equation[correct] << '\n';
            }
            else {
                break;
            }
            correct++;
        }
        correct=0;
};

std::vector <double> division (std::vector <double> v1, std::vector <double>v2, int c){
    std::vector<double> divisor;
    std::vector<double> partial_subtructor;
    std::vector<double> result;
    std::vector<double> k;
        divisor=v1;   
        while(divisor.size()>=v2.size()){
            partial_subtructor.clear();
            double multiplier = divisor[0]/v2[0]; 
            for (int i=0; i<divisor.size(); i++){
                partial_subtructor.push_back(v2[i]*multiplier);
            }
            for (int i=0; i<partial_subtructor.size(); i++){
                divisor[i]= (divisor[i] - partial_subtructor[i]);
            }        
            while (divisor.size()>1 && divisor[0] == 0){
                divisor.erase(divisor.begin());
            }
            result.push_back(multiplier);
        };
        switch (c)
        {
            case 1:
                k = result;
                break;
            case 2:
                k= divisor; 
                break;
        }
    return k;
};

int main () {
    int n1; 
    int n2;
    std::vector <double> v1;    
    std::vector <double> v2;
    std::vector <double> final_result;
    std::vector <double> final_rest;    
    polynom eq;         
    std::cout <<"insert the degree of the first polynom (greatest degree)"<<'\n';
    std::cin >> n1;
    std::cout <<"insert the degree of the second polynom (smallest degree)"<<'\n';
    std::cin >> n2;
    std::cout <<"insert the coefficients of the first polynom of degree"<< n1 <<'\n';
    eq.structure(n1);
    std::cout <<"your first polynom is:" <<'\n';
    v1 = eq.extract();
    stampa(v1);
    std::cout <<"insert the coefficients of the second polynom of degree"<< n2 <<'\n';
    eq.structure(n2);
    std::cout <<"your second polynom is:" <<'\n';    
    v2 = eq.extract();
    stampa(v2);
    final_result = division(v1,v2, 1);
    final_rest = division(v1,v2, 2);    
    std::cout << final_result[0]<<'\n';
}
