//Daniel Braun Sandino
//PRÁCTICA 5 - Ejercicio 1

#include <iostream>
#include <array>

using namespace std;

template<typename T>
class Envase{
private:
    T contenido;
    int cantidad;

public:
    //CONSTRUCTOR POR DEFECTO
    Envase(){

    }

    //CONSTRUCOR POR PARAMETROS
    Envase(const T &content, int cant):contenido(content){
        //GESTOR DE EXCEPCIONES
        if(cant <0 || cant>=25){
            throw string ("Error en la cantidad");
        }else{
            cantidad = cant;
        }
    }

    //CONSTRUCTOR POR COPIA
    Envase(Envase &e):contenido(e.contenido), cantidad(e.cantidad){

    }

    //GETTERS
    T getContenido() const{
        return contenido;
    }

    int getCantidad() const{
        return cantidad;
    }

    //SETTERS
    void setContenido(const T &content){

        contenido = content;
    }

    void setCantidad(int cant){
        //GESTOR DE EXCEPCIONES
        if(cant <0 || cant >= 25){
            throw string ("Error de cantidad");
        }else{
            cantidad = cant;
        }

    }

    //METODO DE LA CLASE - SOBRECARGA BINARIO !=
    bool operator !=(const Envase &e1){
        if(e1.contenido != contenido && e1.cantidad != cantidad){ //Si no son iguales ambos = true
            return true;
        }else{
            return false;
        }
    }

};

ostream &operator <<(ostream &out,const array<int,3> &cadena){
    for(int i{0} ; i<cadena.size() ; i++){
        out<<cadena.at(i)<<", ";
    }
    out<<endl;

    return out;
}

//FUNCION GENERAL - SOBRECARGA BINARIA <<
template<typename T>
ostream &operator <<(ostream &out,const  Envase<T> &e){
    out<<"El contenido es: "<<e.getContenido()<<endl;
    out<<"La cantidad es: "<<e.getCantidad()<<endl;


    return out;
}

int main(){
    Envase<string> e1("Trofeo",3);
    Envase<array<int,3>> e2({1,2,3}, 11);
    Envase<array<int,3>> e3({111,222,333}, 11);
    Envase<array<int,3>> e4({11,22,33}, 11);

    array<int,3> intercambio{11,22,33};

    //Check gestor de excepciones
    try{
        e1.setCantidad(30);

    }catch(const string &error){
        cout<<error<<endl;
    }

    //Check sobrecarga <<
    cout<<e1<<endl;

    //Check sobrecarga antes del cambio setter
    cout<<e2<<endl;

    //Check setter con array
    //e2.setContenido(intercambio);
    cout<<e2<<endl;

    //Check sobrecarga !=
    if(e2 != e3){
        cout<<"Los objetos e2 y e3 son distintos"<<endl;

    }else{
        cout<<"Los objetos e2 y e3 son iguales"<<endl;
    }

    //Check sobrecarga !=
    if(e2 != e4){
        cout<<"Los objetos e2 y e4 son distinto"<<endl;

    }else{
        cout<<"Los objetos e2 y e4 son iguales"<<endl;

    }


    return 0;
}
