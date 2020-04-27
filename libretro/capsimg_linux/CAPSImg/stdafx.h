// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

// OS compatiblity
//#include "targetver.h"		//-- Linux changes

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows specific
//#include <windows.h>			//-- Linux changes

// detect memory leaks in debug builds
#define _CRTDBG_MAP_ALLOC

// standard C/C++ includes
#include <stdlib.h>
//#include <crtdbg.h>			//-- Linux changes
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <vector>
//#include <io.h>			//-- Linux changes
//#include <direct.h>			//-- Linux changes
#include <dirent.h>

//-- Linux changes
#include <stddef.h>			// offsetof
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>			// localtime
#define MAX_PATH ( 260 )
#ifndef __cdecl
#define __cdecl
#endif
#define _lrotl(x,n) (((x) << (n)) | ((x) >> (sizeof(x)*8-(n))))
#define _lrotr(x,n) (((x) >> (n)) | ((x) << (sizeof(x)*8-(n))))
typedef const char *LPCSTR;
typedef const char *LPCTSTR;
//-- Linux changes


#define INTEL
#define MAX_FILENAMELEN (MAX_PATH*2)

// external definitions
#include "CommonTypes.h"

// Core components
#include "BaseFile.h"
#include "DiskFile.h"
#include "MemoryFile.h"
#include "CRC.h"
#include "BitBuffer.h"

// IPF library public definitions
#include "CapsLibAll.h"

// CODECs
#include "DiskEncoding.h"
#include "CapsDefinitions.h"
#include "CTRawCodec.h"

// file support
#include "CapsFile.h"
#include "DiskImage.h"
#include "CapsLoader.h"
#include "CapsImageStd.h"
#include "CapsImage.h"
#include "StreamImage.h"
#include "StreamCueImage.h"
#include "DiskImageFactory.h"

// Device access
#include "C2Comm.h"

// system
#include "CapsCore.h"
#include "CapsFDCEmulator.h"
#include "CapsFormatMFM.h"

#if defined(VITA)
#include <psp2/types.h>
#include <psp2/io/dirent.h>
#include <psp2/kernel/threadmgr.h>
#define mkdir(name,mode) sceIoMkdir(name, 0777)
#define rmdir(name) sceIoRmdir(name)
#endif

//-- Linux changes
#define _access access
#ifndef __MINGW32__
#define _mkdir(x) mkdir(x,0)
#else
#define _mkdir(x) mkdir(x)
#endif
#define d_namlen d_reclen
#define __assume(cond) do { if (!(cond)) __builtin_unreachable(); } while (0)
#define min(x, y) (((x) < (y)) ? (x) : (y))

typedef struct _SYSTEMTIME {
        WORD wYear;
        WORD wMonth;
        WORD wDayOfWeek;
        WORD wDay;
        WORD wHour;
        WORD wMinute;
        WORD wSecond;
        WORD wMilliseconds;
} SYSTEMTIME, *LPSYSTEMTIME;
extern "C" void GetLocalTime(LPSYSTEMTIME lpSystemTime);
//-- Linux changes


