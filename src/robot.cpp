#include "robot.h"
#include <format>

void Robot::place(int x, int y, eDirection dir, std::shared_ptr<Table> const &table)
{
    if (table->isWithinBounds(x, y))
    {
        m_x = x;
        m_y = y;
        m_dir = dir;
        m_pTable = table;
    }
    else
    {
        // do nothing. maybe add logs later
    }
}

std::string Robot::report() const
{
    return std::format("{},{},{}", m_x, m_y, dirToString(m_dir));
}

void Robot::move()
{
    switch (m_dir)
    {
    case eDirection::NORTH:
        ++m_y;
        break;
    case eDirection::SOUTH:
        --m_y;
        break;
    case eDirection::EAST:
        ++m_x;
        break;
    case eDirection::WEST:
        --m_x;
        break;
    }
}

void Robot::left()
{
    m_dir = static_cast<eDirection>((static_cast<int>(m_dir) + (eDirection::SIZE - 1)) % eDirection::SIZE);
}

void Robot::right()
{
    m_dir = static_cast<eDirection>((static_cast<int>(m_dir) + 1) % eDirection::SIZE);
}
