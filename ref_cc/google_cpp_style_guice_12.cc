
  </li>

  <li><p>Single-line nested namespace declarations

    are preferred in new code, but are not required.</p>
  </li>
</ul>

<a id="Unnamed_Namespaces_and_Static_Variables"></a>
<h3 id="Internal_Linkage">Internal Linkage</h3>

<p>When definitions in a <code>.cc</code> file do not need to be
referenced outside that file, give them internal linkage by placing
them in an unnamed namespace or declaring them <code>static</code>.
Do not use either of these constructs in <code>.h</code> files.

</p><p class="definition"></p>
<p>All declarations can be given internal linkage by placing them in unnamed
namespaces. Functions and variables can also be given internal linkage by
declaring them <code>static</code>. This means that anything you're declaring
can't be accessed from another file. If a different file declares something with
the same name, then the two entities are completely independent.</p>

<p class="decision"></p>

<p>Use of internal linkage in <code>.cc</code> files is encouraged
for all code that does not need to be referenced elsewhere.
Do not use internal linkage in <code>.h</code> files.</p>

<p>Format unnamed namespaces like named namespaces. In the
  terminating comment, leave the namespace name empty:</p>


