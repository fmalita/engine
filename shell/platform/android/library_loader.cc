// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/fml/platform/android/jni_util.h"
#include "flutter/lib/jni/dart_jni.h"
#include "flutter/shell/platform/android/flutter_main.h"
#include "flutter/shell/platform/android/platform_view_android.h"
#include "flutter/shell/platform/android/vsync_waiter_android.h"

// This is called by the VM when the shared library is first loaded.
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  // Initialize the Java VM.
  fml::jni::InitJavaVM(vm);

  JNIEnv* env = fml::jni::AttachCurrentThread();
  bool result = false;

  // Register FlutterMain.
  result = shell::RegisterFlutterMain(env);
  FTL_CHECK(result);

  // Register PlatformView
  result = shell::PlatformViewAndroid::Register(env);
  FTL_CHECK(result);

  // Register VSyncWaiter.
  result = shell::VsyncWaiterAndroid::Register(env);
  FTL_CHECK(result);

  // Register DartJni
  result = blink::DartJni::InitJni();
  FTL_CHECK(result);

  return JNI_VERSION_1_4;
}
