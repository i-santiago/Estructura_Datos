#include <iostream>

using namespace std;
#include "Alumno.h"
#include "Arreglo.h"

/*************************** ARCHIVO MAIN ********************************/
/* Función que despliega en pantalla el menu con las opciones que tiene el usuario. */
int MenuOpciones()
{
    char Opcion;
    do
    {
        system("cls");
        cout << "\nA: Dar de alta un nuevo alumno: ";
        cout << "\nI: Imprimir la lista de alumnos: ";
        cout << "\nS: Salir del programa. ";
        cout << "\nIngrese opcion: ";
        cin >> Opcion;

        // Convertimos a mayúscula por si el usuario ingresa minúsculas
        Opcion = toupper(Opcion);
    } while (Opcion != 'A' && Opcion != 'I' && Opcion != 'S');
    return Opcion;
}

int main(){
    /* Se crea un objeto tipo Arreglo de tipo Alumno. */
    Arreglo vecAlumno;
    Alumno a1;
    //variables auxiliares para capturar la información de un nuevo alumno
    int cod;
    string nom,carr;
    char Opc;
    int Res;

    do{
        Opc = MenuOpciones();
        switch(Opc){
        case 'A':
        {
            cout << "\n\n Ingresa los datos del nuevo alumno: ";
            cout<<"\nIngresa el codigo: ";
            cin>>cod;
            cout<<"\nIngresa el nombre: ";
            cin>>nom;
            cout<<"\nIngresa la carrera: ";
            cin>>carr;
              a1.asignarCodigo(cod);
              a1.asignarNombre(nom);
              a1.asignarCarrera(carr);

            Res = vecAlumno.agregarAlumno(a1); /* Se invoca el método agregar alumnos en el arreglo*/

            /* Se despliega un mensaje de acuerdo al resultado obtenido. */
            if (Res == 1)
                cout << "\n\n El nuevo alumno ya fue dado de alta. \n";
            else if (Res == 0)
                cout << "\n\n No hay espacio para registrar el nuevo alumno.\n ";
            break;
        }
        case 'I':
        {
            vecAlumno.imprimirAlumnos();    /* Se invoca el método de impresión del arreglo. */
            break;
        }

        case 'S':
            cout << "\n\n Saliendo del programa...\n\n ";
            break;
        }
        system("pause");
    } while (Opc != 'S');

    return 0;
}

