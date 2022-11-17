/* Ejercicio 4
 * Un  archivo  txt  guarda  datos  de  usuarios  de  un  sistema.  Por
 * cada  usuario  se  guarda  código  (entero),  nombre  (cadena)  y  contraseña
 * (cadena).  Se quiere encontrar contraseñas comunes para sugerirle a esos
 * usuarios que las modifiquen. Escriba un programa que:
 * a) lea los datos y genere una listaUsers de todas las contraseñas que estén
 * repetidas más de 10 veces (que más de 10 usuarios tengan la misma).  La
 * listaUsers debe  estar  ordenada por cantidad de  repeticiones  (primero  las
 * que más se  repiten). b) modifique  el archivo  estableciendo  la  cadena
 * vacía como contraseña para todos los usuarios que tengan alguna de las
 * contraseñas de la listaUsers.
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
  string texto;  // Contraseña en sí
  int repet = 0; // cant de veces repetida
};

ostream &operator<<(ofstream &o, Contrasena c) {
  o << "Pass: " << c.texto << " se repite: " << c.repet;
  return o;
}

int main() {
  ifstream datos("datos.txt");
  // fstream archi("usuarios.bin", ios::binary | ios::in);
  vector<User> listaUsers;
  int cod;
  string nomb, pas;

  while (datos >> cod && datos >> nomb && datos >> pas) {
    User u;

    u.codigo = cod;
    strcpy(u.nombre, nomb.c_str());
    strcpy(u.pass, pas.c_str());

    listaUsers.push_back(u);
  }

  vector<Contrasena> listaPassUsers;
  Contrasena cu;
  cu.texto = listaUsers[0].pass;
  cu.repet += 1;
  listaPassUsers.push_back(cu);

  for (int j = 1; j < listaUsers.size(); j++) {
    for (int i = 0; i < listaPassUsers.size(); i++) {
      if (listaUsers[j].pass != listaPassUsers[i].texto) {
        Contrasena cu;
        cu.texto = listaUsers[j].pass;
        cu.repet += 1;
        listaPassUsers.push_back(cu);
      } else if (listaUsers[j].pass == listaPassUsers[i].texto) {
        listaPassUsers[i].repet++;
      }
    }

    cout << "size " << listaPassUsers.size() << endl;

    for (Contrasena b : listaPassUsers) {
      cout << "pass " << b.texto << " repite " << b.repet << endl;
    }

    return 0;
  }
}