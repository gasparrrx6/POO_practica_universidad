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
};

int main() {
  vector<string> lista(4);
  vector<Alumno> listaa(4);

  cout << "elemento " << lista[0] << " " << lista.size() << endl;

  for (int i = 0; i < lista.size(); i++) {
    cout << lista[i] << endl;
  }

  return 0;
}