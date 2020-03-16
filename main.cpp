

#include <iostream>
//#include <conio.h>
#include <string>

#include "String_Correction.hpp"
#include "Structs.hpp"

using namespace std;

int fromstringtostruct(Jumper &L, string &);
void cleanerstring(string &);




int main()
{
    cout<< "Opcjonalnie, ONP jest wlaczaoce"<<endl;
    Jumper Jump;
    E1ist *** wsk;
    string rownanie;

        while(true)
        {
            cout<<"Napisz Rowananie do rozwiazania: ";

            getline(cin,rownanie);
            cleanerstring(rownanie);

            Jumper Jump;
            l_init(Jump);

            int temp= fromstringtostruct(Jump, rownanie);
            result(wsk,Jump,temp);
    // l_pritln1 (Jump );
    //for(int i=0;i <=temp ;i++)  l_pop_front(Jump);
    // l_remove(Jump,Jump.head->next->next);
    // l_pritln1 (Jump);

    }while(true);
    return 0;
}
void cleanerstring(string &a)
{
    for(int i=0;i<a.length();i++)
    {
       if((a[i]==')') || (a[i]==']') || (a[i]=='}') || (a[i]=='>'))  a[i]=')';
       if((a[i]=='(') || (a[i]=='[') || (a[i]=='{') || (a[i]=='<'))  a[i]='(' ;

       if((a[i]==',') || (a[i]=='.')) a[i]=',';
       if(((checknumber(a[i])) || (checkchar(a[i])))== false)
       {
           a.erase(i,1);
           i--;
       };
    };
}
int fromstringtostruct(Jumper &L, string &text)
{
   float number, befdot=0 , afdot=0 ; bool test =false;
   int a=1;
   for(int i=0;i<text.length();i++)
    {
        if(checkchar(text[i]) && (text[i])!=',')
        {
            test=false;
            befdot=0;
            afdot=0;
            a=1;

            switch(text[i])
            {
                case '+':   l_push_back(L,text[i],0,2); break;
                case '-':   l_push_back(L,text[i],0,2); break;
                case '*':   l_push_back(L,text[i],0,3); break;
                case '/':   l_push_back(L,text[i],0,3); break;
                case '^':   l_push_back(L,text[i],0,4); break;
                case '(':   l_push_back(L,text[i],0,1,true); break;
                case ')':   l_push_back(L,text[i],0,20); break;
            }
        }else
        {
            if(text[i]== ',') {test=true; continue;}
            else{};
            if(test == false) {befdot = befdot*10 + (fromchartoint(text[i]));/*cout << "test2 ";*/ }
            else
            {
                afdot = afdot + (fromchartoint(text[i])) / (exponentiation(a));
                a++;
            }
            if((checknumber(text[i+1]) == false) && (i<=text.length()) && (text[i+1])!=',')
            {
                        number=afdot+befdot;
                        l_push_back(L,0,number,1);
            }

        }
    }
    return L.count;
}

