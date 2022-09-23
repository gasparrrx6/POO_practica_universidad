#include <iostream>
#include <string>
using namespace std;

class Racional {
private:
  int numer;
  int denomin;

public:
  Racional(int n, int d) : numer(n), denomin(d){};
  int getNumer() { return numer; };
  int getDenomin() { return denomin; };
  Racional &operator++();
  Racional operator++(int noseusa);
};

int main() {
  Racional a(3, 5), b(2, 3), c(0, 1);
  return 0;
}

Racional operator+(Racional a, Racional b) {
  int num = a.getNumer() * b.getDenomin() + b.getNumer() * a.getDenomin();
  int den = a.getDenomin() + a.getNumer();
  return Racional(num, den);
};

Racional &Racional::operator++() {
  numer = numer + denomin;
  return *this;
}

Racional Racional::operator++(int noseusa) {
  Racional viejo(numer, denomin);
  numer = numer + denomin;
  return viejo;
}