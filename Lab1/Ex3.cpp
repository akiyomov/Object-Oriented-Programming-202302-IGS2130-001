#include <iostream>
#define INT_MIN 0;
#define INT_MAX 0;
using namespace std;

int main() {
    int x;
    int min = INT_MIN;
    int max = INT_MAX;

    cout << "Type an integer number: ";
    cin >> min;

    for (int i = 1; i < 10; i++) {
        cout << "Type an integer number: ";
        cin >> x;
        
        if (x > max)
            max = x;
        else if(x<min)
            min = x;
    }

    cout << "The maximum number you typed is " << max <<'\n';
    cout << "The minimum number you typed is " << min<<'\n';

    return 0;
}
