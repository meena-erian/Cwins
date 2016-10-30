#include "StringFormating.h"
#include <iostream>


int main()
{
    //Example 1
    int x=2, y=3;
    std::string s = STR+"(" + x + "+" + y + ")*4 = " + (x+y)*4;
    std::cout<<s<<std::endl;
    std::cin.get();//result is "(2+3)*4 = 20"

    //Example 2
    std::cout<< str+"Hello World World" - "Wor" <<std::endl;
    std::cin.get();//result is "Hello ld World"

    s = "Hello World";
    //Example 3
    std::cout<< s - 'l'; //result is "Helo World"
    std::cin.get();

    //Example 4
    std::cout<< s*3; //result is "Hello WorldHello WorldHello World"
    std::cin.get();

    //Example 5
    std::cout<< !s; //result is "dlroW olleH"
    std::cin.get();

    //Example 6
    std::cout<< ++s + --s; //result is "HELLO WORLDhello world"
    std::cin.get();

    //Example 7
    std::string result = s << 3;
    std::cout<<result<<std::endl; //result is "Hello Wo" (removed the last 3 characters)
    std::cout<<(2>>s<<3)<<std::endl; //result is "llo Wo" (removed the last 3 characters and the first 2)
    std::string FirstWord;
    FirstWord<<s; //removes the first word in s and adds it to FirstWord
    std::cout<<FirstWord<<'\n'<<s<<'\n';
    std::cin.get();
}
