
<p>Constructors in a primary template (as opposed to a template specialization)
  also implicitly define deduction guides.</p>

<p>When you declare a variable that relies on CTAD, the compiler selects
  a deduction guide using the rules of constructor overload resolution,
  and that guide's return type becomes the type of the variable.</p>

<p class="pros"></p>
<p>CTAD can sometimes allow you to omit boilerplate from your code.</p>

<p class="cons"></p>
<p>The implicit deduction guides that are generated from constructors
  may have undesirable behavior, or be outright incorrect. This is
  particularly problematic for constructors written before CTAD was
  introduced in C++17, because the authors of those constructors had no
  way of knowing about (much less fixing) any problems that their
  constructors would cause for CTAD. Furthermore, adding explicit deduction
  guides to fix those problems might break any existing code that relies on
  the implicit deduction guides.</p>

<p>CTAD also suffers from many of the same drawbacks as <code>auto</code>,
  because they are both mechanisms for deducing all or part of a variable's
  type from its initializer. CTAD does give the reader more information
  than <code>auto</code>, but it also doesn't give the reader an obvious
  cue that information has been omitted.</p>

<p class="decision"></p>
<p>Do not use CTAD with a given template unless the template's maintainers
  have opted into supporting use of CTAD by providing at least one explicit
  deduction guide (all templates in the <code>std</code> namespace are
  also presumed to have opted in). This should be enforced with a compiler
  warning if available.</p>

<p>Uses of CTAD must also follow the general rules on
  <a href="#Type_deduction">Type deduction</a>.</p>

<h3 id="Designated_initializers">Designated Initializers</h3>

<p>Use designated initializers only in their C++20-compliant form.</p>

<p class="definition"></p>
<p><a href="https://en.cppreference.com/w/cpp/language/aggregate_initialization#Designated_initializers">
  Designated initializers</a> are a syntax that allows for initializing an
  aggregate ("plain old struct") by naming its fields explicitly:</p>
  <pre class="neutralcode">  struct Point {
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
  };

  Point p = {
    .x = 1.0,
    .y = 2.0,
    // z will be 0.0
  };
