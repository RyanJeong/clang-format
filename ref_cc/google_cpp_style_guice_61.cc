class MyClass {
 public:
  int CountFooErrors(const std::vector&lt;Foo&gt;&amp; foos) {
    int n = 0;  // Clear meaning given limited scope and context
    for (const auto&amp; foo : foos) {
      ...
      ++n;
    }
    return n;
  }
  void DoSomethingImportant() {
    std::string fqdn = ...;  // Well-known abbreviation for Fully Qualified Domain Name
  }
 private:
  const int kMaxAllowedConnections = ...;  // Clear meaning within context
};

