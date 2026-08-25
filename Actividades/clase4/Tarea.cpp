#include <iostream>

using namespace std;

class CuentaBancaria{
private:
    string num_cuenta;
    string propietario;
    double saldo;

public:

    string mostrarNumCuenta(){return num_cuenta;}
    string mostrarProp(){return propietario;}
    double mostrarSaldo(){return saldo;}

    CuentaBancaria(string nc, string p, double s){
        num_cuenta = nc;
        propietario = p;
        saldo = s;
    }

    void depositar(double cantidad){
        if(cantidad <= 0){
        cout << "\nCantidad no valida\n" << endl;
        }
        else{
        saldo += cantidad;
        cout << "\nDeposito realizado\n" << endl;
        }

    }
    void retirar(double cantidad){
        if(cantidad > saldo){
        cout << "\nCantidad no valida\n" << endl;
        }
        else if(cantidad <= 0){
        cout << "\nCantidad no valida\n" << endl;
        }
        else{
        saldo -= cantidad;
        cout << "\nRetiro realizado\n" << endl;
        }

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
    CuentaBancaria cb[2]{
        CuentaBancaria("12345", "Claudia Arroyo", 10650.85),
        CuentaBancaria("54321", "Miguel Lomeli", 7800.99)
    };
    double cantidad;
    string nombre, numero;
    int opcion, seleccion;
  

    cout << "===== CUENTAS BANCARIAS =====\n";
    cout << "0. Claudia Arroyo - Cuenta 12345\n";
    cout << "1. Miguel Lomeli - Cuenta 54321\n";
    cout << "\nSeleccione una cuenta: ";
    cin >> seleccion;

    do{
        cout<<"\n ----MENU----\n\n1.Deposito\n2.Retiro\n3.Mostrar datos\n4.Salir\n5.Cambiar de cuenta\n\nSeleccione una opcion\n";
        cin>>opcion;
        switch(opcion){
        case 1:
            cout<<"\n Ingrese Cantidad: ";
            cin>>cantidad;
            cb[seleccion].depositar(cantidad);
            cout << "Saldo: "<< cb[seleccion].mostrarSaldo() << endl;


            break;
        case 2:
            cout<<"\n Ingrese Cantidad: ";
            cin>>cantidad;
            cb[seleccion].retirar(cantidad);
            cout << "Saldo: "<< cb[seleccion].mostrarSaldo() << endl;


            break;
        case 3:
            cb[seleccion].mostrarDatos();


            break;
        case 4:
            cout<<"\nPrograma Finalizado\n";

            break;
        case 5:
             seleccion = 1 - seleccion;

    cout << "\nCambio de cuenta realizado.\n";
    cout << "Ahora esta seleccionada la cuenta: " << cb[seleccion].mostrarNumCuenta() << endl;
    cout << "Propietario: "<< cb[seleccion].mostrarProp() << endl;
            break;
        default:
            cout<<"\nIngrese numero valido\n"<<endl;

        }
    }while(opcion != 4);


    return 0;
}
