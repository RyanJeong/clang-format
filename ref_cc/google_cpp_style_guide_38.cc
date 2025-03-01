
  </li>

  <li>Use portable <a href="#Floating-Point_Types">floating point types</a>;
  avoid <code>long double</code>.</li>

  <li>Use portable <a href="#Integer_Types">integer types</a>; avoid
  <code>short</code>, <code>long</code>, and <code>long long</code>.</li>
</ul>

<h3 id="Preprocessor_Macros">Preprocessor Macros</h3>

<p>Avoid defining macros, especially in headers; prefer
inline functions, enums, and <code>const</code> variables.
Name macros with a project-specific prefix. Do not use
macros to define pieces of a C++ API.</p>

<p>Macros mean that the code you see is not the same as
the code the compiler sees. This can introduce unexpected
behavior, especially since macros have global scope.</p>

<p>The problems introduced by macros are especially severe
when they are used to define pieces of a C++ API,
and still more so for public APIs. Every error message from
the compiler when developers incorrectly use that interface
now must explain how the macros formed the interface.
Refactoring and analysis tools have a dramatically harder
time updating the interface. As a consequence, we
specifically disallow using macros in this way.
For example, avoid patterns like:</p>

<pre class="badcode">class WOMBAT_TYPE(Foo) {
  // ...

 public:
  EXPAND_PUBLIC_WOMBAT_API(Foo)

  EXPAND_WOMBAT_COMPARISONS(Foo, ==, &lt;)
};

