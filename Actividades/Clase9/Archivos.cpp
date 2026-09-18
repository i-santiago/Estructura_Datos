#include <iostream>
#include <fstream>

using namespace std;

#include <cstdlib>
//using std::exit;

int main()
{
    /*
    string mensaje;
    ofstream archLogicoS;

    archLogicoS.open("archivoFisico.txt",ios::app);
    if(archLogicoS.is_open()){
        cout<<"\nAgrega un mensaje al archivo: "<<endl;
        getline(cin,mensaje);
        archLogicoS<<mensaje<<endl;
        archLogicoS.close();
    }
    else{
        cout<<"\nNo se pudo abrir o crear el flujo para escribir en el ..."<<endl;
    }
    ifstream archLogicoE;
    archLogicoE.open("archivoFisico.txt",ios::in);

    if(archLogicoE.is_open()){
        getline(archLogicoE,mensaje);
        cout<<"\nEl mensaje dentro del archivo es: "<<endl;
        cout<<mensaje<<endl;
        archLogicoE.close();
    }
    else{
        cout<<"\nNo se pudo abrir o crear el flujo para leer en el ..."<<endl;
    }
    */ //EJEMPLO1 DE CLASE
    ofstream arch("clientes.dat", ios::out);
    if(!arch){
        cerr<<"No se pudo abrir el archibo"<<endl;
        exit(1);
    }                                                                                                                                              ;
    cout << "Escriba la cuenta, nombre y saldo." << endl
    << "Escriba fin de archivo para terminar la entrada.\n? ";

    int cuenta;
    string nombre;
    double saldo;

    while ( cin >> cuenta >> nombre >> saldo ){
        arch << cuenta << ' ' << nombre << ' ' << saldo << endl;
        cout << "? ";
    }

    return 0;
}

