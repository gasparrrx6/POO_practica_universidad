/* Leer un archivo de texto plano */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream archi("Prueba.txt");
  int x;

  while (archi >> x) {
    cout << x << " ";
  }

  return 0;
}