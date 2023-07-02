// Assignment 1_2_4

// Create a software that can calculate the time difference 
// between a start and end time. 
// Think how you can split the program into multiple functions.

// This is quite an idiotic solution but it is one, anyway.

#include <iostream>
#include <string>

struct Time
{
    int minutes {};
    int hours {};
    int seconds {};
};

void get_time(Time& time)   // function to input data
{
    std::cout << "Enter hours (hh): ";
    std::cin >> time.hours;
    std::cout << "Enter minutes (mm): ";
    std::cin >> time.minutes;
    std::cout << "Enter seconds (ss): ";
    std::cin >> time.seconds;
}

int calc_time_diff(const Time& t1, const Time& t2) // function calculates time diff in seconds
{
    int start_in_sec {t1.hours * 3600 + t1.minutes * 60 + t1.seconds};
    int end_in_sec {t2.hours * 3600 + t2.minutes * 60 + t2.seconds};

    return (end_in_sec - start_in_sec);
}

int main()
{
    std::cout << "Give start time.\n";
    Time start;
    get_time(start);

    std::cout << "Give end time.\n";
    Time end;
    get_time(end);

    std::cout << "Time difference is: " << calc_time_diff(start, end) << " seconds.\n";

    return 0;
}
