#include <iostream>

// Function prototypes
void sort3(double&, double&, double&, bool(*)(double&, double&));
void print3(const double&, const double&, const double&);
void swap2(double&, double&);

// Comparison function prototypes
bool ascending(double&, double&);
bool descending(double&, double&);

int main() {
    // Initialize two sets of three real numbers
    double na1 = 10.3, na2 = -2.1, na3 = 8.0;
    double nd1 = 10.3, nd2 = -2.1, nd3 = 8.0;
    
    // Print the initial values of the first set of numbers
    std::cout << "Before sort:";
    print3(na1, na2, na3);
    
    // Sort the first set in ascending order using the ascending function
    sort3(na1, na2, na3, ascending);

    // Sort the second set in descending order using the descending function
    sort3(nd1, nd2, nd3, descending);
    
    // Print the sorted values of the first set (ascending)
    std::cout << "After sort (ascending):";
    print3(na1, na2, na3);
    
    // Print the sorted values of the second set (descending)
    std::cout << "After sort (descending):";
    print3(nd1, nd2, nd3);
    
    return 0;
}

// Sorts three double values using a comparison function
void sort3(double& a, double& b, double& c, bool(*compare)(double&, double&)){
    // Check if a is greater than b according to the comparison function
    if (compare(a, b)) {
        // Swap a and b if needed
        swap2(a, b);
    }
    
    // Check if b is greater than c according to the comparison function
    if (compare(b, c)) {
        // Swap b and c if needed
        swap2(b, c);
    }
    
    // Recheck a and b and swap them if needed
    if (compare(a, b)) {
        swap2(a, b);
    }
}

// Prints three double values
void print3(const double& a, const double& b, const double& c) {
    std::cout << " " << a << " " << b << " " << c << std::endl;
}

// Swaps two double values
void swap2(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Comparison function for ascending order
bool ascending(double& a, double& b) {
    return a > b;
}

// Comparison function for descending order
bool descending(double& a, double& b) {
    return a < b;
}
