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
 
#ifndef _LIBCPXVTA_H_
#define _LIBCPXVTA_H_

// We support these audio formats
#define TARGET_FORMAT_MP3   1
#define TARGET_FORMAT_OGG   2

typedef struct ConvertSettings {  
  int target_format;    
  int rs_sample_rate; 
  int rs_bit_rate; 
  int rs_channels;  
} ConvertSettings;

typedef void (*NotifyProgressCallback) (int progress); 

// Export functions 
#define DllExport extern "C" __declspec(dllexport)

DllExport int cpxvta_convert(const char* inputFileName, const char* outputFileName, ConvertSettings* settings, NotifyProgressCallback callback); 

#endif // _LIBCPXVTA_H_