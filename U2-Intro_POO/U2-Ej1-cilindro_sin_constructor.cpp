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
  void
  asignarDatos(float altura,
               float r) {  // Se puede explayar una funcion dentro de la clase
    this->altura = altura; // this-> es como decir cilindro->altura
    radio = r;             // o se puede declarar como ya sabemos
  }
  float obtenerVolumen();
};

float cilindro::obtenerVolumen() { // O se puede explayar fuera de la clase con
                                   // el llamado clase::
  return (3.14 * radio * radio * altura);
}

int main() {
  float r1, h1;
  float r2 = 5.3;
  float h2 = 10.2;

  cin >> r2 >> h2;

  cilindro c1, c2;

  c1.asignarDatos(r1, h1);
  c2.asignarDatos(r2, h2);

  cout << "Volumen 1" << c1.obtenerVolumen() << endl;
  cout << "Volumen 2" << c2.obtenerVolumen() << endl;

  return 0;
}