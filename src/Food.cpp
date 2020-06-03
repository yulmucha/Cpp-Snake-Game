#include "Food.h"

Food::Food()
    : mX(0),
      mY(0),
      mState(EFoodState::Fresh),
      mTime(std::chrono::high_resolution_clock::now())
{
}

void Food::Simulate()
{
    mThread = std::thread(&Food::cycleFood, this);
}

void Food::cycleFood()
{
    constexpr int FRESH_DURATION = 4000;

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        auto t = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t - mTime).count();
        if (duration > FRESH_DURATION)
        {
            std::lock_guard<std::mutex> lck(mMutex);
            mState = EFoodState::Rotten;
        }
    }
}