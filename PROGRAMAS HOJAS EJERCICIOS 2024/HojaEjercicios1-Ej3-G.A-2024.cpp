//Daniel Braun Sandino
//Hoja de Ejercicios 1 - Ejercicio 3
#include <iostream>
#include <vector>
using namespace std;

class Fecha{
private:
    int dia;
    int mes;
    int year;

public:
    //CONSTRUCTOR POR DEFECTO CON INICIALIZADOR EN 0
    Fecha():dia(0), mes(0), year(0){

    }

    //CONSTRUCTOR POR PARAMETROS
    Fecha(int d, int m, int y): dia(d), mes(m), year(y){

    }

    //CONSTRUCTOR POR COPIA
    Fecha(const Fecha &otra): dia(otra.dia), mes(otra.mes), year(otra.year){

    }

    //SETTERS
    void setDia(int d){
        dia = d;
    }

    void setMes(int m){
        mes = m;
    }

    void setYear(int y){
        year = y;
    }


    //GETTERS
    int getDia()const {
        return dia;
    }

    int getMes()const {
        return mes;
    }

    int getYear()const {
        return year;
    }

};

class Persona{
private:
    string nombre;
    string apellido;
    int edad;
    Fecha fecha;

public:
    //CONSTRUCTOR POR DEFECTO
    Persona(): nombre(""), apellido(""), edad(0){

    }

    //CONSTRUCTOR POR PARAMETROS
    Persona(string n, string a, int e): nombre(n), apellido(a), edad(e){

    }

    //CONSTRUCTOR POR COPIA
    Persona(const Persona &otro): nombre(otro.nombre), apellido(otro.apellido), edad(otro.edad), fecha(otro.fecha){

    }

    //SETTERS
    void setNombre(const string &n){
        nombre = n;
    }

    void setApellido(const string &a){
        apellido = a;
    }

    void setEdad(int e){
        if(e > 0){
            edad = e;
        }else{
            cout<<"Edad negativa no válida."<<endl;
                    edad = 0;
        }
    }

    void setFecha(int dia, int mes, int year){
        fecha.setDia(dia);
        fecha.setMes(mes);
        fecha.setYear(year);
    }

    //GETTERS
    string getNombre() const{
        return nombre;
    }

    string getApellido() const{
        return apellido;
    }

    int getEdad() const{
        return edad;
    }

    Fecha getFecha(){
        return fecha;
    }
};

void agregarPersona(vector<Persona> &lista){
    Persona p;
    string name, lastName;
    int age;
    int dia, mes, anio;

    //Nombre
    cout<<"Introduce el nombre: ";
    getline(cin, name);

    //Apellido
    cout<<"Introduce el apellido: ";
    getline(cin, lastName);

    //Edad
    cout<<"Introduce la edad: ";
    cin>>age;
    cin.ignore();

    p.setNombre(name);
    p.setApellido(lastName);
    p.setEdad(age);

    //Fecha de nacimiento
    cout<<"Dia de nacimiento: ";
    cin>>dia;

    cout<<"Mes de nacimiento: ";
    cin>>mes;

    cout<<"Anio de nacimiento: ";
    cin>>anio;


    p.setFecha(dia,mes,anio);

    lista.push_back(p);



}


int main(){
    string respuesta, apellidoBuscado;
    int opcion;
    bool personaencontrada{0};
    vector<Persona> almacenPersonas;

    do{
        cout<<"Seleccione una opcion: "<<endl;
        cout<<"1. Ingresar persona nueva."<<endl;
        cout<<"2. Mostrar todos los datos. "<<endl;
        cout<<"3. Mostrar datos de una persona."<<endl;
        cout<<"4. Salir."<<endl;
        cin>>opcion;
        cin.ignore();

        cout<<"------------------------"<<endl;

        switch(opcion){
        case 1:
            //AGREGAR PERSONA
            agregarPersona(almacenPersonas);
            cout<<"------------------------"<<endl;
            break;

        case 2:
            //MOSTRAR TODOS LOS DATOS
            for(int i = 0; i < almacenPersonas.size(); i++){
                cout<<"Nombre persona "<<i + 1<<": "<<almacenPersonas.at(i).getNombre()<<endl;
                cout<<"Apellido persona "<<i + 1<<": "<<almacenPersonas.at(i).getApellido()<<endl;
                cout<<"Edad persona "<<i + 1<<": "<<almacenPersonas.at(i).getEdad()<<endl;
                cout << "Fecha de nacimiento: " << almacenPersonas.at(i).getFecha().getDia() << "/" << almacenPersonas.at(i).getFecha().getMes() << "/" << almacenPersonas.at(i).getFecha().getYear() << endl;


                cout<<"------------------------"<<endl;
            }
            break;

        case 3:
            //MOSTRAR DATOS DE PERSONA
            cout<<"Introduce el apellido de la persona: ";
            getline(cin, apellidoBuscado);
            for (int i = 0; i < almacenPersonas.size(); i++){
                if (almacenPersonas.at(i).getApellido() == apellidoBuscado){
                    cout<<"PERSONA ENCONTRADA."<<endl;
                    cout<<"Nombre persona "<<almacenPersonas.at(i).getNombre()<<endl;
                    cout<<"Apellido persona "<<almacenPersonas.at(i).getApellido()<<endl;
                    cout<<"Edad persona "<<almacenPersonas.at(i).getEdad()<<endl;
                    personaencontrada = true;
                }

            }
            if(personaencontrada == false){
                cout<<"PERSONA NO ENCONTRADA."<<endl;
            }

            personaencontrada = false;

            cout<<"------------------------"<<endl;
            break;

        case 4:
            //SALIR
            cout<<"Adios, gracias."<<endl;
            break;

        default:
            cout<<"Opcion no válida."<<endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}
