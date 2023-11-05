#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

class IntArray {
private:
    int m_len{ 0 };
    int* m_data{ nullptr };

    // Declare friend functions
    friend void setArray(IntArray& arr, int data[], int size);
    friend void displayArray(const IntArray& arr);

public:
    IntArray(int len) : m_len{ len } {
        m_data = new int[m_len];
    }

    ~IntArray() {
        if (m_data) delete[] m_data;
    }
};

// Define friend function setArray
void setArray(IntArray& arr, int data[], int size) {
    for (int i = 0; i < size && i < arr.m_len; ++i) {
        arr.m_data[i] = data[i];
    }
}

// Define friend function displayArray
void displayArray(const IntArray& arr) {
    for (int i = 0; i < arr.m_len; ++i) {
        cout << "[" << i << "]" << arr.m_data[i] << "  ";
        cout << endl;
    }
    cout << endl;
}

const int arSize = 20;

int main() {
    int i;
    int data[arSize];
    IntArray ar{ arSize };
    srand((unsigned int)time(NULL));
    for (i = 0; i < arSize; ++i) data[i] = rand() % 100;
    setArray(ar, data, arSize);
    displayArray(ar);
    return 0;
}
