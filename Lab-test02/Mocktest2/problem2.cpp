#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Meal {
public:
    string type;
    double pricePerPerson;

    Meal(string t, double p) : type(t), pricePerPerson(p) {}
};

class Transaction {
public:
    int transactionID;
    string mealType;
    int numPeople;
    double totalPrice;

    Transaction(int id, string type, int people, double price)
        : transactionID(id), mealType(type), numPeople(people), totalPrice(price) {}
};

class Restaurant {
private:
    string name;
    vector<Meal> meals;
    vector<Transaction> transactions;
    int transactionCounter;

public:
    Restaurant(string n) : name(n), transactionCounter(1) {
        meals.push_back(Meal("Breakfast", 12.0));
        meals.push_back(Meal("Lunch", 20.0));
        meals.push_back(Meal("Tea", 10.0));
    }

    void makeReservation(string mealType, int numPeople) {
        double price = 0;
        for (const Meal& meal : meals) {
            if (meal.type == mealType) {
                price = meal.pricePerPerson * numPeople;
                if (numPeople > 10) price *= 0.9;  // Apply discount
                break;
            }
        }

        transactions.push_back(Transaction(transactionCounter++, mealType, numPeople, price));
        cout << "Transaction ID " << transactions.back().transactionID
             << " has been successfully added. Total Price: $" << price << endl;
    }

    void showTransaction(int transactionID) {
        for (const Transaction& t : transactions) {
            if (t.transactionID == transactionID) {
                cout << "Transaction ID: " << t.transactionID << endl;
                cout << "Meal Type: " << t.mealType
                     << ", Number of People: " << t.numPeople
                     << ", Total Price: $" << t.totalPrice << endl;
                return;
            }
        }
        cout << "Transaction not found!" << endl;
    }

    void showStats() {
        int breakfastCount = 0, lunchCount = 0, teaCount = 0;
        double breakfastRevenue = 0, lunchRevenue = 0, teaRevenue = 0;

        for (const Transaction& t : transactions) {
            if (t.mealType == "Breakfast") {
                breakfastCount += t.numPeople;
                breakfastRevenue += t.totalPrice;
            } else if (t.mealType == "Lunch") {
                lunchCount += t.numPeople;
                lunchRevenue += t.totalPrice;
            } else if (t.mealType == "Tea") {
                teaCount += t.numPeople;
                teaRevenue += t.totalPrice;
            }
        }

        cout << "\nRestaurant Statistics" << endl;
        cout << "Breakfast Reservations: " << breakfastCount
             << ", Total Revenue: $" << breakfastRevenue << endl;
        cout << "Lunch Reservations: " << lunchCount
             << ", Total Revenue: $" << lunchRevenue << endl;
        cout << "Tea Reservations: " << teaCount
             << ", Total Revenue: $" << teaRevenue << endl;
    }
};

int main() {
    Restaurant restaurant("RMIT Restaurant");

    cout << "Welcome to " << restaurant.getName() << endl;
    restaurant.makeReservation("Lunch", 2);
    restaurant.makeReservation("Tea", 12);
    restaurant.makeReservation("Lunch", 3);

    restaurant.showTransaction(1);
    restaurant.showTransaction(2);

    restaurant.showStats();

    return 0;
}
