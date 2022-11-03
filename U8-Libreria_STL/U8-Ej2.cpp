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

#include <iostream>
using namespace std;

int main() {
  int *v = new int(30);

  for (int i = 0; i < 30; i++) {
    v[i] = rand() % 26;
  }

  return 0;
}