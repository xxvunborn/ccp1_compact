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
  B.erase(B.begin()); // we drop the most significant bit

  std::vector<int> gamma = A;
  gamma.insert(gamma.end(), B.begin(), B.end());
  return gamma;
}

int DecodeGama(std::vector<int> gamma) {
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

int main() {
  int input;

  std::vector<int> gamma;
  while (cin >> input) {
    auto tmp = ToGamma(input);
    for (auto bt : tmp) {
      gamma.push_back(bt);
    }
  }
  std::vector<int> gamma = ToGamma(11);
  for (auto i = gamma.begin(); i != gamma.end(); ++i) {
    std::cout << *i;
  }
  std::cout << "\n";
  std::cout << DecodeGama(gamma);
}
