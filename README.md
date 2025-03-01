# clang-format

This repository provides a `clang-format` configuration file that enforces the **K&R style for C** and the **Google C++ Style Guide** for C++.

A reference directory contains source code that follows the correct formatting. Every time the `clang-format` configuration is modified, a GitHub Action verifies whether the formatting is applied correctly.

## `clang-format` Version

The current clang-format version used in this repository is **19**.

The installation instructions for version 19 are as follows:

```shell
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 19

sudo apt install -y clang-format-19
sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-19 100
sudo update-alternatives --set clang-format /usr/bin/clang-format-19
```
