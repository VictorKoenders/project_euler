#include <cstdint>

enum class Weekday
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
};

Weekday operator++(Weekday &day);
Weekday operator++(Weekday &day, int); // postfix operator

enum class Month
{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

Month operator++(Month &month);
Month operator++(Month &month, int); // postfix operator

class Date
{
  public:
    Weekday weekday;
    uint8_t day;
    Month month;
    uint16_t year;

    Date();
    void next();
    uint8_t get_days_in_month();
    bool is_leap_year();
};
 