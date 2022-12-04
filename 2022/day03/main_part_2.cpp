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
    vector<string> packages{GetPackages("data\\part_2\\real_data.txt")};
    uint64_t sum_priorities{0};

    for(size_t i{0}; i < packages.size(); i+=3)
    {
        sum_priorities += GetItemPriority(
                        FindCommomItemBetweenAllThreeElves(packages.at(i),
                                                           packages.at(i+1),
                                                           packages.at(i+2)));
    }

    cout << endl << "Sum of Priorities: " << sum_priorities << "." << endl;

    return 0;
}