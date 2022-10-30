/* Ejercicio 1
 *
 * Implemente una función templatizada llamada ​Mayor(...) que reciba dos
 * rta2es y devuelva el mayor. Compruebe el correcto funcionamiento de la
 * rutina probándola desde un programa cliente con rta2es de tipo ​int​,
 * ​float​ y ​string​.
 * Programe una sobrecarga de la función ​Mayor(...) que
 * reciba un vector y retorne el mayor elemento del mismo.
 * Pruebe la función sobrecargada desde un programa cliente con diversos tipos
 * de datos.
 */

#include <iostream>
#include <string>
#include <vector>
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

template <typename U> U mayor(const vector<U> v) {
  U may = v[0];
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > may) {
      may = v[i];
    }
  }

  return may;
}

int main() {
  int rta1, rta2;

  cout << "Seleccione que desea comparar\n"
       << "1) Variables\n"
       << "2) Vectores\n";
  cin >> rta1;

  switch (rta1) {
  case 1:
    cout << "Seleccione que variables desea comparar\n"
         << "1) Enteros\n"
         << "2) Flotantes\n"
         << "3) Strings\n";
    cin >> rta2;

    break;

  case 2:
    cout << "Seleccione que tipo de vector desea comparar\n"
         << "1) De enteros\n"
         << "2) De flotantes\n"
         << "3) De strings\n";
    cin >> rta2;

    break;
  }

  if (rta1 == 1) {
    switch (rta2) {
    case 1: {
      cout << "Ingrese variables a comparar\n";
      int intA, intB;
      cin >> intA >> intB;
      cout << "El mayor es: " << mayor(intA, intB);

      break;
    }

    case 2: {
      cout << "Ingrese variables a comparar\n";
      float floatA, floatB;
      cin >> floatA >> floatB;
      cout << "El mayor es: " << mayor(floatA, floatB);

      break;
    }

    case 3: {
      cout << "Ingrese variables a comparar\n";
      string stringA, stringB;
      cin >> stringA >> stringB;
      cout << "El mayor es: " << mayor(stringA, stringB);
      break;
    }
    }
  } else if (rta1 == 2) {
    switch (rta2) {
    case 1: {
      cout << "Ingrese variables para cargar el vector y luego compararlas\n";
      vector<int> v;
      int var;

      do {
        cout << "Ingrese el int. (-9999 para terminar)\n";
        cin >> var;
        v.push_back(var);
      } while (var != -9999);

      cout << "El mayor valor es: " << mayor(v);

      break;
    }

    case 2: {
      cout << "Ingrese variables para cargar el vector y luego compararlas\n";
      vector<float> v;
      float var;

      do {
        cout << "Ingrese el float. (-9999 para terminar)\n";
        cin >> var;
        v.push_back(var);
      } while (var != -9999);

      cout << "El mayor valor es: " << mayor(v);

      break;
    }

    case 3: {
      cout << "Ingrese variables para cargar el vector y luego compararlas\n";
      vector<string> v;
      string var;

      do {
        cout << "Ingrese el string. (AAAA para terminar)\n";
        cin >> var;
        v.push_back(var);
      } while (var != "AAAA");

      cout << "El mayor valor es: " << mayor(v);
      break;
    }
    }
  }

  return 0;
}