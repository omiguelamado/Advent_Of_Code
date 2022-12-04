// Advent of Code 2022
// Day 04

#include <string>
#include <vector>
#include "tools.cpp"

using namespace std;

int main(void)
{
    vector<vector<uint64_t>> pairs_of_sections{
        GetPairsOfSections("data\\part_1\\real_data.txt")};

    cout << endl << "Number of overlaps: " << 
    CountOverlapsInPairsOfSections(pairs_of_sections) << endl;

    return 0;
}