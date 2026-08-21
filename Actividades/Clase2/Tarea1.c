#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


//Prototipo de operaciones
void Altas(Agenda agenda[], int *contador);
void Consulta_general(Agenda agenda[], int contador);
void Consulta_individual(Agenda agenda[], int contador);
void Limpiar_buffer(void);

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
        Limpiar_buffer();   /* <-- limpia el '\n' que deja scanf */
        opcion = seleccion;

        switch(seleccion){
        case altas:
            Altas(registro, &contador);
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

/* Limpia el buffer de entrada despues de un scanf con numeros,
   para que un fgets/scanf posterior no lea un '\n' sobrante */
void Limpiar_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Altas(Agenda agenda[], int *contador){
    if(*contador >= 5){
        puts("\nLa agenda esta llena. No se pueden agregar mas registros.");
        return;
    }

Agenda nuevo;

    printf("\n--- ALTA DE REGISTRO ---\n");

    printf("Nombre: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';

    printf("Domicilio: ");
    fgets(nuevo.domicilio, sizeof(nuevo.domicilio), stdin);
    nuevo.domicilio[strcspn(nuevo.domicilio, "\n")] = '\0';

    printf("Telefono: ");
    scanf("%ld", &nuevo.telefono);   /* antes: scanf("&ld", nuevo.telefono) */
    Limpiar_buffer();                /* limpia antes del siguiente fgets */

    printf("Correo: ");
    fgets(nuevo.correo, sizeof(nuevo.correo), stdin);
    nuevo.correo[strcspn(nuevo.correo, "\n")] = '\0';

    printf("Fecha de nacimiento\n");
    printf("  Dia: ");
    scanf("%u", &nuevo.nacimiento.dia);
    printf("  Mes: ");
    scanf("%u", &nuevo.nacimiento.mes);
    printf("  Anyo: ");
    scanf("%u", &nuevo.nacimiento.anyo);
    Limpiar_buffer();

     agenda[*contador] = nuevo;
    (*contador)++;

    puts("Registro agregado con exito.");
}

    void Consulta_general(Agenda agenda[], int contador){
    if(contador == 0){
        puts("\nNo hay registros para mostrar.");
        return;
    }

    printf("\n--- CONSULTAS GENERALES ---\n");
    for(int i = 0; i < contador; i++){
        printf("\nRegistro %d\n", i + 1);
        printf("Nombre: %s\n", agenda[i].nombre);
        printf("Domicilio: %s\n", agenda[i].domicilio);
        printf("Telefono: %ld\n", agenda[i].telefono);
        printf("Correo: %s\n", agenda[i].correo);
        printf("Fecha de nacimiento: %02u/%02u/%04u\n",
               agenda[i].nacimiento.dia,
               agenda[i].nacimiento.mes,
               agenda[i].nacimiento.anyo);
    }
}

void Consulta_individual(Agenda agenda[], int contador){
    if(contador == 0){
        puts("\nNo hay registros para consultar.");
        return;
    }

    char busqueda[20];
    int encontrado = 0;

    printf("\n--- CONSULTA INDIVIDUAL ---\n");
    printf("Escribe el nombre a buscar: ");
    fgets(busqueda, sizeof(busqueda), stdin);
    busqueda[strcspn(busqueda, "\n")] = '\0';

    for(int i = 0; i < contador; i++){
        if(strcmp(agenda[i].nombre, busqueda) == 0){
            printf("\nRegistro encontrado:\n");
            printf("Nombre: %s\n", agenda[i].nombre);
            printf("Domicilio: %s\n", agenda[i].domicilio);
            printf("Telefono: %ld\n", agenda[i].telefono);
            printf("Correo: %s\n", agenda[i].correo);
            printf("Fecha de nacimiento: %02u/%02u/%04u\n",
                   agenda[i].nacimiento.dia,
                   agenda[i].nacimiento.mes,
                   agenda[i].nacimiento.anyo);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        puts("No se encontro ningun registro con ese nombre.");
    }
}
