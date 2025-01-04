#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

class Analyser {
private:
    Node* head;

public:
    Analyser() : head(nullptr) {}

    void addNode(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void traverseList() {
        Node* temp = head;
        bool inRange = false;

        while (temp) {
            if (temp->value == -1) {
                if (inRange) break;
                inRange = true;
            } else if (inRange) {
                cout << temp->value << "-->";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void removeNeg() {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp) {
            if (temp->value == -1) {
                if (prev) prev->next = temp->next;
                else head = temp->next;

                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        printList();
    }

    void printMin() {
        Node* temp = head;
        int minValue = INT_MAX;

        while (temp) {
            if (temp->value < minValue) minValue = temp->value;
            temp = temp->next;
        }

        cout << "Min is " << minValue << endl;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << "-->";
            temp = temp->next;
        }
        cout << endl;
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

    cout << "Linked list after traverseList is called" << endl;
    analyser.traverseList();

    cout << "\nLinked list after removeNeg is called" << endl;
    analyser.removeNeg();

    analyser.printMin();

    return 0;
}
