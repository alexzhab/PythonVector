#include "PythonVector.h"
#include <iostream>
#include <sstream>
#include <string>

namespace {
  #define msg_assert(condition, message) \
  do { \
      if (!(condition)) { \
        std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                  << " line " << __LINE__ << ": " << message << std::endl; \
        std::abort(); \
      } \
  } while (false)

  void copy_array(const double * src, double * dst, const unsigned size) {
    msg_assert(src && dst, "Not initialized memory");
    for (unsigned i{}; i < size; ++i)
      dst[i] = src[i];
  }
}

void PythonVector::init(unsigned size, const double * array) {
  m_size = size;
  m_array = new double[m_size];
  msg_assert(m_array, "Out of memory");

  if (array)
    copy_array(array, m_array, m_size);
}

void PythonVector::clean() {
  delete[] m_array;
  m_array = nullptr;
  m_size = 0;
}

PythonVector::PythonVector(unsigned size) {
  init(size);
}

PythonVector::PythonVector(const double * array, unsigned size) {
  init(size, array);
}

PythonVector::PythonVector(const PythonVector & pv) {
  init(pv.get_size(), pv.m_array);
}

PythonVector & PythonVector::operator=(const PythonVector & pv) {
  if (this == &pv)
    return *this;
  
  clean();
  init(pv.get_size(), pv.m_array);
  
  return *this;
}

PythonVector::~PythonVector() {
  clean();
}

void PythonVector::fill_array(const double * src, const unsigned size) {
  msg_assert(size == m_size, "Array sizes are not equal");
  copy_array(src, m_array, m_size);
}

PythonVector PythonVector::range(int n, int m) const {
  msg_assert(n < m, "n should be less than m");
  msg_assert(m <= m_size, "m should be less than m_size");
  
  const int res_size = m - n;
  PythonVector res(res_size);
  
  copy_array(m_array + n, res.m_array, res_size);

  return res;
}

PythonVector::operator std::string() const {
  std::ostringstream os;

  os << "{";
  for (unsigned i{}; i < m_size; ++i) {
    if (i != 0)
      os << " ";
    os << m_array[i];
    if (i != m_size - 1)
      os << ",";
  }
  os << "}";

  return os.str();
}

double PythonVector::operator[](int idx) const {
  if (idx >= 0)
    return m_array[idx % m_size];
  else
    return m_array[m_size - 1 - std::abs(idx + 1) % m_size]; // shifting idx by 1 because negative numeration starts from -1, not 0
}

PythonVector PythonVector::operator+(const PythonVector & pv) const {
  const unsigned res_size = m_size + pv.m_size;
  PythonVector res(res_size);

  copy_array(m_array, res.m_array, m_size);
  copy_array(pv.m_array, res.m_array + m_size, pv.m_size);

  return res;
}

PythonVector PythonVector::operator*(const PythonVector & pv) const {
  const unsigned res_size = m_size * pv.m_size;
  PythonVector res(res_size);

  for (unsigned i{}; i < pv.m_size; ++i)
    for (unsigned j{}; j < m_size; ++j)
      res.m_array[i * m_size + j] = pv.m_array[i] * m_array[j];

  return res;
}

std::ostream & operator<<(std::ostream & os, const PythonVector & pv) {
  os << std::string(pv) << std::endl;
  return os;
}