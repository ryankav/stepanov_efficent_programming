#ifndef INTSTRUMENTED_H
#define INTSTRUMENTED_H

template <typename T>
struct instrumented {

  const static size_t number_ops;
  static T counts[number_ops];
  const static char* counter_names[number_ops];

  size_t val;

  instrumented(const instrumented& x) : val(x.value) {
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
};

template<typename T>
const size_t instrumented<T>::number_ops = 7;

template <typename T>
const char* instrumented<T>::counter_names[instrumented<T>::number_ops] = { "n", "copy", "assign", "destruct", "default", "equal", "less" }; 

template <typename T>
T instrumented<T>::counts[instrumented<T>::number_ops] = {}; 

#endif
