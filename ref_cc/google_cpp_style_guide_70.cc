

<p>(The same naming rule applies to class- and namespace-scope
constants that are exposed as part of an API and that are intended to look
like functions, because the fact that they're objects rather than functions
is an unimportant implementation detail.)</p>

<p>Accessors and mutators (get and set functions) may be named like
variables. These often correspond to actual member variables, but this is
not required. For example, <code>int count()</code> and <code>void
set_count(int count)</code>.</p>

<h3 id="Namespace_Names">Namespace Names</h3>

<p>Namespace names are all lower-case, with words separated by underscores.
Top-level namespace names are based on the project name
. Avoid collisions
between nested namespaces and well-known top-level namespaces.</p>

<p>The name of a top-level namespace should usually be the
name of the project or team whose code is contained in that
namespace. The code in that namespace should usually be in
a directory whose basename matches the namespace name (or in
subdirectories thereof).</p>



<p>Keep in mind that the <a href="#General_Naming_Rules">rule
against abbreviated names</a> applies to namespaces just as much
as variable names. Code inside the namespace seldom needs to
mention the namespace name, so there's usually no particular need
for abbreviation anyway.</p>

<p>Avoid nested namespaces that match well-known top-level
namespaces. Collisions between namespace names can lead to surprising
build breaks because of name lookup rules. In particular, do not
create any nested <code>std</code> namespaces. Prefer unique project
identifiers
(<code>websearch::index</code>, <code>websearch::index_util</code>)
over collision-prone names like <code>websearch::util</code>. Also avoid overly deep nesting
  namespaces (<a href="https://abseil.io/tips/130">TotW #130</a>).</p>

<p>For <code>internal</code> namespaces, be wary of other code being
added to the same <code>internal</code> namespace causing a collision
(internal helpers within a team tend to be related and may lead to
collisions). In such a situation, using the filename to make a unique
internal name is helpful
(<code>websearch::index::frobber_internal</code> for use
in <code>frobber.h</code>).</p>

<h3 id="Enumerator_Names">Enumerator Names</h3>

<p>Enumerators (for both scoped and unscoped enums) should be named like
<a href="#Constant_Names">constants</a>, not like
<a href="#Macro_Names">macros</a>. That is, use <code>kEnumName</code> not
<code>ENUM_NAME</code>.</p>




