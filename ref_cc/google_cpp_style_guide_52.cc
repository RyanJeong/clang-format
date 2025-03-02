std::unique_ptr<Foo> foo = ...;
[foo = std::move(foo)] () {
  ...
}
