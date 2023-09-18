#include<iostream>

using namespace std;

// Function prototypes
int GetMinimum(int* a, int b);
int GetMaximum(int* a, int b);
double GetAverage(int* a, int b);

int main(){
    int SIZE, min, max;
    double avg;
    
    // Prompt the user for the number of data points to input
    cout << "# of data want to input: ";
    cin >> SIZE;
    
    // Dynamically allocate memory for an array of integers
    int* data = new int[SIZE];

    // Input data from the user
    for(int i = 0; i < SIZE; ++i){
        cout << i << ". Input an integer: ";
        cin >> data[i];
    }

    // Call the functions to compute minimum, maximum, and average
    min = GetMinimum(data, SIZE);
    max = GetMaximum(data, SIZE);
    avg = GetAverage(data, SIZE);

    // Display the results
    cout << "Minimum value: " << min << endl;
    cout << "Maximum value: " << max << endl;
    cout << "Average value: " << avg << endl;

    // Free the dynamically allocated memory
    delete[] data;

    return 0;
}

// Function to find the minimum value in an array
int GetMinimum(int* a, int b){
    int min = a[0];
    for(int i = 1; i < b; ++i){
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

// Function to find the maximum value in an array
int GetMaximum(int* a, int b){
    int max = a[0];
    for(int i = 1; i < b; ++i){
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// Function to calculate the average of values in an array
double GetAverage(int* a, int b){
    double sum = 0.0;
    for(int i = 0; i < b; ++i){
        sum += a[i];
    }
    return sum / b;
}
