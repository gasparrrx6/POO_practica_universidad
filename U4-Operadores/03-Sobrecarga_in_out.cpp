/* Sobrecarga de los operadores cin y cout para sumar complejos */

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

ostream &operator<<(ostream &o, Complejo c);
istream &operator>>(istream &i, Complejo &c);

int main() {
  Complejo c1;

  cin >> c1;

  cout << c1 << endl;

  return 0;
}

float Complejo::getParteReal() const { return m_parteReal; }
float Complejo::getParteImag() const { return m_parteImag; }
void Complejo::setParteReal(float nro) { m_parteReal = nro; }
void Complejo::setParteImag(float nro) { m_parteImag = nro; }

ostream &operator<<(ostream &o, Complejo c) {
  o << c.getParteReal() << " + " << c.getParteImag() << "i ";
  return o;
}

istream &operator>>(istream &i, Complejo &c) {
  float a;
  cout << "Ingrese parte real" << endl;
  i >> a;
  c.setParteReal(a);
  float b;
  cout << "Ingrese parte imaginaria" << endl;
  i >> b;
  c.setParteImag(b);
  return i;
}