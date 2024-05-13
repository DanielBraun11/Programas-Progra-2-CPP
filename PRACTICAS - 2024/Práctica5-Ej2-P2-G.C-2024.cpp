//Daniel Braun Sandino
//PRÁCTICA 5 - Ejercicio 2

#include <iostream>
#include<array>
#include<vector>

using namespace std;

class Animal{
private:
    string grupo; //peces,anfibios,reptiles,aves o mamiferos

public:
    //CONSTRUCTOR POR DEFECTO
    Animal(){

    }

    //CONSTRUCTOR PARAMETRIZADO CON INICIALIZADORES
    Animal(const string &g):grupo(g){

    }

    //DESTRUCTOR
    ~Animal(){

    }

    //GETTER
    const string getGrupo(){
        return grupo;
    }

    //SETTER
    void setGrupo(const string &g){
        grupo = g;
    }

    //METODO MOSTRAR ANIMAL
    void mostrarAnimal(){
        cout<<"El grupo del animal es: "<<grupo<<endl;
    }
};

class Salvaje: public Animal{
private:
    string habitat; //terrestre, acuatico, aereo

public:
    //CONTRUCTOR PARAMETRIZADO CON INICIALIZADORES
    Salvaje(const string &gr, const string &hab):Animal(gr),habitat(hab){

    }

    //DESTRUCTOR
    ~Salvaje(){

    }

    //GETTERS
    const string getHabitat(){
        return habitat;
    }

    //SETTERS
    void setHabitat(const string &hab){
        habitat = hab;
    }

    //METODO MOSTRAR SALVAJE
    void mostrarSalvaje(){
        mostrarAnimal();
        cout<<"El habitat del animal es: "<<habitat<<endl;
    }

};

class Domestico: public Animal{
private:
    string sonido; //guau(perro), miau(gato), kikiriki(gallo), cuac(pato)

public:
    //CONSTRUCTOR PARAMETRIZADO CON INICIALIZADORES
    Domestico(const string &gr, const string &son):Animal(gr), sonido(son){

    }

    //DESTRUCTOR
    ~Domestico(){

    }

    //GETTERS
    const string getSonido(){
        return sonido;
    }

    //SETTERS
    void setSonido(const string &son){
        sonido = son;
    }

    //METODO MOSTRAR DOMESTICO
    void mostrarDomestico(){
        mostrarAnimal();
        cout<<"El sonido del animal es: "<<sonido<<endl;
    }
};

class Mascota: public Domestico{
private:
    array<string,3> accesorios; //correa, plato, pelota

public:
    //CONSTRUCTOR PARAMETRIZADO CON INICIALIZADORES
    Mascota(const string &gr, const string &son, const array<string,3> &acces):Domestico(gr,son), accesorios(acces){

    }

    //DESTRUCTOR
    ~Mascota(){

    }

    //GETTERS
    const array<string,3> &getAccesorios(){
        return accesorios;
    }

    //SETTERS
    void setAccesorios(const array<string,3> &acces){
        accesorios = acces;
    }


    void mostrarMascota(){
        mostrarDomestico();
        cout<<"Los accesorios del animal son: ";
        for(int i{0} ; i<accesorios.size() ; i++){
            cout<<accesorios.at(i)<<", ";
        }
        cout<<endl;

    }
};

int main(){
    vector<Animal> classAnimal;
    vector<Salvaje> classSalvaje;
    vector<Domestico> classDomestico;
    vector<Mascota> classMascota;





    Animal a1("peces"), a2("aves");
    classAnimal.push_back(a1);
    classAnimal.push_back(a2);

    Salvaje s1("peces","acuatico"), s2("aves","aereo");
    classSalvaje.push_back(s1);
    classSalvaje.push_back(s2);

    Domestico d1("peces","gloglo"), d2("aves", "piopio");
    classDomestico.push_back(d1);
    classDomestico.push_back(d2);

    Mascota m1("peces", "gloglo", {"escamas","cola","burbujas"}), m2("aves", "piopio", {"pico","alas","patas"});
    classMascota.push_back(m1);
    classMascota.push_back(m2);



    //Mostrar
    a1.mostrarAnimal();
    cout<<"-------------------------------------------------"<<endl;
    s1.mostrarSalvaje();
    cout<<"-------------------------------------------------"<<endl;
    d2.mostrarDomestico();
    cout<<"-------------------------------------------------"<<endl;
    m2.mostrarMascota();
    cout<<"-------------------------------------------------"<<endl;



    return 0;
}
