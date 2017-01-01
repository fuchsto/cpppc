
1.   Types, Classes, Objects and their State

1.1

Assuming you are confronted with a class that supports the following
use case:

```c++
DateParser date_parser;
date_parser.set_date(today);

auto day = date_parser.day_of_week();
```

What is your objection to this? How would you change the interface of class
`DateParser`?



1.2

Consider the following use case:

```c++
// ...
if (condition) {
	LogFileReader log_reader("performance.log");
	if (log_reader.lines().size() > 1024) { return; }
}
// ...
```

Judging from its usage illustrated above: which rule must be satisfied in the
implementation of class `LogFileReader` (or one of its members)?
Name the technique in resource management that depends on this rule, and
briefly explain its principle.



1.3



2.  Iterators

The following algorithm dereferences and returns a given iterator's successor
unless the successor's referenced value matches some condition. The algorithm
is semantically correct but does not compile for iterators of some containers.
Which containers? Briefly explain why the algorithm does not work for these
and how it has to be changed.

```c++
template <typename Iterator, typename Value = typename Iterator::value_type>
Value next_value_or_default(Iterator it, Iterator end, Value default) {
  if (it == end) { return default; }
  return it[1];
}
```


3.  STL Algorithms


