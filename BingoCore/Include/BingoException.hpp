#pragma once
#include <stdexcept>

class BingoException : std::runtime_error
{

protected:
    BingoException(const std::string &arg) : runtime_error(arg)
    {

    }
};