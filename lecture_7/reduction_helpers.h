template<typename T, typename Op>
class binary_counter 
{
  private:
    std::vector<T> counter;
    T zero;
    Op op;
  
  public:
    binary_counter(const Op& op, const T& zero): op(op), zero(zero) {
      counter.reserve(32);
    }; 

    void add(T x) {
      x = add_to_counter(counter.begin(), counter.end(), op, zero, x);

      if (x != 0) {
        counter.push_back(x);		
      }
    }

    T reduce() {
      return reduce_counter(counter.begin(), counter.end(), op, zero);
    }
};

template<typename T, typename I, typename Op>
// requires Op is BinaryOperation on T
// Op is associative
// and I is ForwardIterator with ValueType T
//
// An intersting point that alex makes is that whilst Carry could
// be passed by reference it's better to pass by value so that the
// assignement isn't a jump to a far away piece of memory in the loop
// better to have it near by so the assignement is more likely to be
// in memory already
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
