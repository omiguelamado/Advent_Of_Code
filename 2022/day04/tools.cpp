// Advent of Code 2022
// Day 04

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define DEBUG_FLAG false

using namespace std;

void ReplaceNonNumbersByEmptySpace(string& str)
{
    for(size_t i{0}; i < str.size(); ++i)
    {
        if(str.at(i) < '0' || str.at(i) > '9')
        {
            str.at(i) = ' ';
        }
    }
}

vector<vector<uint64_t>> GetPairsOfSections(const string& file_name)
{
    ifstream file(file_name);
    vector<vector<uint64_t>> data{};


    if (file.is_open())
    {
        for(string line; getline(file, line); )
        {
            if(DEBUG_FLAG)
                cout << endl << "Pre-Processed section sairs: " << line << endl;

            ReplaceNonNumbersByEmptySpace(line);

            if(DEBUG_FLAG)
                cout << "Pos-Processed section sairs: " << line << endl;
            
            std::istringstream l(line);
            uint64_t n;
            vector<uint64_t> numbers;

            while(l >> n)
            {
                numbers.push_back(n);
            }

            if(numbers.size() == 4)
            {
                data.push_back(numbers);
            }
        }
    }

    return data;
}




uint64_t CountOverlapsInPairsOfSections(const vector<vector<uint64_t>>& pairs)
{
    static uint64_t begin_pair_1;
    static uint64_t end_pair_1;
    static uint64_t begin_pair_2;
    static uint64_t end_pair_2;

    uint64_t overlap_counter{0};

    for(const auto& p : pairs)
    {
        begin_pair_1 = p.at(0);
        end_pair_1 = p.at(1);
        begin_pair_2 = p.at(2);
        end_pair_2 = p.at(3);

        if((begin_pair_2 >= begin_pair_1 && end_pair_2 <= end_pair_1) ||
           (begin_pair_1 >= begin_pair_2 && end_pair_1 <= end_pair_2))
        {
            if (DEBUG_FLAG)
            {
                printf("Overlaped pair: %d-%d | %d-%d\n", begin_pair_1, end_pair_1, begin_pair_2, end_pair_2);
            }
            
            ++overlap_counter;
        }
    }

    return overlap_counter;
}