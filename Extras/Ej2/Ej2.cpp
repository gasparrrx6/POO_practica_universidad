/* Escriba una función genérica para buscar y reemplazar un dato dentro de
 * un archivo binario. La función debe recibir el nombre del archivo y dos datos
 * (A y B) del tipo genérico. Suponiendo que el archivo contiene elementos de
 * dicho tipo, buscar todas las ocurrencias de A, y reemplazarlas por B. No
 * utilice arreglos, vectores ni otros contenedores auxiliares (trabaje
 * directamente sobre el archivo).
 */

#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

template <typename tipoDato>
void buscarReemplazar(string nombre, tipoDato datoA, tipoDato datoB) {
  fstream archi(nombre, ios::binary | ios::in | ios::out | ios::ate);

  tipoDato dato;
  int tamanoArchi = archi.tellg();
  int n = tamanoArchi / sizeof(dato); // tamaño en bytes de cada dato

  for (int i = 0; i < n; i++) {
    archi.seekg(i * sizeof(dato));
    archi.read(reinterpret_cast<char *>(&dato), sizeof(dato));
    if (dato == datoA) {
      archi.seekp(i * sizeof(dato));
      archi.write(reinterpret_cast<char *>(&datoB), sizeof(datoB));
    }
  }
}

int main() {

  int a, b;
  cout << "Ingrese dato a buscar\n";
  cin >> a;
  cout << "Ingrese dato a insertar\n";
  cin >> b;

  buscarReemplazar("datos.bin", a, b);

  return 0;
}