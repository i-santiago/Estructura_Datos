#ifndef ARREGLO_H_INCLUDED
#define ARREGLO_H_INCLUDED

//#include &lt;iostream&gt;
using namespace std;
/************************CLASE ARREGLO************************/
/* Se define una constante que representa el número máximo de elementos que puede almacenar el arreglo. */
#define MAX 10

class Arreglo{
private:
    Alumno Datos[MAX];
    int Tam;
public:
    Arreglo();
    int agregarAlumno(Alumno);
    void imprimirAlumnos();
};

/* Declaración del método constructor. Inicializa el número actual de
   elementos en 0. */

Arreglo::Arreglo()
{
    Tam = 0;
}

/* Método que inserta el elemento Valor en el arreglo. En esta imple-
   mentación no se aceptan elementos repetidos. */
int Arreglo::agregarAlumno(Alumno objA)
{
    int Posic, Resultado = 1;
    if (Tam < MAX)
            Datos[Tam++] = objA;

    else
        Resultado = 0; // El arreglo está lleno
    return Resultado;
}

/* Método que despliega los valores almacenados en las casillas del arreglo. */
void Arreglo::imprimirAlumnos(){
    int Indice;
    if (Tam > 0)
    {
        cout << "\n\n";
        for (Indice = 0; Indice < Tam; Indice++){
            cout << "\t***** Alumno " << Indice+1 <<" *****"<<endl;
            cout << "\t Codigo: " << Datos[Indice].obtenerCodigo()<<endl;
            cout << "\t Nombre: " << Datos[Indice].obtenerNombre()<<endl;
            cout << "\tCarrera: " << Datos[Indice].obtenerCarrera()<<endl;
        }
        cout << "\n\n";
    }
    else
        cout << "\n No hay elementos almacenados.";
}



#endif // ARREGLO_H_INCLUDED
