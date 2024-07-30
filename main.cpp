#include "PythonVector.h"
#include <iostream>

const int arr_size = 5;

int main() {
  try {
    double arr[arr_size] = {1.22, 3.550601, -10, 1e-308, 1e308};

    PythonVector a(arr_size);
    a.fill_array(arr, arr_size);
    
    PythonVector b(arr, arr_size);

    PythonVector c{b};

    PythonVector d;
    d = b;

    std::cout << d;

    double arr2[3] = {1.11, 1e-3, 0.77};
    d = PythonVector(arr2, 3);
    std::cout << d;
    std::cout << std::string(c) << std::endl;

    // PythonVector range = d.range(2, 4); // m should be less than m_size
    // PythonVector range = d.range(2, 1); // n should be less than m
    PythonVector range = d.range(1, 3);
    std::cout << range;

    std::cout << b[2] << " " << b[-2] << " " << b[-10] << std::endl; // prints 2th, 3th and 0th element

    PythonVector e = b + d;
    PythonVector f = b * d;
    std::cout << e;
    std::cout << f;
    
    // PythonVector e{};
    // e.fill_array(arr2, 0); // Not initialized memory
  } catch (const std::exception &e) {
    return EXIT_FAILURE;
  }
  
  return 0;
}