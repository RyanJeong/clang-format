#!/bin/bash

if [ $# -ne 4 ]; then
  echo "Usage: $0 <CLANG_FORMAT_PATH> <CLANG_FORMAT_CONFIG_FILE_PATH> <REFERENCE_DIRECTORY> <TEST_DIRECTORY>"
  exit 1
fi

clang_format="$1"
clang_format_config_file="$2"
ref_dir="$3"
test_dir="$4"

temp_dir=$(mktemp -d -t format_test_XXXXXX)

cleanup() {
  rm -rf "$temp_dir"
}
trap cleanup EXIT

for ref_file in "$ref_dir"/*; do
  if [ ! -f "$ref_file" ]; then
    continue
  fi

  file_name=$(basename "$ref_file")
  test_file="$test_dir/$file_name"
  
  if [ ! -f "$test_file" ]; then
    echo "Test file missing: $file_name"
    exit 1
  fi

  formatted_file="$temp_dir/$file_name"
  # --style='file:./../.clang-format-knr'
  echo "$clang_format --style=file:${clang_format_config_file} $test_file > $formatted_file"
  "$clang_format" --style=file:"${clang_format_config_file}" "$test_file" > "$formatted_file"

  if ! diff -q "$formatted_file" "$ref_file" > /dev/null; then
    echo "Formatting check failed for: $file_name"
    exit 1
  fi
done

echo "All files passed formatting check."

