#pragma once

#include <string>

enum eDirection
{
    // arranged in clockwise order
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
    SIZE

    // XXX: Another approach is to declare this as a bitfield and rely on bit shifting to change directions (<< left, >> right).
    //      Can be done later when implementing midpoint directions (north, northeast, east, ...)
};

std::string const dirToString(eDirection e);
eDirection const stringToDir(std::string dirString);
