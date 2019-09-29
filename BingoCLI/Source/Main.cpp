#include <BingoCLI.hpp>


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    BingoCLI bingoCLI;


    while (true)
    {
        BingoCLI::ClearScreen();
        BingoCLI::PrintLogo();

        bingoCLI.PrintMenu();
    }

}