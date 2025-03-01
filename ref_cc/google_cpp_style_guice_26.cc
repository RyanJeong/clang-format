

  <p><code>thread_local</code> variables inside a function have no initialization
    concerns, but still risk use-after-free during thread exit. Note that you can use
    a function-scope <code>thread_local</code> to simulate a class- or
    namespace-scope <code>thread_local</code> by defining a function or
    static method that exposes it:</p>


