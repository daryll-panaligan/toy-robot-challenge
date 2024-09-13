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

eDirection const stringToDir(std::string dirString)
{
    if (dirString == "NORTH")
    {
        return eDirection::NORTH;
    }
    else if (dirString == "EAST")
    {
        return eDirection::EAST;
    }
    else if (dirString == "SOUTH")
    {
        return eDirection::SOUTH;
    }
    else if (dirString == "WEST")
    {
        return eDirection::WEST;
    }

    return eDirection::SIZE;
}
