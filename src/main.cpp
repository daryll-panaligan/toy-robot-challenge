#include <iostream>

#include "parser.h"
#include "robot.h"
#include "table.h"

int main()
{
    const int WIDTH = 5;
    const int HEIGHT = 5;

    std::string input;

    std::shared_ptr<Parser> parser = std::make_shared<Parser>();
    std::shared_ptr<Robot> robot = std::make_shared<Robot>();
    std::shared_ptr<Table> table = std::make_shared<Table>(WIDTH, HEIGHT);

    while (std::getline(std::cin, input))
    {
        parser->parseCommand(table, robot, input);
    }
}
