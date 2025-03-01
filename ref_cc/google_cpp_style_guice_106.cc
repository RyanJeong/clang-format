
<pre class="badcode">int x, *y;  // Disallowed - no &amp; or * in multiple declaration
int* x, *y;  // Disallowed - no &amp; or * in multiple declaration; inconsistent spacing
char * c;  // Bad - spaces on both sides of *
const std::string &amp; str;  // Bad - spaces on both sides of &amp;

