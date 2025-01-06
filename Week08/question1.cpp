#include <iostream>
using namespace std;

//CLASS DECLARATION
class Node{
    private:
        int value;
        Node *next = nullptr; //by default points to nothing
        Node *prev = nullptr; //by default points to nothing

    public:
        Node(int value=0): value(value){}

        //method to set connections to other nodes
        void setLinks(Node *next, Node *prev){
            this->next = next;
            this->prev = prev;
        }

        //friend functions for access to private attributes
        friend void printForwardLL(Node *head);
        friend void printBackwardLL(Node *tail);
        friend void insertNode(Node *&head, Node *&tail, Node *priorNode, Node *newNode);
        friend void deleteNode(Node *&head, Node *&tail, Node *delNode);
        friend void swapNodes(Node *&head, Node *&tail, Node *first, Node *second);
        friend void sortLL(Node *&head, Node *&tail);
};

//(a) print out values of connected nodes in forward order
void printForwardLL(Node *head){
    Node *curr = head;   //curr is the current node
    while(curr != nullptr){
        cout << curr->value << " --> "; //print out value of current node
        curr = curr->next;  //advance to the next node
    }
    cout << "\n";
}
//(a) print out values of connected nodes in backward order
void printBackwardLL(Node *tail){
    Node *curr = tail;  //curr is the current node
    while(curr != nullptr){
        cout << curr->value << " --> "; //print out value of current node
        curr = curr->prev; //advance to the next node
    }
    cout << "\n";
}
//(b) insert node function. Take note of the requirements in the question
//NOTE: *& is pass-by-preference for the pointer variable
//(same as pass-by-reference for a normal data type)
void insertNode(Node *&head, Node *&tail, Node *priorNode, Node *newNode){
    //if priorNode is nullptr, insert new node as the first node
    if(priorNode == nullptr){   
        //connect newNode as the first node
        newNode->next = head;
        newNode->next->prev = newNode;
        //head is pointing to newNode as the first node
        head = newNode;
    }else{  //else, insert new node right after the priorNode
        //connect newNode to the node after the priorNode
        newNode->next = priorNode->next;
        newNode->next->prev = newNode;
        //connect priorNode to the newNode
        priorNode->next = newNode;
        newNode->prev = priorNode;
        //if priorNode is the last node (i.e. tail is pointing to priorNode), insert new node as the last node
        if(tail == priorNode){
            tail = newNode;
        }
    }
}
//(b) delete node function. Take note of the requirements in the question
void deleteNode(Node *&head, Node *&tail, Node *delNode){
    //if delNode is the head (i.e. head is pointing to delNode), position the head pointer to the correct node.
    if(head == delNode){
        head = delNode->next;
        head->prev = nullptr;
        delNode->next = nullptr;
    //if delNode is the tail, position tail pointer to the correct last node 
    }else if(tail == delNode){
        tail = delNode->prev;
        delNode->prev = nullptr;
        tail->next = nullptr;
    }else{ //delete node normally if both conditions above did not meet
        delNode->next->prev = delNode->prev;
        delNode->prev->next = delNode->next;
        delNode->next = delNode->prev = nullptr;
    }
}
//(c) swap function to swap two nodes (pointed by first and second pointers in the parameter list)
void swapNodes(Node *&head, Node *&tail, Node *first, Node *second){
    //swap nodes
    second->prev = first->prev;
    first->prev = second;
    first->next = second->next;
    second->next = first;
    
    //position head pointer to the correct position if head is pointing to node pointed by first pointer
    if(head != first)
        second->prev->next = second;
    else
        head = second;
    
    //position tail pointer to the correct position if tail is pointing to node pointed by second pointer
    if(tail != second)
        first->next->prev = first;
    else
        tail = first;
}        
//(d) sort the nodes in the linked list in ascending order using bubble sort
void sortLL(Node *&head, Node *&tail){
    //position curr to where the head is pointing. curr pointer will move along the linked list
    Node *curr = head;
    
    //find the number of nodes in the linked list
    int count = 0;
    while(curr != nullptr){
        count++;
        curr = curr->next;
    }

    //if there are n nodes, then there will be (n-1) iterations in the bubble sort
    //use outer for loop for the (n-1) iterations
    for(int i = (count-1); i > 0; i--){
        curr = head;   //after each round, position curr to the first node (i.e. node pointed by head)
        //perform inner loop. Inner loop depends on the i variable of the outer loop
        for(int j=0; j < i; j++){
            //if the value pointed by current node is greater than the value pointed by the next node,
            //swap the nodes, else advance curr pointer to the next node. 
            if(curr->value > curr->next->value){
                swapNodes(head, tail, curr, curr->next);
            }else{
                curr = curr->next;
            }          
        }
    }
}

int main()
{
    //(a)
    Node node1(8), node2(5), node3(3), node4(6);
    //connect nodes
    Node *head = &node1; //head is a pointer variable
    
    node1.setLinks(&node2, nullptr);
    node2.setLinks(&node3, &node1);
    node3.setLinks(&node4, &node2);
    node4.setLinks(nullptr, &node3);

    Node *tail = &node4; //tail is a pointer variable

    //show connections
    cout << "Print forward.\n";
    printForwardLL(head);

    cout << "Print backward.\n";
    printBackwardLL(tail);

    //(b)
    Node node5(100), node6(200);
    
    insertNode(head, tail, nullptr, &node5);
    insertNode(head, tail, &node3, &node6);
    deleteNode(head, tail, &node2);

    cout << "After inserting and deleting nodes.\n";
    printForwardLL(head);
    printBackwardLL(tail);

    //(c) swap the last two nodes
    swapNodes(head, tail, &node6, &node4);

    cout << "After swapping nodes.\n";
    printForwardLL(head);
    printBackwardLL(tail);

    //(d) sort the linked list
    sortLL(head, tail);
    cout << "After sorting.\n";
    printForwardLL(head);
    
    return 0;
}