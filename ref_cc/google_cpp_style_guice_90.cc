

<h3 id="Floating_Literals">Floating-point Literals</h3>

<p>Floating-point literals should always have a radix point, with digits on both
sides, even if they use exponential notation. Readability is improved if all
floating-point literals take this familiar form, as this helps ensure that they
are not mistaken for integer literals, and that the
<code>E</code>/<code>e</code> of the exponential notation is not mistaken for a
hexadecimal digit. It is fine to initialize a floating-point variable with an
integer literal (assuming the variable type can exactly represent that integer),
but note that a number in exponential notation is never an integer literal.
</p>

<pre class="badcode">float f = 1.f;
long double ld = -.5L;
double d = 1248e6;

