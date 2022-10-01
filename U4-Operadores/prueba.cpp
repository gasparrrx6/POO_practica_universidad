#include <iostream>
#include <string>
using namespace std;

class prueba {
  int numero;

public:
  prueba operator+(prueba aux) {
    if (numero > 1) {
      return *this;
    } else {
      return aux;
    };
  }
  void cargarNro(int nro) { numero = nro; };
  int most() { return numero; };
};

int main() {
  prueba a, b, c;
  int nro;

  cout << "ingresar numero";
  cin >> nro;
  a.cargarNro(nro);

  cout << "ingresar numero";
  cin >> nro;
  b.cargarNro(nro);

  c = a.operator+(b);

  cout << c.most();

  return 0;
}