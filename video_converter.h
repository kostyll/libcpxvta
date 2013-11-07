/*
 * Copyright (c) 2013 Christopher Pawelzik <christopher@cpawelzik.com>
 *
 * This file is part of libcpxvta.
 *
 * libcpxvta is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * libcpxvta is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with libcpxvta; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
 
#include <stdio.h>
#include <tchar.h>

#include "libcpxvta.h"

extern "C" { 
  // !Important
  #ifndef __STDC_CONSTANT_MACROS 
    #define __STDC_CONSTANT_MACROS 
  #endif

  #include <libavcodec/avcodec.h>
  #include <libavformat/avformat.h> 
  #include <libavfilter/avfiltergraph.h>
  #include <libavfilter/avcodec.h>
  #include <libavfilter/buffersink.h>
  #include <libavfilter/buffersrc.h>
  #include "libavutil/opt.h"
}

typedef struct FilterContext { 
  AVFilterGraph *filter_graph;
  AVFilterContext *buffersink_ctx;
  AVFilterContext *buffersrc_ctx;
} FilterContext; 

typedef struct AudioInfo {   
  AVCodecContext* audioCodecCtx;
  AVFormatContext* formatCtx; 
  AVCodec* audioCodec;
  int audioStreamIndex; 
} AudioInfo;

#define PRIx64 "lx"