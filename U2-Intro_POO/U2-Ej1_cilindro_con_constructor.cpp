#include <iostream>
#include <string>
using namespace std;

class cilindro {
private:
  // atributos
  float altura;
  float radio;

public:
  // metodos
  cilindro(float r, float h); // Constructor asigna los atributos. Sirve para
                              // evitar crear una funcion.
  float obtenerVolumen();
};

float cilindro::obtenerVolumen() { // O se puede explayar fuera de la clase con
                                   // el llamado clase::
  return (3.14 * radio * radio * altura);
}

cilindro::cilindro(float r, float h) {
  altura = h;
  radio = r;
}

int main() {
  float r1, h1;
  float r2 = 5.3;
  float h2 = 10.2;

  cin >> r2 >> h2;

  cilindro c1(r1, h1), c2(r2, h2);

  cout << "Volumen 1" << c1.obtenerVolumen() << endl;
  cout << "Volumen 2" << c2.obtenerVolumen() << endl;

  return 0;
}