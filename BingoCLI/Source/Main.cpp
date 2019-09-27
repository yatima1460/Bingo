#include <BingoCLI.hpp>


int main(int argc, char* argv[])
{
    BingoCLI bingoCLI;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true)
    {
        BingoCLI::ClearScreen();
        BingoCLI::PrintLogo();

        bingoCLI.PrintMenu();
    }
#pragma clang diagnostic pop
}