#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;

class FBooker {
    private:
        string name;
        vector <FBooker* > friends;

    public:
        //constructor
        FBooker(string name="", vector <FBooker *> friends={})
            : name(name), friends(friends){}

        //Add friends method
        void addFriend(FBooker &aFriend){
            if(!friends.empty()){
                for(int i=0; i<friends.size(); i++){
                    if(friends[i]->name.compare(aFriend.name)==0){
                        cout << friends[i]->name << " is already a friend of " << this->name << "\n";
                        return; 
                    }
                }
            }
            friends.push_back(&aFriend);
            aFriend.friends.push_back(this);
        }

        //View friends method
        void viewFriends() {
            cout << "\nFriends of " << this->name << ":\n";
            for (FBooker* aFriend : friends) {
                cout << aFriend->name << "   ";

            }
            cout << "\n";
        }

        //View friends of friends
        void viewFriendsOfFriends(){
            cout << "\nFriends of friends of " << this->name << ":\n";
            for (FBooker* aFriend : friends) {
                for (FBooker *fof: aFriend->friends) {
                    if (fof != this) { //not including the user itself
                        cout << fof->name << "   ";
                    }
                }

            }
            cout << "\n";
        }
        
        //View mutual friends
        void viewMutualFriends(FBooker &aFriend) {
            cout << "\nMutual friends of " << this->name << " and " << aFriend.name << ":\n";
            for (FBooker* myFriends : friends) {
                for (FBooker *hisFriends: aFriend.friends) {
                    if (myFriends == hisFriends) { 
                        cout << myFriends->name << "   ";
                    }
                }
            }
        }
};

int main(){
    //(a) view friends
    FBooker ling("Ling"), michael("Michael"), john("John"), owen("Owen");
    
    ling.addFriend(michael);
    ling.addFriend(owen);
    michael.addFriend(john);
    michael.addFriend(owen);

    ling.viewFriends();
    michael.viewFriends();

    //(b) show friends of friends
    ling.viewFriendsOfFriends();

    //(c) show mutual friends
    ling.viewMutualFriends(michael);

    return 0;
}