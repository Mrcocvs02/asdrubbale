#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
bool is_even(int n){
    return n % 2 == 0;
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

class matrix{
    public:

        std::vector<long double> sum (std::vector<long double> a, std::vector  <long double> b){
            for(int i=0;i<a.size();i++){
                a[i]+=b[i];
            }
            return a;
        };


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
                    }
                }
                else {
                    std::cout<<"the matrix could not be diagonalized"<<'\n';
                }
            }  
            return a;
        };


        long double insert_value(void){
            long double a;
            std::cin >>a;
                while(std::cin.fail()) {
                    std::cout << "Wrong type of input, try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                std::cin >> a;
               }    
            return a;
        };


        std::vector<std::vector<long double>> structure (long int n, long int m){
            std::vector<std::vector<long double>> matrix;
                for(int i = 0; i < n; i++){
                    std::vector <long double> line;
                        for(int j = 0; j < m; j++){
                            long double a = insert_value();
                            line.push_back(a);
                        }
                matrix.push_back(line);
                }
            return matrix;
        };
        

        std::vector<std::vector<long double>> multiplication (std::vector<std::vector<long double>>A, std::vector<std::vector<long double>>B){
            std::vector<std::vector<long double>> result; 
            std::vector<long double> result_line;           
                if (A[0].size()!=B.size()){
                    std::cout <<"The multiplication is not possible"<<'\n';
                };
                for (int k = 0; k <A.size(); k++){   
                    for (int j=0; j < B[0].size(); j++){
                        long double pruduct = 0; 
                        for(int i = 0; i < B.size(); i++){
                            pruduct += (A[k][i]*B[i][j]);
                        }
                        result_line.push_back(pruduct);     
                    }
                    result.push_back(result_line);
                    result_line.clear();
                }
            return result;
        };


        void print_matrix ( std::vector<std::vector<long double>>a, std::string l){
            std::vector<int> distance;
            std::string n;
            for (int i=0; i< a[0].size();i++){
                std::vector<int> temp;
                for(int j=0; j< a.size();j++){
                    n=std::to_string(a[j][i]);            
                    temp.push_back(n.size());        
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

};



int main() {
    long int nA;
    long int nB;
    long int mA;
    long int mB;
    std::cout<< "Insert the dimension of the first matrix:";
    std::cin >> nA >> mA;
    std::cout<< "Insert the dimension of the second matrix:";
   // std::cin >> nB >> mB;
    matrix mtx;
    std::cout<< "Insert the coefficients of the first matrix:";
    std::vector<std::vector<long double>> A = mtx.structure(nA,mA);
    mtx.print_matrix (A,"A");
    std::cout <<'\n';
    std::cout<< "Insert the coefficients of the second matrix:";
  //  std::vector<std::vector<long double>> B = mtx.structure(nB,mB);
    //mtx.print_matrix (B,"B");
    std::cout <<'\n';
 //   std::vector<std::vector<long double>> C = mtx.multiplication(A,B);
   // mtx.print_matrix (C,"A*B");

    std::vector<std::vector<long double>> D =mtx.gauss(A);
    mtx.print_matrix(D,"D");
}

