# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

project("simplesharedlib")





add_library(${CMAKE_PROJECT_NAME} SHARED
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        native-lib.cpp

)


# Declare the prebuilt shared library (already compiled .so)
add_library(cool_lib SHARED IMPORTED)

# Specify where to find libcool_lib.so for each ABI
set_target_properties(cool_lib PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/${ANDROID_ABI}/libcool_lib.so"
)


target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        cool_lib
        android
        log)