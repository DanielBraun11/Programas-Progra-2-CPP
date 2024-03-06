//Daniel Braun Sandino
//Práctica 1 - Ejercicio 1
#include <iostream>
#include <array>
using namespace std;

class ISBN{
private:
    string idPais;
    string editorial;
    string numEjemplar;
    string codigoControl;

public:
    //CONSTRUCTOR QUE INICIALIZA EL ID EN 84
    ISBN():idPais("84"), editorial(""), numEjemplar(""), codigoControl(""){

    }

    //GETTERS
    string getIdPais(){
        return idPais;
    }

    string getEditorial(){
        return editorial;
    }

    string getNumEjemplar(){
        return numEjemplar;
    }

    string getCodigoControl(){
        return codigoControl;
    }

    //SETTERS
    void setIdPais(){
        cout<<"Introduce el Id del pais: "<<endl;
        getline(cin,idPais);


    }

    void setEditorial(){
        cout<<"Introduce la editorial(5 digitos): "<<endl;
        getline(cin,editorial);
        if(editorial.size() != 5){
            editorial = "00000";
        }

    }

    void setNumEjemplar(){
        cout<<"Introduce el numero de ejemplar(2 digitos): "<<endl;
        getline(cin, numEjemplar);
        if(numEjemplar.size() != 2){
            numEjemplar = "00";
        }

    }

    void setCodigoControl(const string &i){
        codigoControl = i;
    }


    //METODO CALCULAR CONTROL
    string calcularControl(const string &t){
        int suma;
        int resto;


        for(int i{0} ; i<t.size() ; i++){
            suma = suma + (t.at(i) * i + 1);
        }

        resto = suma%11;

        codigoControl = to_string (resto);

        if(codigoControl == "10"){
            codigoControl = "X";

        }

        return codigoControl;

    }

};

//METODO RELLENAR EL IBAN
string UnionDeNumero(ISBN &codigo1){
    string UnionDeCodigo;
    string respuesta;

    cout<<"Desea remplazar el Id del pais inicializado en 84?(si/no): "<<endl;
    getline(cin, respuesta);

    if(respuesta == "si"){
        codigo1.setIdPais();
    }

    codigo1.setEditorial();

    codigo1.setNumEjemplar();

    //Unión
    UnionDeCodigo = codigo1.getIdPais() + codigo1.getEditorial() + codigo1.getNumEjemplar();

    return UnionDeCodigo;

}

//METODO MOSTRAR DATOS ISBN
void mostrarDatos(ISBN &codigo1){
    cout<<"Identificador de pais: "<<codigo1.getIdPais()<<endl;
    cout<<"Editorial: "<<codigo1.getEditorial()<<endl;
    cout<<"Numero de ejemplar: "<<codigo1.getNumEjemplar()<<endl;
    cout<<"Codigo de control: "<<codigo1.getCodigoControl()<<endl;
    cout<<endl;
    cout<<"IBAN: "<<codigo1.getIdPais()<<codigo1.getEditorial()<<codigo1.getNumEjemplar()<<codigo1.getCodigoControl()<<endl;
}

int main(){
    ISBN codigo1;
    string codigoJunto = UnionDeNumero(codigo1);

    //Calcular codigo control
    string codigoFinal = codigo1.calcularControl(codigoJunto);

    codigo1.setCodigoControl(codigoFinal);


    mostrarDatos(codigo1);


    return 0;
}
