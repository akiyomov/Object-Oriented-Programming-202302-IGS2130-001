#include <iostream>

using namespace std;

class Test {
private:
    static int count;  // static member to keep track of the total number of objects
    int id;            // non-static member to store the object's ID
    int data;

public:
    // Constructor
    Test(int a) : data(a), id(count++) {}

    // Member function to get the number of objects
    static int NumOfObjects() {
        return count;
    }

    // Member function to get data
    int getData() {
        return data;
    }

    // Member function to get object ID
    int getID() {
        return id;
    }
};

// Initialize the static member count
int Test::count = 0;

int main() {
    cout << "# of objects: ";
    cout << Test::NumOfObjects() << endl;

    Test t1{10}, t2{20}, t3{30}, t4{40};
    cout << "[t1] data: " << t1.getData() << ", id: " << t1.getID() << endl;
    cout << "[t2] data: " << t2.getData() << ", id: " << t2.getID() << endl;
    cout << "[t3] data: " << t3.getData() << ", id: " << t3.getID() << endl;
    cout << "[t4] data: " << t4.getData() << ", id: " << t4.getID() << endl;

    cout << "# of objects: ";
    cout << Test::NumOfObjects() << endl;

    return 0;
}
