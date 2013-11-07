libcpxvta
=========

An easy to use windows library, based on FFmpeg, to convert videos to audio files. Currently, it supports .mp3 and .ogg file formats.

The DLL exports only one function:

    int cpxvta_convert(const char* inputFileName, const char* outputFileName, ConvertSettings* settings, NotifyProgressCallback callback) 
    
This [blog article](http://www.cpawelzik.com/2013/11/libcpxvta/) explains how to use the library with .NET.