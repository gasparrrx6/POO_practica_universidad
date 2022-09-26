/* Una empresa de telefonia ofrece un plan con abono fijo
 * de $2750 (incluye 20 GB de datos bonificados, $80 por cada GB adicional y
 * llamadas sin cargo) y un plan con tarjeta (sin abono fijo, $20 el minuto de
 * llamada y $220 el GB de datos)
 *
 * a) Programe una clase Cliente con atributos: nombre, número de linea (int),
 * gb datos y minutos.
 *
 * b) Defina un constructor que reciba como parámetros el nombre y número de
 * linea y métodos para obtener el valor de cada atributo, para incrementar la
 * cantidad de gb datos, y para incrementar la cantidad de minutos de llamada
 *
 * H) Utilizando polimorfismo, programe las clases Cliente ConAbono y Cliente
 * Con Tarjeta
 *
 * y agregue un método facturación que devuelva el importe en pesos que debe
 * facturarse a ese cliente.
 *
 * e) Progame una función que reciba como parámetro una lista de clientes y
 * devuelva la facturación total.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cliente {
private:
  string nombre;
  int nroLinea;
  int gbDatos = 0;
  int minutos = 0;

public:
  Cliente(string nombre, int nroLinea);
  string getNombre();
  int getNroLinea();
  int getGbDatos();
  int getMinutos();
  void incrementarGbDatos(int gbConsumidos);
  void incrementarMinutos(int minutosConsumidos);
  virtual int facturacion() = 0;
};

class ClienteAbono : public Cliente {
public:
  ClienteAbono(string nombre, int nroLinea);
  int facturacion() override;
};

class ClienteTarjeta : public Cliente {
public:
  ClienteTarjeta(string nombre, int nroLinea);
  int facturacion() override;
};

int facturacionListaClientes(vector<Cliente> lista);

int main() {
  vector<Cliente *> listaClientes;
  Cliente *a;
  string nombre;
  int nroLinea, gbDatos, minutos, tipo, total = 0;

  cout << "*Nuevo Cliente*\nNro de linea\n";
  cin >> nroLinea;
  do {
    cout << "Nombre\n";
    cin >> nombre;
    cout << "Tipo de plan: 0 si es con abono, 1 si es con tarjeta\n";
    cin >> tipo;
    if (tipo) {
      listaClientes.push_back(a = new ClienteTarjeta(nombre, tipo));
    } else {
      listaClientes.push_back(a = new ClienteAbono(nombre, tipo));
    }
    cout << "Datos consumidos\n";
    cin >> gbDatos;
    a->incrementarGbDatos(gbDatos);
    cout << "Minutos consumidos\n";
    cin >> minutos;
    a->incrementarMinutos(minutos);
    cout << "\n\n*Nuevo Cliente*\nNro de linea (0 para "
            "terminar)\n";
    cin >> nroLinea;
  } while (nroLinea != 0);

  for (int i = 0; i < listaClientes.size(); i++) {
    total += listaClientes[i]->facturacion();
  }
  cout << "La facturacion total de todos los clientes es: $" << total << endl;

  return 0;
}

// Clase Cliente
Cliente::Cliente(string nombre, int nroLinea) {
  this->nombre = nombre;
  this->nroLinea = nroLinea;
}
string Cliente::getNombre() { return nombre; }
int Cliente::getNroLinea() { return nroLinea; }
int Cliente::getGbDatos() { return gbDatos; }
int Cliente::getMinutos() { return minutos; }
void Cliente::incrementarGbDatos(int gbConsumidos) { gbDatos += gbConsumidos; }
void Cliente::incrementarMinutos(int minutosConsumidos) {
  minutos += minutosConsumidos;
}

// Clase ClienteAbon
ClienteAbono::ClienteAbono(string nombre, int nroLinea)
    : Cliente(nombre, nroLinea){};
int ClienteAbono::facturacion() {
  int total = 2750;
  if ((getGbDatos() > 20) && (getGbDatos() != 0)) {
    total += (getGbDatos() - 20) * 80;
  }
  return total;
}

// Clase ClienteTarjeta
ClienteTarjeta::ClienteTarjeta(string nombre, int nroLinea)
    : Cliente(nombre, nroLinea){};
int ClienteTarjeta::facturacion() {
  return getGbDatos() * 220 + getMinutos() * 20;
}

int facturacionListaClientes(vector<Cliente> &lista) {
  int total = 0;
  for (int i = 0; i < lista.size(); i++) {
    total += lista[0].facturacion();
  }
  return total;
}