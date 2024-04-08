//Daniel Braun Sandino
//Práctica 2 - Grupo C

#include <iostream>
#include <string>
#include <array>

using namespace std;

struct Fecha{
    int mm,aa;
};

class Publicacion {
private:
    string titulo{""};
    array<string, 3> autoria{"", "", ""};
    Fecha fecha_public{1,1900};
    int numpag{0};

public:
    //CONSTRUCTOR POR DEFECTO - SIN PUBLICACION (VACIA)
    Publicacion(){

    }

    //CONSTRUCTOR CON PARAMETROS
    Publicacion(const string &t, const array<string, 3> &a, Fecha &fecha_p, int nPaginas):titulo(t), autoria(a), fecha_public(fecha_p), numpag(nPaginas){

    }

    //CONSTRUCTOR POR COPIA
    Publicacion(Publicacion &otra): titulo(otra.titulo), autoria(otra.autoria), fecha_public(otra.fecha_public), numpag(otra.numpag){

    }

    //DESTRUCTOR
    ~Publicacion(){

    }

    //GETTERS
    const string &getTitulo() const;
    void setTitulo(const string &newTitulo);

    const array<string, 3> &getAutoria() const;
    void setAutoria(const array<string, 3> &newAutoria);

    const Fecha &getFecha_public() const;
    void setFecha_public(const Fecha &newFecha_public);

    int getNumpag() const;
    void setNumpag(int newNumpag);

    //MOSTRAR
    void mostrarPublicacion();

    //METODO PARA CREAR UN OBJETO
    void crearPublicacion(){

        //Titulo
        cout<<"Introduce el titulo de la publicacion: "<<endl;
        getline(cin, titulo);

        //Autora
        cout<<"Introduce el nombre de la autora: "<<endl;
        getline(cin, autoria.at(0));


        cout<<"Introduce el primer apellido de la autora: "<<endl;
        getline(cin, autoria.at(1));


        cout<<"Introduce el segundo apellido de la autora: "<<endl;
        getline(cin, autoria.at(2));

        //EXCEPCION QUE LANZA 1 EN CASO DE NO HABER DATOS
        try{
            if (autoria.begin()->empty()){
                throw 1;

            }
        }catch(int excepcion1){
            cout<<excepcion1<<endl;
        }


        //Fecha Publicacion
        cout<<"Introduce el mes de publicacion: "<<endl;
        cin>>fecha_public.mm;
        cin.ignore();

        cout<<"Introduce el anio de publicacion: "<<endl;
        cin>>fecha_public.aa;
        cin.ignore();

        //EXCEPCION QUE LANZA 2 EN CASO DE QUE EL MES ESTE FUERA DE RANGO(1-12)
        try{
            if (fecha_public.mm<0 || fecha_public.mm>12){
                throw 2;
            }

        }catch(int excepcion2){
            cout<<excepcion2<<endl;

        }

        //EXCEPCION QUE LANZA 3 EN CASO DE QUE EL AÑO ESTE FUERA DE RANGO(1900-2024)
        try{
            if (fecha_public.aa<1900 || fecha_public.aa> 2024){
                throw 3;
            }
        }catch(int excepcion3){
            cout<<excepcion3<<endl;
        }

        //Numero de Paginas
        cout<<"Intoduce el numero de paginas: "<<endl;
        cin>>numpag;
        cin.ignore();

        //EXCEPCION QUE LANZA 4 EN CASO DE QUE EL NUMERO DE PAGINAS SEA 0
        try{
            if (numpag < 0){
                throw 4;
            }
        }catch(int excepcion4){
            cout<<excepcion4<<endl;
        }

    }
};

//FUNCION INICIALIZAR ESTANTERIA - INICIALIZA EN PUBLICACIONES VACIAS
void inicializarEstanteria(const array<array<Publicacion,5>, 20> &estanteria){
    for(int i{0} ; i<estanteria.size() ; i++){
        for(int j{0} ; j<estanteria.at(i).size() ; j++){
            estanteria.at(i).at(j);
        }
    }
}

//FUNCION MENU - DEVUELVE LA OPCION QUE DESEE EL USUARIO
int mostrarMenu(){
    int opcion;
    cout<<"Seleccione una opcion: "<<endl;
    cout<<"1. Visualizar el estado de ocupacion de la estanteria."<<endl;
    cout<<"2. Colocar una publicacion en la estanteria."<<endl;
    cout<<"3. Buscar una publicacion de la estanteria."<<endl;
    cout<<"4. Salir."<<endl;
    cin>>opcion;
    cin.ignore();

    return opcion;
}

//FUNCION VISUALIZAR ESTADO ESTANTERIA - VISUALIZACION
void mostrarEstanteria(array<array<Publicacion,5>, 20> &estanteria){
    for(int i{0} ; i<estanteria.size() ; i++){
        for(int j{0} ; j<estanteria.at(i).size() ; j++){
            estanteria.at(i).at(j).mostrarPublicacion();
        }
    }
}


