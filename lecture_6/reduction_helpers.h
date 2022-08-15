//This lecture is motivated by finding the max and second largest
//element.
//The key concept is that the second largest must be an element
//that was compared against the maximum element.
//So now instead of doing a linear comparison we use a tree
//based approach.

//The key point here is that we can use O(log n) extra memory to
//keep track of the heighest ranking elements we've seen.
//As we start at the leaves can compare any elements at the same
//height of the tree.

//The key to being able to do this is that our comparison operation
//is associative. So we can easily reorder the comparisons as we want.


//The idea with this function is that we want to go through
//an iterable object of size Log(n) of the original data
//
template<typename T, typename I, typename Op>
// requires Op is BinaryOperation on T
// Op is associative
// and I is ForwardIterator with ValueType T
T add_to_counter(I first, I last, Op op, const T& zero, T carry) {
  //Alex makes the point that carry should be passed as value.
  //This is because we are going to modify the carry as that's what
  //we'll modify to perform all the comparisons we can.
  //
  //To be explicit the iterators point to the data structure where
  //we have already stored elements that we have seen.
  //This algorithm because of the zeroing of elements in the structure
  //will only find the maximum element.

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
  //move the iterator to the first non-zero element
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
