
  </li>

  <li>To place generated protocol
  message code in a namespace, use the
  <code>package</code> specifier in the
  <code>.proto</code> file. See


  <a href="https://developers.google.com/protocol-buffers/docs/reference/cpp-generated#package">
  Protocol Buffer Packages</a>
  for details.</li>

  <li>Do not declare anything in namespace
  <code>std</code>, including forward declarations of
  standard library classes. Declaring entities in
  namespace <code>std</code> is undefined behavior, i.e.,
  not portable. To declare entities from the standard
  library, include the appropriate header file.</li>

  <li><p>You may not use a <i>using-directive</i>
  to make all names from a namespace available.</p>

<pre class="badcode">// Forbidden -- This pollutes the namespace.
using namespace foo;

