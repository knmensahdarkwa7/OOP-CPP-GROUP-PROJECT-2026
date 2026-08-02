#include <iostream>
#include <string>
using namespace std;

// Forward declarations
class Book;
void runLib(Book library[], int &bookCount);
void runUser(Book library[], int &bookCount);

// ============================================================================
// CLASS: Book
// ============================================================================
class Book {
private:
    string title;
    string author;
    bool isIssued; // Tracks if the book is currently borrowed

public:
    Book() : title("N/A"), author("N/A"), isIssued(false) {}

    void setbook() {
        cout << "Enter the title of book (single word or use _ for spaces): ";
        cin >> title;
        cout << "Enter the author of the book: ";
        cin >> author;
        isIssued = false;
    }

    void displayBook() {
        cout << "Title: " << title << " | Author: " << author 
             << " | Status: " << (isIssued ? "Issued" : "Available") << endl;
    }

    string getTitle() { return title; }
    bool getIsIssued() { return isIssued; }
    void setIssued(bool status) { isIssued = status; }

    ~Book() {}
};

// ============================================================================
// CLASS: User
// ============================================================================
class User {
private:
    string name;
    string user_password;
    string correct_password;

public:
    User() : correct_password("user"), name("UserJohn"), user_password("") {}

    void returnbook(Book library[], int bookCount) {
        if (bookCount == 0) {
            cout << "No books exist in the system to return.\n";
            return;
        }

        string returnTitle;
        cout << "Enter the title of the book you want to return: ";
        cin >> returnTitle;

        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (library[i].getTitle() == returnTitle) {
                found = true;
                if (library[i].getIsIssued()) {
                    library[i].setIssued(false);
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "This book was not marked as issued.\n";
                }
                break;
            }
        }
        if (!found) {
            cout << "Book not found in library records.\n";
        }
    }

    bool verify_password() {
        if (user_password == correct_password) {
            cout << "Correct password!\n";
            return true;
        } else {
            cout << "Wrong password. Try again.\n";
            return false;
        }
    }

    bool EnterPassword() {
        cout << "Enter User password: ";
        cin >> user_password;
        return true;
    }
};

// ============================================================================
// CLASS: Librarian
// ============================================================================
class Librarian { 
private:
    string name;
    string librarian_password;
    string correct_password;

public:
    Librarian() : correct_password("lib"), name("LibJohn"), librarian_password("") {}

    void add_book(Book library[], int &bookCount, int maxCapacity) {
        if (bookCount >= maxCapacity) {
            cout << "Library is at full capacity! Cannot add more books.\n";
            return;
        }
        cout << "\n--- Add New Book ---\n";
        library[bookCount].setbook();
        bookCount++;
        cout << "Book successfully added to the system!\n";
    }

    void issue_book(Book library[], int bookCount) {
        if (bookCount == 0) {
            cout << "No books available in the system.\n";
            return;
        }

        string issueTitle;
        cout << "Enter the title of the book to issue: ";
        cin >> issueTitle;

        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (library[i].getTitle() == issueTitle) {
                found = true;
                if (!library[i].getIsIssued()) {
                    library[i].setIssued(true);
                    cout << "The book '" << issueTitle << "' has been issued successfully!\n";
                } else {
                    cout << "Sorry, this book is already issued to someone else.\n";
                }
                break;
            }
        }
        if (!found) {
            cout << "Book not found in library records.\n";
        }
    }

    bool verify_password() {
        if (librarian_password == correct_password) {
            cout << "Correct password!\n";
            return true;
        } else {
            cout << "Wrong password. Try again.\n";
            return false;
        }
    }

    bool EnterPassword() {
        cout << "Enter Librarian password: ";
        cin >> librarian_password;
        return true;
    }
};

// Global library array & capacity setting
const int MAX_BOOKS = 50;
Book library[MAX_BOOKS];
int bookCount = 0;

// Helper function to view all catalog books
void displayAllBooks(Book library[], int bookCount) {
    if (bookCount == 0) {
        cout << "The library catalog is currently empty.\n";
        return;
    }
    cout << "\n--- Current Library Catalog ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << i + 1 << ". ";
        library[i].displayBook();
    }
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    Librarian l1;
    User u1;

    string mainChoice;

    while (true) {
        cout << "\n=========================================\n";
        cout << " Welcome to Group 2's Library System\n";
        cout << "=========================================\n";
        cout << "1. Librarian Mode\n";
        cout << "2. User Mode\n";
        cout << "3. Exit System\n";
        cout << "Select mode (1-3): ";
        cin >> mainChoice;

        if (mainChoice == "1") {
            int tries = 0;
            bool authenticated = false;
            do {
                l1.EnterPassword();
                if (l1.verify_password()) {
                    authenticated = true;
                    break;
                }
                tries++;
            } while (tries < 5);

            if (authenticated) {
                runLib(library, bookCount);
            } else {
                cout << "Too many failed attempts. Returning to main menu.\n";
            }
        } 
        else if (mainChoice == "2") {
            int tries = 0;
            bool authenticated = false;
            do {
                u1.EnterPassword();
                if (u1.verify_password()) {
                    authenticated = true;
                    break;
                }
                tries++;
            } while (tries < 5);

            if (authenticated) {
                runUser(library, bookCount);
            } else {
                cout << "Too many failed attempts. Returning to main menu.\n";
            }
        } 
        else if (mainChoice == "3") {
            cout << "Exiting system. Goodbye!\n";
            break;
        } 
        else {
            cout << "Invalid selection. Please try again.\n";
        }
    }

    return 0;
}

// ============================================================================
// DASHBOARD CONTROLLERS
// ============================================================================

void runLib(Book library[], int &bookCount) {
    Librarian admin;
    int choice;

    while (true) {
        cout << "\n-----------------------------------------\n";
        cout << "         LIBRARIAN DASHBOARD             \n";
        cout << "-----------------------------------------\n";
        cout << "1. Add a New Book to Library\n";
        cout << "2. Issue a Book to User\n";
        cout << "3. View All Books in Catalog\n";
        cout << "4. Logout / Exit Dashboard\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            admin.add_book(library, bookCount, MAX_BOOKS);
        } else if (choice == 2) {
            admin.issue_book(library, bookCount);
        } else if (choice == 3) {
            displayAllBooks(library, bookCount);
        } else if (choice == 4) {
            cout << "Logging out of Librarian Dashboard...\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }
}

void runUser(Book library[], int &bookCount) {
    User student;
    int choice;

    while (true) {
        cout << "\n-----------------------------------------\n";
        cout << "           USER DASHBOARD                \n";
        cout << "-----------------------------------------\n";
        cout << "1. View Catalog\n";
        cout << "2. Return a Book\n";
        cout << "3. Logout / Exit Dashboard\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if (choice == 1) {
            displayAllBooks(library, bookCount);
        } else if (choice == 2) {
            student.returnbook(library, bookCount);
        } else if (choice == 3) {
            cout << "Logging out of User Dashboard...\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }
}
