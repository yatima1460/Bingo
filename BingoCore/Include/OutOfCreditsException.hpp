#pragma once

#include "BingoException.hpp"


class OutOfCreditsException : BingoException
{

public:
    OutOfCreditsException() : BingoException("PlayerRef is out of Credits")
    {

    }
};