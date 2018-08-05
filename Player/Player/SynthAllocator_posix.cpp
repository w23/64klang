#include <stdlib.h>
#include <string.h>

void* __fastcall SynthMalloc(int size) { return malloc(size); }
void __fastcall SynthFree(void* ptr) {
	// lol crashes free(ptr);
}
void __fastcall SynthDeferredFree() {}
void __fastcall SynthMemSet(void* ptr, int size, int value) { memset(ptr, value, size); }
void __fastcall SynthMemCopy(void* dst, void* src, int s) { memcpy(dst, src, s); }

