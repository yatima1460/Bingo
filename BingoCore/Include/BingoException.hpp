#pragma once

#include <stdexcept>

class BingoException : std::runtime_error
{

protected:
    explicit BingoException(const char* arg) : runtime_error(arg)
    {

    }
};