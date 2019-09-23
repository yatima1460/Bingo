#pragma once

#include <stdexcept>

class BingoException : std::runtime_error
{

protected:
    explicit BingoException(const std::string& arg) : runtime_error(arg)
    {

    }
};