#include "Timer.h"

Timer::~Timer() {
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << std::dec << elapsed_seconds.count() << "s"
        << std::endl;
}
