//Daniel Braun Sandino
//Sobrecargas - Ejemplo rectangulos
#include <iostream>

using namespace std;

class Rectangulo{
private:
    int ladoX;
    int ladoY;

public:
    //CONSTRUCTOR POR DEFECTO
    Rectangulo(): ladoX(0), ladoY(0){

    }

    //CONSTRUCTOR CON PARAMETROS
    Rectangulo(int x, int y): ladoX(x), ladoY(y){

    }

    //MOSTRAR
    void mostrarLados()const{
        cout<<"Lado X: "<<ladoX<<endl;
        cout<<"Lado Y: "<<ladoY<<endl;
    }

    //GETTERS
    int getLadoX()const{
        return ladoX;
    }

    int getLadoY()const{
        return ladoY;
    }

    //SETTERS
    void setLadoX(){
        cout<<"Introduce el lado X: "<<endl;
        cin>>ladoX;
    }

    void setLadoXparametro(int x){
        ladoX = x;
    }

    void setLadoY(){
        cout<<"Introduce el ladoY: "<<endl;
        cin>>ladoY;
    }

    void setLadoYparametro(int y){
        ladoY = y;
    }

    //METODO CALCULAR AREA DEL RECTANGULO
    int calcularArea()const{
        int area;
        area = ladoX * ladoY;

        return area;
    }

    //METODO CALCULAR PERIMETRO DEL RECTANGULO
    int calcularPerimetro(){
        int perimetro;
        perimetro = (2 * ladoX) + (2 * ladoY);

        return perimetro;
    }

    Rectangulo suma(const Rectangulo &r)const{
        int sumaLadosX = ladoX + r.getLadoX();
        int sumaLadosY = ladoY + r.getLadoY();

        Rectangulo nuevoR(sumaLadosX, sumaLadosY);

        return nuevoR;
    }

    //Sobrecarga forma posfija del operador r++ (Si es (int) es r++)
    Rectangulo operator ++(int){

        ladoX++;
        ladoY++;

        Rectangulo r(ladoX, ladoY);
        return r;
    }

    //Sobrecarga forma prefija del operador ++r (Si es () es ++r)
    Rectangulo operator ++(){
        ++ladoX;
        ++ladoY;

        Rectangulo r(ladoX, ladoY);
    }


};

//Sobrecarga binaria
Rectangulo operator +(const Rectangulo &r1, const Rectangulo &r2) {
    int sumaLadosX = r1.getLadoX() + r2.getLadoX();
    int sumaLadosY = r1.getLadoY() + r2.getLadoY();

    Rectangulo sumaR1R2(sumaLadosX, sumaLadosY);

    return sumaR1R2;
}

//Sobrecarga unaria - funcion general
Rectangulo &operator --(Rectangulo &r){
    int nuevoLadoX = r.getLadoX();
    int nuevoLadoY = r.getLadoY();

    nuevoLadoX--;
    nuevoLadoY--;

    r.setLadoXparametro(nuevoLadoX);
    r.setLadoYparametro(nuevoLadoY);

    return r;
}


int main(){

    Rectangulo R1, R2, R3, R4;

    R1.setLadoX();
    R1.setLadoY();

    R2.setLadoX();
    R2.setLadoY();

    //Datos R1
    R1.mostrarLados();
    cout<<"El area del 1er rectangulo es: "<<R1.calcularArea()<<endl;
    cout<<"El perimetro del 1er rectangulo es: "<<R1.calcularPerimetro()<<endl;

    cout<<"-------------------------"<<endl;

    //Datos R2
    R2.mostrarLados();
    cout<<"El area del 2o rectangulo es: "<<R2.calcularArea()<<endl;
    cout<<"El perimetro del 2o rectangulo es: "<<R2.calcularPerimetro()<<endl;

    cout<<"-------------------------"<<endl;

    R3 = R1.suma(R2);

    //Datos R3 = R1 + R2
    R3.mostrarLados();
    cout<<"El area del 3er rectangulo es: "<<R3.calcularArea()<<endl;
    cout<<"El perimetro del 3er rectangulo es: "<<R3.calcularPerimetro()<<endl;

    cout<<"-------------------------"<<endl;

    R4 = R1 + R2;

    //Datos R4 = R1 + R2
    R4.mostrarLados();
    cout<<"El area del 4o rectangulo es: "<<R4.calcularArea()<<endl;
    cout<<"El perimetro del 4o rectangulo es: "<<R4.calcularPerimetro()<<endl;

    cout<<"-------------------------"<<endl;

    //Datos --R1 (resta 1 a cada lado)
    --R1;
    R1.mostrarLados();
    cout<<"El area del 1er rectangulo es: "<<R1.calcularArea()<<endl;
    cout<<"El perimetro del 1er rectangulo es: "<<R1.calcularPerimetro()<<endl;

    cout<<"-------------------------"<<endl;

    //Datos R2++
    R2++; //posfija
    R2.mostrarLados();
    cout<<"El area del 2o rectangulo es: "<<R2.calcularArea()<<endl;
    cout<<"El perimetro del 2o rectangulo es: "<<R2.calcularPerimetro()<<endl;

    cout<<"-------------------------"<<endl;

    return 0;
}
