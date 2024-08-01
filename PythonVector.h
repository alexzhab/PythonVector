#include <iostream>
#include <string>

class PythonVector {
private:
  double * m_array = nullptr;
  unsigned m_size{0};

  void init(unsigned size, const double * array = nullptr);
  void clean();
public:
  PythonVector() = default;
  PythonVector(unsigned size);
  PythonVector(const double * array, unsigned size);
  PythonVector(const PythonVector & pv);
  PythonVector & operator=(const PythonVector & pv);
  ~PythonVector();

  const unsigned get_size() const {
    return m_size;
  }
  void fill_array(const double * src, const unsigned size);
  PythonVector range(int n, int m) const;

  explicit operator std::string() const;
  double operator[](int idx) const;
  PythonVector operator+(const PythonVector & pv) const;
  PythonVector operator*(const PythonVector & pv) const;
  friend std::ostream & operator<<(std::ostream & os, const PythonVector & pv);
};