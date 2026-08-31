#include <iostream>
#include <cctype>

using namespace std;

#define MAX 100

// =================================================================
// DECLARACIÓN Y DEFINICIÓN DE LA PLANTILLA DE LA CLASE ARREGLO
// =================================================================

template <class T>
class Arreglo
{
private:
    T Datos[MAX];
    int Tam;

public:
    Arreglo();
    void Lectura();
    int InsertaDesordenado(T Valor);
    int EliminaDesordenado(T Valor);
    int BuscaDesordenado(T Valor);
    void Escribe();
};

// Constructor: Inicializa el número actual de elementos en 0.
template <class T>
Arreglo<T>::Arreglo()
{
    Tam = 0;
}

// Método para la lectura de los atributos del arreglo.
template <class T>
void Arreglo<T>::Lectura()
{
    int Indice;
    do {
        cout << "\n\n Ingrese total de elementos: ";
        cin >> Tam;
    } while (Tam < 1 || Tam > MAX);

    for (Indice = 0; Indice < Tam; Indice++) {
        cout << "\nIngrese el " << Indice + 1 << " dato: ";
        cin >> Datos[Indice];
    }
}

// Método que busca secuencialmente un elemento en el arreglo.
template <class T>
int Arreglo<T>::BuscaDesordenado(T Valor)
{
    int Indice = 0, Resultado = -1;
    while ((Indice < Tam) && (Datos[Indice] != Valor)) {
        Indice++;
    }
    if (Indice < Tam) {
        Resultado = Indice;
    }
    return Resultado;
}

// Método que inserta un elemento sin aceptar repetidos.
template <class T>
int Arreglo<T>::InsertaDesordenado(T Valor)
{
    int Posic, Resultado = 1;
    if (Tam < MAX) {
        Posic = BuscaDesordenado(Valor);
        if (Posic < 0) {
            Datos[Tam++] = Valor;
        } else {
            Resultado = -1; // Clave duplicada
        }
    } else {
        Resultado = 0; // Arreglo lleno
    }
    return Resultado;
}

// Método que elimina un elemento del arreglo.
template <class T>
int Arreglo<T>::EliminaDesordenado(T Valor)
{
    int Indice, Posic, Resultado = 1;
    if (Tam > 0) {
        Posic = BuscaDesordenado(Valor);
        if (Posic < 0) {
            Resultado = -1; // No encontrado
        } else {
            Tam--;
            for (Indice = Posic; Indice < Tam; Indice++) {
                Datos[Indice] = Datos[Indice + 1];
            }
        }
    } else {
        Resultado = 0; // Arreglo vacío
    }
    return Resultado;
}

// Método que despliega los valores almacenados en el arreglo.
template <class T>
void Arreglo<T>::Escribe()
{
    int Indice;
    if (Tam > 0) {
        cout << "\n\n";
        for (Indice = 0; Indice < Tam; Indice++) {
            cout << '\t' << Datos[Indice];
        }
        cout << "\n\n";
    } else {
        cout << "\n No hay elementos almacenados.";
    }
}

// =================================================================
// FUNCIONES Y MENÚ PRINCIPAL
// =================================================================

int MenuOpciones()
{
    char Opcion;
    do {
        cout << "\n\n\tL: Leer la lista de claves: ";
        cout << "\n\tA: Dar de alta un nuevo alumno: ";
        cout << "\n\tB: Dar de baja un alumno: ";
        cout << "\n\tI: Imprimir la lista de claves: ";
        cout << "\n\tF: Finalizar el proceso. ";
        cout << "\n\n\t Ingrese opcion de trabajo: ";
        cin >> Opcion;
        Opcion = toupper(Opcion);
    } while (Opcion != 'A' && Opcion != 'B' && Opcion != 'L' &&
             Opcion != 'I' && Opcion != 'F');
    return Opcion;
}

int main()
{
    Arreglo<int> ClavAlum;
    int Clave, Res;
    char Opc;

    do {
        Opc = MenuOpciones();
        switch (Opc) {
            case 'L': {
                ClavAlum.Lectura();
                break;
            }
            case 'I': {
                ClavAlum.Escribe();
                break;
            }
            case 'A': {
                cout << "\n\n Clave del nuevo alumno: ";
                cin >> Clave;
                Res = ClavAlum.InsertaDesordenado(Clave);
                if (Res == 1)
                    cout << "\n\n El nuevo alumno ya fue dado de alta.";
                else if (Res == 0)
                    cout << "\n\n No hay espacio para registrar el nuevo alumno.";
                else
                    cout << "\n\n Esa clave ya fue registrada previamente.";
                break;
            }
            case 'B': {
                cout << "\n\n Clave del alumno a dar de baja: ";
                cin >> Clave;
                Res = ClavAlum.EliminaDesordenado(Clave);
                if (Res == 1)
                    cout << "\n\n El alumno ya fue dado de baja.";
                else if (Res == 0)
                    cout << "\n\n No hay alumnos registrados.";
                else
                    cout << "\n\n Esa clave no esta registrada.";
                break;
            }
            case 'F':
                cout << "\n\n Termina el proceso.\n\n";
                break;
        }
    } while (Opc != 'F');

    return 0;
}
