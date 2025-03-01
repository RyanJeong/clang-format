
<p>As with function parameter comments, this can enable tools to detect if
  you get the order of the fields wrong.</p>

<h3 id="CTAD">Class Template Argument Deduction</h3>

<p>Use class template argument deduction only with templates that have
  explicitly opted into supporting it.</p>

<p class="definition"></p>
<p><a href="https://en.cppreference.com/w/cpp/language/class_template_argument_deduction">Class
    template argument deduction</a> (often abbreviated "CTAD") occurs when
  a variable is declared with a type that names a template, and the template
  argument list is not provided (not even empty angle brackets):</p>
  <pre class="neutralcode">std::array a = {1, 2, 3};  // `a` is a std::array&lt;int, 3&gt;
