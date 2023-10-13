#include <stdio.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#define ARR_TYPE uint8_t
#include "./array/array.h"
ARR_TYPE *arr;
ARR_TYPE *arr_to_insert;
int main()
{

    //my_uint64_t_arr=(uint64_t *)calloc(sizeof(uint64_t),10)+1;
    //my_uint64_t_arr[-1]=9;
    //my_uint64_t_arr[5]=6;
    arr=func(init,_ARR_TYPE)(0);
    printf("%ld\n",func(get_len,_ARR_TYPE)(arr));
    func(pub,_ARR_TYPE)(&arr,1);
    func(pub,_ARR_TYPE)(&arr,2);
    func(pub,_ARR_TYPE)(&arr,3);
    func(pub,_ARR_TYPE)(&arr,4);
    func(pub,_ARR_TYPE)(&arr,5);
    func(insert,_ARR_TYPE)(&arr,1,9);
    func(print,_ARR_TYPE)(arr);
    arr_to_insert=func(init,_ARR_TYPE)(3);
    arr_to_insert[0]=55;
    arr_to_insert[1]=56;
    arr_to_insert[2]=57;
    func(insert_arr,_ARR_TYPE)(&arr,2,arr_to_insert);
    func(print,_ARR_TYPE)(arr);

}