/*Отче наш, Иже еси на небесе́х!
Да святится имя Твое, да прии́дет Царствие Твое,
да будет воля Твоя, яко на небеси́ и на земли́.
Хлеб наш насущный да́ждь нам дне́сь;
и оста́ви нам до́лги наша, якоже и мы оставляем должнико́м нашим;
и не введи нас во искушение, но изба́ви нас от лукаваго.
Яко Твое есть Царство и сила, и слава, Отца, и Сына, и Святаго Духа,
ныне и присно, и во веки веков. Аминь.*/
#include "HeaderData.h"

int main()        
{                            
    struct stk_t stk = {};
    
    Init_Stack(&stk); 

    Push_Stack(&stk, 100);
    Dump_Stack(&stk);

    Push_Stack(&stk, 200);

    Push_Stack(&stk, 300);
    Dump_Stack(&stk);

    Calculate_Hash(&stk);

    Push_Stack(&stk, 400);
    Dump_Stack(&stk);

    Push_Stack(&stk, 500);
    Dump_Stack(&stk);

    Push_Stack(&stk, 600);
    Dump_Stack(&stk);

    Pop_Stack(&stk);
    Dump_Stack(&stk);

    Dtor_Stack(&stk);
    return 0;
}