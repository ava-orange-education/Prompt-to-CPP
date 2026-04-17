// main.cpp
// This file serves as the entry point for the zoo application.
// It creates instances of different animals and displays their information and sounds.
#include "animal.h"
#include <iostream>

int main()
{
    Lion lion("Leo");
    Elephant elephant("Ella");
    Parrot parrot("Polly");

    std::cout << "Welcome to the Zoo!" << std::endl << std::endl;

    lion.displayInfo();
    lion.speak();
    std::cout << std::endl;

    elephant.displayInfo();
    elephant.speak();
    std::cout << std::endl;

    parrot.displayInfo();
    parrot.speak();
    std::cout << std::endl;

    return 0;
}
