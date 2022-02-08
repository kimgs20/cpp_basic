/*
constructor, default constructor, constructor overloading
*/

#include <iostream>

class Date {
    int year_;
    int month_;
    int day_;

    // definition of function in class
    // and body of function decripted at the out of the class.
    // because if class memeber function descrpited in the class,
    // then code of class will be so long.
    public:
        // Date() = default;  // define default constructor
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);

    // calculate the total days of specific month
    int GetCurrentMonthTotalDays(int year, int month);

    void ShowDate();

    // constructor
    // :A function that is automatically called when an object is created.
    Date(int year, int month, int day) {
        std::cout << "called constructor" << std::endl;
        year_ = year;
        month_ = month;
        day_ = day;
    }

    // default constructor
    // :if programmer doesn't define the initialization values, it will be used automatically.
    Date() {
        std::cout << "called default constructor" << std::endl;
        year_ = 2023;
        month_ = 7;
        day_ = 12;
    }
};

// class member function
// Class::FunCtion
void Date::SetDate(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2) {
        return month_day[month - 1];
    } else if (year % 4 == 0 && year % 100 != 0) {
        return 29;
    } else {
        return month_day[1];
    }
}

void Date::AddDay(int inc) {
    while (true) {
        int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

        if (day_ + inc <= current_month_total_days) {
            day_ += inc;
            return;
        } else {
            inc -= (current_month_total_days - day_ + 1);
            day_ = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc) {
    AddYear((inc + month_ - 1) / 12);
    month_ += inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
    std::cout << "today is " << year_ << "/" << month_ << "/" << day_ << std::endl;
}

int main() {

    // 1.
    Date day(2022, 2, 2);  // contructor overloading (implicit: recommended)
    // Date day = Date(2022, 2, 2);  // (explicit)
    day.ShowDate();

    day.AddDay(31);
    day.ShowDate();

    day.AddMonth(9);
    day.ShowDate();

    day.AddYear(15);
    day.ShowDate();

    // 2.
    // Date day = Date();  // default constructor
    // Date day2(2022, 2, 2);  // contructor overloading

    // day.ShowDate();
    // day2.ShowDate();

    // 3.
    // Date day();  // (X) this is definition of function that don't have arguments
    // Date day;    // (O) this is call constructor that doesn't have arguments
    // day.ShowDate();

    return 0;
}
