#pragma once

#include <string>
#include <iostream>

enum eDirection;
class Table;

class IRobot
{
public:
    virtual void place(int x, int y, eDirection dir, std::shared_ptr<Table> const &table) = 0;
    virtual std::string report() const = 0;
    virtual bool isPlaced() const = 0;
    virtual void move() = 0;
    virtual void left() = 0;
    virtual void right() = 0;
};
