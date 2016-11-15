
#include "deque.h"
#include "vector.h"

#include <memory.h>
#include <string.h>
#include <stdlib.h>


Deque *
deque__new() {
  Deque * v = (Deque *)malloc(sizeof(Deque));
  v->vector = vector__new();
  return v;
}

Deque *
deque__copy(Deque * other) {
  Deque * v = deque__new();
  deque__assign(v, other);
  return v;
}

void
deque__delete(Deque * v) {
  vector__delete(v->vector);
  free(v);
}

Deque *
deque__assign(Deque * lhs, Deque * rhs) {
  vector__assign(lhs->vector, rhs->vector);
  return lhs;
}

int
deque__equals(Deque * lhs, Deque * rhs) {
  return vector__equals(lhs->vector, rhs->vector);
}


int
deque__size(Deque * v) {
  return vector__size(v->vector);
}

int
deque__empty(Deque * v) {
  return vector__empty(v->vector);
}

void
deque__push_back(Deque * v, DequeValue value) {
  vector__push_back(v->vector, value);
}

DequeValue
deque__pop_back(Deque * v) {
  return vector__pop_back(v->vector);
}

void
deque__push_front(Deque * v, DequeValue value) {
  vector__push_front(v->vector, value);
}

DequeValue
deque__pop_front(Deque * v) {
  return vector__pop_front(v->vector);
}

