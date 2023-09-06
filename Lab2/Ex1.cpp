#include <iostream>

using namespace std;

void inputArray(int*, int);
int searchIndex(int*, int, int);

int main() {
    int size, element, index;
    cout << "Enter size of array: ";
    cin >> size;
    
    // 1. allocate memory for the array
    int* buf = new int[size];
    
    cout << "Enter elements of the array: ";
    inputArray(buf, size);
    
    cout << "Enter element to search: ";
    cin >> element;
    
    index = searchIndex(buf, size, element);
    
    if (index == -1)
        cout << element << " does not exist in the array.";
    else
        cout << element << " is found at index " << index << '.';
    
    // 2. free the allocated memory
    delete[] buf;
    
    return 0;
}

void inputArray(int* p, int a) {
    for (int i = 0; i < a; ++i) {
        cin >> p[i];
    }
}

int searchIndex(int* p, int a, int b) {
    for (int i = 0; i < a; ++i) {
        if (p[i] == b)
            return i;
    }
    return -1;
}
