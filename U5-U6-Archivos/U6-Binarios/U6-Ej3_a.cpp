#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ofstream archi("U6-Ej3.dat", ios::binary);

  for (int i = 0; i < 100; i++) {
    // int nro = 100 + rand() % 400;
    int nro = i + 5;
    archi.write(reinterpret_cast<char *>(&nro), sizeof(nro));
  }

  archi.close();

  ifstream archi2("U6-Ej3.dat", ios::binary | ios::ate);

  int tamano_bytes_archi = archi2.tellg();
  int cant_nros = tamano_bytes_archi / sizeof(int);
  archi2.seekg(0);

  int num;
  for (int i = 0; i < cant_nros; i++) {
    archi2.read(reinterpret_cast<char *>(&num), sizeof(num));
    cout << num << endl;
  }

  archi2.close();

  return 0;
}