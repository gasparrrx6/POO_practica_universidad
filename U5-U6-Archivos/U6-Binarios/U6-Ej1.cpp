#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Par {
  int daton;
  double datod;
};

int main() {
  ofstream archi("U6-Ej1.dat", ios::binary);

  Par par;

  for (int i = 0; i < 200; i++) {
    // int daton = rand();
    // double datod = rand() / 100.0;
    // archi.write(reinterpret_cast<char*>(&daton), sizeof(daton));
    // archi.write(reinterpret_cast<char*>(&datod), sizeof(datod));

    par.daton = rand();
    par.datod = rand() / 100.0;
    archi.write(reinterpret_cast<char *>(&par), sizeof(par));
  }

  ifstream archi2("U6-Ej1.dat", ios::binary | ios::ate);

  cout << "tamano del archivo " << archi2.tellg(); // tamaño es bytes

  archi.close();
  return 0;
}