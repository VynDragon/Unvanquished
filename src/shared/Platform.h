/*
===========================================================================

Daemon GPL Source Code
Copyright (C) 2012-2013 Unvanquished Developers

This file is part of the Daemon GPL Source Code (Daemon Source Code).

Daemon Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your
option) any later version.

Daemon Source Code is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License
along with Daemon Source Code.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#ifndef SHARED_PLATFORM_H_
#define SHARED_PLATFORM_H_

// Platform-specific configuration
#ifdef _WIN32
#define DLL_PREFIX ""
#define DLL_EXT ".dll"
#define EXE_EXT ".exe"
#define PATH_SEP '\\'
#define PLATFORM_STRING "Windows"
#elif defined(__APPLE__)
#define DLL_PREFIX "lib"
#define DLL_EXT ".dylib"
#define EXE_EXT ""
#define PATH_SEP '/'
#define PLATFORM_STRING "Mac OS X"
#elif defined(__linux__)
#define DLL_PREFIX "lib"
#define DLL_EXT ".so"
#define EXE_EXT ""
#define PATH_SEP '/'
#define PLATFORM_STRING "Linux"
#elif defined(__native_client__)
#define ARCH_STRING "Native Client"
#else
#error "Platform not supported"
#endif

// Architecture-specific configuration
#if defined(__i386__) || defined(_M_IX86)
#undef __i386__
#define __i386__ 1
#define ARCH_STRING "x86"
#elif defined(__amd64) || defined(__amd64__) || defined(_M_AMD64) || defined(__x86_64__) || defined(_M_X64)
#undef __x86_64__
#define __x86_64__ 1
#define ARCH_STRING "x86_64"
#elif defined(__pnacl__)
#define ARCH_STRING "PNaCl"
#else
#error "Architecture not supported"
#endif

// SSE support
#if _M_IX86_FP >= 1 || defined(__SSE__)
#include <xmmintrin.h>
#define id386_sse 1
#endif

#endif // SHARED_PLATFORM_H_