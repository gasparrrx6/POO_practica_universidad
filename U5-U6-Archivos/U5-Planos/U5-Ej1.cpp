/* Ejercicio 1
 * Escriba un programa que cargue en un vector de strings una lista de palabras
 * desde un archivo de texto (que contendrá una palabra por línea), muestre en
 * pantalla la cantidad de palabras leídas, las ordene en el vector
 * alfabéticamente, y reescriba el archivo original con la lista ordenada.
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> lista;
  ifstream archi("U5-Ej1.txt");
  string palabra;

  while (archi >>
         palabra) { // toma las palabras del archivo y las guarda en un vector
    lista.push_back(palabra);
  }

  archi.close();

  cout << "Mostrando archivo antes de ordenar\n";
  for (int i = 0; i < lista.size(); i++) {
    cout << lista[i] << endl;
  }

  sort(lista.begin(), lista.end()); // ordenar lista

  ofstream archi2("U5-Ej1.txt", ios::trunc);

  cout << "\nMostrando archivo despues de ordenar\n"; // carga y muestra las
                                                      // palabras ordenadas
  for (int i = 0; i < lista.size(); i++) {
    archi2 << lista[i] << endl;
    cout << lista[i] << endl;
  }

  return 0;
}