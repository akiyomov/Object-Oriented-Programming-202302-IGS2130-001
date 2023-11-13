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
    // Constructor to initialize EBook object with title, ISBN, price, and DRM key
    EBook(const string& t, const string& i,const double& p,const string& d):Book(t,i,p),drmkey(d),format("Kindle"){}

    // Method to display information about the e-book, including book information
    void ShowEBookInfo(){
        ShowBookInfo(); // Call the base class method to display book information
        cout<<"DRMKey: "<<drmkey<<endl;
        cout<<"Format: "<<format<<endl;
    }
};

// Main function
int main() {
    // Create a Book object and display its information
    Book book("Modern C++ Programming Cookbook", "1800208987", 49.99);
    book.ShowBookInfo();
    cout << endl;

    // Create an EBook object and display its information, including book information
    EBook ebook("Modern C++ Programming Cookbook(ebook)", "1800208987", 34.99, "dkb34x!@*~");
    ebook.ShowEBookInfo();

    return 0;
}
