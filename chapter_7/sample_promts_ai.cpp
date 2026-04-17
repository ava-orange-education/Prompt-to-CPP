// function that takes a shared_ptr<string> by const reference and prints it
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

void printString(const std::shared_ptr<std::string> &pStr)
{
    if (pStr)
    {
        std::cout << *pStr << '\n';
    }
    else
    {
        std::cout << "Null string pointer\n";
    }
}