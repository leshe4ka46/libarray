#include <stdlib.h>
_ARR_TYPE *func(init, _ARR_TYPE)(uint64_t len)
{
    _ARR_TYPE *arr = (_ARR_TYPE *)calloc(sizeof(_ARR_TYPE), len + sizeof(uint64_t) / sizeof(_ARR_TYPE)) + sizeof(uint64_t) / sizeof(_ARR_TYPE);
    func(write_len, _ARR_TYPE)(arr, len);
    for (uint64_t i = 0; i < len; i++)
    {
        arr[i] = 0;
    }
    return arr;
}
void func(write_len, _ARR_TYPE)(_ARR_TYPE *arr, uint64_t len)
{
    switch (sizeof(_ARR_TYPE))
    {
    case sizeof(uint64_t):
        arr[-1] = len;
        break;
    case sizeof(uint32_t):
        arr[-2] = len >> 32;
        arr[-1] = len & 0xFFFFFFFF;
        break;
    case sizeof(uint16_t):
        arr[-4] = len >> 16 * 3;
        arr[-3] = (len >> 16 * 2) & 0xFFFF;
        arr[-2] = (len >> 16 * 1) & 0xFFFF;
        arr[-1] = (len >> 16 * 0) & 0xFFFF;
        break;
    case sizeof(uint8_t):
        arr[-8] = len >> 8 * 7;
        arr[-7] = (len >> 8 * 6) & 0xFF;
        arr[-6] = (len >> 8 * 5) & 0xFF;
        arr[-5] = (len >> 8 * 4) & 0xFF;
        arr[-4] = (len >> 8 * 3) & 0xFF;
        arr[-3] = (len >> 8 * 2) & 0xFF;
        arr[-2] = (len >> 8 * 1) & 0xFF;
        arr[-1] = (len >> 8 * 0) & 0xFF;
        break;
    }
}
uint64_t func(get_len, _ARR_TYPE)(_ARR_TYPE *arr)
{
#if _ARR_TYPE == uint8_t || _ARR_TYPE == int8_t
    return arr[-1];
#elif _ARR_TYPE == uint16_t || _ARR_TYPE == int16_t
    return arr[-2] << 32 | arr[-1];
#elif _ARR_TYPE == uint32_t || _ARR_TYPE == int32_t
    return arr[-4] << 16 * 3 | arr[-3] << 16 * 2 | arr[-2] << 16 | arr[-1];
#elif _ARR_TYPE == uint64_t || _ARR_TYPE == int64_t
    return arr[-8] << 8 * 7 | arr[-7] << 8 * 6 | arr[-6] << 8 * 5 | arr[-5] << 8 * 4 | arr[-4] << 8 * 3 | arr[-3] << 8 * 2 | arr[-2] << 8 | arr[-1];
#endif
}
void func(print, _ARR_TYPE)(_ARR_TYPE *arr)
{
    for (uint64_t i = 0; i < func(get_len, _ARR_TYPE)(arr); i++)
    {
#if _ARR_TYPE == uint8_t || _ARR_TYPE == int8_t
        printf("%d ", (uint32_t)arr[i]);
#elif _ARR_TYPE == uint16_t || _ARR_TYPE == int16_t
        printf("%d ", (uint32_t)arr[i]);
#elif _ARR_TYPE == uint32_t || _ARR_TYPE == int32_t
        printf("%d ", arr[i]);
#elif _ARR_TYPE == uint64_t || _ARR_TYPE == int64_t
        printf("%ld ", arr[i]);
#endif
    }
    printf("\n");
}
void func(free, _ARR_TYPE)(_ARR_TYPE *arr)
{
    free((void *)(arr - (sizeof(uint64_t) / sizeof(_ARR_TYPE))));
}
void func(pub, _ARR_TYPE)(_ARR_TYPE **arr, uint64_t value)
{
    _ARR_TYPE *tmp = func(init, _ARR_TYPE)(func(get_len, _ARR_TYPE)(*arr) + 1);
    memcpy(tmp, *arr, func(get_len, _ARR_TYPE)(*arr));
    tmp[func(get_len, _ARR_TYPE)(*arr)] = value;
    func(free, _ARR_TYPE)(*arr);
    *arr = tmp;
}

void func(puf, _ARR_TYPE)(_ARR_TYPE **arr, uint64_t value)
{
    _ARR_TYPE *tmp = func(init, _ARR_TYPE)(func(get_len, _ARR_TYPE)(*arr) + 1);
    memcpy(tmp + 1, *arr, func(get_len, _ARR_TYPE)(*arr));
    tmp[0] = value;
    func(free, _ARR_TYPE)(*arr);
    *arr = tmp;
}

/*void func(swap, _ARR_TYPE)(_ARR_TYPE *arr, uint64_t indexA, uint64_t indexB)
{
    indexA%=func(get_len, _ARR_TYPE)(arr);
    indexB%=func(get_len, _ARR_TYPE)(arr);
    arr[indexA]+=arr[indexB];
    arr[indexB]=arr[indexA]-arr[indexB];
    arr[indexA]-=arr[indexB];
}*/

void func(insert, _ARR_TYPE)(_ARR_TYPE **arr, uint64_t index, uint64_t value)
{
    _ARR_TYPE *tmp = func(init, _ARR_TYPE)(func(get_len, _ARR_TYPE)(*arr) + 1);
    memcpy(tmp, *arr, index);
    tmp[index] = value;
    memcpy(tmp+index+1, *arr+index, func(get_len, _ARR_TYPE)(*arr)-index);
    func(free, _ARR_TYPE)(*arr);
    *arr = tmp;
}

void func(insert_arr, _ARR_TYPE)(_ARR_TYPE **arr, uint64_t index, _ARR_TYPE *inserted)
{
    _ARR_TYPE *tmp = func(init, _ARR_TYPE)(func(get_len, _ARR_TYPE)(*arr) + func(get_len, _ARR_TYPE)(inserted));
    memcpy(tmp, *arr, index);
    memcpy(tmp+index, inserted, func(get_len, _ARR_TYPE)(inserted));
    memcpy(tmp+index+func(get_len, _ARR_TYPE)(inserted), *arr+index, func(get_len, _ARR_TYPE)(*arr)-index);
    func(free, _ARR_TYPE)(*arr);
    *arr = tmp;
}