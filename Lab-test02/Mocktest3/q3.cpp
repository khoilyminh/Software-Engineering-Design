// Due to mismatch between different compiler version, run this command line to compile this file:
// g++ p3.cpp -o p3 -std=c++11
// g++ q1.cpp -o q1 (Normal execution prompt)


#include <iostream>
#include <vector>

using namespace std;

#define DISCOUNT_RATE 0.05

class Product{
    private:
        string name;
        double price;
    
    public:
        //constructor
        Product(string name="", double price=0.0)
            :name(name), price(price){}
        
        void showInfo(){
            cout << name << ", $" << price << "\n";
        }

        friend class Customer;
};

class Shop{
    private:
        string name;
        vector<Product> prodList; 
    
    public:
        Shop(string name="", vector<Product> prodList={})
            :name(name), prodList(prodList){}
        
        void showInfo(){
            cout << "Shop: " << name << "\n";
            cout << "Product list: \n";
            for(Product prod : prodList){
                prod.showInfo();
            }
        }
};

class Order{
    private:
       int orderID;
       vector<Product> boughtList;
       double totExpense;
    
    public:
        //constructor
        Order(int orderID=0, vector<Product> boughtList={}, double totExpense=0.0)
            : orderID(orderID), boughtList(boughtList), totExpense(totExpense){}

        void showInfo(){
            cout << "Order ID: " << orderID << "\n";
            cout << "Bought list: \n";
            for(Product prod : boughtList){
                prod.showInfo();
            }
            cout << "Total expense: " << totExpense << "\n";
        }    
};

class Customer{
    private:
        string name;
        vector<Order> orderList;
        int accType = 1; //normal account = 1, Gold account = 2
    
    public:
        //constructor
        Customer(string name="", int accType=1, vector<Order> orderList={})
            :name(name), accType(accType), orderList(orderList){}
        
        void showInfo(){
            cout << "Customer: " << name << "\n";
            cout << "Account type: " << ((accType== 2)?"Gold":"Normal") << "\n";
            cout << "Order list: \n";
            for(Order o : orderList){
                o.showInfo();
            }
        }

        void buyProduct(vector<Product> prodList){
            double totExpense = 0.0;
            for(Product prod : prodList){
                if(accType == 2) // Gold account
                    totExpense += (prod.price * (1-DISCOUNT_RATE));
                else //normal account
                    totExpense += prod.price;
            }

            int orderID = orderList.size() + 1;
            orderList.push_back(Order(orderID, prodList, totExpense));
        }

};

int main()
{
    Product pd1("Shoe", 20), pd2("Car", 1000), pd3("Book", 10);
    Shop shop1("Shop 1", {pd1, pd2, pd3});
    shop1.showInfo();

    cout << "\n";
    Customer acc1("Name 1", 1);
    acc1.buyProduct({pd1});
    acc1.buyProduct({pd1, pd2, pd3});
    acc1.showInfo();

    cout << "\n";
    Customer acc2("Name 2", 2);
    acc2.buyProduct({pd1});
    acc2.buyProduct({pd1, pd2, pd3});
    acc2.showInfo();

    cout << "\n";
    
    return 0;
}