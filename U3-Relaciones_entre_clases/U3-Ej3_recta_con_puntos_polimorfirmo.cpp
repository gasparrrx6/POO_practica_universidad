/* Construir una recta del tipo y = mx+b a partir de 2 puntos con un struct
 * Punto que almacene x e y de un punto
 */

#include <iostream>
#include <string>
using namespace std;

struct Punto {
  float x;
  float y;
};

class RectaExplicita {
private:
  float m, b;

public:
  RectaExplicita(Punto punto1, Punto punto2);
  string obtenerEcuacion();
  float getM();
  float getB();
};

int main() {
  Punto p1, p2;
  cout << "Ingrese x1\n";
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