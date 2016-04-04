#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> PublicBinary;

void ToBinary(int n) {
  if (n / 2 != 0) {
    ToBinary(n / 2);
  }
  PublicBinary.push_back(n % 2);
  //printf("%d", n % 2);
}

int ToDecimal(std::vector<int> binary){
  int decimal=0;
  int value=0;
  int h = binary.size()-1;
  for(auto i = binary.begin(); i!= binary.end() ; ++i){
    value = pow(2,h);
    if(*i == 1){
      decimal = decimal + value;
    }
    h--;
  }

  return decimal;
}

std::vector<int> ToUnary(int n){

  std::vector<int> binary;

  while(n>0){
    binary.push_back(1);
    n--;
  }
  binary.push_back(0);

  //    for(auto i = binary.begin(); i!= binary.end() ; ++i){
  //        std::cout << *i;
  //    }
  return binary;
}

std::vector<int> ToGamma(int n){

  // Gamma = A*B

  ToBinary(n);
  int BinarySize = PublicBinary.size();

  std::vector<int> A = ToUnary(BinarySize);
  std::vector<int> B = PublicBinary;
  // Le quitamos el bit significativo
  B.erase(B.begin());

  std::vector<int> gamma = A;
  gamma.insert(gamma.end(), B.begin(), B.end());
  return gamma;
}

int DecodeGama(std::vector<int> gamma){

  // Primero tenemos que saber el codigo en unario
  // Para esto hay que ver los numeros de izqueda a derecha
  // Hasta que pillemos el primer cero, y esos numeros seran
  // el codigo unario
  std::vector<int> one;
  one.push_back(1);
  int position=0;

  std::vector<int> binary = gamma;

  for(int i = 0; i < gamma.size(); ++i){
    if( gamma[i] == 0){
      position = i;
      break;
    }
  }

  binary.erase(binary.begin(),binary.begin()+position+1);
  one.insert(one.end(),binary.begin(),binary.end());

  return ToDecimal(one);
}

int main() {

  // Leemos los parametros de la siguente manera
  // El primer valor es el largo del Arreglo A(Llamamos n el largo de A)
  // Los siguentes n valores son los valores del Arreglo A

//  int n = 0;
//  int temp = 0;
//  int RR= 0;
//  int CC = 0;
//  std::vector<std::vector<int> > ArrayA(RR, std::vector<int>(CC));
//
//  std::cout << "pectacular\n";
//
//
//  std::cin >> n;
//  CC = n;
//  while (n>0) {
//    std::cin >> temp;
//
//    ToBinary(temp);
//    ArrayA.push_back(ToGamma(temp));
//    ArrayA.clear();
//    n--;
//  }
//
//  for(int i = 0; i<RR; i++)
//  {
//    for(int j = 0; j<CC; j++)
//    {
//      std::cout << "pectacular 1\n";
//      std::cout<< ArrayA[i][j];
//    }
//  }

    std::vector<int> gamma = ToGamma(11);
    for(auto i = gamma.begin(); i!= gamma.end() ; ++i){
        std::cout << *i;
    }
    std::cout<< "\n";
    std::cout<<DecodeGama(gamma);


}
