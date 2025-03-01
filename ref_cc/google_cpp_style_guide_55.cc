
Instead, prefer to leave code as an ordinary template unless
you can demonstrate that concepts result in significant
improvement for that particular case, such as in the resulting
error messages for a deeply nested or non-obvious
requirement.

<p>Concepts should be statically verifiable by the compiler.
Do not use any concept whose primary benefits would come from a
semantic (or otherwise unenforced) constraint.
Requirements that are unenforced at compile time should instead
be imposed via other mechanisms such as comments, assertions,
or tests.</p>

<h3 id="modules">C++20 modules</h3>

<p>Do not use C++20 Modules.</p>

<p>C++20 introduces "modules", a new language feature designed as an
alternative to textual inclusion of header files. It introduces three
new keywords to support
this: <code>module</code>, export,
and <code>import</code>.

</p><p>Modules are a big shift in how C++ is written and compiled, and we
are still assessing how they may fit into Google's C++ ecosystem in
the future. Furthermore, they are not currently well-supported by our
build-systems, compilers, and other tooling, and need further
exploration as to the best-practices when writing and using them.</p>



<h3 id="coroutines">Coroutines</h3>

<p>Do not use coroutines (yet).</p>

<p>Do not include the <code>&lt;coroutine&gt;</code> header,
or use the <code>co_await</code>, <code>co_yield</code>,
or <code>co_return</code> keywords.</p>

<p>NOTE: this ban is expected to be temporary, while further
guidance is being developed.

</p>

<h3 id="Boost">Boost</h3>

<p>Use only approved libraries from the Boost library
collection.</p>

<p class="definition"></p>
<p> The
<a href="https://www.boost.org/">
Boost library collection</a> is a popular collection of
peer-reviewed, free, open-source C++ libraries.</p>

<p class="pros"></p>
<p>Boost code is generally very high-quality, is widely
portable, and fills many important gaps in the C++
standard library, such as type traits and better binders.</p>

<p class="cons"></p>
<p>Some Boost libraries encourage coding practices which can
hamper readability, such as metaprogramming and other
advanced template techniques, and an excessively
"functional" style of programming. </p>

<p class="decision"></p>



<div>
<p>In order to maintain a high level of readability for
all contributors who might read and maintain code, we
only allow an approved subset of Boost features.
Currently, the following libraries are permitted:</p>

