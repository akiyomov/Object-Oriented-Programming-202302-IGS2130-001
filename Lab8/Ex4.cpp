#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hour;   // 0 - 23
    int minute; // 0 - 59
    int second; // 0 - 59

public:
    // Constructor
    Time(int h = 0, int m = 0, int s = 0)
        : hour(h), minute(m), second(s) {}

    // Copy constructor
    Time(const Time &t)
        : hour(t.hour), minute(t.minute), second(t.second) {}

    // Non-const version
    void printTime() {
        // 24-hour format
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << minute << ":"
             << setw(2) << second;
    }

    // Const version
    void printTime() const {
        // 12-hour format
        cout << setfill('0') << setw(2) << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
             << setw(2) << minute << ":"
             << setw(2) << second
             << (hour < 12 ? "AM" : "PM");
    }
};

int main() {
    const Time t0{7, 3, 5};
    Time t1{13, 45, 9};
    const Time t2{t1};

    cout << "t0:";
    t0.printTime();
    cout << endl;

    cout << "t1:";
    t1.printTime();
    cout << endl;

    cout << "t2:";
    t2.printTime();
    cout << endl;

    return 0;
}
