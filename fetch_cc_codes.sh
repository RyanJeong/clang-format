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

awk 'BEGIN { RS="<pre>|</pre>"; count=0 }
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

echo "Successfully extracted codes to ${target_dir}."

