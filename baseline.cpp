#include <iostream>
#include <iomanip>
#include <chrono>

static unsigned long long UPPER_BOUND = 5*1e10;

int main() {
    std::cout << "Testing numbers from 1 to " << UPPER_BOUND << "\nTesting...\n";
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Test
    for(unsigned long long currentCount = 1; currentCount <= UPPER_BOUND; currentCount++)
    {
        unsigned long long manipulatedCount = currentCount;
        while(manipulatedCount != 1)
        {
            if(manipulatedCount % 2 == 0)
                manipulatedCount /= 2;
            else
            {
                manipulatedCount = manipulatedCount * 3 + 1;
                manipulatedCount /= 2;
            }

            // Numbers below currentCount have already been proved to be magic
            if(currentCount > manipulatedCount)
                break;
        }
    }

    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() / 1e3;
    std::cout << std::fixed << std::setprecision(3) << "The test took approximately " << duration << " seconds";
}