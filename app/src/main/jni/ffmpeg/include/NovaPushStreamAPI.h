/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NovaPushStreamAPI.h
 * Author: root
 *
 * Created on 2019年12月16日, 上午11:39
 */

#ifndef NOVAPUSHSTREAMAPI_H
#define NOVAPUSHSTREAMAPI_H


enum eInputPixelFormat 
{
    PIX_FMT_YUV420P = 0,   
    PIX_FMT_BGR24 = 3,     
    PIX_FMT_NV21 = 24      
};


#ifdef __cplusplus
extern "C" {
#endif

    int NovaPusher_Init();
    
    int NovaPusher_SetVideoEncodeParam(int width, int height,  int fps, int gop, int bitrate, eInputPixelFormat inputFormat, int threadNum);
    
    int NovaPusher_StartupServer(int rtspPort);
    
    int NovaPusher_PutFrameData(unsigned char *rawbuf,  int rawsize);
      
    int NovaPusher_ShutdownServer();
        
    int NovaPusher_DeInit();


#ifdef __cplusplus
}
#endif

#endif /* NOVAPUSHSTREAMAPI_H */

