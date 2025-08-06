#include <jni.h>
#include <string>
#include "cool_lib.h"  // declaration of whatsup() form .so files

extern "C" JNIEXPORT jstring JNICALL
Java_com_simplesharedlib_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {


    // call the c++ function
    int value = 5;
    int result = whatsup(value);

    std::string message = "factorial " + std::to_string(result);
    return env->NewStringUTF(message.c_str());
}