

<p>Code such as this usually breaks when additional
subclasses are added to the class hierarchy. Moreover,
when properties of a subclass change, it is difficult to
find and modify all the affected code segments.</p>

<p>Do not hand-implement an RTTI-like workaround. The
arguments against RTTI apply just as much to workarounds
like class hierarchies with type tags. Moreover,
workarounds disguise your true intent.</p>

<h3 id="Casting">Casting</h3>

<p>Use C++-style casts
like <code>static_cast<float>(double_value)</code>, or brace
initialization for conversion of arithmetic types like
<code>int64_t y = int64_t{1} << 42</code>. Do not use
cast formats like <code>(int)x</code> unless the cast is to
<code>void</code>. You may use cast formats like <code>T(x)</code> only when
<code>T</code> is a class type.</p>

<p class="definition"></p>
<p> C++ introduced a
different cast system from C that distinguishes the types
of cast operations.</p>

<p class="pros"></p>
<p>The problem with C casts is the ambiguity of the operation;
sometimes you are doing a <em>conversion</em>
(e.g., <code>(int)3.5</code>) and sometimes you are doing
a <em>cast</em> (e.g., <code>(int)"hello"</code>). Brace
initialization and C++ casts can often help avoid this
ambiguity. Additionally, C++ casts are more visible when searching for
them.</p>

<p class="cons"></p>
<p>The C++-style cast syntax is verbose and cumbersome.</p>

<p class="decision"></p>
<p>In general, do not use C-style casts. Instead, use these C++-style
casts when explicit type conversion is necessary.
</p>

<ul>
  <li>Use brace initialization to convert arithmetic types
  (e.g., <code>int64_t{x}</code>).  This is the safest approach because code
  will not compile if conversion can result in information loss.  The
  syntax is also concise.</li>

  <li>Use <code>absl::implicit_cast</code>
  to safely cast up a type hierarchy,
  e.g., casting a <code>Foo*</code> to a
  <code>SuperclassOfFoo*</code> or casting a
  <code>Foo*</code> to a <code>const Foo*</code>. C++
  usually does this automatically but some situations
  need an explicit up-cast, such as use of the
  <code>?:</code> operator.</li>

  <li>Use <code>static_cast</code> as the equivalent of a C-style cast
  that does value conversion, when you need to
  explicitly up-cast a pointer from a class to its superclass, or when
  you need to explicitly cast a pointer from a superclass to a
  subclass.  In this last case, you must be sure your object is
  actually an instance of the subclass.</li>



  <li>Use <code>const_cast</code> to remove the
  <code>const</code> qualifier (see <a href="#Use_of_const">const</a>).</li>

  <li>Use <code>reinterpret_cast</code> to do unsafe conversions of
  pointer types to and from integer and other pointer
  types,
  including <code>void*</code>. Use this
  only if you know what you are doing and you understand the aliasing
  issues. Also, consider dereferencing the pointer (without a cast) and
  using <code>std::bit_cast</code> to cast the resulting value.</li>

  <li>Use <code>std::bit_cast</code> to interpret the raw bits of a
  value using a different type of the same size (a type pun), such as
  interpreting the bits of a <code>double</code> as
  <code>int64_t</code>.</li>
</ul>

<p>See the <a href="#Run-Time_Type_Information__RTTI_">
RTTI section</a> for guidance on the use of
<code>dynamic_cast</code>.</p>

<h3 id="Streams">Streams</h3>

<p>Use streams where appropriate, and stick to "simple"
usages. Overload <code><<</code> for streaming only for types
representing values, and write only the user-visible value, not any
implementation details.</p>

<p class="definition"></p>
<p>Streams are the standard I/O abstraction in C++, as
exemplified by the standard header <code><iostream></code>.
They are widely used in Google code, mostly for debug logging
and test diagnostics.</p>

<p class="pros"></p>
<p>The <code><<</code> and <code>>></code>
stream operators provide an API for formatted I/O that
is easily learned, portable, reusable, and extensible.
<code>printf</code>, by contrast, doesn't even support
<code>std::string</code>, to say nothing of user-defined types,
and is very difficult to use portably.
<code>printf</code> also obliges you to choose among the
numerous slightly different versions of that function,
and navigate the dozens of conversion specifiers.</p>

<p>Streams provide first-class support for console I/O
via <code>std::cin</code>, <code>std::cout</code>,
<code>std::cerr</code>, and <code>std::clog</code>.
The C APIs do as well, but are hampered by the need to
manually buffer the input. </p>

