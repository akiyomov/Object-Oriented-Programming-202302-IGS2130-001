#include <iostream>

using namespace std;

// Base class representing a generic fruit
class Fruit {
private:
    string name;   // Name of the fruit
    string color;  // Color of the fruit
protected:
    // Protected setter to change the name of the fruit
    void setName(const string& n) {
        name = n;
    }
public:
    // Constructor to initialize the name and color of the fruit
    Fruit(const string& n, const string& c) : name(n), color(c) {}

    // Getter function to retrieve the name of the fruit
    string getName() const {
        return name;
    }

    // Getter function to retrieve the color of the fruit
    string getColor() const {
        return color;
    }
};

// Derived class representing an Apple, inheriting from the Fruit class
class Apple : public Fruit {
public:
    // Constructor for Apple, with a default color of "green"
    Apple(const string& c = "green") : Fruit{"apple", c} {}
};

// Derived class representing a Banana, inheriting from the Fruit class
class Banana : public Fruit {
public:
    // Constructor for Banana, with a default color of "yellow"
    Banana(const string& c = "yellow") : Fruit{"banana", c} {}
};

class RedBanana : public Banana {
public:
    // Constructor for RedBanana, with a default color of "red"
    RedBanana(const string& c = "red") : Banana{c} {
        setName("red banana"); // Change the name of the fruit
    }
};

int main() {
    Apple a{"red"};
    Banana b;
    RedBanana c;
    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}
