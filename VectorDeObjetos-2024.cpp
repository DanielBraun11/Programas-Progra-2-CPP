//Daniel Braun Sandino
//Ejercicio 2
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class vectorElementos{
private:
    array<int, 10> cadena;
    int suma;

public:
    //Constructor que inicializa el array 1-10
    vectorElementos(): suma(0){
        for(int i{0} ; i<cadena.size() ; i++){
            cadena.at(i) = i+1;
        }
    }

    //Getter
    array<int,10> getCadena(){
        return cadena;
    }

    //Setter
    void setCadena(){
        for(int i{0} ; i<cadena.size() ; i++){
            cout<<"Numero "<<i+1<<": ";
            cin>>cadena.at(i);
        }
    }

    //Calcula suma
    int calulaSuma(){
        //suma = 0;
        for(int i{0} ; i<cadena.size() ; i++){
            suma += cadena.at(i);
        }

        return suma;
    }

};

vectorElementos nuevoObjeto(){
    //vectorElementos operacion = vectorElementos();
    vectorElementos operacion;
    string res;

    cout<<"Desea modificar el array?(si/no): "<<endl;
    cin>>res;

    if(res == "si"){
        operacion.setCadena();
    }

    return operacion;
}

//Mostrar todos los datos
void mostrarTodosLosDatos(vector<vectorElementos> &almacenDeDatos){
    for(int i{0} ; i<almacenDeDatos.size() ; i++){
        cout<<"Operacion "<<i+1<<": "<<endl;
        cout<<"Numeros de la cadena: ";
        array<int,10> cadena = almacenDeDatos.at(i).getCadena();
        for (int j = 0; j < cadena.size(); j++) {
            cout << cadena.at(j) << ", ";
        }
        cout<<endl;
        cout<<"Suma de los numeros iniciales: 55"<<endl;
        cout<<"Suma de los numeros modificados: "<<almacenDeDatos.at(i).calulaSuma()<<endl;;
    }
}

int main(){
    vector<vectorElementos> almacenDeDatos;
    string respuesta;

    do{
        almacenDeDatos.push_back(nuevoObjeto());

        cout<<endl;

        mostrarTodosLosDatos(almacenDeDatos);


        cout<<"-----------------------"<<endl;

        cout<<"Desea seguir operando?(si/no): "<<endl;
        cin>>respuesta;

    }while(respuesta != "no");


    return 0;
}
