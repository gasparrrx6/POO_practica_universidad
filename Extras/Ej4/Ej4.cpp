/* Ejercicio 4
 * Un  archivo  txt  guarda  datos  de  usuarios  de  un  sistema.  Por
 * cada  usuario  se  guarda  código  (entero),  nombre  (cadena)  y  contraseña
 * (cadena).  Se quiere encontrar contraseñas comunes para sugerirle a esos
 * usuarios que las modifiquen. Escriba un programa que:
 * a) lea los datos y genere una lista de todas las contraseñas que estén
 * repetidas más de 10 veces (que más de 10 usuarios tengan la misma).  La lista
 * debe  estar  ordenada por cantidad de  repeticiones  (primero  las  que más
 * se  repiten).
 * b) modifique  el archivo  estableciendo  la  cadena  vacía
 * como contraseña para todos los usuarios que tengan alguna de las contraseñas
 * de la lista.
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct User {
  int codigo;
  char nombre[25], pass[15]; // Definir en exceso
};

struct Contrasena {
  string texto; // Contraseña en sí
  int repet;    // cant de veces repetida
};

ostream &operator<<(ofstream &o, Contrasena c) {
  o << "Pass: " << c.texto << " se repite: " << c.repet;
  return o;
}

int main() {
  ifstream datos("datos.txt");
  fstream archi("usuarios.bin", ios::binary | ios::in);
  vector<User> lista;
  int cod;
  string nomb, pas = 0;

  while (datos >> cod && datos >> nomb && datos >> pas) {
    User u;

    u.codigo = cod;
    strcpy(u.nombre, nomb.c_str());
    strcpy(u.pass, pas.c_str());

    lista.push_back(u);
  }

  vector<Contrasena> listaPass;

  for (User u : lista) {
    for (int i = 0; i < listaPass.size(); i++) {
      if (u.pass != listaPass[i].texto) {
        Contrasena cs;
        cs.texto = u.pass;
        cs.repet += 1;
        listaPass.push_back(cs);
      } else if (u.pass == listaPass[i].texto) {
        listaPass[i].repet++;
      }
    }

    for (Contrasena b : listaPass) {
      cout << b.texto << " " << b.repet << endl;
    }

    return 0;
  }
}