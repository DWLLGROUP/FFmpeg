package com.novasky.ffmpeg;

public class FFmpegUtil {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("NovaPushStream");
        System.loadLibrary("native-lib");
    }


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public  native  String stringFromJNI();

    public  native  int FFNovaPushInit();

    public  native  int NovaPusher_SetVideoEncodeParam(int width, int height,  int fps, int gop, int bitrate, int inputFormat, int threadNum);

    public native  int NovaPusher_StartupServer(int rtspPort);

    public native  int NovaPusher_PutFrameData(byte[]  rawbuf,  int rawsize);

    public native int NovaPusher_ShutdownServer();

    public native  int NovaPusher_DeInit();

}
