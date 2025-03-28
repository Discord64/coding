#pragma once
#include <iostream>
#include <chrono>
#include <ctime>

class Timer {
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock>  end;
public:
    Timer() : start(std::chrono::system_clock::now()) {}
    ~Timer();
};
