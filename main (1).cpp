#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Abstract base class for Book (Abstraction and Inheritance)
class Book {
public:
    // Pure virtual function to display book information (Abstraction)
    virtual void displayInfo() const = 0;
    virtual ~Book() {} // Virtual destructor for polymorphism
};

// Derived class representing a concrete book (Inheritance)
class ConcreteBook : public Book {
private:
    int ISBN;
    string title;
    string author;
    int quantity;
    float price;
    string genre;

public:
    // Constructor to initialize book details (Encapsulation)
    ConcreteBook(int isbn, const string& t, const string& a, int q, float p, const string& g)
        : ISBN(isbn), title(t), author(a), quantity(q), price(p), genre(g) {}

    // Function to display book information (Polymorphism)
    void displayInfo() const override {
        cout << "ISBN: " << ISBN << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Quantity: " << quantity << "\n";
        cout << "Price: " << price << "\n";
        cout << "Genre: " << genre << "\n";
    }

    // Overloaded version of displayInfo with an additional parameter
    void displayInfo(bool displayQuantity) const {
        cout << "ISBN: " << ISBN << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        if (displayQuantity) {
            cout << "Quantity: " << quantity << "\n";
        }
        cout << "Price: " << price << "\n";
        cout << "Genre: " << genre << "\n";
    }

    // Getter function for ISBN (Encapsulation)
    int getISBN() const {
        return ISBN;
    }

    // Getter function for quantity (Encapsulation)
    int getQuantity() const {
        return quantity;
    }

    // Setter function for quantity (Encapsulation)
    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    // Getter function for author (Encapsulation)
    string getAuthor() const {
        return author;
    }

    // Getter function for genre (Encapsulation)
    string getGenre() const {
        return genre;
    }

    // Getter function for price (Encapsulation)
    float getPrice() const {
        return price;
    }
};

// Class representing a collection of books (Encapsulation)
class BookCollection {
private:
    // Vector to store books
    vector<ConcreteBook> books;

public:
    // Function to add a book to the collection (Encapsulation)
    void addBook(const ConcreteBook& book) {
        books.push_back(book);
        cout << "Book added successfully!\n";
    }

    // Function to search for a book by ISBN (Encapsulation and Polymorphism)
    void searchBook(int id) const {
        // Using find_if algorithm to search for a book by ISBN (Encapsulation)
        auto it = find_if(books.begin(), books.end(),
            [id](const ConcreteBook& book) { return book.getISBN() == id; });

        // Checking if the book is found
        if (it != books.end()) {
            cout << "Book Found\n";
            // Displaying the book information (Polymorphism)
            it->displayInfo();
        } else {
            cout << "Book not found\n";
        }
    }

    // Function to update the quantity of a book (Encapsulation)
    void updateBook(int id, int newQuantity) {
        // Using find_if algorithm to find the book by ISBN (Encapsulation)
        auto it = find_if(books.begin(), books.end(),
            [id](const ConcreteBook& book) { return book.getISBN() == id; });

        // Checking if the book is found
        if (it != books.end()) {
            // Updating the quantity of the book (Encapsulation)
            it->setQuantity(newQuantity);
            cout << "Book's quantity updated successfully!\n";
        } else {
            std::cout << "Book not found\n";
        }
    }

    // Function to delete a book by ISBN (Encapsulation)
    void deleteBook(int id) {
        // Using remove_if algorithm to delete the book by ISBN (Encapsulation)
        auto it = remove_if(books.begin(), books.end(),
            [id](const ConcreteBook& book) { return book.getISBN() == id; });

        // Checking if the book is found
        if (it != books.end()) {
            // Erasing the book from the vector (Encapsulation)
            books.erase(it, books.end());
            cout << "Book deleted successfully!\n";
        } else {
            cout << "Book not found\n";
        }
    }

    // Function to search for a book by author (Encapsulation)
    void searchBookByAuthor(const string& author) const {
        bool found = false;
        // Iterating through the vector of books (Encapsulation)
        for (const auto& book : books) {
            // Checking if the author matches (Encapsulation)
            if (book.getAuthor() == author) {
                found = true;
                cout << "Book Found\n";
                // Displaying the book information (Polymorphism)
                book.displayInfo();
            }
        }
        // Displaying a message if the book is not found
        if (!found) {
            cout << "Book not found\n";
        }
    }

