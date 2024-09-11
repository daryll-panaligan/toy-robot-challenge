#include <string>
#include <iostream>
#include "utils.h"

std::string dirToString(eDirection e)
{
    switch (e)
    {
    case SOUTH:
        return "SOUTH";
    case WEST:
        return "WEST";
    case NORTH:
        return "NORTH";
    case EAST:
        return "EAST";
    }
    std::cout << "TWAT" << e;
    // fall through
    return "INVALID";
}
