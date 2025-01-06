#include <iostream>
#include <vector>
using namespace std;

#define SIZE 3
//(a)
class Book{
    private:
        string title;
        int availableCopies;
        vector<string> namesOfBorrowers;
    
    public:
        Book(string title="", int availableCopies=0, vector<string> namesOfBorrowers={})
            : title(title), availableCopies(availableCopies), namesOfBorrowers(namesOfBorrowers){}

        void showInfo(){
            cout << "Book title: " << title << endl;
            cout << "Available copies: " << availableCopies << endl;        
            cout << "Borrowers list: ";
            
            if(namesOfBorrowers.empty())
            {
                cout << "None.\n";
            }else{
                cout << "\n";
                for(string i : namesOfBorrowers){
                    cout << i << endl;
                }
            }
            cout << endl;
        }

        friend class User;  //friend class to grant access to private attributes of Book class in User class
};
//(b)
class User{
    protected:
        string name;
        vector<Book*> borrowedBooks; //vector of Book object pointers

    public:
        User(){}
        User(string name, vector<Book*> borrowedBooks){
            this->name = name;
            this->borrowedBooks = borrowedBooks;
        }

        bool doBorrow(Book &abook){
            //if availableCopies of the book is 0, then cannot perform the borrowing
            if(abook.availableCopies == 0){
                cout << "No copy of the book " << abook.title << "available in library.\n";
                return false;
            }
            
            //insert the address of abook into the borrowedBooks list
            //all location in the borrowedBooks are pointers
            borrowedBooks.push_back(&abook);
            //insert the name of the borrower in namesOfBorrowers list
            abook.namesOfBorrowers.push_back(this->name);
            //decrement availableCopies of the book by 1
            abook.availableCopies--;
            
            return true;
        }

        void doReturn(Book &abook){
            for(int i = 0; i < borrowedBooks.size(); i++){
                if(borrowedBooks[i]->title.compare(abook.title) == 0)
                {
                    for(int j = 0; j < abook.namesOfBorrowers.size(); j++){
                        if(abook.namesOfBorrowers[j].compare(this->name) == 0)
                        {
                            abook.namesOfBorrowers.erase(abook.namesOfBorrowers.begin()+j);
                            abook.availableCopies++;
                            borrowedBooks.erase(borrowedBooks.begin()+i);
                            cout << "Book title " << abook.title << " returned successfully.\n";
                            return;
                        }
                    }
                    cout << "Borrower's name for this book " << abook.title << " not in the list.\n";
                    return;
                }
            }
            cout << "This book " << abook.title << " is not in the borrowed book list.\n";
        }

        void showInfo(){
            cout << "Name: " << name << endl;
            cout << "Borrowed books: ";

            if(borrowedBooks.empty())
            {
                cout << "None.\n";
            }else{
                cout << "\n";

                for(Book* i : borrowedBooks){
                    cout << i->title << endl; 
                }
            }
            cout << endl;
        }
};
//(d)
class SuperUser : public User{
    public:
        SuperUser(string name="", vector<Book *> borrowedBooks={})
            :User(name, borrowedBooks){};

        //function overriding
        bool doBorrow(Book &book1, Book &book2){
            if(User::doBorrow(book1) && User::doBorrow(book2))
                return true;
            
            return false;
        }
};

int main()
{
    /*Create a vector of three Book objects using Dynamic memory allocation*/
    
    // Review: this is the way to request memory allocation and 
    // intialize values for an array of objects
    
    // Book *bookArr = new Book[3]{
    //     Book("Book1", 3, vector<string>{} ), 
    //     Book("Book2", 3, vector<string>{} ),
    //     Book("Book3", 3, vector<string>{} )
    // }


    /*  Solution: create a vector of Boook object pointers,
        and intialize it with three pointers of dynamically allocated objects
        (it is not allowed to request memory allocation for any vector since 
        its size is not fixed)
    */
    //Note: for constructor of each object above, we pass in an empty vector

    vector<Book*> books = {
        new Book("Book1", 3, vector<string>{} ), 
        new Book("Book2", 3, vector<string>{} ),
        new Book("Book3", 3, vector<string>{} )
    };
    
    User user1("Ling Huo Chong", vector<Book *>{}), user2("Michael John", vector<Book *>{});

    cout << "Initial\n";

    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();
    user1.showInfo();
    user2.showInfo();

    cout << "\nSome borrowing\n";

    user1.doBorrow(*books[0]);
    user1.doBorrow(*books[1]);
    user2.doBorrow(*books[1]);
    user2.doBorrow(*books[2]);
    
    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();
    user1.showInfo();
    user2.showInfo();

    cout << "\nSome returning\n";

    user1.doReturn(*books[2]);
    user1.doReturn(*books[1]);
    user2.doReturn(*books[1]);

    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();
    user1.showInfo();
    user2.showInfo();

    cout << "SuperUser mode\n";

    SuperUser sUser1("Rasmus Hojlund", vector<Book *>{});
    sUser1.showInfo();
    
    sUser1.doBorrow(*books[0], *books[1]); 
    
    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();
    
    sUser1.showInfo();
    
    //free memory allocated previously for books from line 141-145
    for(Book* i : books)
        delete i;   

    return 0;
}
