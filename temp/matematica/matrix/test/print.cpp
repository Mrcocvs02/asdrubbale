#include <iostream>
#include <vector>
#include <string>
bool is_even(int n){
    return n % 2 == 0;
};
void print (std::vector<std::vector<long int>>& a){
    std::string number;
    std::vector<int> memory(a[0].size());
    for (int j = 0; j < a.size(); j++){
        std::vector<int> dimension(a[0].size());     
        std::cout <<"| ";
        for (int i = 0; i < a[0].size(); i++){
            number = std::to_string(a[j][i]);
            dimension[i] = number.size();
            if (j!=0){
                if (is_even(abs(memory[i]-dimension[i]))){
                for(int k = 0; k <(abs((memory[i]-dimension[i]))/2); k++){
                        std::cout << " ";
                    }
                }
                else {
                    for(int k = 0; k <=(abs(memory[i]-dimension[i])/2); k++){
                            std::cout << " ";
                    }
                }
            }
            std::cout << a[j][i] << " ";
            if (j!=0){
                if (is_even(abs(memory[i]-dimension[i]))){
                    for(int k = 0; k <(abs(memory[i]-dimension[i])/2); k++){
                        std::cout << " ";
                    }
                }
                else {
                    for(int k = 0; k <(abs((memory[i]-dimension[i]))/2); k++){
                            std::cout << " ";
                    }
                }
            }
            number.clear();
        }
        std::cout <<"|"<< '\n';    
        dimension.clear();

    }
};
int main(){
    std::vector<std::vector<long int>> A;
    std::vector <long int> riga{1,263435,3,4};
    std::vector <long int> riga1{1,3,265,4};
    A.push_back(riga);
    A.push_back(riga1);
    A.push_back(riga);
    A.push_back(riga1);

    print(A);
}