

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#include "class.hpp"
#include "other.hpp"


std::string cleanString (std::string & s)
{   

}


int main()
{
    std::string equation;
    std::cout<<"Write equation:" ;
    getline(std::cin,equation); 
    std::cout << equation << std::endl;
    equation.erase(std::remove_if(equation.begin(),equation.end(),[&equation](char char_mark)
    {
        return not check(char_mark);
    }), equation.end());
    std::cout << equation << std::endl;
    
    return 0;
}

