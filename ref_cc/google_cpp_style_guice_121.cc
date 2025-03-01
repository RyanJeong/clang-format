

<h3 id="Vertical_Whitespace">Vertical Whitespace</h3>

<p>Minimize use of vertical whitespace.</p>

<p>This is more a principle than a rule: don't use blank lines when
you don't have to. In particular, don't put more than one or two blank
lines between functions, resist starting functions with a blank line,
don't end functions with a blank line, and be sparing with your use of
blank lines. A blank line within a block of code serves like a
paragraph break in prose: visually separating two thoughts.</p>

<p>The basic principle is: The more code that fits on one screen, the
easier it is to follow and understand the control flow of the
program. Use whitespace purposefully to provide separation in that
flow.</p>

<p>Some rules of thumb to help when blank lines may be
useful:</p>

<ul>
  <li>Blank lines at the beginning or end of a function
  do not help readability.</li>

  <li>Blank lines inside a chain of if-else blocks may
  well help readability.</li>

  <li>A blank line before a comment line usually helps
  readability — the introduction of a new comment suggests
  the start of a new thought, and the blank line makes it clear
  that the comment goes with the following thing instead of the
  preceding.</li>

  <li>Blank lines immediately inside a declaration of a namespace or block of
  namespaces may help readability by visually separating the load-bearing
  content from the (largely non-semantic) organizational wrapper. Especially
  when the first declaration inside the namespace(s) is preceded by a comment,
  this becomes a special case of the previous rule, helping the comment to
  "attach" to the subsequent declaration.</li>
</ul>

<h2 id="Exceptions_to_the_Rules">Exceptions to the Rules</h2>

<p>The coding conventions described above are mandatory.
However, like all good rules, these sometimes have exceptions,
which we discuss here.</p>



<div>
<h3 id="Existing_Non-conformant_Code" class="no-toc">Existing Non-conformant Code</h3>

<p>You may diverge from the rules when dealing with code that
does not conform to this style guide.</p>

<p>If you find yourself modifying code that was written
to specifications other than those presented by this
guide, you may have to diverge from these rules in order
to stay consistent with the local conventions in that
code. If you are in doubt about how to do this, ask the
original author or the person currently responsible for
the code. Remember that <em>consistency</em> includes
local consistency, too.</p>

</div>



<h3 id="Windows_Code">Windows Code</h3>

<p> Windows
programmers have developed their own set of coding
conventions, mainly derived from the conventions in Windows
headers and other Microsoft code. We want to make it easy
for anyone to understand your code, so we have a single set
of guidelines for everyone writing C++ on any platform.</p>

<p>It is worth reiterating a few of the guidelines that
you might forget if you are used to the prevalent Windows
style:</p>

<ul>
  <li>Do not use Hungarian notation (for example, naming
  an integer <code>iNum</code>). Use the Google naming
  conventions, including the <code>.cc</code> extension
  for source files.</li>

  <li>Windows defines many of its own synonyms for
  primitive types, such as <code>DWORD</code>,
  <code>HANDLE</code>, etc. It is perfectly acceptable,
  and encouraged, that you use these types when calling
  Windows API functions. Even so, keep as close as you
  can to the underlying C++ types. For example, use
  <code>const TCHAR *</code> instead of
  <code>LPCTSTR</code>.</li>

  <li>When compiling with Microsoft Visual C++, set the
  compiler to warning level 3 or higher, and treat all
  warnings as errors.</li>

  <li>Do not use <code>#pragma once</code>; instead use
  the standard Google include guards. The path in the
  include guards should be relative to the top of your
  project tree.</li>

  <li>In fact, do not use any nonstandard extensions,
  like <code>#pragma</code> and <code>__declspec</code>,
  unless you absolutely must. Using
  <code>__declspec(dllimport)</code> and
  <code>__declspec(dllexport)</code> is allowed; however,
  you must use them through macros such as
  <code>DLLIMPORT</code> and <code>DLLEXPORT</code>, so
  that someone can easily disable the extensions if they
  share the code.</li>
</ul>

<p>However, there are just a few rules that we
occasionally need to break on Windows:</p>

<ul>
  <li>Normally we <a href="#Multiple_Inheritance">strongly discourage
  the use of multiple implementation inheritance</a>;
  however, it is required when using COM and some ATL/WTL
  classes. You may use multiple implementation
  inheritance to implement COM or ATL/WTL classes and
  interfaces.</li>

  <li>Although you should not use exceptions in your own
  code, they are used extensively in the ATL and some
  STLs, including the one that comes with Visual C++.
  When using the ATL, you should define
  <code>_ATL_NO_EXCEPTIONS</code> to disable exceptions.
  You should investigate whether you can also disable
  exceptions in your STL, but if not, it is OK to turn on
  exceptions in the compiler. (Note that this is only to
  get the STL to compile. You should still not write
  exception handling code yourself.)</li>

  <li>The usual way of working with precompiled headers
  is to include a header file at the top of each source
  file, typically with a name like <code>StdAfx.h</code>
  or <code>precompile.h</code>. To make your code easier
  to share with other projects, avoid including this file
  explicitly (except in <code>precompile.cc</code>), and
  use the <code>/FI</code> compiler option to include the
  file automatically.</li>

  <li>Resource headers, which are usually named
  <code>resource.h</code> and contain only macros, do not
  need to conform to these style guidelines.</li>
</ul>
</div>
</body>
</html>
