#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class ecuacionCuadratica {
private:
  // atributos
  float a, b, c, discriminante;

public:
  // metodos
  ecuacionCuadratica(float a, float b, float c); // Constructor

  bool setRaicesReales();
  float getRaiz1();
  float getRaiz2();
  float getParteReal();
  float getParteImg();
};

ecuacionCuadratica::ecuacionCuadratica(float a, float b, float c) {
  this->a = a;
  this->b = b;
  this->c = c;
  discriminante = b * b - 4 * a * c;
}

bool ecuacionCuadratica::setRaicesReales() { return discriminante > 0; }

float ecuacionCuadratica::getRaiz1() {
  float raiz;
  if (setRaicesReales()) {
    raiz = (-b + sqrt(discriminante)) / 2 * a;
  }
  return raiz;
}

float ecuacionCuadratica::getRaiz2() {
  float raiz;
  if (setRaicesReales()) {
    raiz = (-b - sqrt(discriminante)) / 2 * a;
  }
  return raiz;
}

// float ecuacionCuadratica::getParteReal() {}

// float ecuacionCuadratica::getParteImg() {}

int main() {
  cout << "Ingresa los coeficientes de la ecuacion" << endl;
  float a, b, c;
  cin >> a >> b >> c;

  ecuacionCuadratica eq(a, b, c);
  if (eq.setRaicesReales()) {
    cout << "Raiz 1 = " << eq.getRaiz1() << " // raiz 2 = " << eq.getRaiz2()
         << endl;
  } else {
    cout << "No tiene raices reales";
  }

  return 0;
}