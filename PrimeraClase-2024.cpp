//Daniel Braun Sandino
//Ejercicio clase Persona
#include <iostream>
#include <vector>
using namespace std;
class Persona{
private:
  string nombre;
  string apellido;
  int edad;

public:

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

string getNombre() const{
return nombre;
}

string getApellido() const{
return apellido;
}

int getEdad() const{
return edad;
}
};

void agregarPersona(vector<Persona> &lista){
  Persona p;
  string name, lastName;
  int age;
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
lista.push_back(p);
}

int main(){
string respuesta, apellidoBuscado;
int opcion;
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
agregarPersona(almacenPersonas);
cout<<"------------------------"<<endl;
break;
  
case 2:
for(int i = 0; i < almacenPersonas.size(); i++){
    cout<<"Nombre persona "<<i + 1<<": "<<almacenPersonas[i].getNombre()<<endl;
    cout<<"Apellido persona "<<i + 1<<": "<<almacenPersonas[i].getApellido()<<endl;
    cout<<"Edad persona "<<i + 1<<": "<<almacenPersonas[i].getEdad()<<endl;
cout<<"------------------------"<<endl;
}
break;
  
case 3:
cout<<"Introduce el apellido de la persona: ";
getline(cin, apellidoBuscado);
for (int i = 0; i < almacenPersonas.size(); i++){
    if (almacenPersonas.at(i).getApellido() == apellidoBuscado){
    cout<<"PERSONA ENCONTRADA."<<endl;
    cout<<"Nombre persona "<<almacenPersonas.at(i).getNombre()<<endl;
    cout<<"Apellido persona "<<almacenPersonas.at(i).getApellido()<<endl;
    cout<<"Edad persona "<<almacenPersonas.at(i).getEdad()<<endl;
break;
}
}
cout<<"PERSONA NO ENCONTRADA."<<endl;
cout<<"------------------------"<<endl;
break;
  
case 4:
cout<<"Adios, gracias."<<endl;
break;
  
default:
cout<<"Opcion no válida."<<endl;
break;
}
  
} while (opcion != 4);
  
return 0;
}
