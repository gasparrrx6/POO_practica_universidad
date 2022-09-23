#include <iostream>
#include <string>
using namespace std;

struct Alumno {
  string nombre;
  float nota;
};

class Curso {
private:
  string m_materia;
  int m_cantAlumnos;
  Alumno *m_alumnos;

public:
  Curso(string nombreMateria, int nAlumnos);
  ~Curso();
  void addAlumno(Alumno);
  float getPromedio();
  Alumno maxAlumno();
  Alumno getAlumnos(int n);
  void vectorVacio();
};

// a constructor
Curso::Curso(string nombreMateria, int nAlumnos) {
  m_materia = nombreMateria;
  m_cantAlumnos = nAlumnos;
  m_alumnos = new Alumno[m_cantAlumnos];
}

// a destructor
Curso::~Curso() { delete[] m_alumnos; }

// b añadir alumnos
void Curso::addAlumno(Alumno b) {
  for (int i = 0; i < m_cantAlumnos; i++) {
    if (m_alumnos[i].nombre == "") {
      m_alumnos[i].nombre = b.nombre;
      m_alumnos[i].nota = b.nota;
      break;
    }
  }
}

// c obtener promedio
float Curso::getPromedio() {
  float sum = 0;
  for (int i = 0; i < m_cantAlumnos; i++) {
    sum += m_alumnos[i].nota;
  }
  return sum / m_cantAlumnos;
}

// d obtener mejor alumno
Alumno Curso::maxAlumno() {
  // se podria hacer sin usar puntero y es lo mismo
  Alumno *direcAlumno;
  float max = 0;
  for (int i = 0; i < m_cantAlumnos; i++) {
    if (m_alumnos[i].nota > max) {
      max = m_alumnos[i].nota;
      direcAlumno = &m_alumnos[i];
    }
  }
  return *direcAlumno;
}

// mostrar alumnos
Alumno Curso::getAlumnos(int n) { return m_alumnos[n]; }

// ver que contiene el vector vacio
void Curso::vectorVacio() {
  cout << "Nombre: " << m_alumnos[0].nombre << " nota: " << m_alumnos[0].nota;
}

int main() {
  // a crear curso
  string materia;
  int cantAlumnos;
  cout << "Ingrese nombre de la materia\n";
  cin >> materia;
  cout << "Ingrese cant de alumnos\n";
  cin >> cantAlumnos;
  Curso a(materia, cantAlumnos);

  // mostrar vector vacio
  cout << "\nEl vector vacio contiene\n";
  a.vectorVacio();
  cout << endl << endl;

  // b cargar alumnos
  Alumno b;
  for (int i = 0; i < cantAlumnos; i++) {
    cout << "Ingrese nombre del alumno\n";
    cin >> b.nombre;
    cout << "Ingrese nota\n";
    cin >> b.nota;
    a.addAlumno(b);
  }

  // mostrar todos los alumnos
  cout << "\nLa lista de alumnos es: \n";
  for (int i = 0; i < cantAlumnos; i++) {
    cout << "Alumno " << i << ": " << a.getAlumnos(i).nombre << " nota "
         << a.getAlumnos(i).nota << endl;
  }

  cout << endl;

  // c promedio
  cout << "La nota promedio es: " << a.getPromedio() << endl;

  // d mostrar el mejor alumno
  cout << "Alumno: " << a.maxAlumno().nombre << " nota: " << a.maxAlumno().nota;

  return 0;
}