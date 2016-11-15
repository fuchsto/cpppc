/*
 * C++ type declaration and references explained in 100 lines of code or less.
 */
int main()
{
  // Anatomy of an assignment by example:
  //
  //     left-hand side       right-hand side
  //            |                    |
  //  .---------'---------.     .----'---.
  //   const Type * lvalue   =   & rvalue
  //   |     |    | |            | |
  //   |     |    | '- named     | '- named or unnamed
  //   |     |    |              |
  //   |     |    '- type        '- operator
  //   |     |
  //   |     '- referenced type
  //   |
  //   '- cvr
  //
  // CVR is short for the qualifier category "const, volatile, reference".

  int value = 100;

  // This is the *declaration* of variable p_value.
  // On the left hand side *of a declaration*, `*` refers to a type.
  int * p_value;

  // This is a *definition* of variable p_value.
  // On the right hand side, & is an operator.
  p_value = &value;

  // On the left hand side *of an assignment* `*` is the dereference
  // operator:
  *p_value = 222;
  // You actually can't mix this up (more important, neither can the
  // compiler) as `*` is not a complete type:
  //
  //    int * inst = NULL; // declaration/definition, int * is complete type
  //        * inst = NULL; // assignment of value referenced by pointer


  // Pointer values have no restriction whatsoever.
  // Therefore, they cannot be trusted:
  p_value = NULL;
  p_value = (int*)(123); // <-- may I introduce you to the
                         //     horrible, horrible C-style cast?

  // On the right hand size, `*` is an operator ...
  int  deref   = *p_value;
  // ... except when used within type specifiers like casts, of course:
  long deref_l = *((long *)p_value);
  //             ^       ^
  //             |       |
  //             |       '- type specifier, casting to "pointer-to-long*
  //             '- dereference operator

  // On the left hand side, `&` denotes a reference type.
  // References must be initialized (= defined) with their declaration.
  // Think of references as 'variable aliases'.
  // They are always named and can only refer to another named value.
  int & ref = value;

  // For a mental model, you can consider references as quantum-entangled.
  ref = 123;
  assert(value == 123);

  // int & one = 1; // <-- nope, `1` is not named
  // one = 2;       // <-- you see the problem?

  // Variables `ref` and `value` are *identical*.
  // In C/C++, two variables are *identical* if they represent the same
  // address:
  assert(&ref == &value);

  // *Equality* refers to the *values* of variables.
  // Obviously, identity implies equality.

  int a, b;
  a = 12;
  b = 12; // a equals b

  // Unfortunately, there is no special operator in C/C++ to test for
  // identity like `===` in other languages.
  // Fortunately, if your concepts are well-defined, you won't need it.

  // In C++ lingo, *named* values are usually called "lvalues", because
  // they can be used at the left hand side of an assignment.
  // *Unnamed* values are called "rvalues" because they can only be used at
  // the right hand side of an assignment.
  //
  // For example, `123` is an rvalue because a statement like:
  //
  //   123 = variable;
  //
  // ... would be nonsensical.

  return EXIT_SUCCESS;
}
