#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Book {
public:
    int id; 
    string title;
    string author;
    int publicationYear;

    Book() : id(0), title(""), author(""), publicationYear(0) {}

    Book(int id_, const string& title_, const string& author_, int year_)
        : id(id_), title(title_), author(author_), publicationYear(year_) {}

    void show() const {
        cout << "ID: " << id << "\n"
            << "Title: " << title << "\n"
            << "Author: " << author << "\n"
            << "Publication Year: " << publicationYear << "\n";
    }
};

class Library {
private:
    unordered_map<int, Book> books; 

public:
    void addBook(const Book& book) {
        if (books.count(book.id) == 0) {
            books[book.id] = book;
            cout << "Book added.\n";
        }
        else {
            cout << "A book with this ID already exists.\n";
        }
    }

    void removeBook(int id) {
        if (books.erase(id)) {
            cout << "Book removed.\n";
        }
        else {
            cout << "Book with this ID not found.\n";
        }
    }

    void findBook(int id) const {
        auto it = books.find(id);
        if (it != books.end()) {
            it->second.show();
        }
        else {
            cout << "Book not found.\n";
        }
    }

    void displayAll() const {
        if (books.empty()) {
            cout << "Library is empty.\n";
        }
        else {
            for (const auto& pair : books) {
                pair.second.show();
                cout << "-------------------\n";
            }
        }
    }
};

int main() {
    Library lib;

    lib.addBook(Book(1, "War and Peace", "Leo Tolstoy", 1869));
    lib.addBook(Book(2, "Crime and Punishment", "Fyodor Dostoevsky", 1866));
    lib.addBook(Book(3, "The Master and Margarita", "Mikhail Bulgakov", 1966));

    cout << "Book list:\n";
    lib.displayAll();

    cout << "\nSearching for book with ID 2:\n";
    lib.findBook(2);

    cout << "\nRemoving book with ID 1:\n";
    lib.removeBook(1);

    cout << "\nUpdated book list:\n";
    lib.displayAll();
}