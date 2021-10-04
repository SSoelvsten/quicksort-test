# Quicksort Test
[![MIT License](https://img.shields.io/badge/license-MIT%20License-blue.svg)](LICENSE.md)
[![linux](https://github.com/SSoelvsten/quicksort-test/actions/workflows/linux.yml/badge.svg)](https://github.com/SSoelvsten/quicksort-test/actions/workflows/linux.yml)
[![macos](https://github.com/SSoelvsten/quicksort-test/actions/workflows/macos.yml/badge.svg)](https://github.com/SSoelvsten/quicksort-test/actions/workflows/macos.yml)
[![windows](https://github.com/SSoelvsten/quicksort-test/actions/workflows/windows.yml/badge.svg)](https://github.com/SSoelvsten/quicksort-test/actions/workflows/windows.yml)

This repository provides a small and simple implementation of the
[Quicksort](https://en.wikipedia.org/wiki/Quicksort) algorithm, which is to be
used as a C++ programming challenge for potential student job candidates. The
programming tasks are described in the
[issues](https://github.com/SSoelvsten/quicksort-test/issues) section of this
repository. See the [criteria](#criteria) below for what to focus on when
solving the exercises.

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Criteria](#criteria)
- [Dependencies](#dependencies)
- [Usage](#usage)
- [License](#license)

<!-- markdown-toc end -->

## Criteria

Your solution should focus on

1. Clean code and software architecture
2. Testing
3. Not decreasing performance of the current solution.

A good but only partial solution to the given tasks is better than a solution
that covers everything poorly.

## Dependencies

The implementation is dependant on the the following external libraries

- [Bandit](https://github.com/banditcpp/bandit):
  Writing and running unit tests

These are directly  imported as submodules. If you have not cloned the
repository recursively, then run the following command

```bash
git submodule update --init --recursive
```

One also needs a _C++_ compiler that supports the _17_ standard. All development
has currently been with the _gcc_ compiler, so we cannot guarantee other
compilers will work out-of-the-box. The project is built with _CMake_. On Ubuntu
20+ you can obtain all these with the following commands.

```bash
apt install g++ cmake libboost-all-dev
```

## Usage

The project is build with _CMake_, though for convenience I have simplified the
_CMake_ interactions to a single _Makefile_ which works on a local machine. This
has only been tested on _Ubuntu 18.04 LTS_ and _20.04 LTS_.

The _Makefile_ provides the following targets

| target  | effect                                    |
|---------|-------------------------------------------|
| `build` | Build the source files                    |
| `clean` | Remove all build files                    |
|         |                                           |
| `test`  | Run all unit tests                        |
| `main`  | Run the _main_ function in `src/main.cpp` |

## License

The software and documentation files in this repository are provided under the
[MIT License](/LICENSE.md).
