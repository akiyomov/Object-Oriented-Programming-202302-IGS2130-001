#include<iostream>

using namespace std;

// Function declarations (prototypes)
void display(int a);
void display(char a);
void display(double a);

int main() {
    // Function calls with different argument types
    display('A');    // Calls the 'display' function for characters
    display(1234);   // Calls the 'display' function for integers
    display(123.4);  // Calls the 'display' function for doubles
}

// Function definitions

void display(int a) {
    cout << "Int type: " << a << '\n';
}

void display(char a) {
    cout << "Char type: " << a << '\n';
}

void display(double a) {
    cout << "Double type: " << a << '\n';
}
