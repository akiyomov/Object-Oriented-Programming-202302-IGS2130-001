#include <iostream>
using namespace std;

// Create a class named IntArray
class IntArray
{
private:
    int m_len{ 0 };    // Length of the array
    int* m_data{ nullptr }; // Pointer to the dynamically allocated array

public:
    // Constructor to initialize the IntArray with a given length using this->
    IntArray(int len) {
        m_len = len; // Set the length of the array
        m_data = new int[m_len]; // Allocate memory for the array
    }

    // Copy constructor to perform a deep copy of an existing IntArray
    IntArray(const IntArray& source) : m_len(source.m_len), m_data(new int[source.m_len]) {
        for (int i = 0; i < m_len; ++i) {
            m_data[i] = source.m_data[i];
        }
    }

    // Destructor to clean up the dynamically allocated memory
    ~IntArray() {
        if (m_data) 
            delete[] m_data; // Deallocate the memory to prevent memory leaks
    }

    // Overloaded assignment operator to perform a deep copy
    IntArray& operator=(const IntArray& source) {
        if (this == &source) {
            return *this;
        }

        delete[] m_data; // Deallocate the current memory

        m_len = source.m_len; // Set the new length
        m_data = new int[m_len]; // Allocate new memory

        for (int i = 0; i < m_len; ++i) {
            m_data[i] = source.m_data[i];
        }

        return *this;
    }

    // Set the value at a specific index in the array
    void set(int index, int value) {
        if (index >= 0 && index < m_len)
            m_data[index] = value; // Set the value at the specified index
    }

    // Get the value at a specific index in the array, with error handling
    int get(int index, int err) const {
        if (index >= 0 && index < m_len)
            return m_data[index]; // Return the value at the specified index
        else
            return err; // Return the 'err' value if the index is out of bounds
    }
};

int main() {
    int i;
    
    // Create an IntArray named 'a' with a length of 10
    cout << "=== IntArray a{ 10 } ===" << endl;
    IntArray a{ 10 };
    
    // Populate the 'a' array with values
    for (i = 0; i < 10; ++i)
        a.set(i, i * 10 + 5);
    
    // Print the values of array 'a'
    cout << "a: ";
    for (i = 0; i < 10; ++i)
        cout << a.get(i, -1) << ' ';
    cout << endl;
    
    // Create a new IntArray 'b' by copying the contents of 'a'
    cout << "=== IntArray b{ a } ===" << endl;
    IntArray b{ a };
    
    // Print the values of array 'b'
    cout << "b: ";
    for (i = 0; i < 10; ++i)
        cout << b.get(i, -1) << ' ';
    cout << endl;
    
    return 0;
}
