#include <string>
#include <iostream>
#include "utils.h"

std::string dirToString(eDirection e)
{
    switch (e)
    {
    case eDirection::NORTH:
        return "NORTH";
    case eDirection::EAST:
        return "EAST";
    case eDirection::SOUTH:
        return "SOUTH";
    case eDirection::WEST:
        return "WEST";
    }

    // fall through
    return "INVALID";
}