    // Function to search for a book by genre (Encapsulation)
    void searchBookByGenre(const string& genre) const {
        bool found = false;
        // Iterating through the vector of books (Encapsulation)
        for (const auto& book : books) {
            // Checking if the genre matches (Encapsulation)
            if (book.getGenre() == genre) {
                found = true;
                cout << "Book Found\n";
                // Displaying the book information (Polymorphism)
                book.displayInfo();
            }
        }
        // Displaying a message if no books are found with the specified genre
        if (!found) {
            cout << "No books found with genre: " << genre << "\n";
        }
    }

    // Function to search for books within a price range (Encapsulation)
    void searchBookByPrice(float minPrice, float maxPrice) const {
        bool found = false;
        // Iterating through the vector of books (Encapsulation)
        for (const auto& book : books) {
            // Checking if the book's price is within the specified range (Encapsulation)
            if (book.getPrice() >= minPrice && book.getPrice() <= maxPrice) {
                found = true;
                cout << "Book Found\n";
                // Displaying the book information (Polymorphism)
                book.displayInfo();
            }
        }
        // Displaying a message if no books are found in the specified price range
        if (!found) {
            cout << "No books found in this price range\n";
        }
    }
};

// Main function
int main() {
    BookCollection bookCollection; // Creating a collection of books (Encapsulation and Objects)

    int choice;
    do {
        // Displaying the menu
        cout << "Menu:\n1. Add a book\n2. Search a book\n3. Update a book\n4. delete the book\n5. Search book by author name\n6. Search book by genre\n7. Search book by price range\n8. exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Using a switch statement to handle user choices (Encapsulation)
        switch (choice) {
            case 1: {
                int isbn, quantity;
                float price;
                string title, author, genre;

                // Getting book details from the user
                cout << "Enter book ISBN: ";
                cin >> isbn;
                cout << "Enter book title: ";
                cin.ignore(); // Ignore newline from previous input
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book quantity: ";
                cin >> quantity;
                cout << "Enter book price: ";
                cin >> price;
                cout << "Enter book genre: ";
                cin.ignore(); // Ignore newline from previous input
                getline(cin, genre);

                // Creating a ConcreteBook object and adding it to the collection
                ConcreteBook book(isbn, title, author, quantity, price, genre);
                bookCollection.addBook(book);
                break;
            }
            case 2: {
                int searchId;
                // Getting ISBN from the user for book search
                cout << "Enter book ISBN to search: ";
                cin >> searchId;
                // Searching for the book in the collection
                bookCollection.searchBook(searchId);
                break;
            }
            case 3: {
                int updateId, newQuantity;
                // Getting ISBN and new quantity from the user for book update
                cout << "Enter book ISBN to update: ";
                cin >> updateId;
                cout << "Enter new quantity: ";
                cin >> newQuantity;
                // Updating the book quantity in the collection
                bookCollection.updateBook(updateId, newQuantity);
                break;
            }
            case 4: {
                int deleteId;
                // Getting ISBN from the user for book deletion
                cout << "Enter book ISBN to delete: ";
                cin >> deleteId;
                // Deleting the book from the collection
                bookCollection.deleteBook(deleteId);
                break;
            }
            case 5: {
                string searchAuthor;
                // Getting author name from the user for author-based book search
                cout << "Enter the author name to search: ";
                cin.ignore(); // Ignore newline from previous input
                getline(cin, searchAuthor);
                // Searching for books by author in the collection
                bookCollection.searchBookByAuthor(searchAuthor);
                break;
            }  
            case 6: {
                string searchGenre;
                // Getting genre from the user for genre-based book search
                cout << "Enter genre to search: ";
                cin.ignore(); // Ignore newline from previous input
                getline(std::cin, searchGenre);
                // Searching for books by genre in the collection
                bookCollection.searchBookByGenre(searchGenre);
                break;
            }
            case 7: {
                float minPrice, maxPrice;
                // Getting price range from the user for price-based book search
                cout << "Enter the minimum price: ";
                cin >> minPrice;
                cout << "Enter the maximum price: ";
                cin >> maxPrice;
                // Searching for books within the specified price range in the collection
                bookCollection.searchBookByPrice(minPrice, maxPrice);
                break;
            }
            case 8:
                cout << "Exiting library management system...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid choice.\n";
        }
    } while (choice != 8);

    return 0;
}