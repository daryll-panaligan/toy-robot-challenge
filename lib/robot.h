#ifndef TOYROBOT_INCLUDE_ROBOT_H_
#define TOYROBOT_INCLUDE_ROBOT_H_

#include <utility>
#include <string>
#include <iostream>
#include "utils.h"
#include "table.h"
#include "IRobot.h"

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

#endif // TOYROBOT_INCLUDE_ROBOT_H_
