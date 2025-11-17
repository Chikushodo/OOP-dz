#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Book
{
private:
	int id;
	string name;
	string author;
	int releaseYear;

public:

	Book(int id, string name, string author, int releaseYear)
	{
		this->id = id;
		this->name = name;
		this->author = author;
		this->releaseYear = releaseYear;
	}

	Book()
	{
		id = 0;
		name = "";
		author = "";
		releaseYear = 0;
	}


	int getId() const
	{
		return id;
	}
	string getName() const
	{
		return name;
	}

	string getAuthor() const
	{
		return author;
	}

	int getReleaseYear() const
	{
		return releaseYear;
	}


	void setId(int id_)
	{
		id = id_;
	}
	void setName(string name_)
	{
		name = name_;
	}
	void setAuthor(string author_)
	{
		author = author_;
	}
	void setReleaseYear(int releaseYear_)
	{
		releaseYear = releaseYear_;
	}
	void print() const
	{
		cout << "id: " << id << endl << "name: " << name << endl << "author: " << author << endl << "release year: " << releaseYear << endl;
	}
};

class Library
{
private:
	unordered_map<int, Book> books;
public:
	void addBook(const Book& book) {
		books[book.getId()] = book;
	}

	void removeBook(int id) {
		auto it = books.find(id);
		if (it != books.end()) {
			books.erase(it);
			cout << "Книга с ID " << id << " удалена." << endl;
		}
		else {
			cout << "Книга с ID " << id << " не найдена." << endl;
		}
	}

	Book* findBook(int id) {
		auto it = books.find(id);
		if (it != books.end()) {
			return &(it->second);
		}
		else {
			return nullptr;
		}
	}

	void printAllBooks() const {
		if (books.empty()) {
			cout << "Библиотека пуста." << endl;
		}
		else {
			for (const auto& pair : books) {
				pair.second.print();
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "RU");
	Library lib;

	lib.addBook(Book(1, "исповедь неполноценного человека", "Осаму Дадзай", 1948));
	lib.addBook(Book(2, "Демиан", "Герман Гессе", 1919));
	lib.addBook(Book(3, "Человек, который смеется", "Виктор Гюго", 1860));

	int searchId = 2;
	Book* foundBook = lib.findBook(searchId);
	if (foundBook) {
		cout << "поиск" << endl;
		foundBook->print();
	}
	else {
		cout << " не найдено\n";
	}
	// удаление
	//
	// lib.removeBook(1);

	lib.printAllBooks();
}