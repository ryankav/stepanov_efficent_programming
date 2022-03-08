#ifndef INTSTRUMENTED_H
#define INTSTRUMENTED_H

template <typename T>
struct instrumented {

  size_t val;
  static const instrumented_meta<T> meta_;
  const static size_t number_ops;
  const static T count[7];
  const static char* headers[7];

  instrumented(const instrumented& x) : val(x.value) {
    count[1]++;
  }

  instrumented& operator=(const instrumented& x) {
    count[2]++;
    val = x.value;
    return *this;
  }

  ~instrumented() {
    count[3]++;
  }

  instrumented() {
    count[4]++;
  }

  friend
  bool operator==(const instrumented& x, const instrumented& y) {
    count[5]++;
    return x.val == y.val;
  }

  friend
  bool operator!=(const instrumented& x, const instrumented& y) {
    return !(x == y);
  }
};

template <typename T>
const char* instrumented<T>::headers[7] = { "n", "copy", "assign", "destruct", "default", "equal", "less" }; 

template <typename T>
const T instrumented<T>::count[7] = {}; 

#endif
