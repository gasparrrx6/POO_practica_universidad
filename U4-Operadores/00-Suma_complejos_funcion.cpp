/* Sobrecarga del operador + para sumar complejos */

#include <iostream>
#include <string>
using namespace std;

class Complejo {
private:
  float m_parteReal;
  float m_parteImag;

public:
  Complejo(float parteReal, float parteImag);
  float getParteReal();
  float getParteImag();
};

Complejo sumar(const Complejo c1, const Complejo c2);

int main() {
  Complejo c1(5, 2), c2(4, 3), c3(0, 0);

  c3 = sumar(c1, c2);

  cout << "Nro complejo: " << c3.getParteReal() << " + " << c3.getParteImag()
       << "i";

  return 0;
}

Complejo::Complejo(float parteReal, float parteImag) {
  m_parteReal = parteReal;
  m_parteImag = parteImag;
}
float Complejo::getParteReal() { return m_parteReal; }
float Complejo::getParteImag() { return m_parteImag; }

Complejo sumar(Complejo c1, Complejo c2) {
  Complejo resultado(c1.getParteReal() + c2.getParteReal(),
                     c1.getParteImag() + c2.getParteImag());
  return resultado;