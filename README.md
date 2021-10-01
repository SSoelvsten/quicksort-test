# Quicksort Test

This repository provides a small and simple implementation of the
[Quicksort](https://en.wikipedia.org/wiki/Quicksort) algorithm, which is to be
used as a C++ programming challenge for potential student job candidates.

The programming exercises are described in the _issues_ section of this
repository. Your solution should focus on _code quality_, _software
architecture_, _testing_, and _not decreasing performance of the current
solution_.

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Dependencies](#dependencies)
- [Usage](#usage)
- [License](#license)

<!-- markdown-toc end -->


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
