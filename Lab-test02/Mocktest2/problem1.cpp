#include <iostream>
#include <string>
using namespace std;

class Block {
public:
    int blockID;
    string hash;
    string prevHash;
    Block* next;

    Block(int id, string h, string prev) : blockID(id), hash(h), prevHash(prev), next(nullptr) {}
};

class Blockchain {
private:
    Block* head;

public:
    Blockchain() : head(nullptr) {}

    void addBlock(int id, string hash, string prevHash) {
        Block* newBlock = new Block(id, hash, prevHash);
        newBlock->next = head;
        head = newBlock;
    }

    void showChain() {
        Block* current = head;
        while (current) {
            cout << "Block ID: " << current->blockID << endl;
            cout << "Hash: " << current->hash << endl;
            cout << "Prev: " << current->prevHash << endl << endl;
            current = current->next;
        }
    }
};

int main() {
    Blockchain chain;
    chain.addBlock(3, "ghi789", "def456");
    chain.addBlock(2, "def456", "abc123");
    chain.addBlock(1, "abc123", "nullptr");

    cout << "Blockchain:" << endl;
    chain.showChain();

    return 0;
}
