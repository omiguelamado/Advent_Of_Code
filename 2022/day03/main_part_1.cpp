// Advent of Code 2022
// Day 03

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tools.cpp"

using namespace std;

int main(void)
{
    vector<string> packages{GetPackages("data\\part_1\\real_data.txt")};
    uint64_t sum_priorities{0};
    
    for (const auto& p : packages)
    {
        for(const auto& item : FindRepeatedItems(p))
        {
            sum_priorities += GetItemPriority(item);
        }
    }

    cout << endl << "Sum of Priorities: " << sum_priorities << "." << endl;

    return 0;
}