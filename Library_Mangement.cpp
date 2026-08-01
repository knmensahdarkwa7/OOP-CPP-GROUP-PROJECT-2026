#include <iostream>
#include <string>
using namespace std;

// Forward declarations for function prototypes (functions defined at the bottom)
void runLib();
void runUser();

// ============================================================================
// CLASS: Book
// Represents a book entity inside the library system.
// ============================================================================
class Book {
private:
    string title;
    string author;
    
public:
    // Default Constructor: Initializes default placeholders for title and author
    Book() : title("N/A"), author("N/A") {}

    // Function to capture and set book details from user input
    void setbook() {
        cout << "Enter the name of book: ";
        cin >> title;
        cout << "Enter the author of the book: ";
        cin >> author;
    }

    // Destructor: Cleans up when a Book object goes out of scope
    ~Book();
};

Book::~Book() {
    // No dynamic memory cleanup required for standard std::string members
}

// ============================================================================
// CLASS: User
// Represents standard library users/students attempting to access user services.
// ============================================================================
class User {
private:
    string name;
    string user_password;      // Stores password entered at runtime
    string correct_password;   // Hardcoded authentication baseline

public:
    // Constructor: Sets default user identity and target password credentials
    User() : correct_password("user"), name("UserJohn"), user_password("") {}

    // Function allowing users to return a book back into system records
    void returnbook(Book& ob) {
        ob.setbook();
    }

    // Authenticates typed password against preset credential
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

    // Prompts input stream to collect candidate password
    bool EnterPassword() {
        cout << "Enter your password: ";
        cin >> user_password;
        return true;
    }
};

// ============================================================================
// CLASS: Librarian
// Represents administrative users managing library issuances and ops.
// ============================================================================
class Librarian { 
private:
    string name;
    Book obj;                   // Composition: Librarian object manages a Book
    string librarian_password;  // Stores password entered at runtime
    string correct_password;    // Hardcoded authentication baseline

public:
    // Constructor: Sets default admin identity and baseline password
    Librarian() : correct_password("lib"), name("LibJohn"), librarian_password("") {}

    // Issues a book to a user by populating details
    void issue_book(Book& ob) {
        ob.setbook();
        cout << "The book has been issued\n";
    }

    // Authenticates librarian's entered password against preset credential
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

    // Prompts input stream to collect candidate password
    bool EnterPassword() {
        cout << "Enter your password: ";
        cin >> librarian_password;
        return true;
    }
};

// ============================================================================
// MAIN FUNCTION: Entry Point & Core Application Loop
// ============================================================================
int main() {
    // Instantiate core objects
    Librarian l1;
    User u1;
    
    string answer;
    int tries = 0;

    cout << "Welcome to group 29's OOP group work" << endl;
    cout << " Are you:\n    1. Librarian mode or\n    2. User mode \n:";
    cin >> answer;

    // --- MODE 1: LIBRARIAN AUTHENTICATION ---
    if(answer == "1") { 
        do {
            l1.EnterPassword();
            // Validate entered password against master secret
            if(l1.verify_password() == true) {
                runLib(); // Trigger administrative dashboard loop
                break;    // Exit login loop upon successful session termination
            }
            tries += 1;
        } while(tries < 5); // Limit retry attempts to 5 max tries
    }
    // --- MODE 2: USER AUTHENTICATION ---
    else if (answer == "2") { 
        do {
            u1.EnterPassword();
            // Validate entered password against user credentials
            if(u1.verify_password() == true) {
                runUser(); // Trigger standard student dashboard loop
                break;     // Exit login loop upon session exit
            }
            tries += 1;
        } while(tries < 5); // Limit retry attempts to 5 max tries
    }

    cout << "Byeeee\n";
    return 0;
}

// ============================================================================
// DASHBOARD CONTROLLERS
// ============================================================================

// Librarian Dashboard Logic (Runs continuously during administrative sessions)
void runLib() {
    while (true) {
        cout << "Running Librarian Dashboard...\n";
        // TODO: Add menu options for issuing books, managing records, or logging out
        break; // Temporary break to avoid infinite print loops during testing
    };
}

// User Dashboard Logic (Runs continuously during student/user sessions)
void runUser() {
    while(true) {
        cout << "Running User Dashboard...\n";
        // TODO: Add menu options for returning books, searching catalog, or logging out
        break; // Temporary break to avoid infinite print loops during testing
    }
}