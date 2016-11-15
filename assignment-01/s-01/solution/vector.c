
#include "vector.h"

#include <memory.h>
#include <string.h>
#include <stdlib.h>


Vector *
vector__new() {
  Vector * v = (Vector *)malloc(sizeof(Vector));
  v->size = 0;
  v->data = NULL;
  return v;
}

Vector *
vector__copy(Vector * other) {
  Vector * v = vector__new();
  vector__assign(v, other);
  return v;
}

void
vector__delete(Vector * v) {
  free(v->data);
  free(v);
}

Vector *
vector__assign(Vector * lhs, Vector * rhs) {
  if (lhs->size != rhs->size) {
    lhs->size = rhs->size;
    lhs->data = (VectorValue *)realloc(lhs->data, lhs->size * sizeof(VectorValue));
  }
  for (int i = 0; i < lhs->size; i++) {
    lhs->data[i] = rhs->data[i];
  }
  return lhs;
}

int
vector__equals(Vector * lhs, Vector * rhs) {
  if (lhs->size != rhs->size) {
    return 0;
  }
  for (int i = 0; i < lhs->size; i++) {
    if (lhs->data[i] != rhs->data[i]) {
      return 0;
    }
  }
  return 1;
}


int
vector__size(Vector * v) {
  return v->size;
}

int
vector__empty(Vector * v) {
  return (v->size == 0) ? 1 : 0;
}

VectorIterator
vector__begin(Vector * v) {
  return v->data;
}

VectorIterator
vector__end(Vector * v) {
  return v->data + v->size;
}

void
vector__push_back(Vector * v, VectorValue value) {
  int o = v->size;
  v->size++;
  v->data    = (VectorValue *)realloc(v->data, v->size * sizeof(VectorValue));
  v->data[o] = value;
}

VectorValue
vector__pop_back(Vector * v) {
  v->size--;
  VectorValue val = v->data[v->size];
  v->data = (VectorValue *)realloc(v->data, v->size * sizeof(VectorValue));
  return val;
}

void
vector__push_front(Vector * v, VectorValue value) {
  v->size++;
  v->data = (VectorValue *)realloc(v->data, v->size * sizeof(VectorValue));
  for (int i = v->size-1; i > 0 ; i--) {
    v->data[i] = v->data[i-1];
  }
  v->data[0] = value;
}

VectorValue
vector__pop_front(Vector * v) {
  VectorValue val = v->data[0];
  v->size--;
  for (int i = 0; i < v->size; i++) {
    v->data[i] = v->data[i+1];
  }
  v->data = (VectorValue *)realloc(v->data, v->size * sizeof(VectorValue));
  return val;
}

VectorValue
vector__at(Vector * v, int offset) {
  return v->data[offset];
}

