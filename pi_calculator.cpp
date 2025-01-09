#include "pi_calculator.h"
#include <thread>
#include <vector>

double calculate_partial_sum(int start, int end, int num_intervals) {
    double sum = 0.0;
    double step = 1.0 / num_intervals;
    for (int i = start; i < end; ++i) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    return sum;
}

double calculate_pi(int num_intervals, int num_threads) {
    std::vector<std::thread> threads;
    std::vector<double> partial_sums(num_threads, 0.0);
    int intervals_per_thread = num_intervals / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * intervals_per_thread;
        int end = (i == num_threads - 1) ? num_intervals : start + intervals_per_thread;
        threads.emplace_back([&partial_sums, i, start, end, num_intervals]() {
            partial_sums[i] = calculate_partial_sum(start, end, num_intervals);
        });
    }
}