<p class="cons"></p>
<ul>
<li>Stream formatting can be configured by mutating the
state of the stream. Such mutations are persistent, so
the behavior of your code can be affected by the entire
previous history of the stream, unless you go out of your
way to restore it to a known state every time other code
might have touched it. User code can not only modify the
built-in state, it can add new state variables and behaviors
through a registration system.</li>

<li>It is difficult to precisely control stream output, due
to the above issues, the way code and data are mixed in
streaming code, and the use of operator overloading (which
may select a different overload than you expect).</li>

<li>The practice of building up output through chains
of <code><<</code> operators interferes with
internationalization, because it bakes word order into the
code, and streams' support for localization is <a href="http://www.boost.org/doc/libs/1_48_0/libs/locale/doc/html/rationale.html#rationale_why">
flawed</a>.</li>





<li>The streams API is subtle and complex, so programmers must
develop experience with it in order to use it effectively.</li>

<li>Resolving the many overloads of <code><<</code> is
extremely costly for the compiler. When used pervasively in a
large code base, it can consume as much as 20% of the parsing
and semantic analysis time.</li>
</ul>

<p class="decision"></p>
<p>Use streams only when they are the best tool for the job.
This is typically the case when the I/O is ad-hoc, local,
human-readable, and targeted at other developers rather than
end-users. Be consistent with the code around you, and with the
codebase as a whole; if there's an established tool for
your problem, use that tool instead.
In particular,

logging libraries are usually a better
choice than <code>std::cerr</code> or <code>std::clog</code>
for diagnostic output, and the libraries in

<code>absl/strings</code>
or the equivalent are usually a
better choice than <code>std::stringstream</code>.</p>

<p>Avoid using streams for I/O that faces external users or
handles untrusted data. Instead, find and use the appropriate
templating libraries to handle issues like internationalization,
localization, and security hardening.</p>

<p>If you do use streams, avoid the stateful parts of the
streams API (other than error state), such as <code>imbue()</code>,
<code>xalloc()</code>, and <code>register_callback()</code>.
Use explicit formatting functions (such as
<code>absl::StreamFormat()</code>) rather than
stream manipulators or formatting flags to control formatting
details such as number base, precision, or padding.</p>

<p>Overload <code><<</code> as a streaming operator
for your type only if your type represents a value, and
<code><<</code> writes out a human-readable string
representation of that value. Avoid exposing implementation
details in the output of <code><<</code>; if you need to print
object internals for debugging, use named functions instead
(a method named <code>DebugString()</code> is the most common
convention).</p>

<h3 id="Preincrement_and_Predecrement">Preincrement and Predecrement</h3>

<p>Use the prefix form (<code>++i</code>) of the increment
and decrement operators unless you need postfix semantics.</p>

<p class="definition"></p>
<p> When a variable
is incremented (<code>++i</code> or <code>i++</code>) or
decremented (<code>--i</code> or <code>i--</code>) and
the value of the expression is not used, one must decide
whether to preincrement (decrement) or postincrement
(decrement).</p>

<p class="pros"></p>

<p>A postfix increment/decrement expression evaluates to the value
<i>as it was before it was modified</i>. This can result in code that is more
compact but harder to read. The prefix form is generally more readable, is
never less efficient, and can be more efficient because it doesn't need to
make a copy of the value as it was before the operation.
</p>

<p class="cons"></p>
<p>The tradition developed, in C, of using post-increment, even
when the expression value is not used, especially in
<code>for</code> loops.</p>

<p class="decision"></p>
<p>Use prefix increment/decrement, unless the code explicitly
needs the result of the postfix increment/decrement expression.</p>

<h3 id="Use_of_const">Use of const</h3>

<p>In APIs, use <code>const</code> whenever it makes sense.
<code>constexpr</code> is a better choice for some uses of
const.</p>

<p class="definition"></p>
<p> Declared variables and parameters can be preceded
by the keyword <code>const</code> to indicate the variables
are not changed (e.g., <code>const int foo</code>). Class
functions can have the <code>const</code> qualifier to
indicate the function does not change the state of the
class member variables (e.g., <code>class Foo { int
Bar(char c) const; };</code>).</p>

<p class="pros"></p>
<p>Easier for people to understand how variables are being
used. Allows the compiler to do better type checking,
and, conceivably, generate better code. Helps people
convince themselves of program correctness because they
know the functions they call are limited in how they can
modify your variables. Helps people know what functions
are safe to use without locks in multi-threaded
programs.</p>

