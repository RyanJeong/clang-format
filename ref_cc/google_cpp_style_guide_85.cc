class Foo {
 public:
  Foo(const Foo&amp;) = delete;
  Foo&amp; operator=(const Foo&amp;) = delete;
};

