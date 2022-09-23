#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persona {
private:
  string apellido;
  string nombre;
  int dni;
  int fechaNac;
  string estadoCivil;

public:
  Persona(string apellido, string nombre, int dni, int fechaNac,
          string estadoCivil);

  int edad(int fechaActual);

  string getApellido() { return apellido; };
  string getNombre() { return nombre; };
  int getDni() { return dni; };
  int getFechaNac() { return fechaNac; };
  string getEstadoCivil() { return estadoCivil; };
};

class Alumno : public Persona {
private:
  float promedio;
  int cantMaterias;

public:
  Alumno(float promedio, int cantMaterias, string apellido, string nombre,
         int dni, int fechaNac, string estadoCivil);
  float meritoAcademico();
  float getPromedio();
};

class Docente : public Persona {
private:
  int fechaIngreso;

public:
  Docente(int fechaIngreso, string apellido, string nombre, int dni,
          int fechaNac, string estadoCivil);
  int getAntiguedad(int fechaActual);
};

class Curso {
private:
  string nombre;
  vector<Alumno> listaAlumnos;
  Docente d;

public:
  Curso(string nombre, Docente d);
  void agregarAlumno(Alumno &a);
  Alumno mejorPromedio();
};

int main() { return 0; }

Persona::Persona(string apellido, string nombre, int dni, int fechaNac,
                 string estadoCivil) {
  this->apellido = apellido;
  this->nombre = nombre;
  this->dni = dni;
  this->fechaNac;
  this->estadoCivil = estadoCivil;
}
int Persona::edad(int fechaActual) { return (fechaActual - fechaNac) / 10000; }

Alumno::Alumno(float promedio, int cantMaterias, string apellido, string nombre,
               int dni, int fechaNac, string estadoCivil)
    : Persona(apellido, nombre, dni, fechaNac, estadoCivil) {
  this->promedio = promedio;
  this->cantMaterias = cantMaterias;
};
float Alumno::meritoAcademico() { return cantMaterias * promedio; };
float Alumno::getPromedio() { return promedio; }

Docente::Docente(int fechaIngreso, string apellido, string nombre, int dni,
                 int fechaNac, string estadoCivil)
    : Persona(apellido, nombre, dni, fechaNac, estadoCivil) {
  this->fechaIngreso = fechaIngreso;
};
int Docente::getAntiguedad(int fechaActual) {
  return (fechaActual - fechaIngreso) / 10000;
};

Curso::Curso(string nombre, Docente newDocente)
    : d(newDocente) { // d es el atributo de la clase Curso
  this->nombre = nombre;
};
void Curso::agregarAlumno(Alumno &a) { listaAlumnos.push_back(a); }
Alumno Curso::mejorPromedio() {
  Alumno a;
  float max = 0;
  for (int i = 0; i < listaAlumnos.size(); i++) {
    if (listaAlumnos[i].getPromedio() > max) {
      a(listaAlumnos[i]);
      max = listaAlumnos[i].getPromedio();
    }
  }
}