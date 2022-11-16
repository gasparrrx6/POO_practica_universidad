/* Ej1
 * Un archivo “discurso.txt” contiene la  transcripción de un discurso
 * de  un  político  importante.  El  político  en  cuestión  tiene  la  mala
 * costumbre  de  usar palabrotas  en  su  discurso.  Sus  asesores  han
 * decidido modificar  la  transcripción  para no  molestar  a  los  votantes
 * más susceptibles.  Para  ello  han  generado  un  archivo “palabrotas.txt”,
 * con  la lista  de  las  que  usa  con más  frecuencia.  Escriba  un programa
 * c++  que modifique  el  archivo  del  discurso  reemplazando  todas  las
 * palabrotas  por “***beep***”.  No  hay palabras cortadas  en  el  texto  y
 * puede haber  2  o mas  palabrotas en una línea.
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Guardar discurso en vector y mostrarlo
  ifstream archiDiscurso("discurso.txt");
  vector<string> discurso;
  string oracion;

  while (getline(archiDiscurso, oracion)) {
    discurso.push_back(oracion);
  }

  archiDiscurso.close();

  for (int i = 0; i < discurso.size(); i++) {
    cout << discurso[i] << endl;
  }

  // Guardar palabrotas en vector
  ifstream archiPalabrotas("palabrotas.txt");
  vector<string> palabrotas;
  string palabrota;

  while (getline(archiPalabrotas, palabrota)) {
    palabrotas.push_back(palabrota);
  }

  archiPalabrotas.close();

  // Reemplazar palabrotas por beep
  string beep = "***beep***";

  for (int i = 0; i < discurso.size(); i++) {
    for (int j = 0; j < palabrotas.size(); j++) {
      int posBusqueda = discurso[i].find(palabrotas[i]);
      if (posBusqueda != -1) {
        // discurso[i].insert(posBusqueda, beep);
        discurso[i].replace(posBusqueda, 4, beep);
      }
    }
  }

  // Guardar discurso censurado en otro archivo y mostrarlo
  ofstream archiCensurado("discursoCensurado.txt");

  cout << endl;
  for (int i = 0; i < palabrotas.size(); i++) {
    archiCensurado << discurso[i] << endl;
    cout << discurso[i] << endl;
  }

  archiCensurado.close();

  return 0;
}