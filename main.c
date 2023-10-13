#include <stdio.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#define ARR_TYPE uint64_t
#include "./array/array.h"

ARR_TYPE *arr_to_insert;

int main()
{
    ARR_TYPE *arr=func(init,_ARR_TYPE)(2);
    func(pub,_ARR_TYPE)(&arr,3);
    func(pub,_ARR_TYPE)(&arr,4);
    func(pub,_ARR_TYPE)(&arr,5);
    func(puf,_ARR_TYPE)(&arr,3);
    func(puf,_ARR_TYPE)(&arr,2);
    func(puf,_ARR_TYPE)(&arr,3);
    func(print,_ARR_TYPE)(arr);
    
    func(insert,_ARR_TYPE)(&arr,5,95);
    func(print,_ARR_TYPE)(arr);

    arr_to_insert=func(init,_ARR_TYPE)(3);
    arr_to_insert[0]=55;
    arr_to_insert[1]=56;
    arr_to_insert[2]=57;
    func(insert_arr,_ARR_TYPE)(&arr,5,arr_to_insert);
    func(print,_ARR_TYPE)(arr);

    func(swap,_ARR_TYPE)(arr,1,2);
    func(print,_ARR_TYPE)(arr);
    ARR_TYPE*slice=func(slice,_ARR_TYPE)(arr,1,5);
    func(print,_ARR_TYPE)(slice);

    _ARR_TYPE *concated=func(concat, _ARR_TYPE)(arr,arr);
    func(print,_ARR_TYPE)(concated);

}