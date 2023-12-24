#include "time.h"

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

void Time::incrementSecond() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            hours++;
            if (hours >= 24) {
                hours = 0;
            }
        }
    }
}

Time Time::operator++() {
    incrementSecond();
    return *this;
}

Time Time::operator--() {
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
        if (minutes < 0) {
            minutes = 59;
            hours--;
            if (hours < 0) {
                hours = 23;
            }
        }
    }
    return *this;
}

bool Time::operator!=(const Time& other) const {
    return (hours != other.hours || minutes != other.minutes || seconds != other.seconds);
}

bool Time::operator==(const Time& other) const {
    return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
}

bool Time::operator>(const Time& other) const {
    if (hours > other.hours)
        return true;
    else if (hours == other.hours && minutes > other.minutes)
        return true;
    else
        return (hours == other.hours && minutes == other.minutes && seconds > other.seconds);
}

bool Time::operator<(const Time& other) const {
    return !(*this > other || *this == other);
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

Time Time::operator+(int seconds) {
    Time result = *this;
    for (int i = 0; i < seconds; ++i) {
        result.incrementSecond();
    }
    return result;
}

Time Time::operator+=(int seconds) {
    for (int i = 0; i < seconds; ++i) {
        incrementSecond();
    }
    return *this;
}

Time Time::operator-=(int seconds) {
    for (int i = 0; i < seconds; ++i) {
        this->operator--();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.hours << ':' << time.minutes << ':' << time.seconds;
    return os;
}

std::istream& operator>>(std::istream& is, Time& time) {
    is >> time.hours >> time.minutes >> time.seconds;
    return is;
}
