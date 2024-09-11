#include "robot.h"
#include <format>

void Robot::place(int x, int y, eDirection dir)
{
    m_coordinates = {x, y};
    m_dir = dir;
}

std::string Robot::report()
{
    return std::format("{},{},{}", m_coordinates.first, m_coordinates.second, dirToString(m_dir));
}

void Robot::move()
{
}

void Robot::left()
{
}

void Robot::right()
{
}
