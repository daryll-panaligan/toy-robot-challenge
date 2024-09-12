#ifndef TOYROBOT_INCLUDE_TABLE_H_
#define TOYROBOT_INCLUDE_TABLE_H_

class Table
{
private:
    int m_xLimit;
    int m_yLimit;

public:
    Table(int xLimit, int yLimit);
    bool isWithinBounds(int x, int y) const;
    void printCoord() const;
};

#endif // TOYROBOT_INCLUDE_TABLE_H_
