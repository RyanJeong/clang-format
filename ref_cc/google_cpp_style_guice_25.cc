
<p>Such a variable is actually a collection of objects, so that when different
threads access it, they are actually accessing different objects.
<code>thread_local</code> variables are much like
<a href="#Static_and_Global_Variables">static storage duration variables</a>
in many respects. For instance, they can be declared at namespace scope,
inside functions, or as static class members, but not as ordinary class
members.</p>

<p><code>thread_local</code> variable instances are initialized much like
static variables, except that they must be initialized separately for each
thread, rather than once at program startup. This means that
<code>thread_local</code> variables declared within a function are safe, but
other <code>thread_local</code> variables are subject to the same
initialization-order issues as static variables (and more besides).</p>

<p><code>thread_local</code> variables have a subtle destruction-order issue:
during thread shutdown, <code>thread_local</code> variables will be destroyed
in the opposite order of their initialization (as is generally true in C++).
If code triggered by the destructor of any <code>thread_local</code> variable
refers to any already-destroyed <code>thread_local</code> on that thread, we will
get a particularly hard to diagnose use-after-free.</p>

<p class="pros"></p>
<ul>
  <li>Thread-local data is inherently safe from races (because only one thread
    can ordinarily access it), which makes <code>thread_local</code> useful for
    concurrent programming.</li>
  <li><code>thread_local</code> is the only standard-supported way of creating
    thread-local data.</li>
</ul>

<p class="cons"></p>
<ul>
  <li>Accessing a <code>thread_local</code> variable may trigger execution of
    an unpredictable and uncontrollable amount of other code during thread-start or
    first use on a given thread.</li>
  <li><code>thread_local</code> variables are effectively global variables,
    and have all the drawbacks of global variables other than lack of
    thread-safety.</li>
  <li>The memory consumed by a <code>thread_local</code> variable scales with
    the number of running threads (in the worst case), which can be quite large
    in a  program.</li>
  <li>Data members cannot be <code>thread_local</code> unless they are also
    <code>static</code>.</li>
  <li>We may suffer from use-after-free bugs if <code>thread_local</code> variables
    have complex destructors. In particular, the destructor of any such variable must not
    call any code (transitively) that refers to any potentially-destroyed
    <code>thread_local</code>. This property is hard to enforce.</li>

  <li>Approaches for avoiding use-after-free in global/static contexts do not work for
    <code>thread_local</code>s. Specifically, skipping destructors for globals and static
    variables is allowable because their lifetimes end at program shutdown. Thus, any "leak"
    is managed immediately by the OS cleaning up our memory and other resources. By
    contrast, skipping destructors for <code>thread_local</code> variables leads to resource
    leaks proportional to the total number of threads that terminate during the lifetime of
    the program.</li>

</ul>

<p class="decision"></p>
  <p><code>thread_local</code> variables at class or namespace scope must be
  initialized with a true compile-time constant (i.e., they must have no
  dynamic initialization). To enforce this, <code>thread_local</code> variables
  at class or namespace scope must be annotated with
  <a href="https://en.cppreference.com/w/cpp/language/constinit">
    <code>constinit</code></a>
  (or <code>constexpr</code>, but that should be rare):</p>

  
