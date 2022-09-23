#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Monomio {
  float coef;
  int exp;

public:
  Monomio(float coef, int exp) {
    this->coef = coef;
    this->exp = exp;
  };

  float evaluarMonomio(float x) { return coef * pow(x, exp); };
};

class Polinomio {
  vector<Monomio> pol;

public:
  void agregarMonomio(float coef, int exp) {
    Monomio m(coef, exp);
    pol.push_back(m);
  };

  float evaluarPolinomio(float x) {
    float suma = 0;
    for (int i = 0; i < pol.size(); i++) {
      suma += pol[i].evaluarMonomio(x);
    }
    return suma;
  };
};

int main() {
  int n;
  cout << "Cantidad de elementos del polinomio: ";
  cin >> n;

  Polinomio pol;
  float c;
  int e;
  for (int i = 0; i < n; i++) {
    cout << "\nGrado: ";
    cin >> e;
    cout << "Coeficiente: ";
    cin >> c;
    pol.agregarMonomio(c, e);
  }

  float x;
  cout << "\nEvaluar en: ";
  cin >> x;
  cout << endl << pol.evaluarPolinomio(x);

  return 0;
}
