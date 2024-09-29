#include <stdio.h>
#include <assert.h>
#include<ctype.h>
#include<stdlib.h>
#include <stddef.h>
typedef double stack_elem_t;

struct stk_t
{
    stack_elem_t* data;
    size_t size;
    size_t capacity;
};

int Push_Stack(struct stk_t *stk, stack_elem_t pushed_element);
int Pop(struct stk_t *stk);
int Init_Stack(stk_t* stk);
int Dump_Stack(stk_t* stk);
int Dtor_Stack(stk_t* stk);