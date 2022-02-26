#ifndef INTSTRUMENTED_H
#define INTSTRUMENTED_H

template <typename T>
struct instrumented {

  size_t val;
  static const size_t number_ops;
  static const T count[7];
  static const char* counter_names[7];

  instrumented(): val() {}
};

template <typename T>
const T instrumented<T>::count[] = {};

#endif
