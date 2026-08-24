#include <iostream>

using namespace std;

class CuentaBancaria{
private:
    string num_cuenta;
    string propietario;
    double saldo;

public:
    //void depositar(double d){ depositar = d;}
   // void retirar(double r){ retirar = r}
    CuentaBancaria(){saldo = 0.0;}
    void asignar_numCuenta(string nc){num_cuenta = nc;}
    void asignar_propietario(string p){propietario = p;}
    string mostrarNumCuenta(){return num_cuenta;}
    string mostrarProp(){return propietario;}

    void depositar(double s){
        saldo += s;
    }
    void retirar(double s){
        if(saldo >=s)
        saldo -= s;
        else
        cout << "\nCantidad no valida\n" << endl;
    }
    double mostrarSaldo(){
        return saldo;

    }
    void mostrarDatos(){
        cout<<"\n   DATOS DE LA CUENTA\n"<< endl;
        cout<<"\nPropietario: "<<propietario<<endl;
        cout<<"\nNumero de Cuenta: "<<num_cuenta<<endl;
        cout<<"\nSaldo: "<<saldo<<endl;




    }


};
int main()
{
    CuentaBancaria cp;
    double cantidad;
    string nombre, numero;
    int opcion;
    /*
    cp.asignar_numCuenta("999");
    cp.asignar_propietario("Richar");
    cp.depositar(2000);
    cp.retirar(1000);
    cout<<"Saldo: "<<cp.mostrarSaldo()<<endl;
    */
    cout<<"\nIngrese numero de cuenta\n"<<endl;
    getline(cin, numero);
    cout<<"\nIngrese nombre de cuenta\n"<<endl;
    getline(cin, nombre);
    cp.asignar_numCuenta(numero);
    cp.asignar_propietario(nombre);
    do{
        cout<<"\n ----MENU----\n\n1.Deposito\n2.Retiro\n3.Mostrar datos\n4.Salir\n\nSeleccione una opcion\n";
        cin>>opcion;
        switch(opcion){
        case 1:
            cout<<"\n Ingrese Cantidad<<";
            cin>>cantidad;
            cp.depositar(cantidad);

            break;
        case 2:
            cout<<"\n Ingrese Cantidad<<";
            cin>>cantidad;
            cp.retirar(cantidad);

            break;
        case 3:
            cp.mostrarDatos();


            break;
        case 4:
            cout<<"\nPrograma Finalizado\n";

            break;
        default:
            cout<<"\nIngrese numero valido\n"<<endl;

        }
    }while(opcion != 4);


    return 0;
}






