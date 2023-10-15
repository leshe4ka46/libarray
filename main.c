#include <stdio.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#define ARR_TYPE uint64_t
#include "./array/array.h"
ARR_TYPE *arr;
ARR_TYPE *arr_to_insert;

int main()
{
    arr=func(init,ARR_TYPE)(0);
    func(pub,ARR_TYPE)(&arr,3);
    func(pub,ARR_TYPE)(&arr,4);
    func(pub,ARR_TYPE)(&arr,5);
    func(puf,ARR_TYPE)(&arr,2);
    func(puf,ARR_TYPE)(&arr,1);
    func(print,ARR_TYPE)(arr);

    func(insert,ARR_TYPE)(&arr,3,95);
    func(print,ARR_TYPE)(arr);

    arr_to_insert=func(init,ARR_TYPE)(3);
    arr_to_insert[0]=55;
    arr_to_insert[1]=56;
    arr_to_insert[2]=57;
    func(insert_arr,ARR_TYPE)(&arr,3,arr_to_insert);
    func(print,ARR_TYPE)(arr);

    func(swap,ARR_TYPE)(arr,1,2);
    func(print,ARR_TYPE)(arr);
    ARR_TYPE*slice=func(slice,ARR_TYPE)(arr,1,5);
    func(print,ARR_TYPE)(slice);

    ARR_TYPE *concated=func(concat, ARR_TYPE)(arr,arr);
    func(print,ARR_TYPE)(concated);

}