#include <iostream>

using namespace std;

#define MAX 10

template <class T>

class Pila {

    private:
        T EspacioPila[MAX];
        int Tope;
    public: Pila();
        void Push(T);
        void Pop(T*);
        int PilaLlena();
        int PilaVacia();

};

template <class T>
Pila<T>::Pila(){
    Tope=-1;
}

template <class T>
void Pila<T>::Push(T Dato){
     EspacioPila[++Tope]=Dato;
    }

template <class T>
void Pila<T>::Pop(T *Valor){
     *Valor = EspacioPila[Tope--];
    }

template <class T>
int Pila<T>::PilaLlena(){
    if(Tope == MAX-1)
        return 1;
    else
        return 0;
}

template <class T>
int Pila<T>::PilaVacia(){
    if(Tope == -1)
        return 1;
    else
        return 0;
}

int main()
{
    Pila<int> ObjPila;
    int Valor = 10, aux;

    while(ObjPila.PilaLlena()!=1){
        ObjPila.Pop(&aux);
        cout<<aux<<"\n";
    }

    return 0;
}
















