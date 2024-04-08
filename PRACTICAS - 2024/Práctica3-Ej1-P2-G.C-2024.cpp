//Daniel Braun Sandino
//Practica 3 - Ejercicio 1

#include <iostream>
#include <string>
#include <array>

using namespace std;

const int DIMcol{20};
const int DIMfila{5};

struct Fecha{
    int mm,aa;
};

struct Posicion{
    int fila, columna;
};

class Publicacion {
private:
    string titulo;
    array<string, 3> autoria;
    Fecha fecha_public;
    int numpag;

public:
    // Constructor por defecto.
    //Publicacion():titulo(""), autoria({"", "", ""}),fecha_public({1, 1900}), numpag(0){}
    // El resto de los atributos se inicializan con los constructores por defecto correspondientes
    Publicacion():numpag(0){}

    // Constructor paramÃ©trico.
    Publicacion(const string &_titulo, const array<string, 3> &_autoria, const Fecha &_fecha_public, int _numpag):
        titulo(_titulo), autoria(_autoria),fecha_public(_fecha_public), numpag(_numpag){}

    // Constructor copia.
    Publicacion(const Publicacion &p):
        titulo(p.titulo), autoria(p.autoria),fecha_public(p.fecha_public), numpag(p.numpag){}

    // Destructor
    ~Publicacion(){}

    const string &getTitulo() const;
    void setTitulo(const string &newTitulo);

    const array<string, 3> &getAutoria() const;
    void setAutoria(const array<string, 3> &newAutoria);

    const Fecha &getFecha_public() const;
    void setFecha_public(const Fecha &newFecha_public);

    int getNumpag() const;
    void setNumpag(int newNumpag);

    void mostrarPublicacion();

    //SOBRECARGA OPERADOR -- POST-DECREMENTO
    Publicacion operator --(int){
        Publicacion actualizada(*this);
        numpag--;

        return actualizada ;
    }

    //SOBRECARGA OPERADOR <
    bool operator < (Publicacion &otro){
        if(fecha_public.aa < otro.fecha_public.aa){
            return true;
        }else if(fecha_public.aa == otro.fecha_public.aa){
            if(fecha_public.mm < otro.fecha_public.mm){
                return true;
            }
        }

        return false;
    }

    friend ostream &operator <<(ostream &out, const Publicacion &p);
    friend istream &operator >>(istream &in, Publicacion &p);
};

//SOBRECARGA OPERADOR <<
ostream &operator <<(ostream &out, const Publicacion &p){
    //out<<"Titulo: "<<p.titulo<<"Autoria: "<<p.autoria<<"Fecha de publicacion: "<<p.fecha_public<<"Numero de paginas: "<<p.numpag;

    out<<"Titulo: "<<p.titulo<<endl;
    out<<"Autoria: ";
    for (string const &autor: p.autoria){
        out << autor << "  ";
    }
    out<<endl;
    out<<"Fecha de publicacion: " << p.fecha_public.mm << "/" << p.fecha_public.aa<<endl;
    out<<p.numpag<<endl;



    return out;
}

//SOBRECARGA OPERADOR >>
istream &operator >>(istream &in, Publicacion &p){
    string titulo;
    array<string, 3> autoria;
    Fecha fechaPublicacion;
    int numPaginas;

    in>>titulo>>numPaginas;

    for(int i{0} ; i<p.autoria.size() ; i++){
        in>>autoria.at(i);
    }

    in>>fechaPublicacion.mm >> fechaPublicacion.aa;


    p.setTitulo(titulo);
    p.setAutoria(autoria);
    p.setFecha_public(fechaPublicacion);
    p.setNumpag(numPaginas);

    return in;
}

//SOBRECARGA - (Elimina la primera publicacion encontrada en la estanteria)
void operator -(array<array<Publicacion,DIMcol>,DIMfila> &mi_estanteria, const Publicacion &p){
    bool cambio{false};


    for(int i{0} ; i<mi_estanteria.size() ; i++){
        for(int j{0} ; j<mi_estanteria.at(i).size() ; j++){
            if (!mi_estanteria.at(i).at(j).getTitulo().empty()){
                mi_estanteria.at(i).at(j) = p;
                cambio = true;

            }
            break;
        }
        break;
    }

    if(cambio == false){
        throw string ("Estanteria vacia");
    }

    /*
    //GESTOR DE EXCEPCION PARA LA ESTANTERIA VACIA
    try{
        if(cambio == false){
            throw string ("Estanteria vacia");
        }
    }catch(string &error){
        cout<<error<<endl;
    }
    */

}

int menu();

void verOcupacion (const array<array<Publicacion,DIMcol>,DIMfila> &E);

Posicion solicitarPosicion();

Publicacion solicitarPublicacion();

