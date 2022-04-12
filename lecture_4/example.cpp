#include <iostream>

template <typename T>
// requires T is Regular
void check_equality(T& a) {
  std::cout << a == a ? "yes" : "no" << std::endl;
}

void main() {
  double x(0.0/0.0);
  check_equality(x);
}
