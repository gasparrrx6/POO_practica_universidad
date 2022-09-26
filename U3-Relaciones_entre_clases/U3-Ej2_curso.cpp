/* Utilice las clases ​Alumno y ​Docente del ejercicio anterior para crear
 * una clase Curso que modele el cursado de una materia. Cada curso tiene un
 * nombre, un profesor a cargo y un número máximo de 50 alumnos. Implemente un
 * metodo AgregarAlumno(...) que permita agregar un alumno al curso y otro
 * metodo MejorPromedio(...) que devuelva el alumno con mejor promedio. Proponga
 * los constructores y métodos extra que considere necesarios.
 */

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
  Persona(){};
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
  Alumno(){};
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

int main() {
  string apellido, nombre, estadoCivil, nombreCurso;
  int dni, fechaNac, cantMaterias, fechaIngreso;
  float promedio = 0;
  Alumno a;

  cout << "Ingrese nombre del curso\n";
  cin >> nombreCurso;

  cout << "\nDatos del docente\n";
  cout << "Fecha de ingreso formato ddmmaaaa\n";
  cin >> fechaIngreso;
  cout << "Apellido\n";
  cin >> apellido;
  cout << "Nombre\n";
  cin >> nombre;
  cout << "DNI\n";
  cin >> dni;
  cout << "Fecha de nacimiento formato ddmmaaaa\n";
  cin >> fechaNac;
  cout << "Estado civil\n";
  cin >> estadoCivil;

  Docente _docente(fechaIngreso, apellido, nombre, dni, fechaNac, estadoCivil);
  Curso curso(nombreCurso, _docente);

  cout << "\nDatos del Alumno\n";
  cout << "Promedio\n";
  cin >> promedio;
  do {
    cout << "Cantidad de materias\n";
    cin >> cantMaterias;
    cout << "Apellido\n";
    cin >> apellido;
    cout << "Nombre\n";
    cin >> nombre;
    cout << "DNI\n";
    cin >> dni;
    cout << "Fecha de nacimiento formato ddmmaaaa\n";
    cin >> fechaNac;
    cout << "Estado civil\n";
    cin >> estadoCivil;
    Alumno b(promedio, cantMaterias, apellido, nombre, dni, fechaNac,
             estadoCivil);
    curso.agregarAlumno(b);
    cout << "\nDatos del Alumno (promedio -1 para terminar)\n";
    cout << "Promedio\n";
    cin >> promedio;
  } while (promedio != -1);

  a = (curso.mejorPromedio());
  cout << "El alumno con mejor promedio es: " << a.getNombre() << " DNI "
       << a.getDni() << " y promedio " << a.getPromedio();

  return 0;
}

// Clase Persona
Persona::Persona(string apellido, string nombre, int dni, int fechaNac,
                 string estadoCivil) {
  this->apellido = apellido;
  this->nombre = nombre;
  this->dni = dni;
  this->fechaNac;
  this->estadoCivil = estadoCivil;
}
int Persona::edad(int fechaActual) { return (fechaActual - fechaNac) / 10000; }

// Clase Alumno
Alumno::Alumno(float promedio, int cantMaterias, string apellido, string nombre,
               int dni, int fechaNac, string estadoCivil)
    : Persona(apellido, nombre, dni, fechaNac, estadoCivil) {
  this->promedio = promedio;
  this->cantMaterias = cantMaterias;
};
float Alumno::meritoAcademico() { return cantMaterias * promedio; };
float Alumno::getPromedio() { return promedio; }

// Clase Docente
Docente::Docente(int fechaIngreso, string apellido, string nombre, int dni,
                 int fechaNac, string estadoCivil)
    : Persona(apellido, nombre, dni, fechaNac, estadoCivil) {
  this->fechaIngreso = fechaIngreso;
};
int Docente::getAntiguedad(int fechaActual) {
  return (fechaActual - fechaIngreso) / 10000;
};

// Clase Curso
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
      a = (listaAlumnos[i]);
      max = listaAlumnos[i].getPromedio();
    }
  }
  return a;
}