/*
 * Diseñe una clase genérica llamada Calculos que tenga como
 * atributos un entero n (tamaño del vector),  un vector de n elementos
 * genéricos y 2 datos de mismo tipo genérico que los elementos del vector. La
 * clase debe tener un constructor, un método llamado dosmax(..) que obtenga los
 * 2 datos mayores del vector y métodos que considere necesarios. En un programa
 * cliente instancie la clase para una lista de flotantes y para una lista de
 * strings que deben leerse como datos.
 */

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

template <typename A> class Generica {
private:
  int n;
  vector<A> array;
  A dato1, dato2;

public:
  Generica() { array.resize(0); }
  Generica(int n) { array.resize(n); }
  void resizeCas(int n) { array.resize(n); }
  void cargarVector(A e, int i) { array[i] = e; }
  tuple<A, A> dosMax() {
    A max1 = array[0], max2 = array[1];
    for (int i = 2; i < array.size(); i++) {
      if (max1 < array[i]) {
        max2 = max1;
        max1 = array[i];
      } else if (max2 < array[i])
        max2 = array[i];
    }
    return make_tuple(max1, max2);
  }
};

int main() {
  // Cambiar string por int o viceversa
  Generica<string> clase;
  string max1, max2, e;
  int n;

  cout << "Ingrese tamano del vector\n";
  cin >> n;
  clase.resizeCas(n);

  for (int i = 0; i < n; i++) {
    cout << "Ingrese elemento\n";
    cin >> e;
    clase.cargarVector(e, i);
  }

  tie(max1, max2) = clase.dosMax();

  cout << "Los 2 mayores son: " << max1 << " y " << max2;

  return 0;
}