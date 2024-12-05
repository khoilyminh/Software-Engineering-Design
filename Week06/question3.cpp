#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string* name;
    int price;

public:
    Book(string name, int price) : price(price) {
        this->name = new string(name);
        if (this->name == nullptr) {
            cerr << "Memory allocation failed!" << endl;
            exit(1);
        }
    }

    // Copy Constructor
    Book(const Book& other) : price(other.price) {
        this->name = new string(*other.name);
        if (this->name == nullptr) {
            cerr << "Memory allocation failed!" << endl;
            exit(1);
        }
    }

    // Copy Assignment Operator
    Book& operator=(const Book& other) {
        if (this != &other) {
            delete name;
            this->name = new string(*other.name);
            if (this->name == nullptr) {
                cerr << "Memory allocation failed!" << endl;
                exit(1);
            }
            this->price = other.price;
        }
        return *this;
    }

    ~Book() {
        delete name;
    }

    void display() const {
        cout << "Name: " << *name << ", Price: " << price << endl;
    }

    int getPrice() const {
        return price;
    }
};

int main() {
    // Create a Book object
    Book book1("The Hitchhiker's Guide to the Galaxy", 25);

    // Test Copy Constructor
    Book book2 = book1;

    // Test Copy Assignment Operator
    Book book3("Another Book", 10);
    book3 = book1;

    // Display all books
    book1.display();
    book2.display();
    book3.display();

    return 0;
}