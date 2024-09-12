#include "table.h"
#include <iostream>
Table::Table(int width, int height)
{
    m_width = width;
    m_height = height;
}
bool Table::isWithinBounds(int x, int y) const
{
    return ((x >= 0) && (x < m_width)) && ((y >= 0) && (y < m_height));
}

void Table::printCoord() const
{
    std::cout << "m_width: " << m_width << "| m_height: " << m_height;
    std::cout << "\n";
}

int Table::getWidth() const
{
    return m_width;
}

int Table::getHeight() const
{
    return m_height;
}
