#include <iostream>

using namespace std; //espacio de nombre, si no se pone esta linea de codigo se debe poner std: : para cada linea de codigo

class Alumno{
    private:
        int codigo;
        string nombre;
        string carrera;
    public:

        // METODOS
        //Get
       void asignarCodigo(int c){codigo = c;}
       void asignarNombre(string n){nombre = n;}
       void asignarCarrera(string car){carrera = car;}
        //Set
        int muestraCodigo(){return codigo;}
        string muestraNombre(){return nombre;}
        string muestraCarrera(){return carrera;}

        //CONSTRUCTOR
      /*  Alumno(){
            cout<<"\nObjeto Alumno Creado\n"<< endl;
        }*/



};

int main(){
    Alumno a1;
    a1.asignarCodigo(12345);
    a1.asignarNombre("Juan Perez");
    a1.asignarCarrera("IMEI");

    cout<< "\nCodigo\t" <<a1.muestraCodigo()<< endl;
    cout<< "\nNombre\t" <<a1.muestraNombre()<< endl;
    cout<< "\nCarrera\t" <<a1.muestraCarrera()<< endl;
    //cout << "Hello world!" << endl;
    return 0;
}

