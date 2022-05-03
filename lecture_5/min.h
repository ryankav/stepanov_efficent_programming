#include <utility>

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
//requires StrictWeakOrdering on ValueType(I)
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

template <typename I, typename Compare>
//requires I is ForwardIterator
//requires StrictWeakOrdering on ValueType(I)
std::pair<I, I> minmax_element(I first, I last, Compare cmp) {
  if (first == last) {
    return std::pair(last, last); 
  }

  I min_el = first;
  ++first;
  if (first == last) {
    return std::pair(min_el, min_el);
  }

  I max_el = first;
  if (cmp(*max_el, *min_el)) {
    std::swap(min_el, max_el);
  }

  ++first;
  if (first == last) {
    return std::pair(min_el, max_el);
  }

  I current = first;
  ++first;
  I next = first;

  while (next != last) {
    //have iterator to potential min
    //have iterator to potential max
    //have current min and current max

    if (cmp(*next, *current)) {
      std::swap(current, next);
    }

    if (!cmp(*next, *max_el)) {
      max_el = next;
    }
    
    if (cmp(*min_el, *current)) {
      max_el = current;
    }

    ++first;
    current = first;
    if (first != last) {
      ++first;
      next = first;
    } else {
      next = last;
    }
  }

  if (current == last) {
    return std::pair(min_el, max_el);
  }

  if (!cmp(*current, *max_el)) {
    max_el = current;
  }
    
  if (cmp(*min_el, *current)) {
    max_el = current;
  }

  return std::pair(min_el, max_el);
}
