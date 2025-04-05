#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <thread>

static unsigned long long UPPER_BOUND = 5*1e11;
static int NUM_THREADS = 15;

bool VerifyMagic(unsigned long long currentCount, unsigned long long upperBound)
{
    // unsigned long long startingCount = currentCount;
    for(currentCount; currentCount <= upperBound; ++currentCount)
    {
        if(currentCount == upperBound)
            break;
        unsigned long long manipulatedCount = currentCount;
        while(manipulatedCount != 1)
        {
            if(manipulatedCount % 2 == 0)
                manipulatedCount >>= 1;
            else
            {
                manipulatedCount = manipulatedCount * 3 + 1;
                manipulatedCount >>= 1;
            }

            // RESTRICTIVE CONDITION -->  if(currentCount > manipulatedCount && manipulatedCount >= startingCount)
            if(currentCount > manipulatedCount)
                break;
        }
    }
    return true;
}

int main() {
    std::cout << "Testing numbers from 1 to " << UPPER_BOUND << "\nTesting...\n";
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> threads;
    
    // Assign Tests
    for(int i = 0; i < NUM_THREADS; ++i)
        threads.emplace_back(VerifyMagic, UPPER_BOUND/NUM_THREADS*i+1, UPPER_BOUND/NUM_THREADS*(i+1));

    // Stop code until threads are done
    for (std::thread& th : threads) {
        th.join();
    }

    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() / 1e3;
    std::cout << std::fixed << std::setprecision(3) << "The test took approximately " << duration << " seconds";
}