#include <jni.h>
#include <string>
#include "third.h"



extern "C"{
JNIEXPORT jint JNICALL
Java_com_test_ndkthirdso_JniUtil_add(JNIEnv *env, jclass type, jint x, jint y) {

    // TODO
    return  third_add(x,y);
}

JNIEXPORT jstring JNICALL
Java_com_test_ndkthirdso_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


}
