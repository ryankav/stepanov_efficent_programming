template <typename T>
// requires T be semiregular
inline
void swap(T& a, T& b) {
  T tmp(a);
  a = b;
  b = tmp;
}

template <typename T>
// requires T be an UnsignedIntegral
inline
void swap_xor(T& a, T& b) {
  if (&a != &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
  }
}
