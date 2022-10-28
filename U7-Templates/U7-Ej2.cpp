/* Ejercicio 2
 *
 * Implemente una función ​Clamp(...) que reciba como parámetros una
 * variable (por referencia) y dos valores indicando los límites superior e
 * inferior para el valor de dicha variable. Si el valor de la variable supera
 * su máximo, este debe ajustarse al máximo valor permitido. De la misma forma
 * si el valor es inferior al mínimo. Pruebe la función templatizada desde un
 * programa cliente.
 */

#include <iostream>
using namespace std;

template <typename T> void clamp(T &v, T max, T min) {
  if (v > max) {
    v = max;
  } else if (v < min) {
    v = min;
  }
}

int main() {
  int nro;
  cin >> nro;

  clamp(nro, 100, 10);

  cout << nro;

  return 0;
}