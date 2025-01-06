#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* nextNode;

    Node(int val) : value(val), nextNode(nullptr) {}
};

class Analyser {
private:
    Node* head;
public:
    Analyser() : head(nullptr) {}

    void addNode(int val) {
        if (head == nullptr) {
            head = new Node(val);
        } else {
            Node* current = head;
            while (current->nextNode != nullptr) {
                current = current->nextNode;
            }
            current->nextNode = new Node(val);
        }
    }

    void traverseList() {
        Node* current = head;
        bool foundFirst = false;
        while (current != nullptr) {
            if (current->value == -1) {
                if (foundFirst) break;
                foundFirst = true;
            } else if (foundFirst) {
                cout << current->value << "-->";
            }
            current = current->nextNode;
        }
        cout << endl;
    }

    void removeNeg() {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->value == -1) {
                if (prev != nullptr) {
                    prev->nextNode = current->nextNode;
                    delete current;
                    current = prev->nextNode;
                } else {
                    head = current->nextNode;
                    delete current;
                    current = head;
                }
            } else {
                prev = current;
                current = current->nextNode;
            }
        }
    }

    void printMin() {
        if (head == nullptr) return;
        int minVal = head->value;
        Node* current = head->nextNode;
        while (current != nullptr) {
            if (current->value < minVal) {
                minVal = current->value;
            }
            current = current->nextNode;
        }
        cout << "Min is " << minVal << endl;
    }

    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << "-->";
            current = current->nextNode;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Analyser analyser;
    analyser.addNode(3);
    analyser.addNode(-1);
    analyser.addNode(5);
    analyser.addNode(2);
    analyser.addNode(7);
    analyser.addNode(-1);

    cout << "Linked list after traverseList is called:" << endl;
    analyser.traverseList();

    cout << "Linked list after removeNeg is called:" << endl;
    analyser.removeNeg();
    analyser.displayList();

    cout << "Min value in the list:" << endl;
    analyser.printMin();

    return 0;
}
