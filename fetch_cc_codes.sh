#!/bin/bash

# Dependencies: curl, gawk
# sudo apt update && sudo apt install curl gawk xmlstarlet

url="https://google.github.io/styleguide/cppguide.html"
html_file=$(mktemp /tmp/page.XXXXXX.html)
trap 'rm -f "${html_file}"' EXIT

curl -s "${url}" -o "${html_file}"

target_dir="ref_cc"
target_postfix="google_cpp_style_guide"
rm -rf ${target_dir}/${target_postfix}*

count=0
output="${target_dir}/${target_postfix}"

# awk 'BEGIN { RS="<pre>|</pre>"; count=0 }
awk 'BEGIN { RS="<pre>|<pre class=\"goodcode\">|<pre class=\"badcode\">|<pre class=\"neutralcode\">|</pre>"; count=0 }
     NR % 2 == 0 {
         filename = sprintf("%s_%d.cc", "'"${output}"'", count++);
         print $0 > filename;
         close(filename);
     }' "${html_file}"

for file in ${output}_*.cc; do
  if command -v xmlstarlet &> /dev/null; then
    xmlstarlet unesc < "${file}" > "${file}.tmp" && mv "${file}.tmp" "${file}"
  else
    perl -MHTML::Entities -pe 'decode_entities($_);' "${file}" > "${file}.tmp" && mv "${file}.tmp" "${file}"
  fi
done

declare -a patterns=(
    "..."
    "if (this_one_thing > this_other_thing &&"
    "return result;                  // No parentheses in the simple case."
    "void SomeFunctionThatDoesNothing() {"
    "TODO: bug 12345678 - Remove this after the 2047q4 compatibility window expires."
    "MyClass::MyClass(int var) : some_var_(var) {"
    "NotCopyableOrMovable& operator=(const NotCopyableOrMovable&)"
    "void Analyze(const std::string &text);"
    "std::for_each(v.begin(), v.end(), [weight, &sum](int x) {"
    " // Used to bounds-check table accesses. -1 means"
    "AddTableEntry()"
    "f(jobs);      // Good -- declaration immediately (or closely) followed by use."
    "std::string tableName;   // Bad - mixed case."
    "typedef unordered_set<DataPoint, hash<DataPoint>, DataPointComparator> TimeSeries;"
    "Used to store field measurements. DataPoint may change from Bar* to some internal type."
    "using TimeSeries = std::unordered_set<DataPoint, std::hash<DataPoint>, DataPointComparator>;"
    "ABSL_ATTRIBUTE_NOINLINE void ExpensiveFunction();"
    "bool result = DoSomething(averyveryveryverylongargument1,"
    "if (condition) {                   // Good - no spaces inside parentheses, space before brace."
    "std::sort(v.begin(), v.end(), [](int x, int y) {"
    "// These are fine, space preceding."
    "int* x, *y;  // Disallowed - no & or * in multiple declaration; inconsistent spacing"
    "if (std::find(v.begin(), v.end(), element) != v.end()) {"
    "if (!IsAlreadyProcessed(element)) {"
    "  void foo();"
    "if (x == kBar)"
    "return (value);                // You wouldn't write var = (value);"
    "if (!success) {"
    "#if DISASTER_PENDING      // Correct -- Starts at beginning of line"
    "    #if DISASTER_PENDING  // Wrong!  The \"#if\" should be at beginning of line"
    "my_widget.Transform(x1, x2, x3,"
    "bool result = DoSomething(scores[x] * y + bases[x],  // Score heuristic."
    "std::vector<char *> x;"
    "i = f();      // Bad -- initialization separate from declaration."
    "for (int i = 0; i < 1000000; ++i) {"
    "    template <typename T, typename U>"
    "Foo x(2);   // Fine, 2 is a constant expression and the chosen constructor is constexpr."
    "digits.erase(std::remove_if(digits.begin(), digits.end(), [&to_remove](int i) {"
    "    {\"assume a zero-length name before {\"},"
    "struct X { int n; };"
    "time_t time(time_t*);      // Not constexpr!"
    "  struct Point {"
    "template <typename T>     // Bad - redundant with negligible benefit"
)

for file in ${output}_*.cc; do
  for pattern in "${patterns[@]}"; do
    if grep -qF "$pattern" "$file"; then
      echo "Removing $file (matched: '$pattern')"
      rm -f "$file"
      break
    fi
  done

  if [ -s "$file" ] && [ -z "$(grep -v '^[[:space:]]*$' "$file")" ]; then
    echo "Removing $file (empty or whitespace-only)"
    rm -f "$file"
  fi
done

echo "Successfully extracted codes to ${target_dir}."

