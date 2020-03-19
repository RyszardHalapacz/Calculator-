#include "other.hpp"
#pragma once

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
bool check(char text_mark)
{
    return (checkchar(text_mark) || checknumber(text_mark));
}