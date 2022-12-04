// Advent of Code 2022
// Day 04
// Tools

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

bool IsTotalOverlap(const vector<uint64_t>& pairs)
{
    uint64_t begin_pair_1{pairs.at(0)};
    uint64_t end_pair_1{pairs.at(1)};
    uint64_t begin_pair_2{pairs.at(2)};
    uint64_t end_pair_2{pairs.at(3)};

    if((begin_pair_2 >= begin_pair_1 && end_pair_2 <= end_pair_1) ||
       (begin_pair_1 >= begin_pair_2 && end_pair_1 <= end_pair_2))
    {
        return true;
    }
    
    return false;
}

bool IsPartialOverlap(const vector<uint64_t>& pairs)
{
    uint64_t begin_pair_1{pairs.at(0)};
    uint64_t end_pair_1{pairs.at(1)};
    uint64_t begin_pair_2{pairs.at(2)};
    uint64_t end_pair_2{pairs.at(3)};

    if((begin_pair_2 >= begin_pair_1 && begin_pair_2 <= end_pair_1) ||
           (end_pair_2 >= begin_pair_1 && end_pair_2 <= end_pair_1) ||
           (begin_pair_1 >= begin_pair_2 && begin_pair_1 <= end_pair_2) ||
           (end_pair_1 >= begin_pair_2 && end_pair_1 <= end_pair_2))
    {
        return true;
    }
    
    return false;
}

uint64_t CountOverlapsInPairsOfSections(const vector<vector<uint64_t>>& pairs, const bool is_partial_overlap)
{
    uint64_t overlap_counter{0};

    for(const auto& p : pairs)
    {
        if([&](){if(is_partial_overlap == true){return IsPartialOverlap(p);} else{return IsTotalOverlap(p);}}())
        {
            if (DEBUG_FLAG)
            {
                is_partial_overlap ? printf("Partial") : printf("Total");
                printf(" overlaped pairs: %d-%d | %d-%d\n", p.at(0), p.at(1),
                p.at(2), p.at(3));
            }
            
            ++overlap_counter;
        }
    }

    return overlap_counter;
}
