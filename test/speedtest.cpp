#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <chrono>
 
volatile int sink;
int main()
{
    std::cout << std::fixed << std::setprecision(9) << std::left;
    for (auto size = 1ull; size <= 1000'000'000ull; size *= 10) {
        // record start time
        auto start = std::chrono::steady_clock::now();
        // do some work
        for (int i = 1; i <= size; i++) {
            int p = 1145141919810LL / 1919810;
        }
        // record end time
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Time to fill and iterate a vector of " << std::setw(9)
                  << size << " ints : " << diff.count() << " s\n";
    }
}