#include "fixtures.h"
#include <format>
std::string toReport(int x, int y, eDirection dir)
{
    return std::format("{},{},{}", x, y, dirToString(dir));
}
