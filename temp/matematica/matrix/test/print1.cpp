#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
bool is_even(int n){
    return n % 2 == 0;
};
       void print_matrix ( std::vector<std::vector<long double>>a, std::string l){
            std::vector<int> distance;
            std::string n;
            for (int i=0; i< a[0].size();i++){
                std::vector<int> temp;
                for(int j=0; j< a.size();j++){

                        long int c=(a[j][i]*100000);
                        while (c%10==0){
                        c=c/10;
                            }

                    n=std::to_string(c);            
                    temp.push_back(n.size()+1); 


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
int main(){
    std::vector<std::vector<long double>> A;
    std::vector <long double> riga{124.34,23.43,54.6};
    std::vector <long double> riga1{1,3,265,4,1,2,3};
    A.push_back(riga);
    A.push_back(riga1);
    A.push_back(riga);
    A.push_back(riga);
    A.push_back(riga1);
     std::string l="A";
    print_matrix(A,l);
}