#include <iostream>
#include <string>
using namespace std;

//variables used
/*Book- title , author.
User- name, user_password , correct_password .
Librarian: name, obj , librarian_password , correct_password .
main()- l1 , u1, answer (mode selection choice), tries (failed login attempt counter).*/

void runLib();
void runUser();

class Book {
    string title;
    string author;
    
public:
    Book() : title("N/A"), author("N/A") {}

    void setbook() {
        cout << "Enter the name of book: ";
        cin >> title;
        cout << "Enter the author of the book: ";
        cin >> author;
    }

    ~Book();
};

Book::~Book() {
    // no special cleanup required
}

class User {
private:
    string name;
    string user_password;
    string correct_password; // Fixed: keep the correct password separate

public:
    User() : correct_password("user"), name("UserJohn"), user_password("") {}

    void returnbook(Book& ob) {
        ob.setbook();
    }

    bool verify_password() {
        if(user_password == correct_password) {
            cout << "correct password\n";
            return true;
        } else {
            cout << "you have entered the wrong password\n";
            cout << "Try again\n";
            return false;
        }
    }

    bool EnterPassword() {
        cout << "Enter your password: ";
        cin >> user_password;
        return true;
    }
};

class Librarian { // Fixed spelling from Libarian
private:
    string name;
    Book obj; 
    string librarian_password;
    string correct_password;

public:
    Librarian() : correct_password("lib"), name("LibJohn"), librarian_password("") {}

    void issue_book(Book& ob) {
        ob.setbook();
        cout << "The book has been issued\n";
    }

    bool verify_password() {
        if(librarian_password == correct_password) {
            cout << "correct password\n";
            return true;
        } else {
            cout << "you have entered the wrong password\n";
            cout << "Try again\n";
            return false;
        }
    }

    bool EnterPassword() {
        cout << "Enter your password: ";
        cin >> librarian_password;
        return true;
    }
};

int main() {
    Librarian l1;
    User u1;
    string answer;
    int tries = 0;

    cout << "Welcome to group 29's OOP group work" << endl;
    cout << " Are you:\n    1. Librarian mode or\n    2. User mode \n:";
    cin >> answer;

    if(answer == "1") { // Librarian Mode
        do {
            l1.EnterPassword();
            if(l1.verify_password() == true) {
                runLib();
                break;
            }
            tries += 1;
        } while(tries < 5);
    }
    else if (answer == "2") { // User Mode
        do {
            u1.EnterPassword();
            if(u1.verify_password() == true) {
                runUser();
                break;
            }
            tries += 1;
        } while(tries < 5);
    }

    cout << "Byeeee\n";
    return 0;
}

void runLib() {
    while(true) {
        cout << "Running Librarian Dashboard...\n";
    }
}

void runUser() {
    while(true) {
        cout << "Running User Dashboard...\n";
    }
}