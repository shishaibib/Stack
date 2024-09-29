#include "HeaderData.h"

int Init_Stack(stk_t* stk)
{
    stk -> capacity = 16;
    stk -> data = (stack_elem_t *)calloc(stk -> capacity, sizeof(stack_elem_t));
    stk -> size = 0;
    return 0;
}

int Dtor_Stack(stk_t* stk)
{
    stk -> size = 0;
    stk -> capacity = 0; 
    free(stk -> data);                                     
    return 0;
}     

int Push_Stack(struct stk_t *stk, stack_elem_t pushed_element)          
{
    printf("New element: %lg \n", pushed_element);
    stk -> data[stk -> size] = pushed_element;
    stk -> size ++;
    return 0;

}

int Pop(struct stk_t *stk)
{
    printf("size before pop = %d \n",stk -> size);
    stk -> data[stk -> size] = 0;
    stk -> size --;
    return 0;  
}
