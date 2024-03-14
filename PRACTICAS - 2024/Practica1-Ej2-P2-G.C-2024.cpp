//Daniel Braun Sandino
//Práctica 1 - Ejercicio 2
#include <iostream>

using namespace std;
struct Autora{
    string nombre;
    string apellido1;
    string apellido2;
};

struct FechaPublic{
    int mes;
    int anio;
};

class Publicacion{
private:
    string titulo;
    Autora autora;
    FechaPublic fechaPublic;
    int numPaginas{0};

public:

    //GETTERS
    string getTitulo(){
        cout<<titulo<<endl;
    }

    Autora getAutora(){
        return autora;

    }

    FechaPublic getFechaPublic(){

        return fechaPublic;
    }

    int getNumPaginas(){
        return numPaginas;
    }

    //SETTERS
    void setTitulo(){
        cout<<"Introduce el titulo: "<<endl;
        getline(cin, titulo);
    }

    void setAutora(){
        //Nombre
        cout<<"Introduce el nombre de la autora: "<<endl;
        getline(cin,autora.nombre);

        //Primer apellido
        cout<<"Introduce el primer apellido de la autora: "<<endl;
        getline(cin, autora.apellido1);

        //Segundo apellido
        cout<<"Introduce el segundo apellido de la autora: "<<endl;
        getline(cin, autora.apellido2);


    }

    void setFechaPublic(){
        //Mes
        cout<<"Introduce el mes de publicacion: "<<endl;
        cin>>fechaPublic.mes;
        if(fechaPublic.mes <= 0 || fechaPublic.mes > 12){
            fechaPublic.mes = 1;
        }
        //Año
        cout<<"Introduce el anio de publicacion: "<<endl;
        cin>>fechaPublic.anio;
        if(fechaPublic.anio <1900){
            fechaPublic.anio = 1900;
        }
    }

    void setNumPaginas(){
        cout<<"Introduce el numero de paginas: "<<endl;
        cin>>numPaginas;
        if(numPaginas <= 0){
            numPaginas = 0;
        }
    }

    //METODO MOSTRAR PUBLICACION
    void mostrarPublicacion(){
        cout<<"Titulo: "<<getTitulo();

        if(autora.nombre == "" && autora.apellido1 == "" && autora.apellido2 == ""){
            cout<<"Datos de la autora: SIN DETERMINAR"<<endl;
        }else{
            cout<<"Nombre Autora: "<<getAutora().nombre<<" "<<getAutora().apellido1<<" "<<getAutora().apellido2<<endl;
        }

        cout<<"Fecha de Publicacion: "<<getFechaPublic().mes<<"/"<<getFechaPublic().anio<<endl;

        cout<<"Numero de paginas: "<<getNumPaginas()<<endl;

    }

};

int main(){
    Publicacion publicacion1;

    publicacion1.setTitulo();
    publicacion1.setAutora();
    publicacion1.setFechaPublic();
    publicacion1.setNumPaginas();

    cout<<"------------------------"<<endl;

    publicacion1.mostrarPublicacion();

    return 0;
}
