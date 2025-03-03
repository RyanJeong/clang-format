using Bar = Foo;
typedef Foo Bar;  // But prefer `using` in C++ code.
using ::other_namespace::Foo;
using enum MyEnumType;  // Creates aliases for all enumerators in MyEnumType.
