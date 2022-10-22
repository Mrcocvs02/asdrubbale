#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

        std::vector<long double> sum (std::vector<long double> a, std::vector  <long double> b){
            for(int i=0;i<a.size();i++){
                a[i]+=b[i];
            }
            return a;
        };

bool is_even(int n){
    return n % 2 == 0;
};

void print_matrix ( std::vector<std::vector<long double>>a, std::string l){
            std::vector<int> distance;
            std::string n;
            for (int i=0; i< a[0].size();i++){
                std::vector<int> temp;
                for(int j=0; j< a.size();j++){
                    n=std::to_string(a[j][i]);            
                    temp.push_back(n.size());
                    std::cout<< n.size();        
                }
                std::sort(temp.begin(), temp.end());
                distance.push_back(temp[temp.size()-1]);
                temp.clear();
        
            };
            for (int j=0; j<a.size();j++ ){
                if (j==(a.size()/2)){
                    std::cout<< l <<"=";
                }
                else{
                    for(int i=0; i<= l.size();i++){
                    std::cout<<" ";
                    }
                }
                std::cout <<"| ";
                for(int i=0;i<a[0].size();i++){
                    n=std::to_string(a[j][i]);
                        if(is_even(abs(n.size()-distance[i]))){
                            for(int q=0;q<(abs(n.size()-distance[i])/2);q++){
                                std::cout <<" ";
                            }   
                        }
                        else{
                            for(int q=0;q<((1+abs(n.size()-distance[i]))/2);q++){
                                std::cout <<" ";
                            } 
                         }
                    std::cout << a[j][i];
                        for(int q=0; q<=(abs(n.size()-distance[i])/2);q++){
                            std::cout <<" ";
                        }
                }
                std::cout <<"|"<< '\n';
                }
        };

bool is_not_empty(std::vector<long double> a){
    int sum=0;
    bool k;
    for (int i=0; i<a.size();i++){
        sum+=a[i];
        if (sum!=0){
            k=true;
        }
        else{
            k=false;
        }
    }
    return k;
}

        std::vector<long double> product (std::vector<long double>a,long double b){
            for (int i=0; i< a.size(); i++){
                a[i]*=b;
            }
            return a;
        }

std::vector<std::vector<long double>> gauss(std::vector<std::vector<long double>>a){
    for(int j=0;j< a.size();j++){
        if(is_not_empty(a[j])){
            for(int k=j+1;k< a.size();k++){
                long double c = a[k][j]/a[j][j];
                a[k]= sum(a[k],product(a[j], (-c)));
                print_matrix(a,"A");
                std::cout<<c<<"p";
            }
        }
        else {
            std::cout<<"the matrix could not be diagonalized"<<'\n';
        }
    }  
    return a;
};

int main(){
    std::vector<std::vector<long double>> A;
    std::vector<std::vector<long double>> B;
    std::vector <long double> riga{4,8,4,};
    std::vector <long double> riga1{4,8,4};
    std::vector <long double> riga2{4,5,6};
    std::vector <long double> riga3{7,5,90};
    A.push_back(riga);
    A.push_back(riga1);
    A.push_back(riga2);
    A.push_back(riga3);
 
    B=gauss(A);
    print_matrix(B,"B");
}