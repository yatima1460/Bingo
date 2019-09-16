#include <Drum.hpp>
#include <iostream>


int main(int argc, char* argv[])
{

    Drum d(60);


    auto result = d.Extract(30);
    for ( int ball : result)
    {
        std::cout << ball << " ";
    }

}