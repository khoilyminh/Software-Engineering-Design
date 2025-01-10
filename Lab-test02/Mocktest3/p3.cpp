#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define DISCOUNT_RATE 0.05

class Product {
private:
    string name;
    double price;

public:
    // Constructor
    Product(string name = "", double price = 0.0) {
        this->name = name;
        this->price = price;
    }

    void showInfo() {
        cout << name << ", $" << price << "\n";
    }

    friend class Customer; // Allow Customer to access private members (if needed)
    friend class Order;
};

class Shop {
private:
    string name;
    vector<Product> prodList;

public:
    // Constructor
    Shop(string name = "", const vector<Product>& pList = vector<Product>()) {
        this->name = name;
        this->prodList = pList;
    }

    void showInfo() {
        cout << "Shop: " << name << "\n";
        cout << "Product list: \n";
        for (int i = 0; i < prodList.size(); i++) {
            prodList[i].showInfo();
        }
    }
};

class Order {
private:
    int orderID;
    vector<Product> boughtList;
    double totExpense;

public:
    // Constructor
    Order(int orderID = 0, const vector<Product>& bList = vector<Product>(), double totExpense = 0.0) {
        this->orderID = orderID;
        this->boughtList = bList;
        this->totExpense = totExpense;
    }

    void showInfo() {
        cout << "Order ID: " << orderID << "\n";
        cout << "Bought list: \n";
        for (int i = 0; i < boughtList.size(); i++) {
            boughtList[i].showInfo();
        }
        cout << "Total expense: " << totExpense << "\n";
    }

    friend class Customer;
};

class Customer {
private:
    string name;
    vector<Order> orderList;
    int accType; // 1 for normal, 2 for gold

public:
    // Constructor
    Customer(string name = "", int accType = 1, const vector<Order>& oList = vector<Order>()) {
        this->name = name;
        this->accType = accType;
        this->orderList = oList;
    }

    void showInfo() {
        cout << "Customer: " << name << "\n";
        cout << "Account type: " << ((accType == 2) ? "Gold" : "Normal") << "\n";
        cout << "Order list: \n";
        for (int i = 0; i < orderList.size(); i++) {
            orderList[i].showInfo();
        }
    }

    void buyProduct(const vector<Product>& prodList) {
        double totExpense = 0.0;
        for (int i = 0; i < prodList.size(); i++) {
            if (accType == 2) { // Gold account
                totExpense += (prodList[i].price * (1 - DISCOUNT_RATE));
            } else { // Normal account
                totExpense += prodList[i].price;
            }
        }

        int orderID = orderList.size() + 1;
        orderList.push_back(Order(orderID, prodList, totExpense));
    }
};

int main() {
    Product pd1("Shoe", 20), pd2("Car", 1000), pd3("Book", 10);

    // Initialize shop1 with products
    Shop shop1("Shop 1", vector<Product>{pd1, pd2, pd3});
    shop1.showInfo();

    cout << "\n";

    // Create customers and simulate purchases
    Customer acc1("Name 1", 1);
    acc1.buyProduct(vector<Product>{pd1});
    acc1.buyProduct(vector<Product>{pd1, pd2, pd3});
    acc1.showInfo();

    cout << "\n";

    Customer acc2("Name 2", 2);
    acc2.buyProduct(vector<Product>{pd1});
    acc2.buyProduct(vector<Product>{pd1, pd2, pd3});
    acc2.showInfo();

    cout << "\n";

    return 0;
}