/*
 * Implemente un método llamado rellena perteneciente a la clase
 * stat_data  que tiene como atributo un objeto list<float> values. La lista
 * values contiene mediciones diarias de un sensor de temperatura. Por fallas en
 * el sensor, algunos días no se registraron mediciones. Para esos días
 * (elementos de la lista) se ha asentado el valor -1. El método  debe buscar y
 * reemplazar estos valores (-1) de la lista por el promedio de los valores
 * adyacentes (anterior y posterior) en cada caso, y retornar el promedio total
 * de los elementos de la lista modificada. Se sabe que en la lista no habrá
 * nunca dos -1 consecutivos. Si hubiera un -1 en el primer o último elemento,
 * en lugar del promedio se debe reemplazar por el único elemento adyacente
 * válido. Proponga en la clase solo los atributos relacionados (o necesarios)
 * para el método. Suponga que otro método se encargó de asignar los datos  a la
 * lista.
 */

#include <iostream>
#include <list>
using namespace std;

class stat_data {
private:
  list<float> values = {-1, 22, 23, 30, -1, 27, 25, -1};

public:
  void rellena();
};

int main() {
  stat_data l;

  l.rellena();

  return 0;
}

void stat_data::rellena() {
  auto it = values.begin();
  auto it2 = values.end();
  auto it3 = it2;
  it3--; // ultimo elemento de la lista

  for (auto i = it; i != it2; i++) {
    if ((*i == -1) && (i != it) &&
        (i != it3)) { // si el -1 no está al principio ni al final
      auto j = i;     // i es donde esta el -1
      j--;            // j es el valor anterior al -1
      auto k = i;
      k++; // k es el valor posterior a -1
      *i = ((*(j) + *(k)) / 2);
    } else if ((*i == -1) && (i == it)) { // si el -1 está al principio
      auto j = i;
      j++;
      *i = *j;
    } else if (*i == -1) { // si el -1 está al final
      auto j = i;
      j--;
      *i = *j;
    }
    cout << *i << endl;
  }
};
