#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Par {
  int daton;
  double datod;
};

int main() {
  int pos;
  Par datos;

  ofstream archi(
      "U3-Ej2.dat",
      ios::binary |
          ios::in); // abre el archivo pero sin sobreescribirlos (ios::in)

  cout << "Ingrese entero \n";
  cin >> datos.daton;
  cout << "Ingrese flotante \n";
  cin >> datos.datod;
  cout << "Ingrese posicion \n";
  cin >> pos;

  archi.seekp((pos - 1) * sizeof(Par));
  archi.write(reinterpret_cast<char *>(&datos), sizeof(datos));
  archi.close();

  ifstream archi2(
      "U3-Ej2.dat",
      ios::binary |
          ios::ate); // abre el archivo y se posiciona al final (ios::ate)

  int tamano_bytes_archi = archi2.tellg();
  int cant_datos = tamano_bytes_archi / sizeof(Par);
  archi2.seekg(0); // se posisciona al principio del archivo

  for (int i = 0; i < cant_datos; i++) {
    archi2.read(reinterpret_cast<char *>(&datos), sizeof(datos));
    cout << datos.daton << "   " << datos.datod << endl;
  }
  archi2.close();

  return 0;
}