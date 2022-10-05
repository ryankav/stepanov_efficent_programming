#include "binary_counter.h"

template <typename I, typename Compare>
// requires I is a ForwardIterator
// and Compare is a StrickWeakOrdering on ValueType(I)

I min_element_binary(I first, I last, Compare cmp) {
  binary_counter<I, MinOp<Compare>> min_counter(...);
  min_counter.add(first);
  while (first != last) min_counter.add(first++);
  return min_counter.reduce();
}

//this is as far a was reached in the half hour mark of part 2
