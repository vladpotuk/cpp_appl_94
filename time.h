#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    Time(int h, int m, int s);

    void incrementSecond();

    
    Time operator++();  
    Time operator--();  
    bool operator!=(const Time& other) const;
    bool operator==(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;
    Time& operator=(const Time& other);
    Time operator+(int seconds);  
    Time operator+=(int seconds);
    Time operator-=(int seconds);

    
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
    friend std::istream& operator>>(std::istream& is, Time& time);
};

#endif 
