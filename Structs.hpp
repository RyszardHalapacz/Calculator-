# pragma once
#include <string>

struct E1ist
{
    E1ist *next, *prev;
    float num;
    int  weight;
    char oper;
    bool bracket;
};
struct Jumper
{
    E1ist * head, *tail;
    unsigned int  count ;
};
void l_push_back( Jumper &, char , float , int , bool = false);
void l_pritln1 (Jumper & );
void l_init(Jumper & );
void result (  E1ist ***&wsk,Jumper &L,int size_array);

void l_remove(Jumper & L, E1ist * e);
void l_pop_front(Jumper & L);

