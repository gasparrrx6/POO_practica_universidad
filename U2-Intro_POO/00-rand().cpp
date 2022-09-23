#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
  for (int i = 0; i < 15; i++) {
    cout << 10 + rand() % 5 << " ";
  }

  return 0;
}
