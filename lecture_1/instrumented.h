#ifndef INTSTRUMENTED_H
#define INTSTRUMENTED_H

template <typename T>
struct instrumented {

  size_t val;
  static const size_t number_ops = 7;
  static const T* count[7];
  static const char* counter_names[7] = { "n", "copy", "assign", "destruct", "default", "equal", "less" };

  instrumented(): val() {}
};

#endif
