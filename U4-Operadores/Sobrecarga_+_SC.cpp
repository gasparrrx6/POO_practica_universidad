/* Sobrecarga del operador + para sumar complejos */

#include <iostream>
#include <string>
using namespace std;

class Complejo {
private:
  float m_parteReal;
  float m_parteImag;

public:
  float getParteReal() const;
  float getParteImag() const;
  void setParteReal(float nro);
  void setParteImag(float nro);
};

Complejo operator+(const Complejo c1, const Complejo c2);

int main() {
  Complejo c1, c2, c3;

  c1.setParteReal(5);
  c1.setParteImag(3);
  c2.setParteReal(4);
  c2.setParteImag(2);

  c3 = c1 + c2;

  cout << "Nro complejo: " << c3.getParteReal() << " + " << c3.getParteImag()
       << "i";

  return 0;
}

float Complejo::getParteReal() const { return m_parteReal; }
float Complejo::getParteImag() const { return m_parteImag; }
void Complejo::setParteReal(float nro) { m_parteReal = nro; }
void Complejo::setParteImag(float nro) { m_parteImag = nro; }

Complejo operator+(Complejo c1, Complejo c2) {
  Complejo resultado;
  resultado.setParteReal(c1.getParteReal() + c1.getParteReal());
  resultado.setParteImag(c2.getParteImag() + c2.getParteImag());
  return resultado;
}