#include <cmath>
#include <iostream>
#include <string>

using namespace std;

struct Punto {
  float x;
  float y;
};

class Recta {
public:
  virtual string obtenerEcuacion() = 0;
  virtual bool pertenece(Punto p) = 0;
};

class RectaExplicita : public Recta { // y = mx + b
private:
  float m, b;

public:
  RectaExplicita(Punto punto1, Punto punto2);
  string obtenerEcuacion() override;
  float getM();
  float getB();
  bool pertenece(Punto p) override;
};

class RectaGeneral : Recta { // Ax + By + C = 0
private:
  float a, b, c;

public:
  RectaGeneral(Punto punto1, Punto punto2);
  string obtenerEcuacion() override;
  float getA();
  float getB();
  float getC();
  bool pertenece(Punto p) override;
};

int main() {
  Punto p1, p2;

  // Recta Explicita
  cout << "Recta explicita\nIngrese x1\n";
  cin >> p1.x;
  cout << "Ingrese y1\n";
  cin >> p1.y;
  cout << "Ingrese x2\n";
  cin >> p2.x;
  cout << "Ingrese y2\n";
  cin >> p2.y;

  RectaExplicita recta(p1, p2);
  cout << "La pendiente de la recta es: " << recta.getM() << endl;
  cout << "La imagen de la recta es: " << recta.getB() << endl;
  cout << "La ecuacion de la recta es: " << recta.obtenerEcuacion();

  // Comporbar si punto pertenece
  cout << "\n\nComprobar si un punto pertenece a la recta\n";
  cout << "Ingrese x\n";
  cin >> p1.x;
  cout << "Ingrese y\n";
  cin >> p1.y;
  cout << recta.pertenece(p1) << endl;

  // Recta general
  cout << "Recta general\nIngrese x1\n";
  cin >> p1.x;
  cout << "Ingrese y1\n";
  cin >> p1.y;
  cout << "Ingrese x2\n";
  cin >> p2.x;
  cout << "Ingrese y2\n";
  cin >> p2.y;

  RectaGeneral rectaGral(p1, p2);
  cout << "El coeficiente A de la recta general es: " << rectaGral.getA()
       << endl;
  cout << "El coeficiente B de la recta general es: " << rectaGral.getB()
       << endl;
  cout << "El coeficiente C de la recta general es: " << rectaGral.getC()
       << endl;
  cout << "La ecuacion de la recta general es: " << rectaGral.obtenerEcuacion();
  // Comporbar si punto pertenece
  cout << "\n\nComprobar si un punto pertenece a la recta\n";
  cout << "Ingrese x\n";
  cin >> p1.x;
  cout << "Ingrese y\n";
  cin >> p1.y;
  cout << rectaGral.pertenece(p1);

  return 0;
}

RectaExplicita::RectaExplicita(Punto punto1, Punto punto2) {
  m = (punto2.y - punto1.y) / (punto2.x - punto1.x);
  b = (punto1.y - m * punto1.x);
};
string RectaExplicita::obtenerEcuacion() {
  return to_string(m) + "x+(" + to_string(b) + ")";
};
float RectaExplicita::getM() { return m; };
float RectaExplicita::getB() { return b; };
bool RectaExplicita::pertenece(Punto p) {
  return fabs(p.y - (m * p.x + b)) < 0.01; // fabs devuelve valor absoluto
};

RectaGeneral::RectaGeneral(Punto punto1, Punto punto2) {
  a = punto2.y - punto1.y;
  b = punto1.x - punto2.x;
  c = (-a * punto1.x) - (b * punto1.y);
};
string RectaGeneral::obtenerEcuacion() {
  return to_string(a) + "x+(" + to_string(b) + ")y+(" + to_string(c) + ")";
}
float RectaGeneral::getA() { return a; };
float RectaGeneral::getB() { return b; };
float RectaGeneral::getC() { return c; };
bool RectaGeneral::pertenece(Punto p) {
  return fabs(a * p.x + b * p.y + c) < 0.01;
};