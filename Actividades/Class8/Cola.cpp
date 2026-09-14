#include <iostream>

using namespace std;
#define MAX 10

template<class T>
    class Cola{
private:
    T EspacioCola[MAX];
    int Frente, Final;
public:
    Cola();
    void InsertarCola(T);
    void EliminaCola(T*);
    int Colallena();
    int ColaVacia();

    };
template <class T>
int Cola<T>::Colallena(){
    if(Final == MAX - 1)
        return 1;
    else
        return 0;
}

template <class T>
int Cola<T>::ColaVacia(){
    if(Frente == -1)
        return 1;
    else
        return 0;
}

template <class T>
Cola<T>::Cola(){
    Frente = -1;
    Final = -1;
}
template <class T>
void Cola<T>::EliminaCola(T *Dato){
    *Dato = EspacioCola[Frente];
    if(Frente == Final){
        Frente = -1;
        Final = -1;
    }else
        Frente++;
}
template <class T>
void Cola<T>::InsertarCola(T Dato){
    EspacioCola[++Final] = Dato;
    if(Final == 0)
        Frente = 0;
}

int main()
{
    Cola<int> ObjCola;
    int Valor;
    if(ObjCola.Colallena() != 1)
        ObjCola.InsertarCola(3);
    else
        cout<<"\nError de desbordamiento. Cola Llena\n";
        if (ObjCola.ColaVacia() != 1){
            ObjCola.EliminaCola(&Valor);
            cout<<Valor<<"\n";
        }else
            cout<<"\nSubdesbordamiento. Cola Vacia.\n";




    return 0;
}
















