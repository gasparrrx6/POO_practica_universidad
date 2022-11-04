/* Escriba un programa que defina un vector dinámico de 30 enteros aleatorios
 * menores que 25.
 * Luego:
 * a. Ordene en forma descendente los elementos ubicados entre las posiciones
 * 10 y 20 inclusive, y muestre el vector.
 * b. Inserte en un nuevo vector los elementos que fueron ordenados en el
 * apartado anterior, y quítelos del vector original.
 * c. Permita ingresar un valor por teclado, y muestre cuántas veces aparece
 * dicho valor en el vector.
 * d. Elimine todas las ocurrencias del valor ingresado en el punto c,
 * utilizando la función remove.
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int *v = new int[30];

  for (int i = 0; i < 30; i++) {
    v[i] = rand() % 26;
    cout << v[i] << " ";
  }

  // a
  sort(v + 10, v + 20);
  reverse(v, v + 30);
  int *v2 = new int[10];

  // b
  copy(v + 10, v + 20, v2); // esto es equivalente al if de abajo

  cout << "\nMuestra el vector ordenado" << endl;
  for (int i = 0; i < 30; i++) {
    cout << v[i] << " ";
    // if (i >= 9 && i <= 19)
    //   v2[i - 9] = v[i];
  }

  cout << "\nMuestra el vector reducido" << endl;
  for (int i = 0; i < 10; i++) {
    cout << v[i] << " ";
  }

  // c
  int nroBuscar;
  cout << "\nIngrese numero a buscar y eliminar\n";
  cin >> nroBuscar;
  auto cantApariciones = count(v, v + 30, nroBuscar);
  cout << "El nro " << nroBuscar << " aparece " << cantApariciones
       << " veces\n";

  // d
  auto itNuevoFinal = remove(v, v + 30, nroBuscar);

  for (auto i = v; i < itNuevoFinal; i++) {
    cout << v[i - v] << " ";
  }

  return 0;
}