#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Obtener nombres
  ifstream archiNombres("nombres.txt");
  string nombre;
  vector<string> listaNombres;

  while (getline(archiNombres, nombre)) {
    listaNombres.push_back(nombre);
  }

  archiNombres.close();

  // Obtener Contraseñas
  ifstream archiPass("pass.txt");
  string pass;
  vector<string> listaPass;

  while (getline(archiPass, pass)) {
    listaPass.push_back(pass);
  }

  archiPass.close();

  // Cargar datos
  ofstream archiDatos("datos.txt");

  for (int i = 0; i < 100; i++) {
    archiDatos << rand() % 9000 + 1000 << " " << listaNombres[rand() % 20]
               << " " << listaPass[rand() % 10] << endl;
  }

  archiDatos.close();

  return 0;
}