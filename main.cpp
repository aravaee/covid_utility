/*
Author: Ali Ravaee
Description: opens a csv file, reads line by line, each line gets parsed by parseRow function
    every line is stored in a vector of type Country
    vector gets sorted according to the user's input
    and displayed in a simple a horizontal bar chart
Date: 07/10/2020
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Country.h"
std::vector<std::string> parseRow(const std::string &row);
void printEmptyLine();
void graph(std::vector<std::string> &names, std::vector<int> &values, bool ASC, const int length);

int main(int argc, char const *argv[])
{
    /* code */
    std::string file_name;
    std::cout << "What is the name of csv file?" << std::endl;
    getline(std::cin, file_name);

    std::ifstream in(file_name);
    std::string s;
    std::vector<Country> records;

    if (in.fail())
        return (std::cout << file_name << " does not exist. Quitting..." << std::endl) && EXIT_FAILURE;

    getline(in, s); // skip the first line

    while (in.good())
    {
        getline(in, s);
        // to avoid adding the last empty line in the summary file to the vector
        if (s != "")
        {
            auto fields = parseRow(s);
            Country c(fields[0], fields[1], std::stoi(fields[2]), std::stoi(fields[3]), std::stoi(fields[4]), std::stoi(fields[5]), std::stoi(fields[6]), std::stoi(fields[7]));
            records.push_back(c);
        }
    }
    in.close();

    int input_field;
    int input_order;
    const int MAX_LENGTH = 95;
    std::vector<int> ten_field_values;
    std::vector<std::string> ten_field_names;

    std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "| Choose the field to sort:     |" << std::endl;
    std::cout << "| Valid enteries: {1,2,3,4,5,6} |" << std::endl;
    std::cout << "| 1) New Confirmed Cases        |" << std::endl;
    std::cout << "| 2) New Deaths                 |" << std::endl;
    std::cout << "| 3) New Recovered Cases        |" << std::endl;
    std::cout << "| 4) Total Confirmed Cases      |" << std::endl;
    std::cout << "| 5) Total Deaths               |" << std::endl;
    std::cout << "| 6) Total Recovered Cases      |" << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
    std::cin >> input_field;
    if (input_field == 1 || input_field == 2 || input_field == 3 || input_field == 4 || input_field == 5 || input_field == 6)
    {
        std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "| Choose the order of sort:     |" << std::endl;
        std::cout << "| Valid enteries: {1,2}         |" << std::endl;
        std::cout << "| 1) Ascending                  |" << std::endl;
        std::cout << "| 2) Descending                 |" << std::endl;
        std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
        std::cin >> input_order;
        if ((input_order == 1 || input_order == 2))
        {
            if (input_field == 1)
            {

                if (input_order == 1)
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetNew_confirmed() < rhs.GetNew_confirmed();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetNew_confirmed());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, true, MAX_LENGTH);
                    if(records[9].GetTotal_confirmed() / MAX_LENGTH < MAX_LENGTH && records[9].GetNew_confirmed() != 0){
                        std::cout << "New Confirmed Cases; Each # is approx. " << 1 << " case" << std::endl;
                    }
                    else{
                        std::cout << "New Confirmed Cases; Each # is approx. " << records[9].GetNew_confirmed() / MAX_LENGTH << " cases" << std::endl;
                    }
                }
                else
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetNew_confirmed() > rhs.GetNew_confirmed();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetNew_confirmed());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, false, MAX_LENGTH);
                    std::cout << "New Confirmed Cases; Each # is approx. " << records[0].GetNew_confirmed() / MAX_LENGTH << " cases" << std::endl;
                }
            }
            else if (input_field == 2)
            {

                if (input_order == 1)
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetNew_deaths() < rhs.GetNew_deaths();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetNew_deaths());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, true, MAX_LENGTH);
                    if(records[9].GetTotal_confirmed() / MAX_LENGTH < MAX_LENGTH && records[9].GetNew_deaths() != 0){
                        std::cout << "New Deaths; Each # is approx. " << 1 << " case" << std::endl;
                    }
                    else{
                        std::cout << "New Deaths; Each # is approx. " << records[9].GetNew_deaths() / MAX_LENGTH << " cases" << std::endl;
                    }
                }
                else
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetNew_deaths() > rhs.GetNew_deaths();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetNew_deaths());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, false, MAX_LENGTH);
                    std::cout << "New Deaths; Each # is approx. " << records[0].GetNew_deaths() / MAX_LENGTH << " cases" << std::endl;
                }
            }
            else if (input_field == 3)
            {

                if (input_order == 1)
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetNew_recovered() < rhs.GetNew_recovered();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetNew_recovered());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, true, MAX_LENGTH);
                    if(records[9].GetTotal_confirmed() / MAX_LENGTH < MAX_LENGTH && records[9].GetNew_recovered() != 0){
                        std::cout << "New Recovered Cases; Each # is approx. " << 1 << " case" << std::endl;
                    }
                    else{
                        std::cout << "New Recovered Cases; Each # is approx. " << records[9].GetNew_recovered() / MAX_LENGTH << " cases" << std::endl;
                    }
                }
                else
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetNew_recovered() > rhs.GetNew_recovered();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetNew_recovered());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, false, MAX_LENGTH);
                    std::cout << "New Recovered Cases; Each # is approx. " << records[0].GetNew_recovered() / MAX_LENGTH << " cases" << std::endl;
                }
            }
            else if (input_field == 4)
            {

                if (input_order == 1)
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetTotal_confirmed() < rhs.GetTotal_confirmed();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetTotal_confirmed());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, true, MAX_LENGTH);
                    if(records[9].GetTotal_confirmed() / MAX_LENGTH < MAX_LENGTH && records[9].GetTotal_confirmed() != 0){
                        std::cout << "Total Confirmed Cases; Each # is approx. " << 1 << " case" << std::endl;
                    }
                    else{
                        std::cout << "Total Confirmed Cases; Each # is approx. " << records[9].GetTotal_confirmed() / MAX_LENGTH << " cases" << std::endl;
                    }
                    
                }
                else
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetTotal_confirmed() > rhs.GetTotal_confirmed();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetTotal_confirmed());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, false, MAX_LENGTH);
                    std::cout << "Total Confirmed Cases; Each # is approx. " << records[0].GetTotal_confirmed() / MAX_LENGTH << " cases" << std::endl;
                }
            }
            else if (input_field == 5)
            {

                if (input_order == 1)
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetTotal_deaths() < rhs.GetTotal_deaths();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetTotal_deaths());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, true, MAX_LENGTH);
                    if(records[9].GetTotal_confirmed() / MAX_LENGTH < MAX_LENGTH && records[9].GetTotal_deaths() != 0){
                        std::cout << "Total Deaths; Each # is approx. " << 1 << " case" << std::endl;
                    }
                    else{
                        std::cout << "Total Deaths; Each # is approx. " << records[9].GetTotal_deaths() / MAX_LENGTH << " cases" << std::endl;
                    }
                }
                else
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetTotal_deaths() > rhs.GetTotal_deaths();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetTotal_deaths());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, false, MAX_LENGTH);
                    std::cout << "Total Deaths; Each # is approx. " << records[0].GetTotal_deaths() / MAX_LENGTH << " cases" << std::endl;
                }
            }
            else if (input_field == 6)
            {

                if (input_order == 1)
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetTotal_recovered() < rhs.GetTotal_recovered();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetTotal_recovered());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, true, MAX_LENGTH);
                    if(records[9].GetTotal_confirmed() / MAX_LENGTH < MAX_LENGTH && records[9].GetTotal_recovered() != 0){
                        std::cout << "Total Recovered Cases; Each # is approx. " << 1 << " case" << std::endl;
                    }
                    else{
                        std::cout << "Total Recovered Cases; Each # is approx. " << records[9].GetTotal_recovered() / MAX_LENGTH << " cases" << std::endl;
                    }
                }
                else
                {
                    std::sort(records.begin(), records.end(), [](const auto &lhs, const auto &rhs) {
                        return lhs.GetTotal_recovered() > rhs.GetTotal_recovered();
                    });
                    for (int i = 0; i < 10; ++i)
                    {
                        ten_field_values.push_back(records[i].GetTotal_recovered());
                        ten_field_names.push_back(records[i].GetCountry_code());
                    }
                    graph(ten_field_names, ten_field_values, false, MAX_LENGTH);
                    std::cout << "Total Recovered Cases; Each # is approx. " << records[0].GetTotal_recovered() / MAX_LENGTH << " cases" << std::endl;
                }
            }
        }
        else
        {
            std::cout << std::endl
                      << "Not a valid entry. Quitting..." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        std::cout << std::endl
                  << "Not a valid entry. Quitting..." << std::endl;
        exit(EXIT_FAILURE);
    }
}
// goes through the line (string) character by character and based on the position of the ,
// push back the word or number into the vector of type string and returns it
std::vector<std::string> parseRow(const std::string &row)
{
    std::vector<std::string> v{""};
    int skip_column = 0; // to skip unnecessary columns when pushing back to the vector
    bool Unquoted = true;
    bool Quoted = false;
    int i = 0;
    for (char c : row)
    {
        if (Unquoted)
        {
            switch (c)
            {
            case ',':
                if (skip_column != 2 && skip_column != 3 && skip_column != 7 && skip_column != 8)
                {
                    v.push_back("");
                    i++;
                }
                skip_column++;
                break;
            case '"':
                Quoted = true;
                Unquoted = false;
                break;
            default:
                if (skip_column != 2 && skip_column != 3 && skip_column != 7 && skip_column != 8)
                    v[i].push_back(c);
                break;
            }
        }
        else if (Quoted)
        {
            switch (c)
            {
            case '"':
                Unquoted = true;
                Quoted = false;
                break;
            default:
                if (skip_column != 2 && skip_column != 3 && skip_column != 7 && skip_column != 8)
                    v[i].push_back(c);
                break;
            }
        }
    }
    return v;
}

