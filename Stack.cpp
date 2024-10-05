#include "HeaderData.h"

int Init_Stack(stk_t* stk)
{
    stk -> capacity = 4;
    stk -> data = (stack_elem_t *)calloc(stk -> capacity, sizeof(stack_elem_t));
    stk -> size = 0;
    for(int i = 0; i < stk -> capacity; i++)
        stk -> data[i] = POISON_NUMBER;
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
    printf("New element: %d \n", pushed_element);
    stk -> data[stk -> size] = pushed_element;
    stk -> size ++;
    Reallocate_Memory(&stk);
    return 0;

}

int Pop_Stack(struct stk_t *stk)
{
    printf("size before pop = %d \n",stk -> size);
    stk -> data[stk -> size - 1] = POISON_NUMBER;
    stk -> size --;
    return 0;  
}

int Reallocate_Memory(struct stk_t **stk)
{
    if ((*stk) -> size == (*stk) -> capacity)
    {
        size_t new_capacity = (*stk) -> capacity * MEMORY_MULTIPLY_COEFICIENT;

        (*stk) -> data = (stack_elem_t*)realloc((*stk) -> data, new_capacity * sizeof(stack_elem_t));
        (*stk) -> capacity = new_capacity;

        for(int i = (*stk) -> size; i < (*stk) -> capacity; i++)
        {
            (*stk) -> data[i] = POISON_NUMBER;
        }
        
        if ((*stk) -> data == NULL)
        {
            printf("memory reallocation failed");
        }
        
    }

    return 0;            
}

int Calculate_Hash(struct stk_t *stk)
{
    stk -> hash = 5381;
    for(int i = 0; i < stk -> capacity; i++)
    {
       stk -> hash = (stk -> hash) * 31 ^ (stk -> data[i]);/*нет совместимости с даблами из-за ^ сделал костыль - перешёл на инт*/ /*к инту контузить длинно длинно*/
       printf("hash(%d) = %d \n", i, stk -> hash);
    }
    stk -> saved_hash = stk -> hash;
    printf("saved hash = %d \n", stk -> saved_hash);
}

int Dump_Stack (stk_t* stk)
{
    printf("size = %d \n",stk -> size);
    printf ("data[adress : %d] \n", &(stk -> data));
    for(int i = 0; i < stk -> capacity; i++)
        printf("data[%d] = %d \n", i, stk -> data[i]);
}

int My_Assert()
{
    
}

int Compare_Hash(stk_t* stk)
{
    if(stk -> saved_hash != stk ->hash)
    {
        printf("hash error");
        abort();
    }
}