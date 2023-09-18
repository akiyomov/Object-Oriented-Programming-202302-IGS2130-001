#include <iostream>
#include <cmath> // Include the cmath library for mathematical functions

// Define a user-defined namespace named "shape"
namespace shape {
    // Function to calculate the area of a rectangle
    double rec_area(double width, double length) {
        // Check if width or length is non-positive (invalid input)
        if (width <= 0 || length <= 0) {
            return 0; // Return 0 for invalid input
        }
        // Calculate and return the area of the rectangle
        return width * length;
    }

    // Function to calculate the area of a triangle
    double tri_area(double base, double height) {
        // Check if base or height is non-positive (invalid input)
        if (base <= 0 || height <= 0) {
            return 0; // Return 0 for invalid input
        }
        // Calculate and return the area of the triangle
        return 0.5 * base * height;
    }

    // Function to calculate the area of a circle
    double cir_area(double radius) {
        // Check if the radius is non-positive (invalid input)
        if (radius <= 0) {
            return 0; // Return 0 for invalid input
        }
        // Calculate and return the area of the circle using the constant M_PI for pi (π)
        return M_PI * radius * radius;
    }
}

int main() {
    using namespace std; // Allow the use of standard library functions without prefixing with "std::"

    // Output area calculations for different shapes
    cout << "Area of Rectangle (W:20, L:10): " << shape::rec_area(20, 10) << endl;
    cout << "Area of Triangle (b:20, h:10): " << shape::tri_area(20, 10) << endl;
    cout << "Area of Circle (r:20): " << shape::cir_area(20) << endl;

    return 0; // Return 0 to indicate successful program execution
}
