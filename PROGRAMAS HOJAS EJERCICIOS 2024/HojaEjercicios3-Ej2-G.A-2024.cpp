//Daniel Braun Sandino
//Hoja de Ejercicios 3 - Ejercicio 2

#include <iostream>

using namespace std;

class Complejo{
private:
    int real;
    int imaginaria;

public:
    //CONSTRUCTOR POR DEFECTO
    Complejo(): real(0), imaginaria(0){

    }

    //CONSTRUCTOR POR PARAMETROS
    Complejo(int r, int i): real(r), imaginaria(i){

    }

    //GETTERS
    int getReal()const {
        return real;
    }

    int getImaginaria()const {
        return imaginaria;
    }

    //SETTERS SIN PARAMETROS
    void setReal(){
        cout<<"Introduce la parte real del numero: "<<endl;
        cin>>real;
    }

    void setImaginaria(){
        cout<<"Introduce la parte imaginaria del numero: "<<endl;
        cin>>imaginaria;
    }

    //SETTERS CON PARAMETROS
    void setReal(int r){
        real = r;
    }

    void setImaginaria(int i){
        imaginaria = i;
    }

    //METODO PARA MOSTRAR NUMERO COMPLEJO
    void mostrarNumero(Complejo &c)const {
        cout<<c.real<<" + "<<c.imaginaria<<"i"<<endl;
    }

    /*
    //SOBRECARGA PARA SUMAR NUMEROS COMPLEJOS
    Complejo operator +(const Complejo &n1, const Complejo &n2){
        int sumaReal = n1.real + n2.real;
        int sumaImagianria = n1.imaginaria + n2.imaginaria;

        Complejo nSumaTotal(sumaReal, sumaImagianria);

        return nSumaTotal;
    }
    */

    /*
    //SOBRECARGA PARA SUMAR NUMEROS COMPLEJOS
    Complejo operator +(const Complejo &c){
        int sumaReal = c.real + c.real;
        int sumaImagianria = c.imaginaria + c.imaginaria;

        Complejo nSumaTotal(sumaReal, sumaImagianria);

        return nSumaTotal;
    }
    */

};


//SOBRECARGA PARA SUMAR NUMEROS COMPLEJOS
Complejo operator +(const Complejo &n1, const Complejo &n2){
    int sumaReal = n1.getReal() + n2.getReal();
    int sumaImagianria = n1.getImaginaria() + n2.getImaginaria();

    Complejo nSumaTotal(sumaReal, sumaImagianria);

    return nSumaTotal;
}

//SOBRECARGA PARA RESTAR NUMEROS COMPLEJOS
Complejo operator -(const Complejo &n1, const Complejo &n2){
    int restaReal = n1.getReal() - n2.getReal();
    int restaImagianria = n1.getImaginaria() - n2.getImaginaria();

    Complejo nRestaTotal(restaReal, restaImagianria);

    return nRestaTotal;
}



int main(){
    Complejo n1, n2, n3, n4;
    Complejo n9(12,5);
    Complejo n10(20,8);

    n1.setReal();
    n1.setImaginaria(5);

    cout<<"Numero Complejo = ";
    n1.mostrarNumero(n1);

    cout<<endl;

    //-----------------------------

    n2.setReal(2);
    n2.setImaginaria();

    cout<<"Numero Complejo: ";
    n2.mostrarNumero(n2);

    cout<<endl;

    //-----------------------------
    //SUMA
    n3 = n1 + n2;

    cout<<"Suma de Numeros Complejo: ";
    n3.mostrarNumero(n3);

    cout<<endl;

    //-----------------------------
    //RESTA
    n4 = n10 - n9;

    cout<<"Resta de Numeros Complejo: ";
    n4.mostrarNumero(n4);

    cout<<endl;


    return 0;
}
