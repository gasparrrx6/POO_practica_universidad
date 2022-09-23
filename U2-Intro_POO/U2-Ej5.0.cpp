#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Curso {
private:
  struct datosAlumno {
    string nombre;
    float nota;
  };
  string materia;
  vector<datosAlumno> alumnos;
  int cantAlumnos;
  int contador = 0;

public:
  Curso(string materia, int alumnos);
  void addAlumno(string nombre, float nota);
  float promedio();
  tuple<string, float> notaMax();
};

// a
Curso::Curso(string materia, int alumnos) {
  cantAlumnos = alumnos;
  this->materia = materia;
  this->alumnos[cantAlumnos];
}

// b
void Curso::addAlumno(string nombre, float nota) {
  datosAlumno datos;
  datos.nombre = nombre;
  datos.nota = nota;
  alumnos[contador] = datos;
  contador++;
}

// c
float Curso::promedio() {
  float suma = 0;
  for (int i = 0; i < cantAlumnos; i++) {
    suma += alumnos[i].nota;
  }
  return suma / cantAlumnos;
}

// d
tuple<string, float> Curso::notaMax() {
  float max = 0;
  int indice;
  for (int i = 0; i < cantAlumnos; i++) {
    if (alumnos[i].nota > max) {
      max = alumnos[i].nota;
      indice = i;
    }
  }
  return make_tuple(alumnos[indice].nombre, alumnos[indice].nota);
}

int main() {
  Curso a("Matematica", 6);
  string nombre;
  float nota;
  char opcion;
  do {
    cout << "Ingrese 'y' para añadir alumno, 'n' para terminar" << endl;
    cin >> opcion;
    cout << "Ingrese nombre y nota del alumno" << endl;
    cin >> nombre;
    cin >> nota;
    a.addAlumno(nombre, nota);
    cout << "añadido";
  } while (opcion == 'y');
  cout << "Promedio de notas" << a.promedio() << endl;
  tie(nombre, nota) = a.notaMax();
  cout << "El alumno con mayor nota es " << nombre << " con " << nota;

  return 0;
}