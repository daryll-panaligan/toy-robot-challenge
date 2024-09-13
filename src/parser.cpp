#include "parser.h"
#include <string>
#include "utils.h"
#include <regex>
void Parser::parseCommand(std::shared_ptr<Table> const &table, std::shared_ptr<IRobot> const &robot, std::string const &command) const
{
    if (command.find("PLACE") == 0)
    {
        std::regex re("PLACE (\\d+),(\\d+),(NORTH|SOUTH|EAST|WEST)$");

        std::smatch match;
        if (std::regex_search(command, match, re))
        {
            int x = std::stoi(match.str(1));
            int y = std::stoi(match.str(2));
            eDirection dir = stringToDir(match.str(3));
            if (eDirection::SIZE == dir)
            {
                // invalid string in case the regex fails for some reason
                return;
            }
            robot->place(x, y, dir, table);
        }
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
