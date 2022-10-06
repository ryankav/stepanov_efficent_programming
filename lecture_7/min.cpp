#include "binary_counter.h"

//TODO: Need to define MinOp class or stuct/functor.
// - compares two iterators and returns the one 
// pointing to the smallest one


template <typename Compare>
class MinOp
{
  private:
    Compare cmp;
  
  public:
    MinOp(Compare const& cmp): cmp(cmp) {}

    //What's the iterator type? We can template it
    template <typename I>
    I operator()(I const& x, I const& y) {
      return cmp(*y, *x) ? y : x;
    } 
};

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
