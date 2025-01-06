#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Block {
private:
    int id;
    string hash;
    Block* prev = nullptr;
public:
    // Constructor
    Block(int id, string hash, Block* prev) : id(id), hash(hash), prev(prev) {}

    // Getters
    int getId() const { return id; }
    string getHash() const { return hash; }
    Block* getPrev() const { return prev; }
};

// Reads block data from "chain.dat" and constructs a linked list of Block objects
void readData(Block*& head) {
    ifstream file("chain.dat");
    int id;
    string hash;

    while (file >> id >> hash) {
        head = new Block(id, hash, head);
    }
}

// Prints the blockchain to the console
void showChain(Block*& head) {
    Block* current = head;
    while (current != nullptr) {
        cout << "Block ID:  " << current->getId() << endl;
        cout << "Hash:      " << current->getHash() << endl;
        if (current->getPrev() != nullptr) {
            cout << "Prev Hash: " << current->getPrev()->getHash() << endl;
        } else {
            cout << "Prev Hash: None (Genesis Block)" << endl;
        }
        cout << endl; // for better readability
        current = current->getPrev();
    }
}

int main() {
    Block* head = nullptr;
    readData(head);
    showChain(head);
    return 0;
}
