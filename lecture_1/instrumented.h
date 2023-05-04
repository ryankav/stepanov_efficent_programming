#ifndef INTSTRUMENTED_H
#define INTSTRUMENTED_H

#include <stddef.h>
#include <iterator>

template <typename T>
struct instrumented {

  constexpr static size_t number_ops = 7;
  static T counts[number_ops];
  const static char* counter_names[number_ops];

  size_t val;

  //regular type
  instrumented(instrumented const& x) : val(x.val) {
    counts[1]++;
  }

  instrumented& operator=(instrumented const& x) {
    counts[2]++;

    val = x.val;
    return *this;
  }

  ~instrumented() {
    counts[3]++;
  }

  instrumented() {
    counts[4]++;
  }

  friend
  bool operator==(instrumented const& x, instrumented const& y) {
    counts[5]++;
    return x.val == y.val;
  }

  friend
  bool operator!=(instrumented const& x, instrumented const& y) {
    return !(x == y);
  }

  //totally ordered
  friend
  bool operator<(instrumented const& x, instrumented const& y) {
    counts[6]++;
    return x.val < y.val;
  }

  friend
  bool operator>(instrumented const& x, instrumented const& y) {
    return y < x;
  }

  friend
  bool operator<=(instrumented const& x, instrumented const& y) {
    return !(y < x);
  }

  friend
  bool operator>=(instrumented const& x, instrumented const& y) {
    return !(x < y);
  }

  //Conversions

  explicit instrumented(T const& x) : val(x) {}

  operator const T() const {
    return val;
  }

  operator T() {
    return val;
  }

  static void initialize(size_t n);
};

template <typename T>
char* const instrumented<T>::counter_names[instrumented<T>::number_ops] = { "n", "copy", "assign", "destruct", "default", "equal", "less" }; 

template <typename T>
T instrumented<T>::counts[instrumented<T>::number_ops] = {};

template <typename T>
void instrumented<T>::initialize(size_t n) {
  std::fill(std::begin(instrumented<T>::counts), std::end(instrumented<T>::counts), 0);
  instrumented<T>::counts[0] = n;
}

#endif
