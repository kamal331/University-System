class Date
{
    /// @brief
    /// This class is used to store a date
    ///  in the format of year, month and day.
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