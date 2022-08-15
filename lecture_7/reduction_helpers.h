template<typename T, typename I, typename Op>
// requires Op is BinaryOperation on T
// Op is associative
// and I is ForwardIterator with ValueType T
T add_to_counter(I first, I last, Op op, const T& zero, T carry) {
  while (first != last) {
    if (*first == zero) {
      *first = carry;
      return zero;
    }

    carry = op(*first, carry);
    
    *first = zero;
    ++first;
  }

  return carry;
}

template<typename T, typename I, typename Op>
// requires Op is BinaryOperation on T
// Op is associative
// and I is ForwardIterator with ValueType T
T reduce_counter(I first, I last, Op op, T& zero) {
  while (first != last && *first == zero) {
    ++first;
  }

  if (first == last) {
    return zero;
  }

  T result = *first;
  ++first;

  while (first != last) {
    if (*first != zero) {
      result = op(*first, result);
    }

    ++first;
  }

  return result;
}
