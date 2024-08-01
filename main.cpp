#include "PythonVector.h"
#include <iostream>
#include <iomanip>

const int arr_size = 5;

int main() {
  double arr[arr_size] = {1, 2, 3, 4, 5};

  std::cout << std::endl << "Checking constructors: " << std::endl;
  PythonVector a(arr_size);
  a.fill_array(arr, arr_size);

  PythonVector b(arr, arr_size);

  PythonVector c{b};

  PythonVector d{};
  std::cout << (d = b);

  double arr2[3] = {-1, 2, 0.7};
  d = PythonVector(arr2, 3);
  std::cout << std::string(d) << std::endl;

  std::cout << std::endl << "Checking member range: " << std::endl;
  // PythonVector rng = d.range(2, 4); // m should be less than m_size
  // PythonVector rng = d.range(2, 1); // n should be less than m
  PythonVector rng = d.range(1, 3);
  std::cout << rng;

  std::cout << std::endl << "Checking range loop: " << std::endl;
  std::cout << std::setw(14) << "[-10, 10]: ";
  for (int i: range(-10, 10)) 
    std::cout << b[i] << " ";
  std::cout << std::endl;
  std::cout << std::setw(14) << "[-10, 10, 2]: ";
  for (int i: range(-10, 10, 2)) 
    std::cout << b[i] << " ";
  std::cout << std::endl;
  // for (int i: range(-10, 10, -1)) // step should be non-negative
  //   std::cout << b[i] << " ";

  std::cout << std::endl << "Checking + *: " << std::endl;
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