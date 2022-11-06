/*  Ejercicio 8.3
 *
 * Cree un programa que lea valores flotantes por teclado y los inserte en una
 * lista. Luego:
 * a. Muestre dicha lista.
 * b. Inserte en medio de cada par de elementos contiguos el promedio de dichos
 * elementos.
 * c. Guarde la lista resultante en un archivo de texto llamado
 * U8-Ej3.txt”​.
 */

#include <iostream>
#include <list>
using namespace std;

int main() {
  list<float> lista;
  float nro;

  // a
  for (int i = 0; i < 5; i++) {
    cout << "Ingrese nro para la lista\n";
    cin >> nro;
    lista.push_back(nro);
  }

  cout << "Lista default\n";
  for (float x : lista) {
    cout << x << " ";
  }

  // b
  for (auto i = lista.begin(); i != lista.end(); i++) {
    if (i != lista.begin()) {
      lista.insert(i, (*i-- + *i++) / 2);
    }
  }

  cout << "\nLista modificada\n";
  for (float x : lista) {
    cout << x << " ";
  }

  return 0;
}