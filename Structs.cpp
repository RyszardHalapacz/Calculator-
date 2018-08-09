
#include"Structs.h"
#include <iostream>
#include <conio.h>
using namespace std;



void l_init(Jumper & L)
{
  L.head  = L.tail  = NULL;
  L.count = 0;
}

void l_pop_front(Jumper & L)
{
  if(L.count) l_remove(L,L.head);
}

void l_remove(Jumper & L, E1ist * e)
{
  L.count--;
  if(e->prev) e->prev->next = e->next;
  else        L.head = e->next;
  if(e->next) e->next->prev = e->prev;
  else        L.tail = e->prev;
  delete e;
}

void l_pritln1 (Jumper & L)
{
    E1ist *p;
    p=L.head;
    while(p)
    {
        switch(p->weight)
        {
            case 1 :  if (p->bracket == true )
                      {
                          cout <<" " << p->oper; p = p->next; break;
                      }
                       else cout <<" " << p->num; p = p->next; break;
            case 2 :  cout <<" " << p->oper; p = p->next; break;
            case 3 :  cout <<" " << p->oper; p = p->next; break;
            case 4 :  cout <<" " << p->oper; p = p->next; break;
            case 10 : cout <<" " << p->oper; p = p->next; break;
        }
    }
}

void l_push_back( Jumper &L, char z, float number, int weig, bool true_false )
{
    E1ist *onemore;
    onemore = new E1ist;
    onemore -> oper = z;
    onemore -> num = number;
    onemore -> weight = weig;
    onemore -> bracket = true_false;

    onemore->prev = L.tail;
    onemore->next = NULL;

    L.tail = onemore;
    L.count++;
    if(onemore->prev) onemore->prev->next = onemore;
    else L.head =onemore;
}

void result (  E1ist ***&wsk, Jumper & L,int Length_equat)
{
        cout<<" Rozpoczecie ONP "<< endl;
        E1ist *p;
        wsk = new E1ist **[2];
        wsk[0]= new E1ist *[Length_equat];
        wsk[1]= new E1ist *[Length_equat];
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<Length_equat;j++)
            {
                wsk[i][j]=  new E1ist;
                wsk[i][j]->weight=0;
            }
        }
            p=L.head;
            int i=0,j=0;
            while(p)
            {
                if(p->weight==1 && p->bracket== false)
                {
                    wsk[0][i++]=p;
                    p=p->next;
                }else
                    switch(p->weight)
                    {

                        case 2 :
                        case 3 :
                        case 4 :        //if(!(j==0 || p->weight > wsk[1][j]->weight))
                                        while(j)
                                        {
                                            if( p->weight <= wsk[1][j-1]->weight)
                                            wsk[0][i++]=wsk[1][--j];
                                            else break;
                                        }

                                        wsk[1][j++]=p;
                                        p=p->next;
                                        break;
                        case 1:         wsk[1][j++]=p;
                                        p=p->next;
                                        break;
                        case 20:        while (wsk[1][j-1]->bracket!=true)
                                        {
                                             wsk[0][i++]=wsk[1][--j];
                                        }
                                        j--;cout<<"XXXX";
                                        p=p->next;
                                        break;
                    }
            }
                while(j>=0)
                {
                    wsk[0][i++]=wsk[1][j--];
                }

        for(int i=0;i<=Length_equat-1;i++)
            {
                switch(wsk[0][i]->weight)
                {

                    case 1:
                                if(wsk[0][i]->bracket != true)
                                {
                                    cout<<" "<<wsk[0][i]->num; break;
                                }
                                if(wsk[0][i]->bracket == true)
                                {
                                    cout<<" "<<wsk[0][i]->oper; break;
                                }
                    case 2: cout<<"  "<<wsk[0][i]->oper; break;
                    case 3: cout<<"  "<<wsk[0][i]->oper; break;
                    case 4: cout<<"  "<<wsk[0][i]->oper; break;
                }
            }
            cout<<endl<< "koniec ONP"<< endl;
           int ending= i-1;
            i=j=0;
            for( int i=0 ; i <= ending ;i++)
            {
                 if(wsk[0][i]->oper == '(')  continue;
                 if( wsk[0][i]->weight == 1 && wsk[0][i]->bracket == false)
                {
                    wsk[1][j++]=wsk[0][i];
                }
                else
                {   if(wsk[0][i]->oper == '('){i++; continue;}
                    else switch(wsk[0][i]->oper)
                    {
                        case '+':   wsk[1][j-2]->num = wsk[1][j-2]->num + wsk[1][j-1]->num;j--; break;
                        case '-':   wsk[1][j-2]->num = wsk[1][j-2]->num - wsk[1][j-1]->num;j--; break;
                        case '*':   wsk[1][j-2]->num = wsk[1][j-2]->num * wsk[1][j-1]->num;j--; break;
                        case '/':   wsk[1][j-2]->num = wsk[1][j-2]->num /  wsk[1][j-1]->num;j--; break;
                    //    case '^':  int z = *(wsk[1][j-1]->num);
                    //                wsk[1][j-2]->num = wsk[1][j-2]->num  ^  z;j--; break;
                    }
                }
            }
            cout<<endl<<endl<<"Wynik    : "<<wsk[1][j-1]->num<< endl;

        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<Length_equat;j++)
            {
              delete  wsk[i][j];
            }
        }

        delete  wsk[0];
        delete  wsk[1];
        delete  wsk;








}









