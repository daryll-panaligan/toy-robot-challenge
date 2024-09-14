#pragma once

#include "table.h"
#include "IRobot.h"
#include "utils.h"

class Robot : public IRobot
{
private:
    int m_x;
    int m_y;
    eDirection m_dir;
    std::shared_ptr<Table> m_pTable;

public:
    Robot() : m_x(-1),
              m_y(-1),
              m_dir(eDirection::SIZE),
              m_pTable(nullptr)
    {
    }
    void place(int x, int y, eDirection dir, std::shared_ptr<Table> const &table);
    std::string report() const;
    bool isPlaced() const;
    void move();
    void left();
    void right();
};
