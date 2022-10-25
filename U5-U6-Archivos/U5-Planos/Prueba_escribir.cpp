/* Escribir en un archivo de texto plano */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int x;
  cout << "Ingrese cant de nros\n";
  cin >> x;
  ofstream archi("Prueba.txt",
                 ios::trunc); // abro archivo, truncandolo (borrando su
                              // contenido), para realizar escritura

  for (int i = 0; i < x; i++) {
    archi << 10 + rand() % 100 << " ";
  }

  return 0;
}