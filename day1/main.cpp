#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int calculate_fuel(int mass)
{
    int total = (int)floor((float)mass / 3.0f) - 2;

    if (total <= 0)
        return 0;

    return total + calculate_fuel(total);
}

int main()
{
    std::ifstream file("input.txt");

    std::string line;
    int total_fuel = 0;
    while (!file.eof()) {
        std::getline(file, line);
        total_fuel += calculate_fuel(std::stoi(line));
    }

    std::cout << "Total fuel required: " << total_fuel << " fuel units" << std::endl;
    
    file.close();
    return 0;
}
