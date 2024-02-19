//Daniel Braun Sandino
//Ejercicio 1
#include <iostream>
#include <cmath>
#include <array>
using namespace std;

class Circulo{
private:
    float radio;
    float area;

public:

    //Constructor por defecto con radio que valga 10
    Circulo(): radio(10), area(0){

    }

    //Constructor con inicializador de radio
    Circulo(float r): radio(r), area(0){

    }

    //Constructor con parámetros
    Circulo(float r, float a): radio(r), area(a) {

    }

    //Constructor por copia
    Circulo(const Circulo &otro): radio(otro.radio), area(otro.radio){

    }

    //Setters
    void setRadio(float r){
        radio = r;
    }

    void setArea(float a){
        area = a;
    }

    //Getters
    float getRadio() const{
        return radio;
    }

    float getArea() const{
        return area;
    }

    //Devolver Area a partir de un radio
    float calcularArea(float r){
        float ar{0};
        const float pi{3.14};
        ar = pi * pow(r,2);

        return ar;
    }

};

int main(){
    //Circulo 1 de radio 10cm
    Circulo C1 = Circulo(); //USO EL DE POR DEFECTO Radio = 10 (auto)

    //Circulo 2 de radio 5cm
    Circulo C2 = Circulo(5); //USO EL DE INICIALIZADOR DE RADIO

    //Circulo 3 de radio 15cm
    Circulo C3 = Circulo(15); //USO EL DE INICIALIZADOR DE RADIO

    //--------------------------------------

    //MOSTRAR LAS AREAS
    array<Circulo, 3> almacenDeCirculos{C1,C2,C3};

    for(int i{0} ; i<almacenDeCirculos.size() ; i++){
        cout<<"Circulo "<<i+1<<": "<<endl;
        cout<<"Radio: "<<almacenDeCirculos.at(i).getRadio()<<endl;
        cout<<"Area: "<<almacenDeCirculos.at(i).calcularArea(almacenDeCirculos.at(i).getRadio())<<endl;
        cout<<endl;
    }


    return 0;
}
