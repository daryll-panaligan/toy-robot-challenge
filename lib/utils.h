#ifndef TOYROBOT_INCLUDE_UTILS_H_
#define TOYROBOT_INCLUDE_UTILS_H_

enum eDirection
{
    // arranged in clockwise order
    SOUTH = 0,
    WEST,
    NORTH,
    EAST
};

std::string dirToString(eDirection e);

#endif // TOYROBOT_INCLUDE_UTILS_H_
