#pragma once

#include "robot.h"
#include "table.h"
#include <iostream>

const int TABLE_HEIGHT = 5;
const int TABLE_WIDTH = 5;

class TestingRobot
{
protected:
    TestingRobot()
    {
        robot = std::make_shared<Robot>();
    }
    std::shared_ptr<Robot> robot;
};

class TestingTable
{
protected:
    TestingTable()
    {
        table = std::make_shared<Table>(TABLE_HEIGHT, TABLE_WIDTH);
    }
    std::shared_ptr<Table> table;
};

std::string toReport(int x, int y, eDirection dir);
