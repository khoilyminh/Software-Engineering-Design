#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string name;
    int price;

public:
    Book(string name, int price) : name(name), price(price) {}

    void display() const {
        cout << "Name: " << name << ", Price: " << price << endl;
    }

    int getPrice() const {
        return price;
    }
};

int main() {
    // a) Create three Book objects using dynamic memory allocation
    Book* books[3];
    for (int i = 0; i < 3; i++) {
        string name;
        int price;
        cout << "Enter name and price for book " << i + 1 << ": ";
        cin >> name >> price;
        books[i] = new Book(name, price);
        if (books[i] == nullptr) {
            cerr << "Memory allocation failed!" << endl;
            return 1;
        }
    }

    // Print and free memory
    for (Book* book : books) {
        book->display();
        delete book;
    }

    // b) Create an array of n Book objects
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    Book* bookArray = new Book[n];
    if (bookArray == nullptr) {
        cerr << "Memory allocation failed!" << endl;
        return 1;
    }

    // Input values for the books
    for (int i = 0; i < n; i++) {
        string name;
        int price;
        cout << "Enter name and price for book " << i + 1 << ": ";
        cin >> name >> price;
        bookArray[i] = Book(name, price);
    }

    // Find the most expensive book
    int mostExpensiveIndex = 0;
    for (int i = 1; i < n; i++) {
        if (bookArray[i].getPrice() > bookArray[mostExpensiveIndex].getPrice()) {
            mostExpensiveIndex = i;
        }
    }
    cout << "The most expensive book is: ";
    bookArray[mostExpensiveIndex].display();

    // Free memory
    delete[] bookArray;

    return 0;
}
