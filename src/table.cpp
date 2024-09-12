#include "table.h"
#include <iostream>
Table::Table(int sizeX, int sizeY)
{
    m_xLimit = sizeX;
    m_yLimit = sizeY;
}
bool Table::isWithinBounds(int x, int y) const
{
    return ((x >= 0) && (x < m_xLimit)) && ((y >= 0) && (y < m_yLimit));
}

void Table::printCoord() const
{
    std::cout << "m_xLimit: " << m_xLimit << "| m_yLimit: " << m_yLimit;
    std::cout << "\n";
}
