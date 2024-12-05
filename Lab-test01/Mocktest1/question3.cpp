#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

class Task {
private:
    int t_Hour;
    int t_Minute;

public:
    // Constructor
    Task(int hour = 0, int minute = 0) : t_Hour(hour), t_Minute((minute >= 0 && minute < 60) ? minute : 0) {}

    // Overload > operator
    bool operator>(const Task &other) const {
        return (t_Hour * 60 + t_Minute) > (other.t_Hour * 60 + other.t_Minute);
    }

    // Overload << operator
    friend std::ostream &operator<<(std::ostream &os, const Task &task) {
        os << std::setw(2) << std::setfill('0') << task.t_Hour << ":"
           << std::setw(2) << std::setfill('0') << task.t_Minute;
        return os;
    }

    // Read task data from a file
    void readFromStream(std::istream &is) {
        is >> t_Hour >> t_Minute;
        if (t_Minute < 0 || t_Minute >= 60) {
            t_Minute = 0;
        }
    }
};

int main() {
    // Read tasks from file
    std::ifstream file("data1.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    Task tasks[4];
    for (int i = 0; i < 4; ++i) {
        tasks[i].readFromStream(file);
    }
    file.close();

    // User input task
    int userHour, userMinute;
    std::cout << "Enter hours and minutes taken for your task: ";
    std::cin >> userHour >> userMinute;

    Task userTask(userHour, userMinute);
    std::cout << "Your task = " << userTask << std::endl;

    for (int i = 0; i < 4; ++i) {
        std::cout << "Task " << (i + 1) << " = " << tasks[i] << std::endl;
    }

    // Count tasks with greater duration
    int count = 0;
    for (const auto &task : tasks) {
        if (task > userTask) {
            ++count;
        }
    }
    std::cout << "Number of tasks time greater than your task time: " << count << std::endl;

    return 0;
}
