#pragma once

class Table
{
private:
    int m_width;
    int m_height;

public:
    Table(int width, int height);
    bool isWithinBounds(int x, int y) const;
    int getWidth() const;
    int getHeight() const;

    void printDimensions() const;
};
