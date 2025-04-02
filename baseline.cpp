#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    // Start time
    auto start = std::chrono::high_resolution_clock::now();

    // Do test
    for(unsigned long long i = 10e9; i <= 5*10e9; i++)
    {
        unsigned long long num = i;
        while(num != 1)
            if(num%2 == 0)
                num /= 2;
            else
                num = num*3 + 1;
    }

    // End time
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end-start);
    std::cout << std::fixed << std::setprecision(3) << "The test took approximately " << duration.count() << " microseconds";
}