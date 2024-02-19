//Daniel Braun Sandino
//Hoja de ejercicios Nº2
//Ejercicio 1

#include <iostream>

using namespace std;

class CalcularNumPositivo{
private:
    float numero;
    float resultado;

public:
    //CONSTRUCTOR POR DEFECTO
    CalcularNumPositivo(): numero(0), resultado(0){

    }

    //CONSTRUCTOR POR PARAMETRO
    CalcularNumPositivo(float n, float r): numero(n), resultado(r){

    }

    //CONSTRUCTOR POR COPIA
    CalcularNumPositivo(CalcularNumPositivo &otro): numero(otro.numero), resultado(otro.resultado){

    }

    //SETTER
    void setNumero(float n){
        numero = n;
    }

    void setResultado(float r){
        resultado = r;
    }

    //GETTERS
    float getNumero(){
        return numero;
    }

    float getResultado(){
        return resultado;
    }

    //METODO PARA SUMAR
    float sumaNum(float num){
        numero = num;
        resultado = resultado + numero;
        return resultado;
    }

    //METODO PARA RESTAR
    float restaNum(float num){
        numero = num;
        resultado -= numero;
        return resultado;
    }

    //METODO PARA MULTIPLICAR
    float multiplicaPor(float num){
        numero = num;
        resultado *= numero;
        return resultado;
    }

    //METODO PARA DIVIDIR
    float dividePor(float num){
        numero = num;
        resultado /= numero;
        return resultado;
    }

};

int main(){
    CalcularNumPositivo operacion1 = CalcularNumPositivo();
    float num;
    int opcion;

    do{
        cout<<"Seleccione una opcion: "<<endl;
        cout<<"1. Sumar."<<endl;
        cout<<"2. Restar."<<endl;
        cout<<"3. Multiplicar."<<endl;
        cout<<"4. Dividir."<<endl;
        cin>>opcion;

        switch(opcion){
        case 1:{
            //SUMAR
            cout<<"Dame un numero: "<<endl;
            cin>>num;

            operacion1.sumaNum(num);
            cout<<"Numero actual: "<<operacion1.getResultado()<<endl;

            cout<<"---------------------"<<endl;

            break;
        }

        case 2:{
            //RESTAR
            cout<<"Dame un numero: "<<endl;
            cin>>num;

            operacion1.restaNum(num);
            cout<<"Numero actual: "<<operacion1.getResultado()<<endl;

            cout<<"---------------------"<<endl;

            break;
        }

        case 3:{
            //MULTIPLICAR
            cout<<"Dame un numero: "<<endl;
            cin>>num;

            operacion1.multiplicaPor(num);
            cout<<"Numero actual: "<<operacion1.getResultado()<<endl;

            cout<<"---------------------"<<endl;
            break;
        }

        case 4:{
            //DIVIDIR
            cout<<"Dame un numero: "<<endl;
            cin>>num;

            try{
                if(num<=0){
                    throw string ("error");

                }else{
                    operacion1.dividePor(num);

                    cout<<"Numero actual: "<<operacion1.getResultado()<<endl;
                }

            }catch(string &e)
            {
                cout<<e<<endl;
            }

            cout<<"---------------------"<<endl;

            break;
        }

        default:{
            //ERROR
            cout<<"Opcion no valida."<<endl;
        }

        }


    }while(opcion > 0 && opcion < 5);


    return 0;
}
