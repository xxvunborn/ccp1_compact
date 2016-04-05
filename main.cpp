#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> PublicBinary;

void ToBinary(int n) {
  if (n / 2 != 0) {
    ToBinary(n / 2);
  }

  PublicBinary.push_back(n % 2);
}

int ToDecimal(std::vector<int> binary) {
  int decimal = 0;
  int value = 0;
  int h = binary.size() - 1;
  for (auto i = binary.begin(); i != binary.end(); ++i) {
    value = pow(2, h);
    if (*i == 1) {
      decimal = decimal + value;
    }
    h--;
  }

  return decimal;
}

std::vector<int> ToUnary(int n) {

  std::vector<int> binary;

  while (n > 0) {
    binary.push_back(1);
    n--;
  }
  binary.push_back(0);

  return binary;
}

std::vector<int> ToGamma(int n) {
  ToBinary(n); // Gamma = A*B
  int BinarySize = PublicBinary.size();
  std::vector<int> A = ToUnary(BinarySize);
  std::vector<int> B = PublicBinary;

  B.erase(B.begin()); // we can drop most significant bit

  std::vector<int> gamma = A;
  gamma.insert(gamma.end(), B.begin(), B.end());

  return gamma;
}

std::vector<int> ToDelta(int n) {
  std::vector<int> A = ToGamma(n); // Delta = A*B
  A.erase(A.begin());              // we can drop most significant bit
  std::vector<int> B = PublicBinary;
  B.erase(B.begin()); // we can drop most significant bit

  std::vector<int> delta = A;
  delta.insert(delta.end(), B.begin(), B.end());
  return delta;
}

int DecodeGama(std::vector<int> gamma) {
  // first we must to know the unary code
  // to achieve this goal we need to lookup the numbers from left to the right
  // untill we'll find the first 0. So, then that number will be the unary code
  std::vector<int> one;
  one.push_back(1);
  int position = 0;

  std::vector<int> binary = gamma;

  for (int i = 0; i < gamma.size(); ++i) {
    if (gamma[i] == 0) {
      position = i;
      break;
    }
  }

  binary.erase(binary.begin(), binary.begin() + position + 1);
  one.insert(one.end(), binary.begin(), binary.end());

  return ToDecimal(one);
}

int DecodeDelta(std::vector<int> delta) { return 1; }

double BitsNecessaryToSaveTheArray(std::vector<int> Array) {

  double size = Array.size();
  double maxValue = 0;
  for (int i = 0; i < size; i++) {
    if (Array[i] > maxValue) {
      maxValue = Array[i];
    }
  }

  return size * log2(maxValue); // N*log2(ø+1)
}

int main() {
  // we will asume that the inputh will be like this.
  // first value will be the size of the vecotr(from now, we call this: n)
  // the following n values will be the values that the vector must be host

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

  return 0;
}
