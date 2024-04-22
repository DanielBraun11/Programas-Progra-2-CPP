//Daniel Braun Sandino
//Ejemplos de herencias - Miembros que NO se heredan - Funcionamiento de contructores y destructores

#include <iostream>

using namespace std;

class CBase{
private:
    int b1;
    int b2;

public:
    int b3;

    //CONTRSUCTOR POR DEFECTO
    CBase():b1(0), b2(1), b3(2){
        cout<<"Constructor CBase: "<<endl;
        cout<<"b1 -> "<<b1<<endl;
        cout<<"b2 -> "<<b2<<endl;
        cout<<"b3 -> "<<b3<<endl;
    }

    //CONSTRUCTOR POR PARAMETROS
    CBase(int n1, int n2, int n3):b1(n1), b2(n2), b3(n3){
        cout<<"Constructor CBase: "<<endl;
        cout<<"b1 -> "<<b1<<endl;
        cout<<"b2 -> "<<b2<<endl;
        cout<<"b3 -> "<<b3<<endl;
    }

    //DESTRUCTOR CLASE BASE
    ~CBase(){
        cout<<"Hola Base"<<endl;
    }


};

class CDerivada: public CBase{
private:
    float f1;
    char c1;

public:
    //CONSTRUCTOR POR PARAMETROS - SOLO DE LA DERIVADA
    CDerivada(float d, char e): f1(d), c1(e){
        cout<<"Constructor CDerivada: "<<endl;
        cout<<"f1 -> "<<f1<<endl;
        cout<<"c1 -> "<<c1<<endl;
    }

    //CONSTRUCTOR POR PARAMTEROS - CON LOS ATRB. DE LA BASE
    CDerivada(int a, int b, int c, float d, char e):CBase(a,b,c){
        f1 = d;
        c1 = e;

        cout<<"Constructor CDerivada: "<<endl;
        cout<<"f1 -> "<<f1<<endl;
        cout<<"c1 -> "<<c1<<endl;
    }

    //DESTRUCTOR CLASE DERIVADA
    ~CDerivada(){
        cout<<"Hola Derivada "<<endl;
    }
};


int main(){

    CDerivada od1 (5.2, 'm');

    CDerivada od2 (11, 22, 33, 15.25, 'm');



    cout<<endl;
    return 0;
}
