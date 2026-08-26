#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

//#include &lt;iostream&gt;
using namespace std;

/*********************** CLASE ALUMNO *******************************/
class Alumno{
 //ATRIBUTOS
 private: //especificador de acceso
   int codigo;
   string nombre;
   string carrera;
 public:
 //CONSTRUCTOR VACIO
  Alumno(){  }

 //METODOS
 void asignarCodigo(int c){
   codigo=c;
 }
 void asignarNombre(string nom){
   nombre=nom;
 }
 void asignarCarrera(string car){
   carrera=car;
 }
 int obtenerCodigo(){
  return codigo;
 }
 string obtenerNombre(){
   return nombre;
 }
 string obtenerCarrera(){
   return carrera;
 }
};//FIN DE LA CLASE ALUMNO


#endif // ALUMNO_H_INCLUDED
