//Daniel Braun Sandino
//Ejemplos de herencias - Cargos (Herencia de clase publica y privada)

#include <iostream>
#include <cmath>

using namespace std;

class Persona{
private:
    string apellidos;

protected:
    string nombre;

public:
    string iniciales;

    //COSNTRUCTOR POR DEFECTO
    Persona():apellidos(""), nombre(""), iniciales(""){

    }

    //CONSTRUCTOR POR PARAMETROS
    Persona(string ape, string nomb, string inic):apellidos(ape), nombre(nomb), iniciales(inic){

    }

    //GETTERS
    string &getApellido(){
        return apellidos;
    }

    string &getNombre(){
        return nombre;
    }

    string &getIniciales(){
        return iniciales;
    }

    //SETTERS
    void setApellidos(string &ape){
        apellidos = ape;
    }

    void setNombre(string &nomb){
        nombre = nomb;
    }

    void setIniciales(string &inic){
        iniciales = inic;
    }
};

class EmpleadoPublic: public Persona{
private:
    int sueldo;

public:
    //CONSTRUCTOR POR DEFECTO
    EmpleadoPublic():sueldo(0){

    }

    //CONSTRUCTOR POR PARAMETROS
    EmpleadoPublic(const string &ape, const string &nomb, const string &inic, int s):Persona(ape,nomb,inic){ //Importante hacer la llamada al contructor de la Clase Base ahi
        sueldo = s;
    }

    //GETTERS
    int getSueldo()const{
        return sueldo;
    }

    //SETTERS
    void setSueldo(int s){
        sueldo = s;
    }
};

class EmpleadoPrivate: private Persona{
private:
    int sueldo;

public:
    //CONSTRUCTOR POR DEFECTO
    EmpleadoPrivate():sueldo(0){

    }

    //CONSTRUCTOR POR PARAMETROS
    EmpleadoPrivate(const string &ape, const string &nomb, const string &inic, int s):Persona(ape,nomb,inic){ //Importante hacer la llamada al contructor de la Clase Base ahi
        sueldo = s;
    }

    //GETTERS
    int getSueldo()const{
        return sueldo;
    }

    //estos getters se ponen de la Clase Base (Clase Persona) porque la herencia es privada
    const string &getApellidoEnEmpleado(){
        return getApellido();
    }

    const string &getNombre(){
        return nombre;
    }

    const string &getIniciales(){
        return iniciales;
    }


    //SETTERS
    void setSueldo(int s){
        sueldo = s;
    }
};
int main(){

    EmpleadoPublic EPub1("Braun Sandino", "Daniel","DBS",3500);
    EmpleadoPrivate EPriv1("Braun Sandino", "Mario","MBS",2000);

    cout<<EPub1.getNombre()<<" "<<EPub1.getApellido()<<" "<<EPub1.iniciales<<" "<<EPub1.getSueldo()<<endl;

    cout<<EPriv1.getNombre()<<" "<<EPriv1.getApellidoEnEmpleado()<<" "<<EPriv1.getIniciales()<<" "<<EPriv1.getSueldo()<<endl;



    cout<<endl;
    return 0;
}
