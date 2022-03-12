#ifndef INTSTRUMENTED_H
#define INTSTRUMENTED_H

#include <iterator>

template <typename T>
struct instrumented {

  const static size_t number_ops;
  static T counts[number_ops];
  const static char* counter_names[number_ops];

  size_t val;

  //regular type
  instrumented(const instrumented& x) : val(x.val) {
    counts[1]++;
  }

  instrumented& operator=(const instrumented& x) {
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
  bool operator==(const instrumented& x, const instrumented& y) {
    counts[5]++;
    return x.val == y.val;
  }

  friend
  bool operator!=(const instrumented& x, const instrumented& y) {
    return !(x == y);
  }

  //totally ordered
  friend
  bool operator<(const instrumented& x, const instrumented& y) {
    counts[6]++;
    return x.val < y.val;
  }

  friend
  bool operator>(const instrumented& x, const instrumented& y) {
    return y < x;
  }

  friend
  bool operator<=(const instrumented& x, const instrumented& y) {
    return !(y < x);
  }

  friend
  bool operator>=(const instrumented& x, const instrumented& y) {
    return !(x < y);
  }

  //Conversions

  explicit instrumented(const T& x) : val(x) {}

  operator const T() const {
    return val;
  }

  operator T() {
    return val;
  }

  static void initialize(size_t n);
};

template<typename T>
const size_t instrumented<T>::number_ops = 7;

template <typename T>
const char* instrumented<T>::counter_names[instrumented<T>::number_ops] = { "n", "copy", "assign", "destruct", "default", "equal", "less" }; 

template <typename T>
T instrumented<T>::counts[instrumented<T>::number_ops] = {};

template <typename T>
void instrumented<T>::initialize(size_t n) {
  std::fill(std::begin(instrumented<T>::counts), std::end(instrumented<T>::counts), 0);
  instrumented<T>::counts[0] = n;
}

#endif
