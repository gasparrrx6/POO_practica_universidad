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

template <typename A, typename B>
void buscarReemplazar(string nombre, A datoA, B datoB) {
  fstream archi(nombre, ios::binary | ios::in | ios::out);
}

int main() { return 0; }