#include "date_utils.h"

Weekday operator++(Weekday &day)
{
    day = static_cast<Weekday>((static_cast<uint8_t>(day) + 1) % 8);
    return day;
}

Weekday operator++(Weekday &day, int) // postfix operator
{
    Weekday result = day;
    ++day;
    return result;
}

Month operator++(Month &month)
{
    month = static_cast<Month>((static_cast<uint8_t>(month) + 1) % 12);
    return month;
}

Month operator++(Month &month, int) // postfix operator
{
    Month result = month;
    ++month;
    return result;
}

Date::Date() : weekday(Weekday::Monday),
               day(1),
               month(Month::January),
               year(1900)
{
}

void Date::next()
{
    this->day++;
    if (this->weekday == Weekday::Sunday)
        this->weekday = Weekday::Monday;
    else
        this->weekday++;

    uint8_t last_day_of_month = get_days_in_month();
    if (this->day > last_day_of_month)
    {
        this->day = 1;
        if (this->month == Month::December)
        {
            this->year++;
            this->month = Month::January;
        }
        else
        {
            this->month++;
        }
    }
}

uint8_t Date::get_days_in_month()
{
    switch (this->month)
    {
    case Month::January:
    case Month::March:
    case Month::May:
    case Month::July:
    case Month::August:
    case Month::October:
    case Month::December:
        return 31;
    case Month::February:
        return this->is_leap_year() ? 29 : 28;
    default:
        return 30;
    }
}

bool Date::is_leap_year()
{
    if ((this->year % 400) == 0)
        return true;
    if ((this->year % 100) == 0)
        return false;
    return this->year % 4 == 0;
}
