

<h4 id="Implementation_Comment_Donts">Don'ts</h4>

<p>Do not state the obvious. In particular, don't literally describe what
code does, unless the behavior is nonobvious to a reader who understands
C++ well. Instead, provide higher level comments that describe <i>why</i>
the code does what it does, or make the code self describing.</p>

Compare this:

<pre class="badcode">// Find the element in the vector.  &lt;-- Bad: obvious!
if (std::find(v.begin(), v.end(), element) != v.end()) {
  Process(element);
}

