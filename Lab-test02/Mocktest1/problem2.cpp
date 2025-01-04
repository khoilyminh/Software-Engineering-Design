#include <iostream>
#include <string>
using namespace std;

class City {
public:
    string name;
    int stayingDays;
    City* nextCity;

    City(string n, int days) : name(n), stayingDays(days), nextCity(nullptr) {}
};

class Trip {
private:
    City* head;

public:
    Trip() : head(nullptr) {}

    void addCity(string name, int days) {
        City* newCity = new City(name, days);
        if (!head) {
            head = newCity;
        } else {
            City* temp = head;
            while (temp->nextCity) temp = temp->nextCity;
            temp->nextCity = newCity;
        }
    }

    void displayTrip() {
        City* temp = head;
        while (temp) {
            cout << temp->name << ": " << temp->stayingDays << " days" << endl;
            temp = temp->nextCity;
        }
    }

    void updateCity(string name, int days) {
        City* temp = head;
        City* prev = nullptr;
        int totalDays = 0;

        while (temp) {
            if (temp->name == name) {
                if (days == 0) {
                    // Remove city
                    if (prev) prev->nextCity = temp->nextCity;
                    else head = temp->nextCity;
                    delete temp;
                    cout << "> Removed from the trip plan. ";
                } else {
                    temp->stayingDays = days;
                    cout << "> Updated. ";
                }
                break;
            }
            prev = temp;
            temp = temp->nextCity;
        }

        temp = head;
        while (temp) {
            totalDays += temp->stayingDays;
            temp = temp->nextCity;
        }
        cout << "There will be a total of " << totalDays << " days staying in the next cities in the trip." << endl;
    }
};

int main() {
    Trip trip;
    trip.addCity("Hue", 5);
    trip.addCity("Da Nang", 3);
    trip.addCity("Nha Trang", 4);
    trip.addCity("Da Lat", 2);
    trip.addCity("Can Tho", 3);

    cout << "Initial Trip Plan:" << endl;
    trip.displayTrip();

    trip.updateCity("Nha Trang", 5);
    trip.updateCity("Da Lat", 0);

    cout << "\nUpdated Trip Plan:" << endl;
    trip.displayTrip();

    return 0;
}