void colocarPublicacion (array<array<Publicacion,DIMcol>,DIMfila> &);

void buscarPublicacion (array<array<Publicacion,DIMcol>,DIMfila> &);

//MAIN
int main() {

    int opcion;

    //libreria de 5 estantes para 20 publicaciones cada uno
    //array<array<Publicacion,20>,5> mi_estanteria;
    //se podrÃ­a hacer con constantes
    array<array<Publicacion,DIMcol>,DIMfila> mi_estanteria;
    Publicacion p;

    do{
        opcion = menu();
        try{
            switch(opcion){
            case 1:
                cout << "\n\n\tVer Ocupacion";
                verOcupacion(mi_estanteria);
                break;
            case 2:
                cout << "\n\n\tColocar Publicacion";
                try{
                    colocarPublicacion(mi_estanteria);
                }
                catch (int excepcion){
                    switch(excepcion){
                    case 1:
                        cerr << "\n\n\tCapturada la excepcion 1";
                        break;
                    case 2:
                        cerr << "\n\n\tCapturada la excepcion 2";
                        break;
                    case 3:
                        cerr << "\n\n\tCapturada la excepcion 3";
                        break;
                    case 4:
                        cerr << "\n\n\tCapturada la excepcion 4";
                        break;
                    }
                }
                break;
            case 3:
                cout << "\n\n\tBuscar Publicacion";
                buscarPublicacion(mi_estanteria);
                break;

            case 4: //OPERACIONES EXTRAS PRACTICA 3
                int opcionExtra;

                cout<<"Introduce la opcion extra(1-3): "<<endl;
                cout<<"1. Restar 1 al numero de paginas de una publicacion."<<endl;
                cout<<"2. Comparacion de fechas de publicacion."<<endl;
                cout<<"3. Eliminar la primera publicacion que encuentre en la estanteria."<<endl;
                cin>>opcionExtra;

                switch(opcionExtra){
                case 1: //Resta 1 al numero de paginas de una publicacion

                    colocarPublicacion(mi_estanteria);

                    if(mi_estanteria.at(0).at(0).getTitulo().empty()){
                        cout<<"Error, en esta posicion no hay publicacion."<<endl;
                    }else{
                        mi_estanteria.at(0).at(0)--;
                        cout<<"Accion realizada con exito."<<endl;
                        cout<<"-----------------------------"<<endl;
                    }

                    break;

                case 2: //Comparacion de fechas de publicacion
                    int fila1, col1, fila2, col2;
                    bool esMenor;

                    cout<<"Introduce la posicion de la publicacion 1: "<<endl;
                    cout<<"Introduce la fila de la publicacion 1: "<<endl;
                    cin>>fila1;
                    cout<<"Introduce la columna de la publicacion 1: "<<endl;
                    cin>>col1;


                    cout<<"Introduce la posicion de la publicacion 2: "<<endl;
                    cout<<"Introduce la fila de la publicacion 2: "<<endl;
                    cin>>fila2;
                    cout<<"Introduce la columna de la publicacion 2: "<<endl;
                    cin>>col2;

                    if(mi_estanteria.at(fila1).at(col1).getTitulo().empty() || mi_estanteria.at(fila2).at(col2).getTitulo().empty()){
                        cout<<"Error, algunas de las 2 posiciones esta vacia (sin publicacion)."<<endl;
                    }else{
                        esMenor = mi_estanteria.at(fila1).at(col1) < mi_estanteria.at(fila2).at(col2);
                        cout<<"Accion realizada con exito."<<endl;
                        cout<<"La afirmacion de que la publicacion 1 es menor que la publicacion 2 es"<<boolalpha<<" "<<esMenor<<endl;
                        cout<<"-----------------------------"<<endl;
                    }

                    break;

                case 3: //Eliminar la primera publicacion que encuentre en la estanteria

                    try{
                        mi_estanteria - p;
                        verOcupacion(mi_estanteria);
                        cout<<"Eliminada."<<endl;
                    }catch(const string &error){
                        cout<<error<<endl;
                    }

                    break;

                default: cout<<"La opcion no es valida."<<endl;
                }


                break;

            case 0: cout << "\n\n\tGracias y hasta pronto";
                break;
            default: cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;
            }
        }
        catch (const string &msg){
            cerr << "\n\n\tCapturada la excepcion con el mensaje: " << msg;
        }
    }while (opcion != 0);

    cout << "\n\n\t";
    return 0;
}

