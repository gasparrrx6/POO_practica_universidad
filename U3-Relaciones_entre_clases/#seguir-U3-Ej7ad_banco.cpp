#include <iostream>
#include <string>
using namespace std;

class Cuenta {
private:
  string titular;
  int nroCuenta;
  string tipoCuenta;
  float saldo;

public:
  void setDeposito(float saldo);
  float getSaldo();
};

class CuentaCorriente {
private:
  saldoMinimo;

public:
  comprobarSaldo();
};

class CuentaAhorro {
private:
  interes;

public:
  void calcIntereses();
  reintegro();
};

int main() { return 0; }

Cuenta::Cuenta(string titular, int nroCuenta, string tipoCuenta) {
  this.titular = titular;
  this.nroCuenta = nroCuenta;
  this.tipoCuenta = tipoCuenta;
}
