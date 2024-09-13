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
        if (command == "MOVE")
        {
            robot->move();
        }
        else if (command == "LEFT")
        {
            robot->left();
        }
        else if (command == "RIGHT")
        {
            robot->right();
        }
        else if (command == "REPORT")
        {
            robot->report();
        }
    }
    else
    {
        // robot isn't on the table, ignore.
    }
}
