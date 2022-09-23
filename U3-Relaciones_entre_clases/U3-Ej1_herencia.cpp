#include <iostream>
#include <string>
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
  /*Cuando cosntruya el Alumno aparte de sus parametros tengo que pasarle una
   * persona ya construida, mas tedioso y confuso
   * Alumno(int promedio, int cantMaterias, Persona a) : Persona(a);
   */

  Alumno(float promedio, int cantMaterias,
         /*parametros de Persona -->*/ string apellido, string nombre, int dni,
         int fechaNac, string estadoCivil);
  // envio los datos recibidos a los atributos de persona de éste alumno
  float meritoAcademico();
};

class Docente : public Persona {
private:
  int fechaIngreso;

public:
  Docente(int fechaIngreso, string apellido, string nombre, int dni,
          int fechaNac, string estadoCivil);
  int getAntiguedad(int fechaActual);
};

int main() {
  string apellido;
  string nombre;
  int dni;
  int fechaNac;
  string estadoCivil;
  float promedio;
  int cantMaterias;

  cout << "\nDatos del alumno\n" << endl;
  cout << "Apellido" << endl;
  cin >> apellido;
  cout << "Nombre" << endl;
  cin >> nombre;
  cout << "DNI" << endl;
  cin >> dni;
  cout << "Fecha de nacimiento" << endl;
  cin >> fechaNac;
  cout << "Estado civil" << endl;
  cin >> estadoCivil;
  cout << "Promedio" << endl;
  cin >> promedio;
  cout << "Cantidad de materias aprobadas" << endl;
  cin >> cantMaterias;

  Alumno a(promedio, cantMaterias, apellido, nombre, dni, fechaNac,
           estadoCivil);

  int fechaIngreso;
  int fechaActual;

  cout << "\nDatos del docente\n" << endl;
  cout << "Apellido" << endl;
  cin >> apellido;
  cout << "Nombre" << endl;
  cin >> nombre;
  cout << "DNI" << endl;
  cin >> dni;
  cout << "Fecha de nacimiento" << endl;
  cin >> fechaNac;
  cout << "Estado civil" << endl;
  cin >> estadoCivil;
  cout << "Fecha de ingreso. (formato aaaammdd)" << endl;
  cin >> fechaIngreso;
  cout << "Fecha de actual" << endl;
  cin >> fechaActual;

  Docente d(fechaIngreso, apellido, nombre, dni, fechaNac, estadoCivil);

  cout << "\nEl merito academico del alumno " << a.getNombre() << " con DNI "
       << a.getDni() << " es: " << a.meritoAcademico() << endl;

  cout << "\nLa antiguedad del docente " << d.getApellido()
       << " es: " << d.getAntiguedad(fechaIngreso)
       << ". Y su estado civil actual es: " << d.getEstadoCivil();
  ;

  return 0;
}

Persona::Persona(string apellido, string nombre, int dni, int fechaNac,
                 string estadoCivil) {
  this->apellido = apellido;
  this->nombre = nombre;
  this->dni = dni;
  this->fechaNac;
  this->estadoCivil = estadoCivil;
}
int Persona::edad(int fechaActual) { return (fechaActual - fechaNac) / 10000; }

Alumno::Alumno(float promedio, int cantMaterias,
               /*parametros de Persona -->*/ string apellido, string nombre,
               int dni, int fechaNac, string estadoCivil)
    : Persona(apellido, nombre, dni, fechaNac, estadoCivil) {
  this->promedio = promedio;
  this->cantMaterias = cantMaterias;
};
float Alumno::meritoAcademico() { return cantMaterias * promedio; };

Docente::Docente(int fechaIngreso, string apellido, string nombre, int dni,
                 int fechaNac, string estadoCivil)
    : Persona(apellido, nombre, dni, fechaNac, estadoCivil) {
  this->fechaIngreso = fechaIngreso;
};
int Docente::getAntiguedad(int fechaActual) {
  return (fechaActual - fechaIngreso) / 10000;
};