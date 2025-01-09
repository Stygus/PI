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
}