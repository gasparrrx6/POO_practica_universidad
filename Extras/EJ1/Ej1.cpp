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

void reemplazar(string &discurso, string palabrota);

int main() {
  // Guardar discurso en un string y mostrarlo
  ifstream archiDiscurso("discurso.txt");
  string discurso, oracion;

  while (getline(archiDiscurso, oracion)) {
    discurso += oracion + "\n";
  }

  archiDiscurso.close();

  cout << discurso << endl;

  // Obtener palabrotas y ya reemplazar
  ifstream archiPalabrotas("palabrotas.txt");
  string palabrota;

  while (getline(archiPalabrotas, palabrota)) {
    reemplazar(discurso, palabrota);
  }

  archiPalabrotas.close();

  // Guardar discurso censurado en otro archivo y mostrarlo
  ofstream archiCensurado("discursoCensurado.txt");

  archiCensurado << discurso;
  cout << discurso << endl;

  archiCensurado.close();

  return 0;
}

void reemplazar(string &discurso, string palabrota) {
  string beep = "***beep***";
  int posicion = discurso.find(palabrota); // busca la posicion de la palabrota
  while (posicion != string::npos) {       // si hay
    discurso.replace(posicion, palabrota.size(), beep); // la remplaza
    posicion = discurso.find(
        palabrota, posicion + beep.size()); // sigue buscando mas palabrotas
  }
}