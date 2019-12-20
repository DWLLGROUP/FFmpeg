#include <jni.h>
#include <string>
#include "ffmpeg/include/NovaPushStreamAPI.h"
//#include "include/NovaPushStreamAPI.h"//导入第三方头文件

extern "C"
JNIEXPORT jstring JNICALL
Java_com_novasky_ffmpeg_FFmpegUtil_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_novasky_ffmpeg_FFmpegUtil_FFNovaPushInit(JNIEnv *env, jobject thiz) {
    // TODO: implement FFNovaPushInit()
    return NovaPusher_Init();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_novasky_ffmpeg_FFmpegUtil_NovaPusher_1SetVideoEncodeParam(JNIEnv *env, jobject thiz,
                                                                   jint width, jint height,
                                                                   jint fps, jint gop, jint bitrate,
                                                                   jint input_format,
                                                                   jint thread_num) {
    // TODO: implement NovaPusher_SetVideoEncodeParam()
    return  NovaPusher_SetVideoEncodeParam( width,  height,   fps,  gop,  bitrate,  (eInputPixelFormat)input_format,  thread_num);
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_novasky_ffmpeg_FFmpegUtil_NovaPusher_1StartupServer(JNIEnv *env, jobject thiz,
                                                             jint rtsp_port) {
    // TODO: implement NovaPusher_StartupServer()
    return NovaPusher_StartupServer(rtsp_port);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_novasky_ffmpeg_FFmpegUtil_NovaPusher_1PutFrameData(JNIEnv *env, jobject thiz,
                                                            jbyteArray rawbuf, jint rawsize) {
    jbyte *bytes = env->GetByteArrayElements(rawbuf, 0);

    int ret = NovaPusher_PutFrameData((unsigned char*)bytes, rawsize);

    env->ReleaseByteArrayElements(rawbuf, bytes, 0);

    return ret;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_novasky_ffmpeg_FFmpegUtil_NovaPusher_1ShutdownServer(JNIEnv *env, jobject thiz) {
    // TODO: implement NovaPusher_ShutdownServer()
    return NovaPusher_ShutdownServer();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_novasky_ffmpeg_FFmpegUtil_NovaPusher_1DeInit(JNIEnv *env, jobject thiz) {
    // TODO: implement NovaPusher_DeInit()

    return NovaPusher_DeInit();
}
