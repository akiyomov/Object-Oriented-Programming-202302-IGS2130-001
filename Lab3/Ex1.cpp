#include <iostream>

using namespace std;

int main() {
    int a;
    
    do {
        cout << "Enter your score of the exam:";
        cin >> a;
        
        switch (a) {
            case 90 ... 100:
                cout << "Congratulations. Your grade is A!" << '\n';
                cout << '\n';
                break;
            case 80 ... 89:
                cout << "Your grade: B" << '\n';
                cout << '\n';
                break;
            case 70 ... 79:
                cout << "Your grade: C" << '\n';
                cout << '\n';
                break;
            case 60 ... 69:
                cout << "Your grade: D" << '\n';
                cout << '\n';
                break;
            case 0 ... 59:
                cout << "Sorry, your grade: F" << '\n';
                cout << '\n';
                break;
            default:
                break;
        }
        
    } while (a >= 0);
    
    cout << "End of the program";
}
