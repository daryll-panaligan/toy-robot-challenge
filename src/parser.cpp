#include "parser.h"
#include <string>
#include "utils.h"

void Parser::parseCommand(std::shared_ptr<Table> const &table, std::shared_ptr<IRobot> const &robot, std::string const &command) const
{
    if (command.find("PLACE") == 0)
    {
        int x = 0;
        int y = 0;
        eDirection dir = eDirection::SOUTH;
        robot->place(0, 0, eDirection::SOUTH, table);
    }
    else if (robot->isPlaced())
    {
        if ("MOVE" == command)
        {
            robot->move();
        }
        else if ("LEFT" == command)
        {
            robot->left();
        }
        else if ("RIGHT" == command)
        {
            robot->right();
        }
        else if ("REPORT" == command)
        {
            robot->report();
        }
    }
    else
    {
        return; // robot isn't on the table, ignore.
    }
}
