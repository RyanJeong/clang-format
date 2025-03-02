
    The <code>auto</code> can also be qualified with <code>const</code>,
    <code>&</code>, and <code>&&</code>, but note that these qualifiers
    technically apply to the anonymous tuple/struct/array, rather than the
    individual bindings. The rules that determine the types of the bindings
    are quite complex; the results tend to be unsurprising, except that
    the binding types typically won't be references even if the declaration
    declares a reference (but they will usually behave like references anyway).
  </dd>
</dl>

<p>(These summaries omit many details and caveats; see the links for further
  information.)</p>

<p class="pros"></p>

<ul>
  <li>C++ type names can be long and cumbersome, especially when they
    involve templates or namespaces.</li>
  <li>When a C++ type name is repeated within a single declaration or a
    small code region, the repetition may not be aiding readability.</li>
  <li>It is sometimes safer to let the type be deduced, since that avoids
    the possibility of unintended copies or type conversions.</li>
</ul>

<p class="cons"></p>
<p>C++ code is usually clearer when types are explicit,
  especially when type deduction would depend on information from
  distant parts of the code. In expressions like:</p>

<pre class="badcode">auto foo = x.add_foo();
auto i = y.Find(key);

