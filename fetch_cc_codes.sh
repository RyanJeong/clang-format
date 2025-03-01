#!/bin/bash

# Dependencies: curl, gawk
# sudo apt update && sudo apt install curl gawk

url="https://google.github.io/styleguide/cppguide.html"
html_file=$(mktemp /tmp/page.XXXXXX.html)
trap 'rm -f "${html_file}"' EXIT

curl -s "${url}" -o "${html_file}"

target_dir="ref_cc"
target_postfix="google_cpp_style_guide"
rm -rf ${target_dir}/${target_postfix}*

count=0
output="${target_dir}/${target_postfix}"

awk 'BEGIN { RS="<pre>|</pre>"; count=0 }
     NR % 2 == 0 {
         filename = sprintf("%s_%d.cc", "'"${output}"'", count++);
         print $0 > filename;
         close(filename);
     }' "${html_file}"

echo "Successfully extracted codes to ${target_dir}."

