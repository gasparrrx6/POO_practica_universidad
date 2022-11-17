/*
 * Ej3
 * a) Escriba una función genérica mediana3 que reciba 3 valores de
 * un mismo tipo genérico y retorne la mediana (la mediana es uno de los 3, el
 * que no es ni  el  mínimo  ni  el  máximo).
 * b)  Escriba  un programa cliente que muestre  la  mediana entre 3 flotantes
 * que ingrese el usuario; y entre 3 fracciones. Las fracciones deben ser del
 * tipo: struct Fraccion {int num, den;};
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename dato> dato mediana3(dato a, dato b, dato c) {
  int *v = new dato[];
  // sort(lista.begin(), lista.end());
  v[1] = a;
  v[2] = b;
  v[3] = c;
  cout << v[1];
  cout << v[2];
  cout << v[3];
  return lista[1];
}

struct fraccion {
  int num, den;
};

ostream &operator<<(ostream &o, fraccion a) {
  o << a.num << "/" << a.den;
  return o;
}

istream &operator>>(istream &i, fraccion a) {
  cout << "num";
  i >> a.num;
  cout << "den";
  i >> a.den;
  cout << "es: " << a;
  return i;
}

size_t operator new[](fraccion a) {}

int main() {
  int e;
  cout << "Ingrese 3 numeros\n"
       << "1) Enteros\n"
       << "2) Flotantes\n"
       << "3) Fracciones\n";
  cin >> e;

  switch (e) {
  case 1: {
    int a, b, c, m;
    cin >> a >> b >> c;
    m = mediana3(a, b, c);
    cout << m;
    break;
  }

  case 2: {
    float a, b, c, m;
    cin >> a >> b >> c;
    m = mediana3(a, b, c);
    cout << m;
    break;
  }

  case 3: {
    fraccion a, b, c, m;
    cin >> a >> b >> c;
    m = mediana3(a, b, c);
    cout << m;
    break;
  }
  }

  return 0;
}