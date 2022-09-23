#include <cmath>
#include <iostream>

using namespace std;

struct Punto {
  float x, y;
};

///*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
class Recta {
public:
  virtual string getEcuacion() = 0;
  virtual bool pertenece(Punto p3) = 0;
  virtual ~Recta(){};
};

///*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
class RectaExplicita : public Recta {
  float m, b; /// y = mx + b
public:
  RectaExplicita(Punto p1, Punto p2) {
    this->m = (p2.y - p1.y) / (p2.x - p1.x);
    this->b = p1.y - m * p1.x;
  }

  string getEcuacion() override {
    return "y = " + to_string(m) + "x + " + to_string(b);
  }

  bool pertenece(Punto p3) override {
    return fabs(p3.y - (m * p3.x + b)) < 0.00001;
  }

  float getM() { return m; }
  float getB() { return b; }
};

///*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
class RectaGeneral : public Recta {
  float a, b, c; /// ax + by + c = 0
public:
  RectaGeneral(Punto p1, Punto p2) {
    this->a = p2.y - p1.y;
    this->b = p1.x - p2.y;
    this->c = -a * p1.x - b * p1.y;
  };

  string getEcuacion() override {
    return to_string(a) + "x + " + to_string(b) + "y + " + to_string(c) +
           " = 0";
  };

  bool pertenece(Punto p3) override {
    return a * p3.x + b * p3.y + c < 0.00001;
  }

  float getA() { return a; };
  float getB() { return b; };
  float getC() { return c; };
};

///*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int main() { return 0; }
