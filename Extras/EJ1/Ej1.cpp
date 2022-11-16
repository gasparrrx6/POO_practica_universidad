#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream archiDiscurso("discurso.txt");
  vector<string> discurso;
  string oracion;

  while (getline(archiDiscurso, oracion)) {
    discurso.push_back(oracion);
  }

  archiDiscurso.close();

  for (int i = 0; i < discurso.size(); i++) {
    cout << discurso[i] << endl;
  }

  return 0;
}