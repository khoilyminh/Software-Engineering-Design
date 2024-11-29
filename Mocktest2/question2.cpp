#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hour;
    int minute;

public:
    Time(int hour = 0, int minute = 0) {
        this->hour = (hour >= 0 && hour < 24) ? hour : 0;
        this->minute = (minute >= 0 && minute < 60) ? minute : 0;
    }

    Time operator+(const Time& other) const {
        int totalMinutes = minute + other.minute;
        int newHour = hour + other.hour + totalMinutes / 60;
        int newMinute = totalMinutes % 60;
        newHour %= 24;
        return Time(newHour, newMinute);
    }

    friend ostream& operator<<(ostream& os, const Time& time) {
        os << setw(2) << setfill('0') << time.hour << ":" << setw(2) << setfill('0') << time.minute;
        return os;
    }
    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }
};

int main() {
    // Sample usage for part (b) and (c)
    Time t1(5, 23);
    Time t2(23, 42);
    Time t3 = t1 + t2;
    cout << t1 << "+" << t2 << "=" << t3 << endl;

    // Part (d)
    Time times[4];
    ifstream inputFile("data2-mock2.dat");

    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open file data2.dat" << endl;
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        int hour, minute;
        inputFile >> hour >> minute;
        times[i] = Time(hour, minute);
    }
    inputFile.close();

    int lowestIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (times[i].getHour() < times[lowestIndex].getHour() ||
            (times[i].getHour() == times[lowestIndex].getHour() && times[i].getMinute() < times[lowestIndex].getMinute())) {
            lowestIndex = i;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << "Time " << i + 1 << "=" << times[i] << endl;
    }
    cout << "Lowest time = " << times[lowestIndex] << endl;

    return 0;
}
