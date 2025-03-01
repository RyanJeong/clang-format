

<h3 id="Nonmember,_Static_Member,_and_Global_Functions">Nonmember, Static Member, and Global Functions</h3>

<p>Prefer placing nonmember functions in a namespace; use completely global
functions rarely. Do not use a class simply to group static members. Static
methods of a class should generally be closely related to instances of the
class or the class's static data.</p>


<p class="pros"></p>
<p>Nonmember and static member functions can be useful in
some situations. Putting nonmember functions in a
namespace avoids polluting the global namespace.</p>

<p class="cons"></p>
<p>Nonmember and static member functions may make more sense
as members of a new class, especially if they access
external resources or have significant dependencies.</p>

<p class="decision"></p>
<p>Sometimes it is useful to define a
function not bound to a class instance. Such a function
can be either a static member or a nonmember function.
Nonmember functions should not depend on external
variables, and should nearly always exist in a namespace.
Do not create classes only to group static members;
this is no different than just giving the names a
common prefix, and such grouping is usually unnecessary anyway.</p>

<p>If you define a nonmember function and it is only
needed in its <code>.cc</code> file, use
<a href="#Internal_Linkage">internal linkage</a> to limit
its scope.</p>

<h3 id="Local_Variables">Local Variables</h3>

<p>Place a function's variables in the narrowest scope
possible, and initialize variables in the declaration.</p>

<p>C++ allows you to declare variables anywhere in a function.
We encourage you to declare them in a scope as local as
possible, and as close to the first use as possible.
This makes it easier for the reader to find the
declaration and see what type the variable is and what it
was initialized to. In particular, initialization should
be used instead of declaration and assignment, e.g.,:</p>

<pre class="badcode">int i;
i = f();      // Bad -- initialization separate from declaration.

