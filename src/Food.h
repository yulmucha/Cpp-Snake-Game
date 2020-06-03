#pragma once

class Food
{
public:
    int GetX() const { return mX; }
    int GetY() const { return mY; }
    void SetX(const int x) { mX = x; }
    void SetY(const int y) { mY = y; }

private:
    int mX;
    int mY;
};