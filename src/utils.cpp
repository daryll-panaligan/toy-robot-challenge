#include <string>
#include <iostream>
#include "utils.h"

std::string dirToString(eDirection e)
{
    switch (e)
    {
    case NORTH:
        return "NORTH";
    case EAST:
        return "EAST";
    case SOUTH:
        return "SOUTH";
    case WEST:
        return "WEST";
    }

    // fall through
    return "INVALID";
}
