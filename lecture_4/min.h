template <typename T, typename Compare>
//requires StrictWeakOrdering on T
inline
const T& min(const T& a, const T& b, Compare cmp) {
  return cmp(b, a) ? b : a;
}
