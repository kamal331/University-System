#ifndef __DATE_H_
#define __DATE_H_

/*****************************************************
 *   \class Date                                     *
 *   \brief A class for date to store date of exams  *
 *          in a format of day/month/year            *
 *   \param day, month, year                         *
 *****************************************************/

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int month, int day, int year);
    Date(); // default constructor

    int getDay();
    int getMonth();
    int getYear();

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    void printDate();

    Date *operator=(Date *date);
    // overloading operator for input and output
    friend ostream &operator<<(ostream &output, const Date &date);
    friend istream &operator>>(istream &input, Date &date);
};

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date()
{
    this->year = 0;
    this->month = 0;
    this->day = 0;
}

int Date::getYear()
{
    return this->year;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getDay()
{
    return this->day;
}

void Date::setYear(int year)
{
    this->year = year;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setDay(int day)
{
    this->day = day;
}

void Date::printDate()
{
    cout << this->year << "/" << this->month << "/" << this->day << endl;
}

Date *Date::operator=(Date *date)
{
    this->year = date->year;
    this->month = date->month;
    this->day = date->day;
    return this;
}

ostream &operator<<(ostream &output, const Date &date)
{
    output << date.year << "/" << date.month << "/" << date.day;
    return output;
}

istream &operator>>(istream &input, Date &date)
{
    input >> date.year >> date.month >> date.day;
    return input;
}

#endif