// SlaveApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

int main()
{
    const std::vector<std::string> vocabulary{
          "zero"
        , "one"
        , "two"
        , "three"
        , "four"
        , "five"
        , "six"
        , "seven"
        , "eight"
        , "nine"
        , "ten"
    };

    const std::chrono::duration<double, std::milli> timeout(1000);
    
    int c = 0;
    for(; c < 10; ++c)
    {
        std::cout << c << ".  " << vocabulary[c] << std::endl;
        std::this_thread::sleep_for(timeout);
    }
    std::cout << c << ". " << vocabulary[c] << std::endl;

    return 0;
}
