#include <iostream>

using namespace std;

class Number {
public:
    // Constructor to initialize the value
    Number() : value(0.0) {}

    // Function to set the value
    void setValue(double val) {
        value = val;
    }

    // Function to get the value
    double getValue() const {
        return value;
    }

    // Function to add a value to the current value
    double add(double val) {
        value += val;
        return value;
    }

    // Function to subtract a value from the current value
    double sub(double val) {
        value -= val;
        return value;
    }

    // Function to multiply the current value by a value
    double mul(double val) {
        value *= val;
        return value;
    }

    // Function to divide the current value by a value
    double div(double val) {
        if (val != 0.0) {
            value /= val;
        } else {
            cout << "Error: Division by zero!" << endl;
        }
        return value;
    }

private:
    double value;
};

int main() {
    Number n1, n2;
    n1.setValue(0.0);

    cout << "n1: " << n1.getValue() << endl;
    cout << "n1+=10.5: " << n1.add(10.5) << endl;
    cout << "n1-=1.5: " << n1.sub(1.5) << endl;
    cout << "n1*=3.0: " << n1.mul(3.0) << endl;
    cout << "n1/=9.0: " << n1.div(9.0) << endl;

    n2.setValue(n1.getValue());

    return 0;
}
