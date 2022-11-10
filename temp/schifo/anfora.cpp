#include <iostream>
class ind
{
    int an1; //max5
    int an2; //max3
    public: 
        ind () {an1; an2;}
    int getan1 () {
        return an1;
    }
    int getan2 (){
        return an2;
    }
    void fullan1(){
        an1=5;
    }
    void fullan2(){
        an2=3;
    }
        void empty1(){
        an1=0;
    }
    void empty2(){
        an2=0;
    }
    void travaso1_2(){
        if (an1+an2>3){
            int c = 3-an2;
            an1 -= c;
            an2 =3; 
        }
        else {
            an2 += an1;
            an1 = 0;
        }
    }
    void travaso2_1(){
        if (an1+an2>5){
            int c = 5-an1;
            an2 -= c;
            an1 = 5;
        }
        else {
            an1 += an2;
            an2 = 0; 
        }
    }
};
int main (){
    ind k; 
    int c;
    std::cout <<"anfor 1 conteins " << k.getan1() <<" liters, "<< "anfor 2 conteins " << k.getan2() << " liters "<< '\n';
    std::cout <<"press a series of operations to obtain 4 liters in anfor 1" <<'\n' << 
        "1 riempi anfora 1" <<'\n' << 
        "2 riempi anfora 2"<<'\n' << 
        "3 svuota anfora 1"<<'\n' <<
        "4 svuota anfora 2"<<'\n' <<
        "5 travasa anfora 1 in anfora 2"<<'\n'<<
        "6 travasa anfora 2 in anfora 1"<<'\n';
    do
    {
        std::cin >> c;
            switch (c){
                case 1:
                    k.fullan1();
                    break;
                case 2:
                    k.fullan2();
                    break;
                case 3:
                    k.empty1();
                    break;
                case 4:
                    k.empty2();
                    break;
                case 5:
                    k.travaso1_2();
                    break;
                case 6:
                    k.travaso2_1();
                    break; 
                case 0:
                    exit;
                    break;       
            }
            int a = k.getan1();
            int b = k.getan2();
            std::cout <<"anfor 1 conteins " << a <<" liters, "<< "anfor 2 conteins " << b << " liters "<< '\n';
    } while (k.getan1() != 4);
    std::cout << "marrogay è orgoglioso di te, hai vinto" << '\n';
}