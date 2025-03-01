
<pre class="badcode">// bad: non-trivial destructor
const std::string kFoo = "foo";

// Bad for the same reason, even though kBar is a reference (the
// rule also applies to lifetime-extended temporary objects).
const std::string&amp; kBar = StrCat("a", "b", "c");

void bar() {
  // Bad: non-trivial destructor.
  static std::map&lt;int, int&gt; kData = {{1, 0}, {2, 0}, {3, 0}};
}