// prints a line, to keep code tidy (somewhat)
void printEmptyLine()
{
    std::cout << "   |                                                                                                " << std::endl;
}

// I tried to not pass the entire vector of records to avoid copying the whole thing
// two small vectors are passed and a simple horizontal bar is drawn
void graph(std::vector<std::string> &country_code, std::vector<int> &field_value, bool ASC, const int length)
{ // graph(records, 123456, true)
    const int MAX_LENGTH = length;
    std::cout << std::endl;
    if (ASC)
    {
        // if bottom ten countries have value > 0
        if (field_value[9] != 0)
        { // 
            if (field_value[9] > MAX_LENGTH)
            {
                for (int i = 0; i < 9; ++i)
                {
                    std::cout << country_code[i] << " | ";
                    for (int j = 0; j < (field_value[i] * MAX_LENGTH) / field_value[9]; ++j)
                    {
                        std::cout << "#";
                    }
                    std::cout << std::endl;
                    printEmptyLine();
                }
                std::cout << country_code[0] << " | ";
                for (int i = 0; i < MAX_LENGTH; ++i)
                {
                    std::cout << "#";
                }
                std::cout << std::endl;
                printEmptyLine();
            }
            else{
                for (int i = 0; i < 10; ++i)
                {
                    std::cout << country_code[i] << " | ";
                    for (int j = 0; j < field_value[i]; ++j)
                    {
                        std::cout << "#";
                    }
                    std::cout << std::endl;
                    printEmptyLine();
                }
            }
        }
        else
        {
            for (int i = 0; i < 10; ++i)
                {
                    std::cout << country_code[i] << " | ";
                    std::cout << std::endl;
                    printEmptyLine();
                }
        }
        std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
    }
    if (!ASC)
    {
        std::cout << country_code[0] << " | ";
        for (int i = 0; i < MAX_LENGTH; ++i)
        {
            std::cout << "#";
        }
        std::cout << std::endl;
        printEmptyLine();

        for (int i = 1; i < 10; ++i)
        {
            std::cout << country_code[i] << " | ";
            for (int j = 0; j < (field_value[i] * MAX_LENGTH) / field_value[0]; ++j)
            {
                std::cout << "#";
            }
            std::cout << std::endl;
            printEmptyLine();
        }
        std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
    }
}