//FUNCION COLOCAR UNA PUBLICACION EN LA ESTANTERIA
void colocarPublicacion(array<array<Publicacion,5>, 20> &estanteria){
    int fila, col;

    cout<<"Introduce la fila donde quiera guardar la Publicacion(0-3): "<<endl;
    cin>>fila;
    cin.ignore();

    cout<<"Introduce la columna donde quiera guardar la Publicacion(0-19): "<<endl;
    cin>>col;
    cin.ignore();

    //EXCEPCION QUE LANZA ERROR SI LA POSICION ESTA OCUPADA
    try{
        if(estanteria.at(fila).at(col).getTitulo() != ""){
            throw string ("Sitio ocupado con otra publicacion.");
        }else{
            estanteria.at(fila).at(col).crearPublicacion();
        }
    }catch(const string &error){
        cout<<error<<endl;
    }


}

//FUNCION BUSCAR PUBLICACION
Publicacion buscarPublicacion( array<array<Publicacion,5>, 20> &estanteria){
    int fila, col;

    cout<<"Introduce la fila de la publicacion que buscas(0-3): "<<endl;
    cin>>fila;
    cin.ignore();

    cout<<"Introduce la columna de la publicacion que buscas(0-19): "<<endl;
    cin>>col;
    cin.ignore();

    if(estanteria.at(fila).at(col).getTitulo() != ""){
        //Existe y muestro
        estanteria.at(fila).at(col).mostrarPublicacion();
    }

    //EXCEPCION QUE LANZA ERROR SI NO EXISTE LA PUBLICACION
    try{
        if(estanteria.at(fila).at(col).getTitulo() == ""){
            throw string ("Sitio vacio, no hay publicacion.");
        }

    }catch(const string &error){
        cout<<error<<endl;
    }
}


int main() {
    //ESTANTERIA DE LA BIBLIOTECA
    array<array<Publicacion,5>, 20> estanteria;
    int opcion;

    //OPERACIONES
    inicializarEstanteria(estanteria);

    do{
        opcion = mostrarMenu();

        switch(opcion){
        case 1://VISUALIZAR EL ESTADO DE OCUPACION DE LA ESTANTERIA
        {
            mostrarEstanteria(estanteria);

            break;
        }

        case 2://COLOCAR UNA PUBLICACION EN LA ESTANTERIA
        {

            colocarPublicacion(estanteria);

            break;

        }

        case 3://BUSCAR UNA PUBLICACION DE LA ESTANTERIA
        {

            buscarPublicacion(estanteria);

            break;

        }

        case 4://SALIR
        {
            cout<<"Adios, gracias."<<endl;

            break;

        }

        default://OPCION NO VALIDA
        {
            cout<<"Opcion no valida."<<endl;
        }

        }


    }while(opcion != 4);










    return 0;
}








//------------CLASE Publicacion
const string &Publicacion::getTitulo() const
{
    return titulo;
}

void Publicacion::setTitulo(const string &newTitulo)
{
    titulo = newTitulo;
}

const array<string, 3> &Publicacion::getAutoria() const
{
    return autoria;
}

void Publicacion::setAutoria(const array<string, 3> &newAutoria)
{
    //EXCEPCION QUE LANZA 1 EN CASO DE NO HABER DATOS
    try{
        if (newAutoria.begin()->empty()){
            throw 1;

        }
    }catch(int excepcion1){
        cout<<excepcion1<<endl;
    }

}

const Fecha &Publicacion::getFecha_public() const
{
    return fecha_public;
}

void Publicacion::setFecha_public(const Fecha &newFecha_public)
{
    //EXCEPCION QUE LANZA 2 EN CASO DE QUE EL MES ESTE FUERA DE RANGO(1-12)
    try{
        if (newFecha_public.mm<0 || newFecha_public.mm>12){
            throw 2;
        }

    }catch(int excepcion2){
        cout<<excepcion2<<endl;

    }

    //EXCEPCION QUE LANZA 3 EN CASO DE QUE EL AÑO ESTE FUERA DE RANGO(1900-2024)
    try{
        if (newFecha_public.aa<1900 || newFecha_public.aa> 2024){
            throw 3;
        }
    }catch(int excepcion3){
        cout<<excepcion3<<endl;
    }

}

int Publicacion::getNumpag() const
{
    return numpag;
}

void Publicacion::setNumpag(int newNumpag)
{
    //EXCEPCION QUE LANZA 4 EN CASO DE QUE EL NUMERO DE PAGINAS SEA 0
    try{
        if (newNumpag < 0){
            throw 4;
        }
    }catch(int excepcion4){
        cout<<excepcion4<<endl;
    }
}

void Publicacion::mostrarPublicacion(){
    cout << "\n\n\tLos datos de la publicacion son: ";
    cout << "\n\t\tTitulo: " << titulo;
    cout << "\n\t\tAutores: ";
    for (string const &autor: autoria){
        cout << autor << "  ";
    }
    cout << "\n\t\tFecha de publicacion: " << fecha_public.mm << "/" << fecha_public.aa;
    cout << "\n\t\tPaginas: " << numpag;
}

