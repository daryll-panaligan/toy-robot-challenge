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

bool Robot::isPlaced() const
{
    return (m_pTable != nullptr);
}

std::string Robot::report() const
{
    if (isPlaced())
    {
        return std::format("{},{},{}", m_x, m_y, dirToString(m_dir));
    }
    else
    {
        return "INVALID";
    }
}

void Robot::move()
{
    int new_x = m_x;
    int new_y = m_y;
    switch (m_dir)
    {
    case eDirection::NORTH:
        new_y = m_y + 1;
        break;
    case eDirection::SOUTH:
        new_y = m_y - 1;
        break;
    case eDirection::EAST:
        new_x = m_x + 1;
        break;
    case eDirection::WEST:
        new_x = m_x - 1;
        break;
    }

    if (m_pTable->isWithinBounds(new_x, new_y))
    {
        m_x = new_x;
        m_y = new_y;
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
