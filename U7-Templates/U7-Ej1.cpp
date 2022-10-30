/* Ejercicio 1
 *
 * Implemente una función templatizada llamada ​Mayor(...) que reciba dos
 * valores y devuelva el mayor. Compruebe el correcto funcionamiento de la
 * rutina probándola desde un programa cliente con valores de tipo ​int​,
 * ​float​ y ​string​.
 * Programe una sobrecarga de la función ​Mayor(...) que
 * reciba un vector y retorne el mayor elemento del mismo.
 * Pruebe la función sobrecargada desde un programa cliente con diversos tipos
 * de datos.
 */

#include <iostream>
#include <string>
using namespace std;

template <typename T> T mayor(T a, T b) {
  T may;
  if (a > b) {
    may = a;
  } else {
    may = b;
  }

  return may;
}

int main() {
  int valor, intA, intB;
  float floatA, floatB;
  string stringA, stringB;
  cout << "Seleccione que variables desea comparar\n"
       << "1) Enteros\n"
       << "2) Flotantes\n"
       << "3) Strings\n";
  cin >> valor;

  cout << "Ingrese variables a comparar\n";
  switch (valor) {
  case 1:
    cin >> intA >> intB;
    cout << "El mayor es: " << mayor(intA, intB);

    break;

  case 2:
    cin >> floatA >> floatB;
    cout << "El mayor es: " << mayor(floatA, floatB);

    break;

  case 3:
    cin >> stringA >> stringB;
    cout << "El mayor es: " << mayor(stringA, stringB);
  }

  return 0;
}