<ul>
  <li>
  <a href="https://www.boost.org/libs/utility/call_traits.htm">
  Call Traits</a> from <code>boost/call_traits.hpp</code></li>

  <li><a href="https://www.boost.org/libs/utility/compressed_pair.htm">
  Compressed Pair</a> from  <code>boost/compressed_pair.hpp</code></li>

  <li><a href="https://www.boost.org/libs/graph/">
  The Boost Graph Library (BGL)</a> from <code>boost/graph</code>,
  except serialization (<code>adj_list_serialize.hpp</code>) and
   parallel/distributed algorithms and data structures
   (<code>boost/graph/parallel/*</code> and
   <code>boost/graph/distributed/*</code>).</li>

  <li><a href="https://www.boost.org/libs/property_map/">
  Property Map</a> from <code>boost/property_map</code>, except
  parallel/distributed property maps (<code>boost/property_map/parallel/*</code>).</li>

  <li><a href="https://www.boost.org/libs/iterator/">
  Iterator</a> from <code>boost/iterator</code></li>

  <li>The part of <a href="https://www.boost.org/libs/polygon/">
  Polygon</a> that deals with Voronoi diagram
  construction and doesn't depend on the rest of
  Polygon:
  <code>boost/polygon/voronoi_builder.hpp</code>,
  <code>boost/polygon/voronoi_diagram.hpp</code>, and
  <code>boost/polygon/voronoi_geometry_type.hpp</code></li>

  <li><a href="https://www.boost.org/libs/bimap/">
  Bimap</a> from <code>boost/bimap</code></li>

  <li><a href="https://www.boost.org/libs/math/doc/html/dist.html">
  Statistical Distributions and Functions</a> from
  <code>boost/math/distributions</code></li>

  <li><a href="https://www.boost.org/libs/math/doc/html/special.html">
  Special Functions</a> from <code>boost/math/special_functions</code></li>

  <li><a href="https://www.boost.org/libs/math/doc/html/root_finding.html">
  Root Finding &amp; Minimization Functions</a> from <code>boost/math/tools</code></li>

  <li><a href="https://www.boost.org/libs/multi_index/">
  Multi-index</a> from <code>boost/multi_index</code></li>

  <li><a href="https://www.boost.org/libs/heap/">
  Heap</a> from <code>boost/heap</code></li>

  <li>The flat containers from
  <a href="https://www.boost.org/libs/container/">Container</a>:
  <code>boost/container/flat_map</code>, and
  <code>boost/container/flat_set</code></li>

  <li><a href="https://www.boost.org/libs/intrusive/">Intrusive</a>
  from <code>boost/intrusive</code>.</li>

  <li><a href="https://www.boost.org/libs/sort/">The
  <code>boost/sort</code> library</a>.</li>

  <li><a href="https://www.boost.org/libs/preprocessor/">Preprocessor</a>
  from <code>boost/preprocessor</code>.</li>
</ul>

<p>We are actively considering adding other Boost
features to the list, so this list may be expanded in
the future.</p>
</div>




<h3 id="Disallowed_Stdlib">Disallowed standard library features</h3>


<p>As with <a href="#Boost">Boost</a>, some modern C++
library functionality encourages coding practices that hamper
readability—for example by removing
checked redundancy (such as type names) that may be
helpful to readers, or by encouraging template
metaprogramming. Other extensions duplicate functionality
available through existing mechanisms, which may lead to confusion
and conversion costs.</p>

<p class="decision"></p>
<p>The following C++ standard library features may not be used:</p>

<ul>


  <li>Compile-time rational numbers
  (<code>&lt;ratio&gt;</code>), because of concerns that
  it's tied to a more template-heavy interface
  style.</li>

  <li>The <code>&lt;cfenv&gt;</code> and
  <code>&lt;fenv.h&gt;</code> headers, because many
  compilers do not support those features reliably.</li>

  <li>The <code>&lt;filesystem&gt;</code> header, which

  does not have sufficient support for testing, and suffers
  from inherent security vulnerabilities.</li>


</ul>

<h3 id="Nonstandard_Extensions">Nonstandard Extensions</h3>

<p>Nonstandard extensions to C++ may not be used unless otherwise specified.</p>

<p class="definition"></p>
<p>Compilers support various extensions that are not part of standard C++. Such
  extensions include GCC's <code>__attribute__</code>, intrinsic functions such
  as <code>__builtin_prefetch</code> or SIMD, <code>#pragma</code>, inline
  assembly, <code>__COUNTER__</code>, <code>__PRETTY_FUNCTION__</code>,
  compound statement expressions (e.g., <code>foo = ({ int x; Bar(&amp;x); x
    })</code>, variable-length arrays and <code>alloca()</code>, and the
   "<a href="https://en.wikipedia.org/wiki/Elvis_operator">Elvis
     Operator</a>" <code>a?:b</code>.</p>

<p class="pros"></p>
  <ul>
    <li>Nonstandard extensions may provide useful features that do not exist
      in standard C++.</li>
    <li>Important performance guidance to the compiler can only be specified
      using extensions.</li>
  </ul>

<p class="cons"></p>
  <ul>
    <li>Nonstandard extensions do not work in all compilers. Use of nonstandard
      extensions reduces portability of code.</li>
    <li>Even if they are supported in all targeted compilers, the extensions
      are often not well-specified, and there may be subtle behavior differences
      between compilers.</li>
    <li>Nonstandard extensions add to the language features that a reader must
      know to understand the code.</li>
    <li>Nonstandard extensions require additional work to port across architectures.</li>
  </ul>

<p class="decision"></p>
<p>Do not use nonstandard extensions. You may use portability wrappers that
  are implemented using nonstandard extensions, so long as those wrappers

  are provided by a designated project-wide portability
    header.</p>

<h3 id="Aliases">Aliases</h3>

<p>Public aliases are for the benefit of an API's user, and should be clearly documented.</p>

<p class="definition"></p>
<p>There are several ways to create names that are aliases of other entities:</p>

