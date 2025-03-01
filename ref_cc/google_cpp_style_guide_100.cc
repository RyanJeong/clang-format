

<p>This exception does not apply to multi-keyword statements like
<code>if ... else</code> or <code>do ... while</code>.</p>

<pre class="badcode">// Bad - `if ... else` statement is missing braces.
if (x) DoThis();
else DoThat();

// Bad - `do ... while` statement is missing braces.
do DoThis();
while (x);

