/* Ejercicio 2
 *
 * En un archivo de texto llamado U5-Ej2_lista.txt​, se encuentran los nombres
 * y notas de los alumnos de una comisión de Programación Orientada a Objetos.
 * a) Escriba una función modificar() que reciba el nombre de un alumno y dos
 * notas, y modifique el archivo reemplazando las dos notas por el promedio.
 * b) En el porgrama main lea la lista del archivo y genere otro archivo de
 * texto U5-Ej2_promedios.txt ​con una tabla donde cada línea posea el
 * nombre, el promedio, y la condición final de cada uno de los alumnos
 * (promedio<40: desaprobado; promedio>=40: regular; promedio>=80:
 * promocionado).
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Alumno {
  string nombre;
  int nota1, nota2;
};

float modificar(Alumno &a) { return (a.nota1 + a.nota2) / 2.0; };

int main() {
  ifstream archi("U5-Ej2_lista.txt");
  vector<Alumno> lista;
  Alumno a;

  while (getline(archi, a.nombre) &&
         archi >> a.nota1 >> a.nota2) { // cargar los datos en un vector
    archi.ignore();
    lista.push_back(a);
  }

  archi.close();

  for (int i = 0; i < lista.size(); i++) {
    cout << lista[i].nombre << " " << lista[i].nota1 << " " << lista[i].nota2
         << endl;
  }

  ofstream archi2("U5-Ej2_promedios.txt", ios::trunc);
  float prom;

  for (int i = 0; i < lista.size(); i++) {
    prom = modificar(lista[i]);
    string condicion;
    if (prom >= 40 && prom < 80) {
      condicion = "Regular";
    } else if (prom >= 80) {
      condicion = "Promocionado";
    } else {
      condicion = "Libre";
    }
    archi2 << lista[i].nombre << " " << prom << " " << condicion << endl;
  }

  archi2.close();

  ifstream archi3("U5-Ej2_promedios.txt", ios::app);
  string renglon;

  cout << endl;
  while (getline(archi3, renglon)) {
    cout << renglon << endl;
  }

  archi.close();

  return 0;
}