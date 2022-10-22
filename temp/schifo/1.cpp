/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Indovinello
{
    int anf1;
    int anf2;
    public:
    Indovinello(){anf1=0;anf2=0;}
    int getAnfora1(){return anf1;}
    int getAnfora2(){return anf2;}
    void riempi1(){anf1=3;}
    void riempi2(){anf2=5;}
    void svuota1(){anf1=0;}
    void svuota2(){anf2=0;}
    void travasa2in1()
    {
        int vuoto1=3-anf1;
        if(vuoto1<anf2)
        {
            anf2=anf2-vuoto1;
            anf1=3;
        }
        else
        {
            anf1=anf1+anf2;
            anf2=0;
        }
    }
    void travasa1in2()
    {
        int vuoto2=3-anf2;
        if(vuoto2<anf1)
        {
            anf1=anf1-vuoto2;
            anf2=3;
        }
        else
        {
            anf2=anf2+anf1;
            anf1=0;
        }
    }
};

int main()
{
    Indovinello ind;
    char c;
    do
    {
        cout<<"l'anfora 1 contiene "<<ind.getAnfora1();
        cout<<"l'anfora 2 contiene "<<ind.getAnfora2();
        cout<<endl;
        cout<<"cosa vuoi che faccia"<<endl;
        cout<<"1 riempi anfora 1"<<endl;
        cout<<"2 riempi anfora 2"<<endl;
        cout<<"3 svuota anfora 1"<<endl;
        cout<<"5 travasa anfora 1 in anfora 2"<<endl;
        cout<<"6 travasa anfora 2 in anfora 1"<<endl;cout<<"4 svuota anfora 2"<<endl;
        cin>>c;

        switch(c)
        {
        case 1:
            ind.riempi1();
            break;
        case 2:
            ind.riempi2();
            break;
        case 3:
            ind.svuota1();
            break;
        case 4:
            ind.svuota2();
            break;
        case 5:
            ind.travasa1in2();
            break;
        case 6:
            ind.travasa2in1();
            break;
        default:;
        }

    }while(ind.getAnfora2()==4);
    cout<<"hai vinto";


}