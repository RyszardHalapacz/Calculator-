
#include"String_Correction.hpp"


int fromchartoint(char text_mark )
 {
     switch(text_mark)
     {
         case '0': return 0;
         case '1': return 1;
         case '2': return 2;
         case '3': return 3;
         case '4': return 4;
         case '5': return 5;
         case '6': return 6;
         case '7': return 7;
         case '8': return 8;
         case '9': return 9;
     }
 }
float exponentiation (int a)
{
    int  b=10;
    for (int i=1; i<a; i++)
    {
        b=b*10;
    };
    return b;
}
bool checknumber(char text_mark)
{
    if((text_mark>='0') && (text_mark<='9')) return true;
    else return false;
}
bool checkchar(char text_mark)
{
    if((text_mark=='+') || (text_mark=='-') || (text_mark=='*') || (text_mark=='/') ||(text_mark=='(') || (text_mark==')') || (text_mark == ',') || (text_mark=='^')) return true;
    else return false;
}

