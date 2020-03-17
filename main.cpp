

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
    auto it = equation.begin();
    std::cout<<"Write equation: ";
    getline(std::cin,equation); 
    std::cout << equation << std::endl;
    std::remove_if(equation.begin(),equation.end(),[&equation, &it](char a){
        it++;
        std::cout << *it << std::endl;
        return a=='a';
    });
    std::cout << equation << std::endl;
    
    return 0;
}

