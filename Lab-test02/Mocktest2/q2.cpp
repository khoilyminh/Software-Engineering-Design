#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Meal {
private:
    string type;
    double pricePerPerson;
public:
    Meal(string t, double p) : type(t), pricePerPerson(p) {}
    string getType() const { return type; }
    double getPricePerPerson() const { return pricePerPerson; }
};

class Transaction {
private:
    int transactionId;
    Meal meal;
    int numPeople;
    double totalPrice;
public:
    Transaction(int id, Meal m, int num) : transactionId(id), meal(m), numPeople(num) {
        totalPrice = numPeople * meal.getPricePerPerson();
        if (numPeople > 10) totalPrice *= 0.9; // Apply 10% discount for more than 10 people
    }
    int getId() const { return transactionId; }
    void showDetails() const {
        cout << "Transaction ID: " << transactionId << endl;
        cout << "Meal Type: " << meal.getType() << ", Number of People: " << numPeople << ", Total Price: " << totalPrice << endl;
    }
    string getMealType() const { return meal.getType(); }
    double getTotalPrice() const { return totalPrice; }
};

class Restaurant {
private:
    string name;
    vector<Transaction> transactions;
    static int nextTransactionId;
public:
    Restaurant(string n) : name(n) {}

    void makeReservation(string mealType, double pricePerPerson, int numPeople) {
        Meal meal(mealType, pricePerPerson);
        Transaction transaction(nextTransactionId++, meal, numPeople);
        transactions.push_back(transaction);
        cout << "Transaction ID " << transaction.getId() << " has been successfully added. Total Price: $" << transaction.getTotalPrice() << endl;
    }

    void showTransaction(int id) const {
        for (const auto& transaction : transactions) {
            if (transaction.getId() == id) {
                transaction.showDetails();
                return;
            }
        }
        cout << "Transaction ID not found." << endl;
    }

    void showStats() const {
        int breakfastCount = 0, lunchCount = 0, teaCount = 0;
        double breakfastRevenue = 0, lunchRevenue = 0, teaRevenue = 0;

        for (const auto& transaction : transactions) {
            if (transaction.getMealType() == "Breakfast") {
                breakfastCount++;
                breakfastRevenue += transaction.getTotalPrice();
            } else if (transaction.getMealType() == "Lunch") {
                lunchCount++;
                lunchRevenue += transaction.getTotalPrice();
            } else if (transaction.getMealType() == "Tea") {
                teaCount++;
                teaRevenue += transaction.getTotalPrice();
            }
        }

        cout << "Restaurant Statistics" << endl;
        cout << "Breakfast Reservations: " << breakfastCount << ", Total Revenue: $" << breakfastRevenue << endl;
        cout << "Lunch Reservations: " << lunchCount << ", Total Revenue: $" << lunchRevenue << endl;
        cout << "Tea Reservations: " << teaCount << ", Total Revenue: $" << teaRevenue << endl;
    }
};

int Restaurant::nextTransactionId = 1;

int main() {
    Restaurant rmitRestaurant("RMIT Restaurant");
    
    rmitRestaurant.makeReservation("Lunch", 20.00, 2);
    rmitRestaurant.makeReservation("Tea", 10.00, 12);
    rmitRestaurant.makeReservation("Lunch", 20.00, 3);
    
    rmitRestaurant.showTransaction(1);
    rmitRestaurant.showTransaction(2);
    rmitRestaurant.showTransaction(3);
    
    rmitRestaurant.showStats();
    
    return 0;
}
