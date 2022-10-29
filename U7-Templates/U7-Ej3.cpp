/*Ejercicio 3
 *
 * Programe una clase templatizada llamada ​VectorDinamico (similar a la de la
 * guía 2). La clase debe poseer:
 * a) Un constructor que reciba el tamaño inicial del vector, y reserve
 * la memoria necesaria.
 * b) Un destructor que se encargue de liberar la memoria reservada.
 * c) Una sobrecarga del operador[] que reciba el número de elemento,
 * devuelva su valor, y permita modificarlo.
 * d) Modifique o sobrecargue el constructor para que permita
 * generar valores aleatorios con los cuales inicializar
 * las posiciones del arreglo que reserva.
 * Utilice la clase desde un programa cliente creando
 * vectores aleatorios con diversos tipos de datos (int,double,string, etc).
 */

#include <iostream>
#include <string>
using namespace std;

template <typename T> class VectorDinamico {
private:
  T *vector;
  int tamano;

public:
  // a
  template <typename U>
  VectorDinamico(int n,
                 U algunaFuncAleatorio) { // U es el tipo de dato que retorana
                                          // la funcion (int, char, string) y
                                          // algunaFuncAleatorio es el parametro
    tamano = n;
    vector = new T[n];

    // d
    for (int i = 0; i < n; i++) {
      vector[i] = algunaFuncAleatorio();
    }
  }
  // b
  ~VectorDinamico() { delete[] vector; };
  // c
  T &operator[](int i) { return vector[i]; }
  T operator[](int i) const { return vector[i]; }
};

int aleatorioInt() { return rand() % 101; }
char aleatorioChar() { return 'A' + rand() % 26; }
string aleatorioString() {
  string cadena;

  for (int i = 0; i < 4; i++) {
    cadena += 'A' + rand() % 26;
  }

  return cadena;
}

int main() {

  int tipo, tamano;
  cout << "Ingrese tipo de vector\n"
       << "1) de enteros\n"
       << "2) de Char\n"
       << "3) de String\n";
  cin >> tipo;
  cout << "Ingrese el tamano\n";
  cin >> tamano;

  switch (tipo) {
  case 1:
    VectorDinamico<int> vInt(tamano, aleatorioInt);

    for (int i = 0; i < tamano; i++) {
      cout << vInt[i] << endl;
    }
    break;

  case 2:
    VectorDinamico<char> vChar(tamano, aleatorioChar);

    for (int i = 0; i < tamano; i++) {
      cout << vChar[i] << endl;
    }
    break;

  case 3:
    VectorDinamico<string> vString(tamano, aleatorioString);

    for (int i = 0; i < tamano; i++) {
      cout << vString[i] << endl;
    }
    break;
  }

  // fdf
  return 0;
}