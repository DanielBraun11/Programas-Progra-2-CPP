//Daniel Braun Sandino
//Práctica 4 - Grupo C

#include <iostream>
#include <array>
#define DIM 5

using namespace std;

class Libro{
private:
    string titulo;
    int anioPubli;

public:
    //CONSTRUCTOR PARAMETRIZADO
    Libro(string t, int a):titulo(t), anioPubli(a){

    }

    //CONSTRUCOTR POR DEFECTO
    Libro(): titulo(""), anioPubli(0){

    }

    //GETTERS
    const string &getTitulo()const {
        return titulo;
    }

    int getAnioPubli()const{
        return anioPubli;
    }

    //SETTERS CON PARAMETROS
    void setTitulo(const string &t){
        titulo = t;
    }

    void setAnioPubli(int a){
        anioPubli = a;
    }
};

//---------------------------------------------------------
//TEMPLATE PARA ARRAY - BUSQUEDA DE NUMERO
template<typename T>
int buscarElemento(const array<T,DIM> &cadena ,const T &numBuscar){
    //cout<<"hola";
    for(int i{0} ; i<cadena.size() ; i++){
        if(cadena.at(i) == numBuscar){
            return i;
        }
    }

    return -1;
}

//TEMPLATE PARA LIBRO - BUSQUEDA DE LIBRO
template<>
int buscarElemento(const array<Libro,DIM> &cadena,const Libro &libroBuscado){
    //cout<<"hola";
    for(int i{0} ; i<cadena.size() ; i++){
        if(cadena.at(i).getTitulo() == libroBuscado.getTitulo()){
            return i;
        }
    }

    return -1;
}


//TEMPLATE PARA RELLENAR EL ARRAY CON NUMEROS
template<typename T>
array<T,DIM> rellenarArray(array<T,DIM> &cadena){
    cout<<"Vamos a rellenar la cadena."<<endl;

    for(int i{0} ; i<cadena.size() ; i++){
        cout<<"Posicion "<<i<<": "<<endl;
        cin>>cadena.at(i);
    }

    return cadena;
}


//TEMPLATE PARA LA CLASE MIS DATOS
template<typename T>
class MisDatos{
private:
    int indice;
    array<T,DIM> datos;

public:
    //CONSTRUCTOR POR DEFECTO
    MisDatos():indice(DIM){

    }

    //CONSTRUCTOR PARAMETRIZADO
    MisDatos(T valor){
        datos.at(0) = valor;
        indice = 0;
    }

    //GETTERS
    int getIndice()const {
        return indice;
    }

    T getDatos()const {
        return datos;
    }


    //METODO PARA OBTENER ULTIMO ELEMENTO
    const T &obtenerUltimoElemento()const{
        if(indice == DIM){
            string mnsj = "Error, esta vacio";
            throw mnsj;
        }

        return datos.at(0);
    }

    //METODO PARA ELIMINAR ELEMENTO
    void eliminarElemento(){
        T valorObtenido;
        try{
            if(indice == DIM){
                throw string ("Error, no hay datos");
            }
        }catch(const string &error1){
            cout<<error1<<endl;
        }

        if(indice == 0){
            indice = DIM;
        }

        if(indice > 0){
            datos.at(0) = datos.at(indice);
            indice--;
        }
    }

    //METODO PARA INCLUIR ELEMENTO
    void incluirElemento(T datoRecibido){
        if(indice == DIM){
            datos.at(0) == datoRecibido;
            indice = 0;
        }

        if(indice >= 0 and indice <= DIM - 2){
            indice++;
            datos.at(indice) = datos.at(0);
            datos.at(0) = datoRecibido;
        }

        try{
            if(indice == DIM - 1){
                throw string ("Error, esta lleno");
            }
        }catch(const string &error2){
            cout<<error2<<endl;
        }

    }
};

//-----------------------------------------------------------

int main(){

    array<int,DIM> cadena;
    array<Libro,DIM> cadenaLibros;
    int respuesta1, respuesta2;


    cadena = rellenarArray<int>(cadena);

    //Creo y coloco libros en la cadena
    Libro l1("Libro 0", 2000);
    cadenaLibros.at(0) = l1;

    l1.setTitulo("Libro 1");
    l1.setAnioPubli(2001);
    cadenaLibros.at(1) = l1;

    l1.setTitulo("Libro 2");
    l1.setAnioPubli(2002);
    cadenaLibros.at(2) = l1;

    l1.setTitulo("Libro 3");
    l1.setAnioPubli(2003);
    cadenaLibros.at(3) = l1;

    l1.setTitulo("Libro 4");
    l1.setAnioPubli(2004);
    cadenaLibros.at(4) = l1;

    Libro lPrueba1("Libro 1", 2001);
    Libro lPrueba2("Libro 5", 2005);


    //Mostrar array de numeros
    for(int i{0} ; i<cadena.size() ; i++){
        cout<<cadena.at(i)<<", ";
    }
    cout<<endl;

    //Buscar un numero en el array
    respuesta1 = buscarElemento<int>(cadena,2);
    cout<<"Respuesta: "<<respuesta1<<endl;

    //Buscar un libro en el array
    respuesta2 = buscarElemento<Libro>(cadenaLibros,lPrueba1);
    cout<<"Respuesta Buscar Libro 1: "<<respuesta2<<endl;

    respuesta2 = buscarElemento<Libro>(cadenaLibros,lPrueba2);
    cout<<"Respuesta Buscar Libro 5: "<<respuesta2<<endl;

//----------------------------------------------------------------------
//CHECK APARTADO 2

    MisDatos<int> enteros;
    MisDatos<string> texto;

    try{
        //Entero
        //enteros.obtenerUltimoElemento();
        enteros.incluirElemento(11);
        cout<<enteros.obtenerUltimoElemento()<<endl;

        enteros.incluirElemento(25);
        cout<<enteros.obtenerUltimoElemento()<<endl;

        enteros.eliminarElemento();
        cout<<enteros.obtenerUltimoElemento()<<endl;

        //String
        texto.obtenerUltimoElemento();
        texto.incluirElemento("Hola mundo");
        cout<<enteros.obtenerUltimoElemento()<<endl;

        texto.incluirElemento("Me llamo Dani");
        cout<<texto.obtenerUltimoElemento()<<endl;

        texto.eliminarElemento();
        cout<<texto.obtenerUltimoElemento()<<endl;


    }catch(string &error0){
        cout<<error0<<endl;
    }






    MisDatos<Libro> libro;





    return 0;
}