<p class="cons"></p>
<p><code>const</code> is viral: if you pass a
<code>const</code> variable to a function, that function
must have <code>const</code> in its prototype (or the
variable will need a <code>const_cast</code>). This can
be a particular problem when calling library
functions.</p>

<p class="decision"></p>
<p>We strongly recommend using <code>const</code>
in APIs (i.e., on function parameters, methods, and
non-local variables) wherever it is meaningful and accurate. This
provides consistent, mostly compiler-verified documentation
of what objects an operation can mutate. Having
a consistent and reliable way to distinguish reads from writes
is critical to writing thread-safe code, and is useful in
many other contexts as well. In particular:</p>

<ul>
  <li>If a function guarantees that it will not modify an argument
  passed by reference or by pointer, the corresponding function parameter
  should be a reference-to-const (<code>const T&</code>) or
  pointer-to-const (<code>const T*</code>), respectively.</li>

  <li>For a function parameter passed by value, <code>const</code> has
  no effect on the caller, thus is not recommended in function
  declarations. See


  <a href="https://abseil.io/tips/109">TotW #109</a>.


  </li><li>Declare methods to be <code>const</code> unless they
  alter the logical state of the object (or enable the user to modify
  that state, e.g., by returning a non-<code>const</code> reference, but that's
  rare), or they can't safely be invoked concurrently.</li>
</ul>

<p>Using <code>const</code> on local variables is neither encouraged
nor discouraged.</p>

<p>All of a class's <code>const</code> operations should be safe
to invoke concurrently with each other. If that's not feasible, the class must
be clearly documented as "thread-unsafe".</p>


<h4>Where to put the const</h4>

<p>Some people favor the form <code>int const *foo</code>
to <code>const int* foo</code>. They argue that this is
more readable because it's more consistent: it keeps the
rule that <code>const</code> always follows the object
it's describing. However, this consistency argument
doesn't apply in codebases with few deeply-nested pointer
expressions since most <code>const</code> expressions
have only one <code>const</code>, and it applies to the
underlying value. In such cases, there's no consistency
to maintain. Putting the <code>const</code> first is
arguably more readable, since it follows English in
putting the "adjective" (<code>const</code>) before the
"noun" (<code>int</code>).</p>

<p>That said, while we encourage putting
<code>const</code> first, we do not require it. But be
consistent with the code around you!</p>

<h3 id="Use_of_constexpr">Use of constexpr, constinit, and consteval</h3>

<p>Use <code>constexpr</code> to define true
constants or to ensure constant initialization.
Use <code>constinit</code> to ensure constant
initialization for non-constant variables.
</p>

<p class="definition"></p>
<p> Some variables can be declared <code>constexpr</code>
to indicate the variables are true constants, i.e., fixed at
compilation/link time. Some functions and constructors
can be declared <code>constexpr</code> which enables them
to be used in defining a <code>constexpr</code>
variable. Functions can be declared <code>consteval</code>
to restrict their use to compile time.</p>

<p class="pros"></p>
<p>Use of <code>constexpr</code> enables definition of
constants with floating-point expressions rather than
just literals; definition of constants of user-defined
types; and definition of constants with function
calls.</p>

<p class="cons"></p>
<p>Prematurely marking something as <code>constexpr</code> may cause
migration problems if later on it has to be downgraded.
Current restrictions on what is allowed in <code>constexpr</code>
functions and constructors may invite obscure workarounds
in these definitions.</p>

<p class="decision"></p>
<p><code>constexpr</code> definitions enable a more
robust specification of the constant parts of an
interface. Use <code>constexpr</code> to specify true
constants and the functions that support their
definitions. <code>consteval</code> may be used for
code that must not be invoked at runtime.
Avoid complexifying function definitions to
enable their use with <code>constexpr</code>. Do not use
<code>constexpr</code> or <code>consteval</code> to force inlining.</p>

<h3 id="Integer_Types">Integer Types</h3>

<p>Of the built-in C++ integer types, the only one used
 is
<code>int</code>. If a program needs an integer type of a
different size, use an exact-width integer type from
<code><cstdint></code>, such as
<code>int16_t</code>. If you have a
value that could ever be greater than or equal to 2^31,
use a 64-bit type such as <code>int64_t</code>.
Keep in mind that even if your value won't ever be too large
for an <code>int</code>, it may be used in intermediate
calculations which may require a larger type. When in doubt,
choose a larger type.</p>

<p class="definition"></p>
<p>C++ does not specify exact sizes for the integer types
like <code>int</code>. Common sizes on contemporary architectures are
16 bits for <code>short</code>, 32 bits for <code>int</code>, 32 or 64
bits for <code>long</code>, and 64 bits for <code>long long</code>,
but different platforms make different choices, in particular
for <code>long</code>.</p>

