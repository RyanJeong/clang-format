

<p>Note that certain universally-known abbreviations are OK, such as
<code>i</code> for an iteration variable and <code>T</code> for a
template parameter.</p>

<p>For the purposes of the naming rules below, a "word" is anything that you
would write in English without internal spaces. This includes abbreviations,
such as acronyms and initialisms. For names written in mixed case (also
sometimes referred to as
"<a href="https://en.wikipedia.org/wiki/Camel_case">camel case</a>" or
"<a href="https://en.wiktionary.org/wiki/Pascal_case">Pascal case</a>"), in
which the first letter of each word is capitalized, prefer to capitalize
abbreviations as single words, e.g., <code>StartRpc()</code> rather than
<code>StartRPC()</code>.</p>

<p>Template parameters should follow the naming style for their
category: type template parameters should follow the rules for
<a href="#Type_Names">type names</a>, and non-type template
parameters should follow the rules for <a href="#Variable_Names">
variable names</a>.

</p><h3 id="File_Names">File Names</h3>

<p>Filenames should be all lowercase and can include
underscores (<code>_</code>) or dashes (<code>-</code>).
Follow the convention that your

project uses. If there is no consistent
local pattern to follow, prefer "<code>_</code>".</p>

<p>Examples of acceptable file names:</p>

<ul>
  <li><code>my_useful_class.cc</code></li>
  <li><code>my-useful-class.cc</code></li>
  <li><code>myusefulclass.cc</code></li>
  <li><code>myusefulclass_test.cc // _unittest and _regtest are deprecated.</code></li>
</ul>

<p>C++ files should have a <code>.cc</code> filename extension, and header files
should have a <code>.h</code> extension. Files that rely on being textually included at specific points
should end in <code>.inc</code> (see also the section on
<a href="#Self_contained_Headers">self-contained headers</a>).</p>

<p>Do not use filenames that already exist in
<code>/usr/include</code>, such as <code>db.h</code>.</p>

<p>In general, make your filenames very specific. For
example, use <code>http_server_logs.h</code> rather than
<code>logs.h</code>. A very common case is to have a pair
of files called, e.g., <code>foo_bar.h</code> and
<code>foo_bar.cc</code>, defining a class called
<code>FooBar</code>.</p>

<h3 id="Type_Names">Type Names</h3>

<p>Type names start with a capital letter and have a capital
letter for each new word, with no underscores:
<code>MyExcitingClass</code>, <code>MyExcitingEnum</code>.</p>

<p>The names of all types — classes, structs, type aliases,
enums, and type template parameters — have the same naming convention.
Type names should start with a capital letter and have a capital letter
for each new word. No underscores. For example:</p>


