

<p>The expressions <code>outer::inner::foo()</code> and
<code>outer::foo()</code> are interchangeable. Inline
namespaces are primarily intended for ABI compatibility
across versions.</p>

<p class="cons"></p>

<p>Namespaces can be confusing, because they complicate
the mechanics of figuring out what definition a name refers
to.</p>

<p>Inline namespaces, in particular, can be confusing
because names aren't actually restricted to the namespace
where they are declared. They are only useful as part of
some larger versioning policy.</p>

<p>In some contexts, it's necessary to repeatedly refer to
symbols by their fully-qualified names. For deeply-nested
namespaces, this can add a lot of clutter.</p>

<p class="decision"></p>

<p>Namespaces should be used as follows:</p>

<ul>
  <li>Follow the rules on <a href="#Namespace_Names">Namespace Names</a>.
  </li><li>Terminate multi-line namespaces with comments as shown in the given examples.
  </li><li>

  <p>Namespaces wrap the entire source file after
  includes,
  <a href="https://gflags.github.io/gflags/">
  gflags</a> definitions/declarations
  and forward declarations of classes from other namespaces.</p>


