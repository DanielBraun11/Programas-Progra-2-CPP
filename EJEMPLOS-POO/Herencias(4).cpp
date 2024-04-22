//Daniel Braun Sandino
//Herencias - Ejecución de los Constructores - SIMPLE

#include <iostream>

using namespace std;

class Padre{
public:
    Padre(int N){
        cout<<"Constructor Padre "<<N<<endl;
    }
};

class Hijo: public Padre{
public:
    Hijo():Padre(100){
        cout<<"Constructor Hijo"<<endl;
    }
};

class Nieto: public Hijo{
public:
    Nieto(){
        cout<<"Contructor Nieto"<<endl;
    }
};

int main(){

    Nieto prueba;


    cout<<endl;
    return 0;
}
