
#include "stack.h"
#include "vector.h"

#include <memory.h>
#include <string.h>
#include <stdlib.h>


Stack *
stack__new() {
  Stack * v = (Stack *)malloc(sizeof(Stack));
  v->vector = vector__new();
  return v;
}

Stack *
stack__copy(Stack * other) {
  Stack * v = stack__new();
  stack__assign(v, other);
  return v;
}

void
stack__delete(Stack * v) {
  vector__delete(v->vector);
  free(v);
}

Stack *
stack__assign(Stack * lhs, Stack * rhs) {
  vector__assign(lhs->vector, rhs->vector);
  return lhs;
}

int
stack__equals(Stack * lhs, Stack * rhs) {
  return vector__equals(lhs->vector, rhs->vector);
}


int
stack__size(Stack * v) {
  return vector__size(v->vector);
}

int
stack__empty(Stack * v) {
  return vector__empty(v->vector);
}

void
stack__push(Stack * v, StackValue value) {
  vector__push_back(v->vector, value);
}

StackValue
stack__pop(Stack * v) {
  return vector__pop_back(v->vector);
}

