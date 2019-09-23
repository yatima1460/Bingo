#pragma once


#include "BingoException.hpp"

class EmptyDrumException : BingoException
{

public:
    EmptyDrumException() : BingoException("You can't extract more balls than the ones left in the drum!")
    {

    }
};