#pragma once

#include "BingoException.hpp"


class OutOfCreditsException : BingoException
{

public:
    OutOfCreditsException() : BingoException("Player is out of Credits")
    {

    }
};