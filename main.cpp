#include "time.h"

int main() {
    Time currentTime(12, 30, 45);

    std::cout << "Current Time: " << currentTime << std::endl;

    ++currentTime;  
    std::cout << "Time after increment: " << currentTime << std::endl;

    Time newTime = currentTime + 5;  
    std::cout << "Time after adding 5 seconds: " << newTime << std::endl;

    return 0;
}
