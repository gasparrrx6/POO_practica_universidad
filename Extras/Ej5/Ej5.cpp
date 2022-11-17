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
  Generica(A n) { array.resize(n); }
  void cargarVector(A e, int i) { array[i] = e; }
  tuple<A> dosMax() {
    A max1 = array[0], max2;
    for (A i : array) {
      if (max1 < i) {
        max2 = max1;
        max1 = i;
      } else if (max2 < i)
        max2 = i;
    }
    return make_tuple(max1, max2);
  }
};

int main() { return 0; }