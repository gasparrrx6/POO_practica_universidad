#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class VectorDinamico {
private:
  int *a; // puntero para almacenar el vector
  int t;  // tamaño
public:
  VectorDinamico(int n);
  VectorDinamico(VectorDinamico &copia);
  ~VectorDinamico();
  void Duplicar();
  void getVector();
  int VerElemento(int p);
};

// a
VectorDinamico::VectorDinamico(int n) {
  t = n;
  a = new int[t]; // crea t enteros dinamicos
  for (int i = 0; i < t; i++) {
    a[i] = 100 + rand() % 50;
  }
}

// constructor de copia no usado en el codigo
VectorDinamico::VectorDinamico(VectorDinamico &copia) {
  t = copia.t;
  a = new int[t];
  for (int i = 0; i < t; i++) {
    a[i] = copia.a[i];
  }
}

// b
VectorDinamico::~VectorDinamico() { delete[] a; }

// c
// primer intento fallido porque no inicializaba los nuevos valores
// void VectorDinamico::Duplicar() {
//   int *aux = a; // guarda la direccion actual del vector
//   *a = *a * 2;  // duplica la direccion actual
//   // recorre desde la direccion antigua hasta la direccion actual
//   for (int *i = aux; i < a; i++) {
//     a[*i] = 100 + rand() % 50;
//   }
// }

void VectorDinamico::Duplicar() {
  int aux = t;
  t *= 2;
  for (int i = aux; i <= t; i++) {
    a[i] = 100 + rand() % 50;
  }
}

// mostrar vector
// // opcion con puntero y tamaño, **preguntar si se puede saberla
// // posicion final del vector con puntero sin saber t**
// void VectorDinamico::getVector() {
//   for (int i = *a; i < *a + t; i++) {
//     cout << a[i - *a] << " ";
//   }
// }

// opcion usando t que es el tamaño del vector
void VectorDinamico::getVector() {
  for (int i = 0; i < t; i++) {
    cout << a[i] << " ";
  }
}

// d
int VectorDinamico::VerElemento(int p) { return a[p - 1]; }

int main() {
  VectorDinamico a(5);
  cout << "Vector normal" << endl;
  a.getVector();
  a.Duplicar();
  cout << endl << "Vector duplicado" << endl;
  a.getVector();
  int e;
  cout << endl << "Ingrese elemento a ver (de 1 a 10)" << endl;
  cin >> e;
  cout << "El elemento en la posicion " << e << " es: " << a.VerElemento(e);

  return 0;
}