#include <iostream>
#include <string>
using namespace std;

int main() { return 0; }

bool operator<(Racional a, Racional b) {
  float a = a.getNumer() / (a.getDenomin() * 1.0);
  float b = b.getNumer() / (b.getDenomin() * 1.0);
  return a < b;
}
