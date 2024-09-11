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
    // Counterclockwise movement
    switch (m_dir)
    {
    case NORTH:
        m_dir = eDirection::WEST;
        break;
    case WEST:
        m_dir = eDirection::SOUTH;
        break;
    case SOUTH:
        m_dir = eDirection::EAST;
        break;
    case EAST:
        m_dir = eDirection::NORTH;
        break;
    }
}

void Robot::right()
{
    // Clockwise movement
    switch (m_dir)
    {
    case NORTH:
        m_dir = eDirection::EAST;
        break;
    case EAST:
        m_dir = eDirection::SOUTH;
        break;
    case SOUTH:
        m_dir = eDirection::WEST;
        break;
    case WEST:
        m_dir = eDirection::NORTH;
        break;
    }
}
