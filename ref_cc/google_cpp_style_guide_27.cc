

  <p>Note that <code>thread_local</code> variables will be destroyed whenever a thread exits.
    If the destructor of any such variable refers to any other (potentially-destroyed)
    <code>thread_local</code> we will suffer from hard to diagnose use-after-free bugs.
    Prefer trivial types, or types that provably run no user-provided code at destruction to
    minimize the potential of accessing any other <code>thread_local</code>.
  </p>

<p><code>thread_local</code> should be preferred over other mechanisms for
defining thread-local data.</p>

<h2 id="Classes">Classes</h2>

<p>Classes are the fundamental unit of code in C++. Naturally,
we use them extensively. This section lists the main dos and
don'ts you should follow when writing a class.</p>

<h3 id="Doing_Work_in_Constructors">Doing Work in Constructors</h3>

<p>Avoid virtual method calls in constructors, and avoid
initialization that can fail if you can't signal an error.</p>

<p class="definition"></p>
<p>It is possible to perform arbitrary initialization in the body
of the constructor.</p>

<p class="pros"></p>
<ul>
  <li>No need to worry about whether the class has been initialized or
  not.</li>

  <li>Objects that are fully initialized by constructor call can
  be <code>const</code> and may also be easier to use with standard containers
  or algorithms.</li>
</ul>

<p class="cons"></p>
<ul>
  <li>If the work calls virtual functions, these calls
  will not get dispatched to the subclass
  implementations. Future modification to your class can
  quietly introduce this problem even if your class is
  not currently subclassed, causing much confusion.</li>

  <li>There is no easy way for constructors to signal errors, short of
  crashing the program (not always appropriate) or using exceptions
  (which are <a href="#Exceptions">forbidden</a>).</li>

  <li>If the work fails, we now have an object whose initialization
  code failed, so it may be an unusual state requiring a <code>bool
  IsValid()</code> state checking mechanism (or similar) which is easy
  to forget to call.</li>

  <li>You cannot take the address of a constructor, so whatever work
  is done in the constructor cannot easily be handed off to, for
  example, another thread.</li>
</ul>

<p class="decision"></p>
<p>Constructors should never call virtual functions. If appropriate
for your code ,
terminating the program may be an appropriate error handling
response. Otherwise, consider a factory function
or <code>Init()</code> method as described in
<a href="https://abseil.io/tips/42">TotW #42</a>.
Avoid <code>Init()</code> methods on objects with
no other states that affect which public methods may be called
(semi-constructed objects of this form are particularly hard to work
with correctly).</p>

<a id="Explicit_Constructors"></a>
<h3 id="Implicit_Conversions">Implicit Conversions</h3>

<p>Do not define implicit conversions. Use the <code>explicit</code>
keyword for conversion operators and single-argument
constructors.</p>

<p class="definition"></p>
<p>Implicit conversions allow an
object of one type (called the <dfn>source type</dfn>) to
be used where a different type (called the <dfn>destination
type</dfn>) is expected, such as when passing an
<code>int</code> argument to a function that takes a
<code>double</code> parameter.</p>

<p>In addition to the implicit conversions defined by the language,
users can define their own, by adding appropriate members to the
class definition of the source or destination type. An implicit
conversion in the source type is defined by a type conversion operator
named after the destination type (e.g., <code>operator
bool()</code>). An implicit conversion in the destination
type is defined by a constructor that can take the source type as
its only argument (or only argument with no default value).</p>

<p>The <code>explicit</code> keyword can be applied to a constructor
or a conversion operator, to ensure that it can only be
used when the destination type is explicit at the point of use,
e.g., with a cast. This applies not only to implicit conversions, but to
list initialization syntax:</p>

