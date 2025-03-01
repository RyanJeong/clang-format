# clang-format

- You can easily verify how the formatter arranges things using the command below.

```sh
$ clang-format test.cc --verbose
Formatting [1/1] test.cc
... skipped ...
```

## Generate Source Codes To Test `clang-format`

This process is only needed when you want to add reference codes to test `clang-format`.

```shell
# Generate C test codes
rm -rf test_c && \
  cp -r ref_c test_c && \
  for code in test_c/*; do clang-format -i ${code}; done
```

## Test `clang-format`

```shell
# Test clang-format for C K&R style
./check_format.sh "$(which clang-format)" ".clang-format-knr" ref_c test_c
```
