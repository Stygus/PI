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
