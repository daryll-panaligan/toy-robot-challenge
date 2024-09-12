#ifndef TOYROBOT_INCLUDE_TABLE_H_
#define TOYROBOT_INCLUDE_TABLE_H_

class Table
{
private:
    int m_width;
    int m_height;

public:
    Table(int width, int height);
    bool isWithinBounds(int x, int y) const;
    void printCoord() const;

    int getWidth() const;
    int getHeight() const;
};

#endif // TOYROBOT_INCLUDE_TABLE_H_
