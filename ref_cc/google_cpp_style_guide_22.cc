

<p>All but the first statement expose us to indeterminate initialization
ordering.</p>

<p>The concept we are looking for is called <em>constant initialization</em> in
the formal language of the C++ standard. It means that the initializing
expression is a constant expression, and if the object is initialized by a
constructor call, then the constructor must be specified as
<code>constexpr</code>, too:</p>
<pre class="goodcode">struct Foo { constexpr Foo(int) {} };

int n = 5;  // Fine, 5 is a constant expression.
Foo x(2);   // Fine, 2 is a constant expression and the chosen constructor is constexpr.
Foo a[] = { Foo(1), Foo(2), Foo(3) };  // Fine
