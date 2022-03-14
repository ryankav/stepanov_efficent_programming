template<typename T, typename U>
struct pair {
  T m0;
  U m1;

  //conversions between T
  pair(const T& x) : m0(x), m1(x) {}
  pair(const T& x, const U& y) : m0(x), m1(y) {}
  operator const T() const { return m0; }
  operator const U() const { return m1; }
  operator T() { return m0; }
  operator U() { return m1; }

  //semi-regular
  pair() {}
  ~pair() {}
  singleton(const singleton& x) : value(x.value) {}
  singleton& operator=(const singleton& x) {
    value = x.value;
    return *this;
  }

  //regular
  friend
  operator==(const pair& x, const pair& y) {
    return x.m0 == y.m0 && x.m1 == y.m1;
  }

  friend
  operator!=(const singleton& x, const singleton& y) {
    return !(x == y);
  }

  //totally ordered

  friend
  bool operator<(const instrumented& x, const instrumented& y) {
    return x.m0 < y.m0;
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