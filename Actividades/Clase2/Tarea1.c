#include <stdio.h>
#include <stdlib.h>


struct birth_date{
    unsigned int mes, dia, anyo;
};
typedef struct birth_date Fecha;

struct agenda{
    char nombre[20];
    char domicilio[20];
    long telefono;
    char correo[20];
    Fecha nacimiento;
};

typedef struct agenda Agenda;

enum tipo_operacion {altas = 1, consulta_general, consulta_individual, salir};
typedef enum tipo_operacion Operacion;


//Prototipo de operaciones falta corregir
void Altas(Agenda agenda[], int contador);
void Consulta_general(Agenda agenda[], int contador);
void Consulta_individual(Agenda agenda[], int contador);

int main()
{
    Agenda registro[5];
    int contador = 0;
    Operacion opcion;
    int seleccion;

    do{
        puts("MENU");
        puts("1.ALTAS");
        puts("2.CONSULTAS GENERALES");
        puts("3.CONSULTA INDIVIDUAL");
        puts("4.SALIR");

        printf("ELIGE TU OPCION: ");
        scanf("%d", &seleccion);
        opcion = seleccion;

        switch(seleccion){
        case altas:
            Altas(registro, contador);
            break;

        case consulta_general:
            Consulta_general(registro, contador);
            break;

        case consulta_individual:
            Consulta_individual(registro, contador);
            break;

        case salir:
                puts("\nSaliendo del programa");
                break;

            default:
                puts("\nOpcion no valida.");
        }

    }while(seleccion != salir);






return 0;
}





















