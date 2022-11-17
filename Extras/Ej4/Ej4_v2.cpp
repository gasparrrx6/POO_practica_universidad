/* Ejercicio 4
 * Un  archivo  txt  guarda  datos  de  usuarios  de  un  sistema.  Por
 * cada  usuario  se  guarda  código  (entero),  nombre  (cadena)  y  contraseña
 * (cadena).  Se quiere encontrar contraseñas comunes para sugerirle a esos
 * usuarios que las modifiquen. Escriba un programa que:
 * a) lea los datos y genere una listaUsers de todas las contraseñas que estén
 * repetidas más de 5 veces (que más de 5 usuarios tengan la misma).  La
 * listaUsers debe  estar  ordenada por cantidad de  repeticiones  (primero  las
 * que más se  repiten).
 * b) modifique  el archivo  estableciendo  la  cadena
 * vacía como contraseña para todos los usuarios que tengan alguna de las
 * contraseñas de la listaUsers.
 */

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct User {
  int codigo;
  char nombre[25], pass[15]; // Definir en exceso
};

ostream &operator<<(ostream &o, User u) {
  o << u.codigo << " " << u.nombre << " " << u.pass;
  return o;
}

struct Contrasena {
  string texto;  // Contraseña en sí
  int repet = 0; // cant de veces repetida

  bool operator<(Contrasena c) {
    return this->repet < c.repet;
  } // Sobrecarga para poder usar el sort()

  bool operator==(Contrasena c) {
    return this->texto == c.texto;
  } // Sobrecarga para poder usar el count()
};

int main() {
  // Leer del txt y pasarlo a binario
  ifstream datos("datos.txt");
  fstream archi("usuarios.bin", ios::binary | ios::in | ios::out);
  int cod;
  string nomb, pas;

  while ((datos >> cod) && (datos >> nomb) && (datos >> pas)) {
    User u;

    u.codigo = cod;
    strcpy(u.nombre, nomb.c_str());
    strcpy(u.pass, pas.c_str());

    archi.write(reinterpret_cast<char *>(&u), sizeof(u));
  }

  // Guardar toodas las contraseñas en un vector
  archi.ate;
  int cantUsers = archi.tellg() / sizeof(User);
  vector<string> listaDeTodasLasContrasenas;
  archi.seekg(0);

  for (int i = 0; i < cantUsers; i++) {
    User u;

    archi.seekg(i * sizeof(u));
    archi.read(reinterpret_cast<char *>(&u), sizeof(u));
    listaDeTodasLasContrasenas.push_back(u.pass);
  }

  // Contar apariciones de cada contraseña
  vector<Contrasena> listaContrasenasFinal;

  for (string pass : listaDeTodasLasContrasenas) {
    int cantApariciones = count(listaDeTodasLasContrasenas.begin(),
                                listaDeTodasLasContrasenas.end(), pass);
    if (cantApariciones >= 8) {
      Contrasena cu;
      cu.texto = pass;
      cu.repet = cantApariciones;
      listaContrasenasFinal.push_back(cu);
    }
  }

  // Ordenar lista de contraseñas de +repet a -repet
  sort(listaContrasenasFinal.begin(), listaContrasenasFinal.end());
  reverse(listaContrasenasFinal.begin(), listaContrasenasFinal.end());
  auto itBegin = listaContrasenasFinal.begin();
  auto itEnd =
      unique(listaContrasenasFinal.begin(), listaContrasenasFinal.end());

  cout << "CONTRASENAS Repetidas\n";
  for (auto i = itBegin; i != itEnd; i++) {
    cout << listaContrasenasFinal[i - itBegin].texto
         << " se repite: " << listaContrasenasFinal[i - itBegin].repet << endl;
  }

  // Crear archivo nuevo sin contraseñas repetidas
  fstream archiFinal("terminado.bin", ios::binary | ios::in | ios::out);

  for (int j = 0; j < cantUsers; j++) {
    User u;

    archi.seekg(j * sizeof(u));
    archi.read(reinterpret_cast<char *>(&u), sizeof(u));

    Contrasena c; // Es necesarios crear un objeto c para comparar en el find
    c.texto = u.pass;

    auto f =
        find(listaContrasenasFinal.begin(), listaContrasenasFinal.end(), c);

    if (f != listaContrasenasFinal.end()) {
      string vacio = "";
      strcpy(u.pass, vacio.c_str());
    }
    archiFinal.seekp(j * sizeof(u));
    archiFinal.write(reinterpret_cast<char *>(&u), sizeof(u));
    cout << u << endl;
  }

  // Mostrar lista final
  archiFinal.seekg(0);

  cout << "\nLista Final\n";
  for (int i = 0; i < cantUsers; i++) {
    User u;

    archi.seekg(i * sizeof(u));
    archiFinal.read(reinterpret_cast<char *>(&u), sizeof(u));
    cout << u << endl;
  }

  return 0;
}