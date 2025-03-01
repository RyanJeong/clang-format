

  <p>In new code, <code>using</code> is preferable to <code>typedef</code>,
  because it provides a more consistent syntax with the rest of C++ and works
  with templates.</p>

  <p>Like other declarations, aliases declared in a header file are part of that
  header's public API unless they're in a function definition, in the private portion of a class,
  or in an explicitly-marked internal namespace. Aliases in such areas or in <code>.cc</code> files
  are implementation details (because client code can't refer to them), and are not restricted by
  this rule.</p>

<p class="pros"></p>
  <ul>
    <li>Aliases can improve readability by simplifying a long or complicated name.</li>
    <li>Aliases can reduce duplication by naming in one place a type used repeatedly in an API,
      which <em>might</em> make it easier to change the type later.
    </li>
  </ul>

<p class="cons"></p>
  <ul>
    <li>When placed in a header where client code can refer to them, aliases increase the
      number of entities in that header's API, increasing its complexity.</li>
    <li>Clients can easily rely on unintended details of public aliases, making
      changes difficult.</li>
    <li>It can be tempting to create a public alias that is only intended for use
      in the implementation, without considering its impact on the API, or on maintainability.</li>
    <li>Aliases can create risk of name collisions</li>
    <li>Aliases can reduce readability by giving a familiar construct an unfamiliar name</li>
    <li>Type aliases can create an unclear API contract:
      it is unclear whether the alias is guaranteed to be identical to the type it aliases,
      to have the same API, or only to be usable in specified narrow ways</li>
  </ul>

<p class="decision"></p>
<p>Don't put an alias in your public API just to save typing in the implementation;
  do so only if you intend it to be used by your clients.</p>
<p>When defining a public alias, document the intent of
the new name, including whether it is guaranteed to always be the same as the type
it's currently aliased to, or whether a more limited compatibility is
intended. This lets the user know whether they can treat the types as
substitutable or whether more specific rules must be followed, and can help the
implementation retain some degree of freedom to change the alias.</p>
<p>Don't put namespace aliases in your public API. (See also <a href="#Namespaces">Namespaces</a>).
</p>

<p>For example, these aliases document how they are intended to be used in client code:</p>

