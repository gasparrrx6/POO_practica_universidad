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
#include <numeric>
#include <vector>

using namespace std;

int main() {
  vector<int> v(5);
  int nro;

  cout << "Ingrese 15 enteros\n";
  for (int e = 0; e < v.size(); e++) {
    cin >> nro;
    v[e] = nro;
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
  for (int &e : v) {
    cout << e << " ";
  }

  // b.1
  cout << "\nEl min es: " << *(min_element(v.begin(), v.end()))
       << ", y el max es: " << *(max_element(v.begin(), v.end()));

  // b.2
  int suma = accumulate(v.begin(), v.end(), 0);
  cout << "\nLa suma de todos los elementos es: " << suma;

  // b.3
  cout << "\nEl promedio es: " << float(suma / v.size());

  auto itStart = v.begin();
  auto itFin = v.end();
  sort(itStart, itFin);
  cout << "\nLa mediana es: " << v[v.size() / 2];

  // c
  // mostrar ordenado
  cout << "\nMostrando con rangos\n";
  for (int &e : v) {
    cout << e << " ";
  }

  do {
    cout << "\nIngrese valor a buscar\n";
    cin >> nro;
    auto posNroBuscado =
        find(v.begin(), v.end(), nro); // guarda la direc de mem de nro
    if (posNroBuscado != v.end()) {
      cout << "El nro esta en la posicion: " << posNroBuscado - v.begin() + 1;
    } else {
      cout << "Ese nro no esta en la lista";
    }
  } while (nro != 999);

  return 0;
}

/*
 * vector:
 * 54  23  78  89  65  end
 * 110 111 112 113 114 115
 *
 * posNroBuscado = 113
 *
 * posNroBuscado - v.end() = posicion real para la pc (desde 0) + 1
 * 113 - 110 = 3 + 1
 */