

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#include "class.hpp"



std::string cleanString (std::string & s)
{   

}


int main()
{
    std::string equation;
    std::cout<<"Write equation: ";
    getline(std::cin,equation); 
    std::cout << equation << std::endl;
    equation.erase(std::remove_if(equation.begin(),equation.end(),[&equation](char a)
    {
        return a=='a';
    }), equation.end());
    std::cout << equation << std::endl;
    
    return 0;
}

