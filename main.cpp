#include "PythonVector.h"
#include <iostream>

const int arr_size = 5;

int main() {
  double arr[arr_size] = {1, 2, 3, 4, 5};

  PythonVector a(arr_size);
  a.fill_array(arr, arr_size);

  PythonVector b(arr, arr_size);

  PythonVector c{b};

  PythonVector d{};
  std::cout << (d = b);

  double arr2[3] = {1.11, 2, 0.77};
  d = PythonVector(arr2, 3);
  std::cout << d;
  std::cout << std::string(c) << std::endl;

  // PythonVector range = d.range(2, 4); // m should be less than m_size
  // PythonVector range = d.range(2, 1); // n should be less than m
  PythonVector range = d.range(1, 3);
  std::cout << range;

  std::cout << b[2] << " " << b[-2] << " " << b[-10] << " " << b[10] << std::endl; // prints 2th, 3th and 0th element

  PythonVector e = b + d;
  PythonVector f = b * d;
  std::cout << e;
  std::cout << f;

  PythonVector j{0};
  std::cout << j + b;
  // PythonVector h{nullptr, 10}; // // Not initialized memory
  // PythonVector g{};
  // g.fill_array(arr2, 0); // Not initialized memory
  
  return 0;
}