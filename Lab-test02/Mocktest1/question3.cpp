#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Product {
public:
    string name;
    double price;
    int stockQuantity;

    Product(string n, double p, int q) : name(n), price(p), stockQuantity(q) {}
};

class Customer {
public:
    string name;
    double lastBill;
    int loyaltyPoints;

    Customer(string n) : name(n), lastBill(0), loyaltyPoints(0) {}
};

class Shop {
private:
    string shopName;
    vector<Product> products;
    vector<Customer> customers;
    double totalRevenue;

public:
    Shop(string name) : shopName(name), totalRevenue(0) {}

    void addProduct(string name, double price, int quantity) {
        products.push_back(Product(name, price, quantity));
    }

    void addCustomer(string name) {
        customers.push_back(Customer(name));
    }

    void printBill(string customerName, unordered_map<string, int> purchases) {
        double billAmount = 0;
        for (auto& p : purchases) {
            string productName = p.first;
            int quantity = p.second;

            for (auto& product : products) {
                if (product.name == productName) {
                    if (product.stockQuantity >= quantity) {
                        billAmount += product.price * quantity;
                        product.stockQuantity -= quantity;
                    } else {
                        cout << "Insufficient stock for " << productName << endl;
                    }
                    break;
                }
            }
        }

        for (auto& customer : customers) {
            if (customer.name == customerName) {
                customer.lastBill = billAmount;
                customer.loyaltyPoints += static_cast<int>(billAmount);
                break;
            }
        }

        totalRevenue += billAmount;
        cout << "Bill for " << customerName << ": $" << billAmount << endl;
    }

    void processReturn(string customerName, string productName, int quantity) {
        for (auto& customer : customers) {
            if (customer.name == customerName) {
                for (auto& product : products) {
                    if (product.name == productName) {
                        double refund = product.price * quantity;
                        customer.lastBill -= refund;
                        customer.loyaltyPoints -= static_cast<int>(refund);
                        product.stockQuantity += quantity;
                        totalRevenue -= refund;

                        cout << "Refund for " << quantity << " " << productName << ": $" << refund << endl;
                        return;
                    }
                }
            }
        }
        cout << "Return not processed. Invalid product or customer." << endl;
    }

    void generateSalesReport() {
        cout << "\nSales Report:" << endl;
        cout << "Total Revenue: $" << totalRevenue << endl;

        string bestSellingProduct;
        int maxSales = 0;
        unordered_map<string, double> revenuePerProduct;

        for (auto& product : products) {
            double revenue = (product.stockQuantity - product.stockQuantity) * product.price;
            revenuePerProduct[product.name] = revenue;

            if (revenue > maxSales) {
                maxSales = revenue;
                bestSellingProduct = product.name;
            }
        }

        for (auto& entry : revenuePerProduct) {
            cout << entry.first << ": $" << entry.second << endl;
        }

        cout << "Best Selling Product: " << bestSellingProduct << endl;
    }
};

int main() {
    Shop shop("Retail Shop");

    // Add products
    shop.addProduct("Apple", 1.2, 50);
    shop.addProduct("Milk", 2.5, 30);
    shop.addProduct("Bread", 1.5, 20);

    // Add customers
    shop.addCustomer("John Doe");
    shop.addCustomer("Jane Smith");

    // Purchases 
    unordered_map<string, int> purchases;
    purchases.insert(make_pair("Apple", 10)); 
    purchases.insert(make_pair("Milk", 5)); 

    shop.printBill("John Doe", purchases);

    // Process a return
    shop.processReturn("John Doe", "Apple", 5);

    // Generate sales report
    shop.generateSalesReport();

    return 0;
}