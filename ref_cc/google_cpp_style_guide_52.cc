std::unique_ptr&lt;Foo&gt; foo = ...;
[foo = std::move(foo)] () {
  ...
}
