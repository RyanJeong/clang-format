
<p>The type of a capture with an initializer is deduced using the same rules
  as <code>auto</code>.</p>

<p class="pros"></p>
<ul>
  <li>Lambdas are much more concise than other ways of
   defining function objects to be passed to STL
   algorithms, which can be a readability
   improvement.</li>

  <li>Appropriate use of default captures can remove
    redundancy and highlight important exceptions from
    the default.</li>

   <li>Lambdas, <code>std::function</code>, and
   <code>std::bind</code> can be used in combination as a
   general purpose callback mechanism; they make it easy
   to write functions that take bound functions as
   arguments.</li>
</ul>

<p class="cons"></p>
<ul>
  <li>Variable capture in lambdas can be a source of dangling-pointer
  bugs, particularly if a lambda escapes the current scope.</li>

  <li>Default captures by value can be misleading because they do not prevent
  dangling-pointer bugs. Capturing a pointer by value doesn't cause a deep
  copy, so it often has the same lifetime issues as capture by reference.
  This is especially confusing when capturing <code>this</code> by value,
  since the use of <code>this</code> is often implicit.</li>

  <li>Captures actually declare new variables (whether or not the captures have
    initializers), but they look nothing like any other variable declaration
    syntax in C++. In particular, there's no place for the variable's type,
    or even an <code>auto</code> placeholder (although init captures can
    indicate it indirectly, e.g., with a cast). This can make it difficult to
    even recognize them as declarations.</li>

  <li>Init captures inherently rely on <a href="#Type_deduction">type
      deduction</a>, and suffer from many of the same drawbacks as
    <code>auto</code>, with the additional problem that the syntax doesn't
    even cue the reader that deduction is taking place.</li>

  <li>It's possible for use of lambdas to get out of
  hand; very long nested anonymous functions can make
  code harder to understand.</li>

</ul>

<p class="decision"></p>
<ul>
<li>Use lambda expressions where appropriate, with formatting as
described <a href="#Formatting_Lambda_Expressions">below</a>.</li>
<li>Prefer explicit captures if the lambda may escape the current scope.
For example, instead of:
<pre class="badcode">{
  Foo foo;
  ...
  executor-&gt;Schedule([&amp;] { Frobnicate(foo); })
  ...
}
// BAD! The fact that the lambda makes use of a reference to `foo` and
// possibly `this` (if `Frobnicate` is a member function) may not be
// apparent on a cursory inspection. If the lambda is invoked after
// the function returns, that would be bad, because both `foo`
// and the enclosing object could have been destroyed.

