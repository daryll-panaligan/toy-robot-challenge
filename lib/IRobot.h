#ifndef TOYROBOT_INCLUDE_IROBOT_H_
#define TOYROBOT_INCLUDE_IROBOT_H_

#include <string>
#include "utils.h"
#include "table.h"

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

#endif // TOYROBOT_INCLUDE_IROBOT_H_
