#include <iostream>
using namespace std;

class Broker{
    private:
        string name;
        int buyPrice;
        Broker *nextBuyer = nullptr;
    
    public:
        //constructor
        Broker(string name="", int buyPrice=0)
            :name(name), buyPrice(buyPrice){}

        void setNextBuyer(Broker *next){
            this->nextBuyer = next;
        }

        int getProfit(){
            return (nextBuyer->buyPrice - this->buyPrice);
        }
        
        friend void viewTransact(Broker *head);
        friend void lowestProfit(Broker *head);
};

/*(a)*/
void viewTransact(Broker *head){
    if(head == nullptr){
        cout << "There's no transaction.\n";
    }else{
        Broker *curr = head;

        cout << curr->name << ": initially bought the house for $" 
            << curr->buyPrice << "\n";
        
        while(curr->nextBuyer != nullptr){ 
            cout << curr->name << " --> " 
                << curr->nextBuyer->name 
                << " : price = $" << curr->nextBuyer->buyPrice 
                << "\n";
            curr = curr->nextBuyer; 
        }
    }
}
/*(b)*/
void lowestProfit(Broker *head){
    if(head == nullptr){
        cout << "There's no transaction.\n";
    }else if(head->nextBuyer == nullptr){
        cout << "There's only one buyer. Therefore, no profit yet.\n";
    }else{
        Broker *lowestBroker = nullptr;
        Broker *curr = head;

        lowestBroker = curr;
        curr = curr->nextBuyer;
        while(curr->nextBuyer != nullptr){
            if(lowestBroker->getProfit() > curr->getProfit())
                lowestBroker = curr;
            curr = curr->nextBuyer;
        }

        cout << "Broker with the lowest profit: " 
            << lowestBroker->name << " with profit of "
            << lowestBroker->getProfit() << "\n";
    }
}

int main()
{
    Broker b1("David", 800), b2("John", 1000), 
        b3("Peter", 1200), b4("Luna", 1800), 
        b5("Sophia", 3500);
    
    Broker *head = &b1;
    b1.setNextBuyer(&b2);
    b2.setNextBuyer(&b3);
    b3.setNextBuyer(&b4);
    b4.setNextBuyer(&b5);
    b5.setNextBuyer(nullptr);

      //(a)
    cout << "Real estate transactions\n";
    viewTransact(head);

    //(b)
    cout << "Broker with lowest profile\n";
    lowestProfit(head);

    return 0;
}