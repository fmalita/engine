// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_FML_PLATFORM_ANDROID_JNI_UTIL_H_
#define FLUTTER_FML_PLATFORM_ANDROID_JNI_UTIL_H_

#include <jni.h>

#include <vector>

#include "flutter/fml/platform/android/scoped_java_ref.h"
#include "lib/ftl/macros.h"

namespace fml {
namespace jni {

void InitJavaVM(JavaVM* vm);

JNIEnv* AttachCurrentThread();

void DetachFromVM();

void InitAndroidApplicationContext(const JavaRef<jobject>& context);

const jobject GetAndroidApplicationContext();

std::string JavaStringToString(JNIEnv* env, jstring string);

ScopedJavaLocalRef<jstring> StringToJavaString(JNIEnv* env,
                                               const std::string& str);

std::vector<std::string> StringArrayToVector(JNIEnv* env, jobjectArray jargs);

ScopedJavaLocalRef<jobjectArray> VectorToStringArray(
    JNIEnv* env,
    const std::vector<std::string>& vector);

bool HasException(JNIEnv* env);

bool ClearException(JNIEnv* env);

std::string GetJavaExceptionInfo(JNIEnv* env, jthrowable java_throwable);

}  // namespace jni
}  // namespace fml

#endif  // FLUTTER_FML_PLATFORM_ANDROID_JNI_UTIL_H_
