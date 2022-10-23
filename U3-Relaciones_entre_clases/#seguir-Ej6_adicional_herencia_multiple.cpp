#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Circulo {
private:
  float radio;

public:
  float getPerimetro();
  float getArea();
  void setDatos(float r);
};

class Rectangulo {
private:
  float lado1;
  float lado2;

public:
  float getArea();
  void setDatos(float l1, float l2);
};

class Poligono {
private:
  float radio;
  int nroLados;

public:
  float getLado();
  int getNroLados();
  float getArea();
  void setDatos(float r, int nl);
};

class Triangulo {
private:
  float altura;
  float base;

public:
  float getArea();
  void setDatos(float a, float b);
};

class Cilindro : public Circulo, Rectangulo {
public:
  float getArea();
  void setDatos(float, float);
};

class PrismaRegular : public Rectangulo, Poligono {
public:
  float getArea();
  void setDatos(int, float, float);
};

class PiramideRegular : public Poligono, Triangulo {
public:
  float getArea();
  void setDatos(int, float, float);
};

int main() {
  float angulo = 90;
  angulo *= M_PI / 180;
  cout << int(1.5) << endl;
  cout << sin(angulo);
  return 0;
}

// Clase Circulo
float Circulo::getPerimetro() { return 2 * 3.1416 * radio; }
float Circulo::getArea() { return 3.1416 * radio * radio; }
void Circulo::setDatos(float r) { radio = r; }

// Clase Rectangulo
float Rectangulo::getArea() { return lado1 * lado2; }
void Rectangulo::setDatos(float l1, float l2) {
  lado1 = l1;
  lado2 = l2;
}

// Clase Poligono
float Poligono::getLado() {
  float angulo = 360 / (2 * nroLados); // en grados
  angulo *= M_PI / 180;                // en radianes
  return sin(angulo);
}
int Poligono::getNroLados() { return nroLados; }
float Poligono::getArea() {
  // divido el poligno en triangulos y calculo la altura con pitagoras
  // radio^2 = (getLado()/2)^2 + x^2
  // sqrt(radio^2 - (getLado()/2)^2) = x
  float alturaTriangulo =
      sqrt(radio * radio - (getLado() / 2) * (getLado() / 2));
  // calculo el area del triangulo
  float areaTraingulo = alturaTriangulo * getLado();
  // el area del poligono es igual a
  // la suma de el area de todos los triangulos
  return areaTraingulo * nroLados;
}
void Poligono::setDatos(float r, int nl) {
  radio = r;
  nroLados = nl;
}

// Clase Triangulo
float Triangulo::getArea() { return base * altura; }
void Triangulo::setDatos(float a, float b) {
  altura = a;
  base = b;
}

// Clase Cilindro
float Cilindro::getArea() {
  // area de cilindro = areaBase(areaCirulo=pi*r*r) + areaLateral(r*h*2pi)
  // pero como ya tenemos el area del cilindro solo se multiplica por 1pi
  return Circulo::getArea() + Rectangulo::getArea() * M_PI;
}
void Cilindro::setDatos(float radio, float altura) {
  Circulo::setDatos(radio);
  Rectangulo::setDatos(radio * 2, altura);
}
