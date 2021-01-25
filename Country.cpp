/*
Author: Ali Ravaee
Description: header file for Country class and code description
Date: 07/10/2020
*/

#include "Country.h"

// Country::Country(){}
Country::Country(std::string country_name, std::string country_code, int new_confirmed,
 int new_deaths, int new_recovered, int total_confirmed, int total_deaths, int total_recovered){
    this->country_name = country_name;
    this->country_code = country_code;
    this->new_confirmed = new_confirmed;
    this->new_deaths = new_deaths;
    this->new_recovered = new_recovered;
    this->total_confirmed = total_confirmed;
    this->total_deaths = total_deaths;
    this->total_recovered = total_recovered;
}
Country::~Country(){} // can be empty

std::string Country::GetCountry_name() const
{
    return country_name;
}
void Country::SetCountry_name(std::string country_name)
{
    this->country_name = country_name;
}

std::string Country::GetCountry_code() const
{
    return country_code;
}
void Country::SetCountry_code(std::string country_code)
{
    this->country_code = country_code;
}

int Country::GetNew_confirmed() const
{
    return new_confirmed;
}
void Country::SetNew_confirmed(int new_confirmed)
{
    this->new_confirmed = new_confirmed;
}

int Country::GetNew_deaths() const
{
    return new_deaths;
}
void Country::SetNew_deaths(int new_deaths)
{
    this->new_deaths = new_deaths;
}

int Country::GetNew_recovered() const
{
    return new_recovered;
}
void Country::SetNew_recovered(int new_recovered)
{
    this->new_recovered = new_recovered;
}

int Country::GetTotal_confirmed() const
{
    return total_confirmed;
}
void Country::SetTotal_confirmed(int total_confirmed)
{
    this->total_confirmed = total_confirmed;
}

int Country::GetTotal_deaths() const
{
    return total_deaths;
}
void Country::SetTotal_deaths(int total_deaths)
{
    this->total_deaths = total_deaths;
}

int Country::GetTotal_recovered() const
{
    return total_recovered;
}
void Country::SetTotal_recovered(int total_recovered)
{
    this->total_recovered = total_recovered;
}
