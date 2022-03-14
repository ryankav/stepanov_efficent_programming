template<typename T>
struct singleton {
  T value;

  //conversions between T
  singleton(const T& x) : value(x) {}
  operator const T() const { return value; }
  operator T() { return value; }

  //semi-regular
  singleton() {}
  ~singleton() {}
  singleton(const singleton& x) : value(x.value) {}
  singleton& operator=(const singleton& x) {
    value = x.value;
    return *this;
  }

  //regular
  friend
  operator==(const singleton& x, const singleton& y) {
    return x.value == y.value;
  }

  friend
  operator!=(const singleton& x, const singleton& y) {
    return !(x == y);
  }

  //totally ordered

  friend
  bool operator<(const instrumented& x, const instrumented& y) {
    return x.value < y.value;
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
