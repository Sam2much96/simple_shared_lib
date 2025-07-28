#include <jni.h>
#include <string>
#include <dlfcn.h>   // for dlopen, dlsym

extern "C" JNIEXPORT jstring JNICALL
Java_com_simplesharedlib_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    // Open the shared library
    void* handle = dlopen("libcool_lib.so", RTLD_LAZY);

    if (!handle) {
        std::string err = "Failed to load library: ";
        err += dlerror();
        return env->NewStringUTF(err.c_str());
    }

    // Clear any existing errors
    dlerror();

    // Define function pointer type
    typedef int (*WhatsUpFunc)(int);

    // Lookup symbol
    WhatsUpFunc whatsup = (WhatsUpFunc)dlsym(handle, "whatsup");

    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::string err = "Failed to load symbol: ";
        err += dlsym_error;
        dlclose(handle);
        return env->NewStringUTF(err.c_str());
    }

    // call the c++ function
    int value = 5;
    int result = whatsup(value);

    // Clean up
    dlclose(handle);

    // format the result to a C sting

    std::string message = "factorial " + std::to_string(result);
    return env->NewStringUTF(message.c_str());
}