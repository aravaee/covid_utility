/*
Author: Ali Ravaee
Description: this class is used to hold the information about each country
Date: 07/10/2020
*/

#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>

class Country
{
private:
    std::string country_name;
    std::string country_code;
    int new_confirmed;
    int new_deaths;
    int new_recovered;
    int total_confirmed;
    int total_deaths;
    int total_recovered;

public:
    //Country();
    Country(std::string, std::string, int, int, int, int, int, int);
    ~Country();

    std::string GetCountry_name() const;
    void SetCountry_name(std::string country_name);

    std::string GetCountry_code() const;
    void SetCountry_code(std::string country_code);

    int GetNew_confirmed() const;
    void SetNew_confirmed(int new_confirmed);

    int GetNew_deaths() const;
    void SetNew_deaths(int new_deaths);

    int GetNew_recovered() const;
    void SetNew_recovered(int new_recovered);

    int GetTotal_confirmed() const;
    void SetTotal_confirmed(int total_confirmed);

    int GetTotal_deaths() const;
    void SetTotal_deaths(int total_deaths);

    int GetTotal_recovered() const;
    void SetTotal_recovered(int total_recovered);
};

#endif // !COUNTRY_H
