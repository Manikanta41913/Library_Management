#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    int bookID;
    string bookName, shelfPosition;
    string authorName;
    int yearOfPublication, bookCount, floorNumber;

    Book(int bookID, string bookName, string authorName, int yearOfPublication, int bookCount, int floorNumber, string shelfPosition) {
        this->bookID = bookID;
        this->bookName = bookName;
        this->authorName = authorName;
        this->yearOfPublication = yearOfPublication;
        this->floorNumber = floorNumber;
        this->shelfPosition = shelfPosition;
        this->bookCount = bookCount;
    }
};

class LibraryManagementSystem {
public:
    vector<Book> books;

    void addBook(string bookName, string authorName, int yearOfPublication, int bookCount, int floorNumber, string shelfPosition) {
        Book newBook(books.size() + 1, bookName, authorName, yearOfPublication, bookCount, floorNumber, shelfPosition);
        books.push_back(newBook);
    }
    
    void searchBook(string BookName){
    	for(int i = 0; i < books.size(); i++){
    		if(books[i].bookName == BookName){
    		cout << "\nBook ID: " << books[i].bookID << endl;
            cout << "Book Name: " << books[i].bookName << endl;
            cout << "Author Name: " << books[i].authorName << endl;
            cout << "Year of Publication: " << books[i].yearOfPublication << endl;
            cout << "Book Available: " << books[i].bookCount << endl;
            cout << "Floor Number: " << books[i].floorNumber << endl;
            cout << "Shelf Position: " << books[i].shelfPosition << endl;
            cout << endl;
            return;
			}
		}
        cout << "Book not found" << endl;
    }

    void displayBooks() {
        for (int i = 0; i < books.size(); i++){
            cout << "\nBook ID: " << books[i].bookID << endl;
            cout << "Book Name: " << books[i].bookName << endl;
            cout << "Author Name: " << books[i].authorName << endl;
            cout << "Year of Publication: " << books[i].yearOfPublication << endl;
            cout << "Book Available: " << books[i].bookCount << endl;
            cout << "Floor Number: " << books[i].floorNumber << endl;
            cout << "Shelf Position: " << books[i].shelfPosition << endl;
            cout << endl;
        }
    }

    void deleteBook(int bookID) {
        for (int i = 0; i < books.size(); i++){
            if(books[i].bookID == bookID){
                books.erase(books.begin() + i);
                cout << "Deleted the books successfully" << endl;
                return;
            }
        }
        cout << "Book not found" << endl;
        return;
    }

    int getAllBooksCount() {
        int TotalBooks = 0;
        for (int i = 0; i < books.size(); i++){
            TotalBooks += books[i].bookCount;
        }
        return TotalBooks;
    }
};


int main() {
string bookN;
LibraryManagementSystem libraryManagementSystem;

libraryManagementSystem.addBook("The Lord of the Rings", "J.R.R. Tolkien", 1954, 14, 2, "A12");
libraryManagementSystem.addBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979, 15, 2, "A12");
libraryManagementSystem.addBook("The Hunger Games", "Suzanne Collins", 2008, 17, 2, "A12");

while (true) {
    string bookName, authorName, shelfPosition;
    cout << "Press 1 to add a book to the library.\nPress 2 to get information about all books in library." << endl;
    cout << "Press 3 to get information by name.\nPress 4 to delete a book.\nPress 5 to get count of books in the library.\nPress 6 to exit." << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            int yearOfPublication, bookCount, floorNumber;

            cout << "Enter the book name: ";
            cin.ignore();
            getline(cin, bookName);
            cout << "Enter the author name: ";
            getline(cin, authorName);
            cout << "Enter the year of publication: ";
            cin >> yearOfPublication;
            cout << "Enter the number of books to be added: ";
            cin >> bookCount;
            cout << "Enter the floor number: ";
            cin >> floorNumber;
            cout << "Enter the shelf position: ";
            cin >> shelfPosition;

            libraryManagementSystem.addBook(bookName, authorName, yearOfPublication, bookCount, floorNumber, shelfPosition);
            break;
        case 2:
            libraryManagementSystem.displayBooks();
            break;
        case 3:
            cout << "Enter the name of the book to search: ";
            cin.ignore();
            getline(cin, bookN);
            libraryManagementSystem.searchBook(bookN);
            break;
        case 4:
            cout << "Enter the ID of the book to delete: ";
            int bookID;
            cin >> bookID;
            libraryManagementSystem.deleteBook(bookID);
            break;
        case 5:
            cout << "Total number of books in the library: " << libraryManagementSystem.getAllBooksCount() << "\n" << endl;
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}

return 0;
}
