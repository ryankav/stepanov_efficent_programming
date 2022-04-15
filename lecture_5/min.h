//function object below rather than function call for performance
template <typename T>
//requires T is totallyordered
struct less {
  inline
  bool operator()(const T& a, const T&b) const {
    return a < b;
  }
};

template <typename T, typename Compare>
//requires StrictWeakOrdering on T
inline
const T& min(const T& a, const T& b, Compare cmp) {
  return cmp(b, a) ? b : a;
}

template <typename T>
inline
const T& min(const T& a, const T& b) {
  return min(a, b, std::less<T>());
}

template <typename T, typename Compare>
//requires StrictWeakOrdering on T
inline
const T& max(const T& a, const T& b, Compare cmp) {
  return cmp(b, a) ? a : b;
}

template <typename T, typename Compare>
//requires StrictWeakOrdering on T
inline
void sort2(T& a, T& b, Compare cmp) {
  if (cmp(b, a)) {
    std::swap(a, b);
  }
}

template <typename I, typename Compare>
//requires I is ForwardIterator
I min_element(I first, I last, Compare cmp) {
  I min_el = first;
  while (first != last) {
    if (cmp(*first, *min_el)) {
      min_el = first;
    }
    ++first;
  }

  return min_el;
}
