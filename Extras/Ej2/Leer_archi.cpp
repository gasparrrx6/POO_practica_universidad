#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream acrhi("datos.bin", ios::binary | ios::in);

  int a;
  for (int i = 0; i < 10; i++) {
    acrhi.read(reinterpret_cast<char *>(&a), sizeof(a));
    cout << a << endl;
  }

  acrhi.close();
}