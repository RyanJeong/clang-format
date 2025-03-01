
    <code>auto</code> can be qualified with <code>const</code>, and can be
    used as part of a pointer or reference type, and (since C++17) as a
    non-type template argument. A rare variant of this syntax uses
    <code>decltype(auto)</code> instead of <code>auto</code>, in which case
    the deduced type is the result of applying
    <a href="https://en.cppreference.com/w/cpp/language/decltype"><code>decltype</code></a>
    to the initializer.
  </dd>
  <dt><a href="https://en.cppreference.com/w/cpp/language/function#Return_type_deduction">Function return type deduction</a></dt>
  <dd><code>auto</code> (and <code>decltype(auto)</code>) can also be used in
    place of a function return type. The compiler deduces the return type from
    the <code>return</code> statements in the function body, following the same
    rules as for variable declarations:
    <pre class="neutralcode">auto f() { return 0; }  // The return type of f is int
