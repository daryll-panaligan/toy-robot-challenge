#ifndef TOYROBOT_INCLUDE_ROBOT_H_
#define TOYROBOT_INCLUDE_ROBOT_H_

#include <utility>
#include <string>
#include "utils.h"

class Robot
{
private:
    int m_x = -1;
    int m_y = -1;
    eDirection m_dir;
    std::string dirString(eDirection e);

public:
    void place(int x, int y, eDirection dir);
    std::string report();

    void move();
    void left();
    void right();
};

#endif // TOYROBOT_INCLUDE_ROBOT_H_
