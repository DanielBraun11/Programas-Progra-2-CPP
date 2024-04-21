//Daniel Braun Sandino
//Ejemplos de herencias - Figuras Geometricas

#include <iostream>
#include <cmath>

using namespace std;

class figuraGeometrica{

private:
    int nLados;
    float longitud;

public:
    //CONSTRUCTOR DEFECTO
    figuraGeometrica():nLados(0), longitud(0){

    }

    //CONSTRUCTOR PARAMETRICO
    figuraGeometrica(int nL, float(l)):nLados(nL), longitud(l){

    }

    //GETTERS
    int getNumLados()const {
        return nLados;
    }

    float getLongitud()const {
        return longitud;
    }

    //SETTERS
    void setNumLados(int nL){
        nLados = nL;
    }

    void setLongitud(float l){
        longitud = l;
    }

    //METODO CALULAR PERIEMTRO
    float calcularPerimetro(){
        float perimetro;

        perimetro = nLados * longitud;

        return perimetro;
    }
};

class trianguloEquilatero: public figuraGeometrica{
private:
    float altura;

public:
    //CONSTRUCTOR POR DEFECTO
    trianguloEquilatero():altura(0){

    }

    //CONSTRUCTOR POR PARAMETROS
    trianguloEquilatero(float a): altura(a){

    }

    //GETTERS
    float getAltura()const{
        return altura;
    }

    //SETTERS
    void setAltura(float a){
        altura = a;
    }

    //CALCULAR ALTURA
    void calcularAltura(float l){
        altura = sqrt(pow(l,2) + pow(l,2));
    }
};

class cuadrado: public figuraGeometrica{
private:
    float diagonal;

public:
    //CONSTRUCTOR POR DEFECTO
    cuadrado():diagonal(0){

    }

    //CONSTRUCTOR POR PARAMETRO
    cuadrado(float d):diagonal(d){

    }

    //GETTERS
    float getDiagonal()const{
        return diagonal;
    }

    //SETTERS
    void setDiagonal(float d){
        diagonal = d;
    }

    //METODO PARA CALCULAR LA DIAGONAL
    void calcularDiagonal(float l){
        diagonal = sqrt(pow(l,2) + pow(l,2));
    }
};

int main(){
    trianguloEquilatero T1, T2;
    cuadrado C1(3), C2;

    T1.setNumLados(3);
    T1.setLongitud(5.2);

    T2.calcularAltura(5);

    cout<<"El perimetro es: "<<T1.calcularPerimetro()<<endl;

    cout<<"La altura del triangulo T2 es igual a "<<T2.getAltura()<<endl;

    cout<<"El numero de lados del triangulo T1 es "<<T1.getNumLados()<<endl; //No puedo usar diraectamente .nLados aunque la herencia sea publica

    //---------------------------------------------------

    cout<<"Diagonal del cuadrado C1 "<<C1.getDiagonal()<<endl;
    C2.setLongitud(5);
    C2.calcularDiagonal(C2.getLongitud());
    cout<<"La diagonal del cuadrado C2: "<<C2.getDiagonal()<<endl;
    
    //---------------------------------------------------


    cout<<endl;
    return 0;
}
