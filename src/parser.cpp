#include "parser.h"
#include <string>
#include "utils.h"

void Parser::parseCommand(std::shared_ptr<Table> const &table, std::shared_ptr<Robot> const &robot, std::string const &command) const
{
    if (command.find("PLACE") == 0)
    {
        int x = 0;
        int y = 0;
        eDirection dir = eDirection::SOUTH;
        robot->place(0, 0, eDirection::SOUTH, table);
    }
    else if (true)
    {
        if (command == "MOVE")
        {
            throw "not implemented yet";
        }
        else if (command == "LEFT")
        {
            throw "not implemented yet";
        }
        else if (command == "RIGHT")
        {
            throw "not implemented yet";
        }
        else if (command == "REPORT")
        {
            throw "not implemented yet";
        }
    }
    else
    {
        // robot isn't on the table, ignore.
    }
}
