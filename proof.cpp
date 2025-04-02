#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    // Start time
    auto start = std::chrono::high_resolution_clock::now();

    // Do test
    for(int i = 2; i <= 5; i++)
    {
        int num = i;
        while(num != 1)
        {
            if(num%2 == 0)
            {
                std::cout << "number is even:\t" << num << "\n";
                num /= 2;
            }
            else
            {
                std::cout << "number is odd:\t" << num << "\n";
                num = num*3 + 1;
            }
        }
        std::cout << "Magic!\n";
    }

    // End time
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start) / 10e3;
    std::cout << std::fixed << std::setprecision(4) << "The test took approximately " << duration.count() << " microseconds";
}