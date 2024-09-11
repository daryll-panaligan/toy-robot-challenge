#ifndef TOYROBOT_INCLUDE_UTILS_H_
#define TOYROBOT_INCLUDE_UTILS_H_

enum eDirection
{
    // arranged in clockwise order
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
};

std::string dirToString(eDirection e);

#endif // TOYROBOT_INCLUDE_UTILS_H_
