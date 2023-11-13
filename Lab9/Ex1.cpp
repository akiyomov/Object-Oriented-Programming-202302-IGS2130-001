#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;


const int arSize = 20;
class IntArray
{
private:
    int m_len{ 0 };
    int* m_data{ nullptr };

public:
    IntArray(int len)
        : m_len{ len }
    {
        m_data = new int[m_len];
    }
    ~IntArray() {
        if (m_data) delete[] m_data;

    }
    // Friend declaration
    friend class IntArrayHandler;
};

class IntArrayHandler {
private:
    IntArray* m_array; // Pointer to the IntArray object

public:
    // Constructor
    IntArrayHandler(IntArray* array) : m_array(array) {}

    // Member functions to interact with IntArray
    void setArray(int data[], int size);
    void displayArray();
    void stat();
    void setIntArray(IntArray* array) {
        m_array = array;
    }
};

void IntArrayHandler::setArray(int data[], int size) {
    for (int i = 0; i < size && i < m_array->m_len; ++i) {
        m_array->m_data[i] = data[i];
    }
}

void IntArrayHandler::displayArray() {
    for (int i = 0; i < m_array->m_len; ++i) {
        cout << "[" << i << "]" << m_array->m_data[i] << "  ";
        cout << endl;
    }
    cout << endl;
}

void IntArrayHandler::stat() {
    int sum = 0;
    for (int i = 0; i < m_array->m_len; ++i) {
        sum += m_array->m_data[i];
    }
    double average = sum / (double)m_array->m_len;

    cout << "# of elements:" << m_array->m_len << endl;
    cout << "Sum:" << sum << endl;
    cout << "Average:" << average << endl; // Default double precision
}


int main() {
    int i;
    int data1[arSize], data2[arSize];
    IntArray ar1{ arSize }, ar2{ arSize };
    srand((unsigned int)time(NULL));
    for (i = 0; i < arSize; ++i) {
        data1[i] = rand() % 100;
        data2[i] = rand() % 100;
    }

    IntArrayHandler handler{ &ar1 };
    handler.setArray(data1, arSize);
    cout << "== ar1: displayArray() ===" << endl;
    handler.displayArray();
    cout << "====== ar1: stat() =======" << endl;
    handler.stat();
    cout << "==========================" << endl;
    handler.setIntArray(&ar2);
    handler.setArray(data2, arSize);
    cout << endl << "== ar2: displayArray() ===" << endl;
    handler.displayArray();
    cout << "====== ar2: stat() =======" << endl;
    handler.stat();
    cout << "==========================" << endl;
    return 0;
}

