

<p>Dynamic initialization of static local variables is allowed (and common).</p>



<h4>Common patterns</h4>

<ul>
  <li>Global strings: if you require a named global or static string constant,
    consider using a <code>constexpr</code> variable of
    <code>string_view</code>, character array, or character pointer, pointing
    to a string literal. String literals have static storage duration already
    and are usually sufficient.
    See <a href="https://abseil.io/tips/140">TotW #140.</a></li>
  <li>Maps, sets, and other dynamic containers: if you require a static, fixed
    collection, such as a set to search against or a lookup table, you cannot
    use the dynamic containers from the standard library as a static variable,
    since they have non-trivial destructors. Instead, consider


    a simple array of trivial types, e.g., an array of arrays of ints (for a "map from int to
    int"), or an array of pairs (e.g., pairs of <code>int</code> and <code>const
    char*</code>). For small collections, linear search is entirely sufficient
    (and efficient, due to memory locality); consider using the facilities from
    <a href="https://github.com/abseil/abseil-cpp/blob/master/absl/algorithm/container.h">absl/algorithm/container.h</a>
    for the standard operations. If necessary, keep the collection in sorted
    order and use a binary search algorithm.

    If you do really prefer a dynamic container from the standard library, consider using
    a function-local static pointer, as described below
    .</li>
  <li>Smart pointers (<code>std::unique_ptr</code>, <code>std::shared_ptr</code>): smart
    pointers execute cleanup during destruction and are therefore forbidden.
    Consider whether your use case fits into one of the other patterns described
    in this section. One simple solution is to use a plain pointer to a
    dynamically allocated object and never delete it (see last item).</li>
  <li>Static variables of custom types: if you require static, constant data of
    a type that you need to define yourself, give the type a trivial destructor
    and a <code>constexpr</code> constructor.</li>
  <li>If all else fails, you can create an object dynamically and never delete
    it by using a function-local static pointer or reference (e.g.,
    <code>static const auto&amp; impl = *new T(args...);</code>).</li>
</ul>

<h3 id="thread_local">thread_local Variables</h3>

<p><code>thread_local</code> variables that aren't declared inside a function
must be initialized with a true compile-time constant,
and this must be enforced by using the
<a href="https://en.cppreference.com/w/cpp/language/constinit">
  <code>constinit</code></a>
attribute. Prefer
<code>thread_local</code> over other ways of defining thread-local data.</p>

<p class="definition"></p>
<p>Variables can be declared with the
<code>thread_local</code> specifier:</p>

