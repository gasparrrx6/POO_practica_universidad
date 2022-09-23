#include <iostream>
#include <string>
#include <vector>
using namespace std;

class polinomio {
private:
  int grado;
  vector<float> coef;

public:
  polinomio(int grado);
  void cambiarCoef(int grado, float c);
  float evaluar(float x);
  void getPolinomio(polinomio);
};

// a
polinomio::polinomio(int grado) {
  this->grado = grado;
  coef.resize(grado + 1,
              0); // Inicializa el vector de n grado (+1 por el ter. ind.) en 0
};

// b
void polinomio::cambiarCoef(int grado, float c) { coef[grado] = c; }

// calcular potencia
float potencia(float base, int exp) {
  float resultado = 1;
  for (int i = 0; i <= exp; i++) {
    resultado *= base;
  }
  return resultado;
}

// c
float polinomio::evaluar(float x) {
  float resultado = 0;
  for (int i = 0; i <= grado; i++) {
    resultado += coef[i] * potencia(x, i);
  }
  return resultado;
}

// d
void polinomio::getPolinomio(polinomio) {
  for (int i = 0; i <= grado; i++) {
    if (i == 0) {
      cout << coef[i];
    } else if (i == 1 && coef[i] > 0) {
      cout << " + " << coef[i] << "x";
    } else if (i == 1 && coef[i] < 0) {
      cout << " " << coef[i] << "x";
    } else if (coef[i] > 0) {
      cout << " + " << coef[i] << "x^(" << i << ")";
    } else if (coef[i] < 0) {
      cout << " " << coef[i] << "x^(" << i << ")";
    } else {
      continue;
    }
  }
}

int main() {
  // crear polinomio
  int grado;
  cout << "Ingrese el grado del polinomio" << endl;
  cin >> grado;
  polinomio p(grado);

  // armar polinomio
  float c;
  for (int i = 0; i <= grado; i++) {
    cout << "Ingrese coeficiente para el grado " << i << endl;
    cin >> c;
    p.cambiarCoef(i, c);
  }

  // evaluar polinomio
  float x;
  cout << "Ingrese valor a evluar" << endl;
  cin >> x;
  cout << endl
       << "El valor del polinomio evaluado en " << x << " es: " << p.evaluar(x)
       << endl;

  // mostrar polinomio
  cout << "El polinomio final es:" << endl;
  p.getPolinomio(p);

  return 0;
}