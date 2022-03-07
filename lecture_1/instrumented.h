#ifndef INTSTRUMENTED_H
#define INTSTRUMENTED_H

template <typename T>
struct instrumented_meta {
  const T count[7];
  const char* headers[7];

  instrumented_meta() : headers{ "n", "copy", "assign", "destruct", "default", "equal", "less" } {}
  ~instrumented_meta() {}
  instrumented_meta(const instrumented_meta& x): count(x.count), headers(x.headers) {}
  instrumented_meta& operator=(const instrumented_meta& x) {
    count = x.count;
    headers = x.headers;
    return *this;
  }
  increment(int index) {
    ++count[index];
  }
};

template <typename T>
struct instrumented {

  size_t val;
  static const instrumented_meta<T> meta_;
  static const size_t number_ops;
  static const 

  instrumented(const instrumented& x) : val(x.value) {
    meta_.increment(1);
  }

  instrumented& operator=(const instrumented& x) {
    val = x.value;
    meta_.increment(2);
    return *this;
  }

  ~instrumented() {
    meta_.increment(3);
  }

  instrumented() {
    meta_.increment(4);
  }

  friend
  bool operator==(const instrumented& x, const instrumented& y) {
    meta_.increment(5);
    return x.val == y.val;
  }

  friend
  bool operator!=(const instrumented& x, const instrumented& y) {
    return !(x == y);
  }
};

#endif
