#include <iostream>
using namespace std;


class Book{
    string title;
    string author;
    
    public:
    Book():title("N/A"),author("N/A"){}


    void setbook(){
        cout<<"Enter the name of book: ";
        cin>> title;
        cout<< "Enter the author of the book: ";
        cin>> author;
    }

    ~Book();

};

Book::~Book() {
    // no special cleanup required
}

class User{
    private:
    string name;
    string user_password;

    public:
    User():user_password("user"),name("UserJohn"){}
    void returnbook(Book& ob){
        ob.setbook();
    }

    bool verify_password(){
        if(user_password == "user"){
            cout<<"correct password";
            return true;
        }
        else{
            cout<<"you have entered the wrong password"<<endl;
            cout<<"Try again"<< endl;
            return false;
        }
        
    }
    bool EnterPassword(){
        cout<<"Enter your password: ";
        cin>> user_password;
    }


};

class Libarian{
    private:
    string name;
    Book obj; 
    string Libarian_password;

    public:
    Libarian():Libarian_password("lib"),name("LibJohn"){}

    void issue_book(Book& ob){
        ob.setbook();
        cout<< "The book has been issued";
    }

    bool verify_password(){
        if(Libarian_password == "lib"){
            cout<<"correct password";
            return true;
        }
        else{
            cout<<"you have entered the wrong password"<<endl;
            cout<< "Try again";
            return false;
        }
        
    }

    bool EnterPassword(){
        cout<<"Enter your password: ";
        cin>> Libarian_password;
    }

};

int main(){
    Libarian l1;
    User u1;
    string answer;
    int tries = 0;

    cout<<"Welcome to group 29's OOP group work"<<endl;
    cout<<" Are you:\n    1.user mode or\n    2.Librarian mode "<<endl;
    cin>>answer;
    if(answer  == "1"){
        do{
            l1.EnterPassword();
            l1.verify_password();
            if(l1.verify_password() == true){
                runLib();
                break;
            }
            tries += 1;
            
        }while(tries < 5);
    }
    else if (answer == "2")
    {
        do{
            u1.EnterPassword();
            u1.verify_password();
            if(u1.verify_password() == true){
                runUser();
                break;
            }
            tries += 1;
            
        }while(tries < 5);
    }

    cout<< "Byeeee";

    return 0;

}

void runLib(){
    while(true){
        cout<<"run Lib";
        //finish morrow
    }

}
void runUser(){
    while(true){
        cout<< "run Lib";
        //finish morrow
    }
}

