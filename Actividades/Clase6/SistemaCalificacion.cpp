/* Se incluye una biblioteca que contiene la plantilla de la clase
Arreglo, de esta manera se evita repetir código. En la biblioteca
"PlanArreglo.h" se tiene todo el código del programa 4.1.*/

#include "arreglo.h"
#include "locale.h"

/* Función que despliega en pantalla las opciones de trabajo que tiene
el usuario. */
int MenuOpciones()
{
    char Opcion;
    do {
        cout << "\n MENU - SISTEMA DE CALIFICACIONES";
        cout << "\n\nA: Ingresa las Calificaciones : ";
        cout << "\nB: Imprimir Calificaciones: ";
        cout << "\nC: Mostrar la calificación mas alta: ";
        cout << "\nD: Mostrar la calificación mas baja: ";
        cout << "\nE: Imprimir total de calificaciones menores a 6 ";
        cout << "\nF: Imprimir total de calificaciones mayores a 8.5 ";
        cout << "\nS: Salir: ";

        cout << "\n\n Ingrese opción de trabajo: ";
        cin >> Opcion;
        Opcion=toupper(Opcion);
    } while (Opcion != 'A' && Opcion != 'B' && Opcion != 'C' && Opcion != 'D' && Opcion != 'E' && Opcion != 'F' && Opcion != 'S');
    return Opcion;
}


int main()
{
    setlocale(LC_ALL, "spanish");
    Arreglo<double> vcalif;
    double Clave, Res;
    char Opc;


    do {
        Opc = MenuOpciones();
        switch (Opc)
        {


            case 'C': {
                cout << "\n\n Nueva Calificacion: ";
                cin >> Clave;
                Res = vcalif.InsertaDesordenado(Clave);

                if (Res == 1)
                    cout << "\n\n La calificacion ya fue dado de alta. ";
                else
                    if (Res == 0)
                        cout << "\n\n No hay espacio para registrar calificaciones. ";
                    else
                        cout << "\n\n Esa calificacion ya fue registrada \npreviamente. ";
                break;
            }
            case 'B': {
                cout << "\n\n Las calificaciones existentes son: ";
                Res = vcalif.EliminaDesordenado(Clave);

                break;
            }

            case 'C': {
                cout << "\n\n Clave del alumno a dar de baja: ";
                cin >> Clave;
                Res = vcalif.EliminaDesordenado(Clave);

                if (Res == 1)
                    cout << "\n\n El alumno ya fue dado de baja. ";
                else
                    if (Res == 0)
                        cout << "\n\n No hay alumnos registrados. ";
                    else
                        cout << "\n\n Esa clave no está registrada. ";
                break;
            }
            case 'A': {
                vcalif.Lectura();
                break;
            }
            case 'B': {
                vcalif.Escribe();
                break;
            }

            case 'S':
                cout << "\n\n Termina el proceso.\n\n ";
                break;
        }

    } while (Opc != 'S');
}
