**Dependencies:**

A compiler with support for C++20
CMake version 3.28.3
Catch2 v3.7.1 for unit testing. Cmake will auto fetch and build this for you.

**Build instructions:**

```
#cd into project dir
# make build directory if doesn't already exist
mkdir build
cd build
# generate cmake files
cmake ..
# compile
cmake --build .
```

**Testing instructions:**

```
cd build
cmake ..
cmake --build .
ctest --verbose
```

**Usage Instructions:**

```
./grep-file-search "ITEM_IM_SEARCHING_FOR" ~/
```