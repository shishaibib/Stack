#include "HeaderData.h"

int Dump_Stack (stk_t* stk)
{
    printf("size = %d \n",stk -> size);
    printf ("data[adress : %d] \n", &(stk -> data));
    for(int i = 0; i < stk -> size; i++)
        printf("data[%d] = %lg \n", i, stk -> data[i]);
}

int My_Assert()
{
    
}





