template<typename T>
struct singleton {
  typedef T value_type;
  T value;

  //conversions between T
  explicit singleton(const T& x) : value(x) {}
  explicit operator T() const { return value; }

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