//____________FUNCIONES GENERALES
// Funcion para escribir el menu en pantalla
int menu () {
    const int OPCIONES{4}; //modifico porque añado una opcion mas 3 -> 4
    int miOpcion;

    do {
        cout << "\n\n\t1. Visualizar estado de ocupacion de la estanteria.";
        cout << "\n\n\t2. Colocar una publicacion en la estanteria.";
        cout << "\n\n\t3. Buscar una publicacion de la estanteria.";
        cout << "\n\n\t4. Opciones extras (Practica 3).";

        cout << "\n\n\t0. Salir Programa.";
        cout << "\n\n\t   Teclee la opcion: ";
        cin >> miOpcion;
        cin.ignore();   // Limpia el buffer de entrada

        if (miOpcion < 0 || miOpcion > OPCIONES)
            cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;

    } while (miOpcion < 0 || miOpcion > OPCIONES);

    return miOpcion;
}

void verOcupacion (const array<array<Publicacion,DIMcol>,DIMfila> &E){
    cout << "\n\n\tL=posision libre\t\tO=posicion ocupada";
    cout << "\n\n\t";
    for (size_t fil{0}; fil < E.size(); fil++){
        for (size_t col{0}; col < E.at(fil).size(); col++){
            if (E.at(fil).at(col).getTitulo().empty()){
                cout << "  L";
            }
            else{
                cout << "  O";
            }
        }
        cout << "\n\n\t";
    }
}

Posicion solicitarPosicion(){
    Posicion pos;
    do{
        cout << "\n\n\tIndique la fila: ";
        cin >> pos.fila;

        if (pos.fila < 0 || pos.fila >= DIMfila){
            cout << "\n\n\tPor favor, el valor de la fila tiene que ser un valor entre 0 y 4.";
        }
    }while (pos.fila < 0 || pos.fila >= DIMfila);

    do{
        cout << "\n\n\tIndique la columna: ";
        cin >> pos.columna;

        if (pos.columna < 0 || pos.columna >= DIMcol){
            cout << "\n\n\tPor favor, el valor de la columna tiene que ser un valor entre 0 y 19.";
        }
    }while (pos.columna < 0 || pos.columna >= DIMcol);

    cin.ignore();

    return pos;
}

Publicacion solicitarPublicacion(){
    Publicacion p;
    string tit;
    array<string,3> autor;
    Fecha fech;
    int pag;

    cout << "\n\n\tIndique el titulo: ";
    getline(cin, tit);
    p.setTitulo(tit);

    for (int i{0}; i < 3; i++){
        cout << "\n\n\tIndique el autor " << i << ": ";
        getline(cin, autor.at(i));
    }
    p.setAutoria(autor);

    cout << "\n\n\tIndique el mes de publicacion: ";
    cin >> fech.mm;
    cout << "\n\n\tIndique el annio de publicacion: ";
    cin >> fech.aa;
    p.setFecha_public(fech);

    cout << "\n\n\tIndique el numero de paginas de la publicacion: ";
    cin >> pag;
    cin.ignore();
    p.setNumpag(pag);

    return p;
}
void colocarPublicacion (array<array<Publicacion,DIMcol>,DIMfila> &E){
    Posicion pos;
    Publicacion mi_articulo;
    pos = solicitarPosicion();
    if (E.at(pos.fila).at(pos.columna).getTitulo().empty()){
        mi_articulo = solicitarPublicacion();
        E.at(pos.fila).at(pos.columna)=mi_articulo;
    }
    else{
        throw string("Sitio ocupado con otra publicacion");
    }
}

void buscarPublicacion (array<array<Publicacion,DIMcol>,DIMfila> &E){
    Posicion pos;

    pos = solicitarPosicion();
    if (E.at(pos.fila).at(pos.columna).getTitulo().empty()){
        throw string("Sitio vacio, no hay publicacion");
    }
    else{
        cout<<E.at(pos.fila).at(pos.columna);   //SOBRECARGA OPERADOR <<
        //cout<<E.at(pos.fila).at(pos.columna).mostrarPublicacion();
    }
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
    if (newAutoria.begin()->empty()){
        autoria.at(0) = "SIN DETERMINAR";
        throw 1;
    }
    else {
        autoria = newAutoria;
    }
}

const Fecha &Publicacion::getFecha_public() const
{
    return fecha_public;
}

void Publicacion::setFecha_public(const Fecha &newFecha_public)
{
    if (newFecha_public.mm<=0 || newFecha_public.mm>12){
        fecha_public.mm = 1;
        throw 2;
    }
    else{
        fecha_public.mm = newFecha_public.mm;
    }

    if (newFecha_public.aa<1900 || newFecha_public.aa> 2024){
        fecha_public.aa = 1900;
        throw 3;
    }
    else{
        fecha_public.aa = newFecha_public.aa;
    }
}

int Publicacion::getNumpag() const
{
    return numpag;
}

void Publicacion::setNumpag(int newNumpag)
{
    if (newNumpag < 0){
        numpag = 0;
        throw 4;
    }
    else{
        numpag = newNumpag;
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
