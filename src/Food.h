#pragma once

#include <thread>
#include <mutex>
#include <iostream>

enum class EFoodState
{
    Fresh,
    Rotten
};

class Food
{
public:
    Food();
    int GetX() const { return mX; }
    int GetY() const { return mY; }
    EFoodState GetState() const { return mState; }
    void SetX(const int x) { mX = x; }
    void SetY(const int y) { mY = y; }
    void SetState(EFoodState state) { mState = state; }
    void SetTimeNow() { mTime = std::chrono::high_resolution_clock::now(); }
    void Simulate();

private:
    void cycleFood();
    int mX;
    int mY;
    EFoodState mState;
    std::chrono::_V2::high_resolution_clock::time_point mTime;
    std::thread mThread;
    std::mutex mMutex;
};