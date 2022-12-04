// Advent of Code 2022
// Day 03

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

#define DEBUG_FLAG false

using namespace std;

vector<string> GetPackages(const string& file_name)
{
    ifstream file(file_name);
    vector<string> data{};

    if (file.is_open())
    {
        for(string line; getline(file, line); )
        {
            data.push_back(line);
        }
    }

    return data;
}

pair<string,string> SplitItems(const string& s)
{
    size_t half_size{s.size()/2};

    pair<string,string> string{s.substr(0 , half_size),s.substr(half_size)};

    if(DEBUG_FLAG)
    {
        cout << endl;
        cout << "Original Package: " << s << " (size: " << s.size() << ")" << endl;
        cout << "Splitted Package: " << string.first << " | " << string.second << endl;
    }

    return string;
}

vector<char> FindRepeatedItems(const string& s)
{
    pair<string,string> splitted_strings{SplitItems(s)};
    vector<char> repeated_characters{};

    for(const auto& c1 : splitted_strings.first)
    {
        for(const auto& c2 : splitted_strings.second)
        {
            if(c1 == c2)
            {
                bool is_repeated{false};

                for(const auto& rc : repeated_characters)
                {
                    if(c1 == rc)
                    {
                        is_repeated = true;
                        break;
                    }
                }

                if(!is_repeated)
                {
                    repeated_characters.push_back(c1);
                    
                    if(DEBUG_FLAG)
                    {
                        cout << "New Item Repeated (" << c1 << ")" << endl;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    if(DEBUG_FLAG)
    {
        cout << "Repeated Characters (" << repeated_characters.size() << "): ";
        for(const auto& c : repeated_characters)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return repeated_characters;
}

char FindCommomItemBetweenAllThreeElves(const string& rucksack_1,
                                        const string& rucksack_2,
                                        const string& rucksack_3)
{
    for(const auto& c1 : rucksack_1)
    {
        for(const auto& c2 : rucksack_2)
        {
            if(c1 == c2)
            {
                for(const auto& c3 : rucksack_3)
                {
                    if(c1 == c3)
                    {
                        return c1;
                    }
                }
            }
        }
    }

    return {0x60};
}

size_t GetItemPriority(char item)
{
    static const size_t upper_case_shift('a'-'A' + ('z'-'a')+1);
    
    const bool is_upper_case{[&](){if(item < 'a'){return true;} else{return false;}}()};
    size_t priority{};

    priority = (item - 'a') + 1;

    if(is_upper_case)
    {
        priority += upper_case_shift;
    }

    return priority;
}