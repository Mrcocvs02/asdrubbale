#include <iostream>
char lowercase (char a){
    a = tolower (a); 
    return a;
}
int main (){
    char a;
    std::cin >> a;
    char res = lowercase(a);
    std::cout << res <<"\n";
}