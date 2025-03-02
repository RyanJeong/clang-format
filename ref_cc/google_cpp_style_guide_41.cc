

<a id="auto"></a>
<h3 id="Type_deduction">Type Deduction (including auto)</h3>

<p>Use type deduction only if it makes the code clearer to readers who aren't
  familiar with the project, or if it makes the code safer. Do not use it
  merely to avoid the inconvenience of writing an explicit type.</p>

<p class="definition"></p>

<p>There are several contexts in which C++ allows (or even requires) types to
be deduced by the compiler, rather than spelled out explicitly in the code:</p>
<dl>
  <dt><a href="https://en.cppreference.com/w/cpp/language/template_argument_deduction">Function template argument deduction</a></dt>
  <dd>A function template can be invoked without explicit template arguments.
    The compiler deduces those arguments from the types of the function
    arguments:
    <pre class="neutralcode">template <typename T>
void f(T t);

f(0);  // Invokes f<int>(0)
