#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
private:
  string nombre, especie, raza;
  int edad;

public:
  Animal(string nombre, string especie, string raza, int edad);
  string getNomnbre();
  string getEspecie();
  string getRaza();
  int getEdad();
  virtual string hablar() = 0;
  virtual string moverse() = 0;
};

class Perro : public Animal {
public:
  Perro(string nombre, string raza, int edad)
      : Animal(nombre, "perro", raza, edad){};
  string hablar() override;
  string moverse() override;
};

class Gato : public Animal {
public:
  Gato(string nombre, string raza, int edad)
      : Animal(nombre, "gato", raza, edad){};
  string hablar() override;
  string moverse() override;
};

class Loro : public Animal {
public:
  Loro(string nombre, string raza, int edad)
      : Animal(nombre, "loro", raza, edad){};
  string hablar() override;
  string moverse() override;
};

int main() {
  vector<Animal *> zoologico;
  string nombre, raza;
  int edad, tipo;

  // Cargar animales
  cout << "Ingrese tipo de animal a cargar:\n"
       << "1) Perro\n"
       << "2) Gato\n"
       << "3) Loro\n"
       << "0) Finalizar\n";
  cin >> tipo;
  while (tipo != 0) {
    cout << "Nombre\n";
    cin >> nombre;
    cout << "Raza\n";
    cin >> raza;
    cout << "Edad (en anios)\n";
    cin >> edad;
    if (tipo == 1) {
      zoologico.push_back(new Perro(nombre, raza, edad));
    } else if (tipo == 2) {
      zoologico.push_back(new Gato(nombre, raza, edad));
    } else if (tipo == 3) {
      zoologico.push_back(new Loro(nombre, raza, edad));
    }
    cout << "Ingrese tipo de animal a cargar:\n"
         << "1) Perro\n"
         << "2) Gato\n"
         << "3) Loro\n"
         << "0) Finalizar\n";
    cin >> tipo;
  }

  // Interacciones
  for (int i = 0; i < zoologico.size(); i++) {
    cout << "\nEl " << zoologico[i]->getEspecie() << " "
         << zoologico[i]->getRaza() << " " << zoologico[i]->getNomnbre()
         << " tiene " << zoologico[i]->getEdad() << " anios.\nDice "
         << zoologico[i]->hablar() << " y " << zoologico[i]->moverse() << ".\n";
  }

  return 0;
}

// Clase Animal
Animal::Animal(string nombre, string especie, string raza, int edad) {
  this->nombre = nombre;
  this->especie = especie;
  this->edad = edad;
  this->raza = raza;
}
string Animal::getNomnbre() { return nombre; }
string Animal::getEspecie() { return especie; }
string Animal::getRaza() { return raza; };
int Animal::getEdad() { return edad; }

// Clase Perro
string Perro::hablar() { return "guau!"; }
string Perro::moverse() { return "corre"; }

// Clase Gato
string Gato::hablar() { return "miau!"; }
string Gato::moverse() { return "trepa"; }

// Clase Loro
string Loro::hablar() { return "dame la papa!"; }
string Loro::moverse() { return "vuela"; }