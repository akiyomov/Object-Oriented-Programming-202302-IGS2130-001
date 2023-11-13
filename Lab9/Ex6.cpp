#include<iostream>

using namespace std;

// Class representing a physical book
class Book{
private:
    string title;
    string isbn;
    double price;

public:
    // Constructor to initialize Book object with title, ISBN, and price
    Book(const string& t, const string& i,const double& p ):title(t),isbn(i),price(p){}

    // Method to display information about the book
    void ShowBookInfo(){
        cout<<"Title: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"Price(USD): "<<price<<endl;
    }
};

// Class representing an electronic book, inheriting from the Book class
class EBook : public Book{
private:
    string drmkey;
    string format;

public:
    // Constructor to initialize EBook object with title, ISBN, price, DRM key, and format (default: "Kindle")
    EBook(const string& t, const string& i,const double& p,const string& d,const string& f="Kindle"):Book(t,i,p),drmkey(d),format(f){}

    // Method to display information about the e-book, including book information
    void ShowEBookInfo(){
        ShowBookInfo(); // Call the base class method to display book information
        cout<<"DRMKey: "<<drmkey<<endl;
        cout<<"Format: "<<format<<endl;
    }
};

// Class representing a collection of e-books
class EBookLibrary{
private:
    EBook* m_books[100];
    int m_cnt;

public:
    // Constructor to initialize EBookLibrary object with zero books
    EBookLibrary():m_cnt(0){}

    // Destructor to clean up allocated memory (not implemented here)
    ~EBookLibrary(){}

    // Method to add an e-book to the library
    void AddBook(EBook* book);

    // Method to display information about all e-books in the library
    void ShowAllBooks(void);
};

// Method to add an e-book to the library
void EBookLibrary::AddBook(EBook* book){
    m_books[m_cnt++] = book;
}

// Method to display information about all e-books in the library
void EBookLibrary::ShowAllBooks(){
    for(int i = 0; i<m_cnt;++i){
        m_books[i]->ShowEBookInfo();
        cout << endl;
    }
}

// Main function
int main() {
    // Create an EBookLibrary object
    EBookLibrary elib;

    // Add e-books to the library
    elib.AddBook(new EBook{ "Book1", "1234567890", 10.99, "AAAAAA", "ePub" });
    elib.AddBook(new EBook{ "Book2", "2345678901", 20.99, "BBBBBB" });
    elib.AddBook(new EBook{ "Book3", "3456789012", 30.99, "CCCCCC", "ePub"});
    elib.AddBook(new EBook{ "Book4", "4567890123", 40.99, "DDDDDD" });

    // Display information about all e-books in the library
    elib.ShowAllBooks();

    return 0;
}
