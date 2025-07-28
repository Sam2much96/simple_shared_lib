## cool_lib

Usage:

```cpp
#include "cool_lib/cool_lib.h"
[...]
int result = cool_library::whatsup(42);
```

## Installation

```bash
# configure the project
cmake -Bbuild .

# build the project
make -Cbuild -j4

# install the project (into /usr/local/)
sudo make -Cbuild install
```

Output of the install command:

```
-- Up-to-date: /usr/local/include/cool_lib/cool_lib.h
-- Up-to-date: /usr/local/lib/libcool_lib.so.0.0.1
-- Up-to-date: /usr/local/lib/libcool_lib.so.0
-- Up-to-date: /usr/local/lib/libcool_lib.so
-- Installing: /usr/local/lib/cmake/cool_lib/cool_libTargets.cmake
-- Installing: /usr/local/lib/cmake/cool_lib/cool_libTargets-debug.cmake
-- Installing: /usr/local/lib/cmake/cool_lib/cool_libConfig.cmake
-- Installing: /usr/local/lib/cmake/cool_lib/cool_libConfigVersion.cmake
```

At this point there is a `.so` (the library) for linking, and a header file `cool_lib/cool_lib.h` for inclusion.


## Test app

There is also at test app that gets compiled:

```text
[dsc@fastbox shared_lib (master ✗)]$ ./build/bin/cool_test
whatsup() called :)
factorial(42) = 0
```

it links against our library:

```text
[dsc@fastbox shared_lib (master ✗)]$ ldd /build/bin/cool_test
	libcool_lib.so.0
```

## Building for Android

git clone https://github.com/kroketio/simple_shared_lib.git
cd simple_shared_lib

The path to android ndk is usually ~/Android/Sdk/ndk/27.0.12077937

mkdir build-armv7 && cd build-armv7

cmake ../ \
  -DCMAKE_TOOLCHAIN_FILE=/home/samuel/Android/Sdk/ndk/27.0.12077973/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI=armeabi-v7a \
  -DANDROID_PLATFORM=android-24 \
  -DCMAKE_BUILD_TYPE=Release

cmake --build . --target cool_lib -- -j4

Verify it with ``` $file libcool_lib.so ```, the output should be ```ELF 32-bit LSB shared object, ARM, EABI5 ... ```

