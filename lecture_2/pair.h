template<typename T, typename U>
struct pair {
  typedef T m0_type;
  typedef U m1_type;

  T m0;
  U m1;

  //conversion
  pair(const T& x, const U& y) : m0(x), m1(y) {}

  pair() {}
  ~pair() {}
  pair(const pair& x) : m0(x.m0), m1(x.m1) {}
  pair& operator=(const pair& x) {
    m0 = x.m0;
    m1 = x.m1;
    return *this;
  }

  friend
  operator==(const pair& x, const pair& y) {
    return x.m0 == y.m0 && x.m1 == y.m1;
  }

  friend
  operator!=(const pair& x, const pair& y) {
    return !(x == y);
  }

  friend
  bool operator<(const pair& x, const pair& y) {
    return x.m0 < y.m0 || (x.m0 == y.m0 && x.m1 < y.m1);
  }

  friend
  bool operator>(const pair& x, const pair& y) {
    return y < x;
  }

  friend
  bool operator<=(const pair& x, const pair& y) {
    return !(y < x);
  }

  friend
  bool operator>=(const pair& x, const pair& y) {
    return !(x < y);
  }
};