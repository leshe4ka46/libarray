#ifndef _LIB_ARRAY_
#define _LIB_ARRAY_
#include <inttypes.h>
#include <string.h>
#define _ARR_TYPE ARR_TYPE
#define arr_func(name,argtype) arr_ ## name ## _ ## argtype
#define func(...) arr_func(__VA_ARGS__)

void func(write_len, _ARR_TYPE)(_ARR_TYPE *, uint64_t);
uint64_t func(get_len, _ARR_TYPE)(_ARR_TYPE *);
_ARR_TYPE *func(init, _ARR_TYPE)(uint64_t);
void func(print, _ARR_TYPE)(_ARR_TYPE *);
void func(pub, _ARR_TYPE)(_ARR_TYPE **, uint64_t);
void func(puf, _ARR_TYPE)(_ARR_TYPE **, uint64_t);
void func(swap, _ARR_TYPE)(_ARR_TYPE *, uint64_t, uint64_t);
_ARR_TYPE *func(slice, _ARR_TYPE)(_ARR_TYPE *, uint64_t, uint64_t);
_ARR_TYPE *func(concat, _ARR_TYPE)(_ARR_TYPE *, _ARR_TYPE *);
#include "array.c"
#endif /* _LIB_ARRAY_ */