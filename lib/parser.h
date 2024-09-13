#ifndef TOYROBOT_INCLUDE_PARSER_H_
#define TOYROBOT_INCLUDE_PARSER_H_

#include "robot.h"
#include "table.h"
#include <iostream>

class Parser
{
public:
    void parseCommand(std::shared_ptr<Table> const &table, std::shared_ptr<IRobot> const &robot, std::string const &command) const;
};

#endif // TOYROBOT_INCLUDE_PARSER_H_
