
<p>If the type is a template instance, and the parameters are
  boilerplate but the template itself is informative, you can use
  class template argument deduction to suppress the boilerplate. However,
  cases where this actually provides a meaningful benefit are quite rare.
  Note that class template argument deduction is also subject to a
  <a href="#CTAD">separate style rule</a>.</p>

<p>Do not use <code>decltype(auto)</code> if a simpler option will work,
  because it's a fairly obscure feature, so it has a high cost in code
  clarity.</p>

<h4>Return type deduction</h4>

<p>Use return type deduction (for both functions and lambdas) only if the
  function body has a very small number of <code>return</code> statements,
  and very little other code, because otherwise the reader may not be able
  to tell at a glance what the return type is. Furthermore, use it only
  if the function or lambda has a very narrow scope, because functions with
  deduced return types don't define abstraction boundaries: the implementation
  <em>is</em> the interface. In particular, public functions in header files
  should almost never have deduced return types.</p>

<h4>Parameter type deduction</h4>

<p><code>auto</code> parameter types for lambdas should be used with caution,
  because the actual type is determined by the code that calls the lambda,
  rather than by the definition of the lambda. Consequently, an explicit
  type will almost always be clearer unless the lambda is explicitly called
  very close to where it's defined (so that the reader can easily see both),
  or the lambda is passed to an interface so well-known that it's
  obvious what arguments it will eventually be called with (e.g.,
  the <code>std::sort</code> example above).</p>

<h4>Lambda init captures</h4>

<p>Init captures are covered by a <a href="#Lambda_expressions">more specific
    style rule</a>, which largely supersedes the general rules for
  type deduction.</p>

<h4>Structured bindings</h4>

<p>Unlike other forms of type deduction, structured bindings can actually
  give the reader additional information, by giving meaningful names to the
  elements of a larger object. This means that a structured binding declaration
  may provide a net readability improvement over an explicit type, even in cases
  where <code>auto</code> would not. Structured bindings are especially
  beneficial when the object is a pair or tuple (as in the <code>insert</code>
  example above), because they don't have meaningful field names to begin with,
  but note that you generally <a href="#Structs_vs._Tuples">shouldn't use
    pairs or tuples</a> unless a pre-existing API like <code>insert</code>
  forces you to.</p>

<p>If the object being bound is a struct, it may sometimes be helpful to
  provide names that are more specific to your usage, but keep in mind that
  this may also mean the names are less recognizable to your reader than the
  field names. We recommend using a comment to indicate the name of the
  underlying field, if it doesn't match the name of the binding, using the
  same syntax as for function parameter comments:</p>
  
