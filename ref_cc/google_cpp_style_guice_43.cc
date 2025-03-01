
  </dd>
  <dt><a href="https://isocpp.org/wiki/faq/cpp14-language#lambda-captures">Lambda init captures</a></dt>
  <dd>Lambda captures can have explicit initializers, which can be used to
    declare wholly new variables rather than only capturing existing ones:
    <pre class="neutralcode">[x = 42, y = "foo"] { ... }  // x is an int, and y is a const char*
