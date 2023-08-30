#include <iostream>

using namespace std;

// Function prototype (declaration)
int add(int, int);
int mul(int, int);

int main() {
    int num1, num2, sum, mult;
    
    cout << "Enter two numbers to add and multiply: ";
    cin >> num1 >> num2;
    
    // Function call
    sum = add(num1, num2);
    mult = mul(num1,num2);
    
    cout << "Sum = " << sum<<'\n';
    cout << "Multiplication = " <<mult<<'\n';
    
    return 0;
}

// Function definition
int add(int a, int b) {
    int result;  
    result = a + b;  
    return result; 
}

// Function definition
int mul(int a, int b) {
    int result;  
    result = a * b;  
    return result; 
}
