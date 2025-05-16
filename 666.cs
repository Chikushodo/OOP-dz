using System;

public class Book
{
    public string Title { get; set; }
    public string Author { get; set; }
    public int Year { get; set; }
    public int Id { get; set; }

    public Book(int id, string title, string author, int year)
    {
        Id = id;
        Title = title;
        Author = author;
        Year = year;
    }

    public override string ToString()
    {
        return $"ID: {Id}, Title: {Title}, Author: {Author}, Year: {Year}";
    }
}

public class Library
{
    private Dictionary<int, Book> books = new Dictionary<int, Book>();

    public void AddBook(Book book)
    {
        if (!books.ContainsKey(book.Id))
        {
            books[book.Id] = book;
            Console.WriteLine("Book added.");
        }
        else
        {
            Console.WriteLine("A book with this ID already exists.");
        }
    }
    public void RemoveBook(int id)
    {
        if (books.Remove(id))
        {
            Console.WriteLine("Book removed.");
        }
        else
        {
            Console.WriteLine("Book not found.");
        }
    }
    public Book FindBook(int id)
    {
        if (books.TryGetValue(id, out Book book))
        {
            return book;
        }
        else
        {
            Console.WriteLine("Book not found.");
            return null;
        }
    }
    public void DisplayBooks()
    {
        if (books.Count == 0)
        {
            Console.WriteLine("Library is empty.");
        }
        else
        {
            foreach (var book in books.Values)
            {
                Console.WriteLine(book);
            }
        }
    }
}

class Program
{
    static void Main()
    {
        Library library = new Library();
        library.AddBook(new Book(1, "1984", "George Orwell", 1949));
        library.AddBook(new Book(2, "The Hobbit", "J.R.R. Tolkien", 1937));
        library.AddBook(new Book(3, "To Kill a Mockingbird", "Harper Lee", 1960));

        Console.WriteLine("Library contents:");
        library.DisplayBooks();

        Console.WriteLine("nFinding book with ID 2:");
        Book foundBook = library.FindBook(2);
        if (foundBook != null)
        {
            Console.WriteLine(foundBook);
        }

        Console.WriteLine("nRemoving book with ID 1:");
        library.RemoveBook(1);
        Console.WriteLine("nLibrary contents after removal:");
        library.DisplayBooks();
    }
}
