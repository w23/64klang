#pragma once

#ifdef _WIN32
#error This file is not for windows
#endif

#include <stdint.h>

typedef bool BOOL;
typedef uint8_t BYTE;
typedef uint8_t *LPBYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int64_t __int64;

#ifdef _WIN32
#define M128I_I32(m, i) ((m).m128i_i32[i])
#else
#define M128I_I32(m, i) ((m)[i])
#endif