<p class="pros"></p>
<p>Uniformity of declaration.</p>

<p class="cons"></p>
<p>The sizes of integral types in C++ can vary based on
compiler and architecture.</p>

<p class="decision"></p>

<p>
The standard library header <code><cstdint></code> defines types
like <code>int16_t</code>, <code>uint32_t</code>,
<code>int64_t</code>, etc. You should always use
those in preference to <code>short</code>, <code>unsigned
long long</code> and the like, when you need a guarantee
on the size of an integer. Prefer to omit the <code>std::</code>
prefix for these types, as the extra 5 characters do
not merit the added clutter. Of the built-in integer types, only
<code>int</code> should be used. When appropriate, you
are welcome to use standard type aliases like
<code>size_t</code> and <code>ptrdiff_t</code>.</p>

<p>We use <code>int</code> very often, for integers we
know are not going to be too big, e.g., loop counters.
Use plain old <code>int</code> for such things. You
should assume that an <code>int</code> is

at least 32 bits, but don't
assume that it has more than 32 bits. If you need a 64-bit
integer type, use <code>int64_t</code> or <code>uint64_t</code>.

</p><p>For integers we know can be "big",
 use
<code>int64_t</code>.
</p>

<p>You should not use the unsigned integer types such as
<code>uint32_t</code>, unless there is a valid
reason such as representing a bit pattern rather than a
number, or you need defined overflow modulo 2^N. In
particular, do not use unsigned types to say a number
will never be negative. Instead, use

assertions for this.</p>



<p>If your code is a container that returns a size, be
sure to use a type that will accommodate any possible
usage of your container. When in doubt, use a larger type
rather than a smaller type.</p>

<p>Use care when converting integer types. Integer conversions and
promotions can cause undefined behavior, leading to security bugs and
other problems.</p>

<h4>On Unsigned Integers</h4>

<p>Unsigned integers are good for representing bitfields and modular
arithmetic. Because of historical accident, the C++ standard also uses
unsigned integers to represent the size of containers - many members
of the standards body believe this to be a mistake, but it is
effectively impossible to fix at this point. The fact that unsigned
arithmetic doesn't model the behavior of a simple integer, but is
instead defined by the standard to model modular arithmetic (wrapping
around on overflow/underflow), means that a significant class of bugs
cannot be diagnosed by the compiler. In other cases, the defined
behavior impedes optimization.</p>

<p>That said, mixing signedness of integer types is responsible for an
equally large class of problems. The best advice we can provide: try
to use iterators and containers rather than pointers and sizes, try
not to mix signedness, and try to avoid unsigned types (except for
representing bitfields or modular arithmetic). Do not use an unsigned
type merely to assert that a variable is non-negative.</p>

<h3 id="Floating-Point_Types">Floating-Point Types</h3>

<p>Of the built-in C++ floating-point types, the only ones used
 are <code>float</code> and
<code>double</code>. You may assume that these types represent IEEE-754 binary32
and binary64, respectively.</p>

<p>Do not use <code>long double</code>, as it gives non-portable
results.</p>

<a id="64-bit_Portability"></a>
<h3 id="Architecture_Portability">Architecture Portability</h3>

<p>Write architecture-portable code. Do not rely on CPU features specific to a
single processor.</p>

<ul>
  <li>When printing values, use type-safe numeric formatting libraries like
  <a href="https://github.com/abseil/abseil-cpp/blob/master/absl/strings/str_cat.h"><code>absl::StrCat</code></a>,
  <a href="https://github.com/abseil/abseil-cpp/blob/master/absl/strings/substitute.h"><code>absl::Substitute</code></a>,
  <a href="https://github.com/abseil/abseil-cpp/blob/master/absl/strings/str_format.h"><code>absl::StrFormat</code></a>,
  or <a href="#Streams"><code>std::ostream</code></a> instead of the
  <code>printf</code> family of functions.</li>

  <li>When moving structured data into or out of your process, encode it using a
  serialization library like
  <a href="https://protobuf.dev/">Protocol
  Buffers</a> rather than copying the in-memory representation around.
  </li>

  <li>If you need to work with memory addresses as integers, store them in
  <code>uintptr_t</code>s rather than <code>uint32_t</code>s or
  <code>uint64_t</code>s.</li>

  <li>
  Use <a href="#Casting">braced-initialization</a> as needed to create
  64-bit constants. For example:

