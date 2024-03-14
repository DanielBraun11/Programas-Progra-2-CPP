//Daniel Braun Sandino
//Hoja de Ejercicios 3 - Ejercicio 1

#include <iostream>

using namespace std;

class Rectangulo{
private:
    int ladoX;
    int ladoY;

public:
    //CONSTRUCTOR POR DEFECTO
    Rectangulo():ladoX(0), ladoY(0){

    }

    //CONSTRUCTOR POR PARAMETRO
    Rectangulo(int x, int y): ladoX(x), ladoY(y){

    }

    //GETTERS
    int getLadoX() const{
        return ladoX;
    }

    int getLadoY()const{
        return ladoY;
    }


   //SETTERS SIN PARAMETROS
    void setLadoX(){
        cout<<"Introduce el lado X: "<<endl;
        cin>>ladoX;
    }

    void setLadoY(){
        cout<<"Introduce el lado Y: "<<endl;
        cin>>ladoY;
    }

    //SETTER CON PARAMETRO
    void setLadoXparametro(int x){
        ladoX = x;
    }

    void setLadoYparametro(int y){
        ladoY = y;
    }

    //CALCULAR AREA
    int calcularArea(Rectangulo &r){
        int area = r.getLadoX() * r.getLadoY();

        return area;
    }

    //CALCULAR EL PERIMETRO
    int calcularPerimetro(Rectangulo &r){
        int perimetro = (2 * r.getLadoX()) + (2 * r.getLadoY());

        return perimetro;
    }

    //MOSTRAR DATOS
    void mostrarDatos(Rectangulo &r){
        cout<<"Lado X: "<<r.getLadoX()<<endl;
        cout<<"Lado Y: "<<r.getLadoY()<<endl;
        cout<<"Area: "<<r.calcularArea(r)<<endl;
        cout<<"Perimetro: "<<r.calcularPerimetro(r)<<endl;
    }


    /*
    //SOBRECARGA RESTA DE RECTANGULOS
    Rectangulo operator -(const Rectangulo &r1, const Rectangulo &r2){
        int ladoXnuevo = r1.getLadoX() - r2.getLadoX();
        int ladoYnuevo = r1.getLadoX() - r2.getLadoY();

        Rectangulo e(ladoXnuevo, ladoYnuevo);

        return e;
    }
    */

    Rectangulo operator -(const Rectangulo &r) {
        int ladoXnuevo = ladoX - r.ladoX;
        int ladoYnuevo = ladoY - r.ladoY;
        return Rectangulo(ladoXnuevo, ladoYnuevo);
    }


    //SOBRECARGA DECREMENTO - PREFIJO
    Rectangulo operator --(){
        --ladoX;
        --ladoY;

        Rectangulo r(ladoX,ladoY);
        return r;
    }

    //SOBRECARGA DECREMENTO - POSFIJO
    Rectangulo operator --(int){
        ladoX--;
        ladoY--;

        Rectangulo r(ladoX,ladoY);
        return r;
    }

    //SOBRECARGA SIGNO <
    bool operator <(const Rectangulo &r){
        if((ladoX < r.getLadoX()) && (ladoY < r.getLadoY())){
            return true;
        }else{
            return false;
        }
    }

    //SOBRECARGA SIGNO >
    bool operator >(const Rectangulo &r){
        if((ladoX > r.getLadoX()) && (ladoY > r.getLadoY())){
            return true;
        }else{
            return false;
        }
    }

    //SOBRECARGA SIGNO ==
    bool operator ==(const Rectangulo &r){
        if((ladoX == r.getLadoX()) && (ladoY == r.getLadoY())){
            return true;
        }else{
            return false;
        }
    }

};

int main(){
    Rectangulo R1, R2, R3, R4, R5, R6, R7, R8;

    //R1
    R1.setLadoXparametro(6);
    R1.setLadoYparametro(3);

    //R2
    R2.setLadoXparametro(4);
    R2.setLadoYparametro(2);


    //Mostrar datos

    //R1
    cout<<"~~~~~R1~~~~~~"<<endl;
    R1.mostrarDatos(R1);

    cout<<"--------------------"<<endl;

    //R2
    cout<<"~~~~~R2~~~~~~"<<endl;
    R2.mostrarDatos(R2);

    cout<<"--------------------"<<endl;

    //R3 = R1 - R2
    cout<<"~~~~~R3~~~~~~"<<endl;
    R3 = R1 - R2;
    R3.mostrarDatos(R3);

    cout<<"--------------------"<<endl;

    //R4 = R1 - 1 //Asigno a R4 la modifcación y tambien cambio el valor de R1
    cout<<"~~~~~R4~~~~~~"<<endl;
    R4 = R1--;
    R4.mostrarDatos(R4);

    cout<<"--------------------"<<endl;

    //R5 = R2 - 1 //Asigno a R5 la modificacion y tambien cambio el valor en R2
    cout<<"~~~~~R5~~~~~~"<<endl;
    R5 = --R2;
    R5.mostrarDatos(R5);

    cout<<"--------------------"<<endl;

    //R6 = R2 si R2<R1, sino R6 = R1
    cout<<"~~~~~R6~~~~~~"<<endl;

    if(R5 > R3){
        R7 = R5;
    }else{
        R7 = R1;
    }
    R6.mostrarDatos(R6);

    cout<<"--------------------"<<endl;

    //R7 = R3 si R3>R2, sino R7 = R2
    cout<<"~~~~~R7~~~~~~"<<endl;

    if(R1 > R2){
        R7 = R5;
    }else{
        R7 = R1;
    }
    R7.mostrarDatos(R7);

    cout<<"--------------------"<<endl;

    //R8 = R5 si R1 y R2 son iguales, sino R8 = R1
    cout<<"~~~~~R8~~~~~~"<<endl;
    if(R1 == R2){
        R8 = R5;
    }else{
        R8 = R1;
    }
    R8.mostrarDatos(R8);

    cout<<"--------------------"<<endl;


    return 0;
}
