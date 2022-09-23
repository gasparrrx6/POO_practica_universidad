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

ostream &operator<<(ostream &o, Complejo a);
istream &operator>>(istream &i, Complejo &a);
Complejo operator+(Complejo a, Complejo b);
Complejo operator-(Complejo a, Complejo b);
Complejo operator*(Complejo a, Complejo b);
Complejo operator==(Complejo a, Complejo b);

int main() {
  int prueba = 0;

  return 0;
}

ostream &operator<<(ostream &o, Complejo a) {
  o << "(" << a.getParteReal() << "+" << a.getParteImag() << ")";
  return o;
}
istream &operator>>(istream &i, Complejo a);
Complejo operator+(Complejo a, Complejo b);
Complejo operator-(Complejo a, Complejo b);
Complejo operator*(Complejo a, Complejo b);
Complejo operator==(Complejo &a, Complejo &b);