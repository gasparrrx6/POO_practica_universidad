/* Escriba un programa que permita al usuario ingresar 15 valores por teclado,
 * los almacene en un vector y luego:
 * a. Muestre el vector generado utilizando 3 mecanismos de iteración
 * diferentes:
 * 1. utilizando el operador []
 * 2. utilizando iteradores
 * 3. utilizando el for basado en rangos
 * b. Calcule y muestre:
 * 1. los valores de los elementos máximo y mínimo
 * 2. la suma de todos los elementos del arreglo
 * 3. el promedio y la mediana de los elementos del arreglo
 * c. Permita al usuario ingresar un valor, e informe si se encuentra en el
 * vector, y en caso afirmativo, en qué posición.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(5);
  int nro;

  cout << "Ingrese 15 enteros\n";
  for (int &e : v) {
    cin >> nro;
    e = nro;
  }

  // a.1
  cout << "\nMostrando con []\n";
  for (int e = 0; e < v.size(); e++) {
    cout << v[e] << " ";
  }

  // a.2
  cout << "\nMostrando con iteradores\n";
  for (auto e = v.begin(); e < v.end(); advance(e, 1)) {
    cout << *e << " ";
  }

  // a.3
  cout << "\nMostrando con rangos\n";
  for (auto e = v.begin(); e < v.end(); e++) {
    cout << *e << " ";
  }

  return 0;
}