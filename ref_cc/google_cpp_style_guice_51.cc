const std::vector&lt;int&gt; lookup_table = ...;
std::vector&lt;int&gt; indices = ...;
// Captures `lookup_table` by reference, sorts `indices` by the value
// of the associated element in `lookup_table`.
std::sort(indices.begin(), indices.end(), [&amp;](int a, int b) {
  return lookup_table[a] &lt; lookup_table[b];
});

