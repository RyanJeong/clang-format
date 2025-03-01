

<p>Be careful when using a braced initialization list <code>{...}</code>
on a type with an <code>std::initializer_list</code> constructor.
A nonempty <i>braced-init-list</i> prefers the
<code>std::initializer_list</code> constructor whenever
possible. Note that empty braces <code>{}</code> are special, and
will call a default constructor if available. To force the
non-<code>std::initializer_list</code> constructor, use parentheses
instead of braces.</p>


