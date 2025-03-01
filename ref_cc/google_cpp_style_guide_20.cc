

<h3 id="Static_and_Global_Variables">Static and Global Variables</h3>

<p>Objects with
<a href="http://en.cppreference.com/w/cpp/language/storage_duration#Storage_duration">
static storage duration</a> are forbidden unless they are
<a href="http://en.cppreference.com/w/cpp/types/is_destructible">trivially
destructible</a>. Informally this means that the destructor does not do
anything, even taking member and base destructors into account. More formally it
means that the type has no user-defined or virtual destructor and that all bases
and non-static members are trivially destructible.
Static function-local variables may use dynamic initialization.
Use of dynamic initialization for static class member variables or variables at
namespace scope is discouraged, but allowed in limited circumstances; see below
for details.</p>

<p>As a rule of thumb: a global variable satisfies these requirements if its
declaration, considered in isolation, could be <code>constexpr</code>.</p>

<p class="definition"></p>
<p>Every object has a <dfn>storage duration</dfn>, which correlates with its
lifetime. Objects with static storage duration live from the point of their
initialization until the end of the program. Such objects appear as variables at
namespace scope ("global variables"), as static data members of classes, or as
function-local variables that are declared with the <code>static</code>
specifier. Function-local static variables are initialized when control first
passes through their declaration; all other objects with static storage duration
are initialized as part of program start-up. All objects with static storage
duration are destroyed at program exit (which happens before unjoined threads
are terminated).</p>

<p>Initialization may be <dfn>dynamic</dfn>, which means that something
non-trivial happens during initialization. (For example, consider a constructor
that allocates memory, or a variable that is initialized with the current
process ID.) The other kind of initialization is <dfn>static</dfn>
initialization. The two aren't quite opposites, though: static
initialization <em>always</em> happens to objects with static storage duration
(initializing the object either to a given constant or to a representation
consisting of all bytes set to zero), whereas dynamic initialization happens
after that, if required.</p>

<p class="pros"></p>
<p>Global and static variables are very useful for a large number of
applications: named constants, auxiliary data structures internal to some
translation unit, command-line flags, logging, registration mechanisms,
background infrastructure, etc.</p>

<p class="cons"></p>
<p>Global and static variables that use dynamic initialization or have
non-trivial destructors create complexity that can easily lead to hard-to-find
bugs. Dynamic initialization is not ordered across translation units, and
neither is destruction (except that destruction
happens in reverse order of initialization). When one initialization refers to
another variable with static storage duration, it is possible that this causes
an object to be accessed before its lifetime has begun (or after its lifetime
has ended). Moreover, when a program starts threads that are not joined at exit,
those threads may attempt to access objects after their lifetime has ended if
their destructor has already run.</p>

<p class="decision"></p>
<h4>Decision on destruction</h4>

<p>When destructors are trivial, their execution is not subject to ordering at
all (they are effectively not "run"); otherwise we are exposed to the risk of
accessing objects after the end of their lifetime. Therefore, we only allow
objects with static storage duration if they are trivially destructible.
Fundamental types (like pointers and <code>int</code>) are trivially
destructible, as are arrays of trivially destructible types. Note that
variables marked with <code>constexpr</code> are trivially destructible.</p>

