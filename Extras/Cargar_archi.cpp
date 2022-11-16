#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ofstream archi("datos.bin", ios::binary);

  for (int i = 0; i < 10; i++) {
    int a = rand() % 91 + 10;
    archi.write(reinterpret_cast<char *>(&a), sizeof(a));
  }

  archi.close();

  ifstream archi2("datos.bin", ios::binary | ios::in);

  int a;
  for (int i = 0; i < 10; i++) {
    archi2.read(reinterpret_cast<char *>(&a), sizeof(a));
    cout << a << endl;
  }

  archi2.close();

  return 0;
}