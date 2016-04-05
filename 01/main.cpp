#include <iostream>
#include <vector>
#include <cmath>

double BitsNecessaryToSaveTheArray(std::vector<int> Array) {

  double size = Array.size();
  double maxValue = 0;
  for (int i = 0; i < size; i++) {
    if (Array[i] > maxValue) {
      maxValue = Array[i];
    }
  }

  return (size + 1) * log2(maxValue + 1); // N*log2(ø+1)
}

int main() {
  // Leemos los parametros de la siguente manera
  // El primer valor es el largo del Arreglo A(Llamamos n el largo de A)
  // Los siguentes n valores son los valores del Arreglo A

  int n = 0;
  int temp = 0;
  std::vector<int> ArrayA;
  std::vector<int> ArrayB;

  std::cin >> n;
  while (n) {
    std::cin >> temp;
    ArrayA.push_back(temp);
    n--;
  }

  std::cin >> n;
  while (n) {
    std::cin >> temp;
    ArrayB.push_back(temp);
    n--;
  }

  std::cout << BitsNecessaryToSaveTheArray(ArrayA);
}
