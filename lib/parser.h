#pragma once

#include "robot.h"
#include "table.h"
#include <iostream>

class Parser
{
public:
    void parseCommand(std::shared_ptr<Table> const &table, std::shared_ptr<IRobot> const &robot, std::string const &command) const;
};
