//Daniel Braun Sandino
//HERENCIAS

#include <iostream>
#include <cmath>

using namespace std;

class figuraGeometrica {
private:
    int nlados;
    float longitud;
public:
    figuraGeometrica():nlados(0), longitud(0){

    }

    figuraGeometrica (int n, float l):nlados(n), longitud(l){

    }

    float calcularPerimetro() const{
        return nlados*longitud;
    }

    void setLongitud(float l){
        longitud = l;
    }

    float getLongitud() const{
        return longitud;
    }
    void setNLados(int n){
        nlados = n;
    }

    int getNLados() const{
        return nlados;
    }
};

class triangulo: public figuraGeometrica {
private:
    float altura;
public:
    triangulo():altura(0) {

    }

    void setAltura(float h){
        altura = h;
    }

    float getAltura() const{
        return altura;
    }
    void calcularAltura(){
        altura = sqrt(pow(getLongitud(),2) - pow(getLongitud()/2,2));
    }
};


int main()
{
    triangulo T1;

    T1.setLongitud(4);
    T1.setNLados(3);
    cout << "\n\n\tEl perimetro del triangulo es: "
         << T1.calcularPerimetro();
    T1.calcularAltura();
    cout << "\n\n\tLa altura del triangulo es: "
         << T1.getAltura();

    cout << "\n\n\t";

    return 0;
}
