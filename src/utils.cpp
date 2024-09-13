#include <string>
#include <iostream>
#include "utils.h"

std::string const dirToString(eDirection e)
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

    return "INVALID";
}
