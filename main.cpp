#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include "pi_calculator.h"

int main() {
    std::vector<long long int> accuracies = {100000000, 1000000000, 3000000000};
    std::ofstream outfile("pi_result.csv", std::ios_base::app);
    outfile << "Dokladnosc,Watki,PI,Czas" << std::endl;
    for (const auto& accuracy : accuracies) {
        for (int num_threads = 1; num_threads <= 50; ++num_threads) {
            auto start = std::chrono::high_resolution_clock::now();
            double pi = calculate_pi(accuracy, num_threads);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
    
        }
    }
    return 0;
}