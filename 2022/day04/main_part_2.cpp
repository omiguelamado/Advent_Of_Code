// Advent of Code 2022
// Day 04
// Part 2

#include <string>
#include <vector>
#include "tools.cpp"

using namespace std;

int main(void)
{
    vector<vector<uint64_t>> pairs_of_sections{
        GetPairsOfSections("data\\real_data.txt")};

    cout << endl << "Number of partial overlaps: " << 
    CountOverlapsInPairsOfSections(pairs_of_sections, true) << endl;

    return 0;
}