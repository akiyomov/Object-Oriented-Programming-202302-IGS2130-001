#include<iostream>

using namespace std;

class Calculate{
private:
    double a;
public:
    //defualt constructor
    Calculate(){
        a = 0;
    }
    double getValue(){
        return a;
    }
    double add(double b){
        a += b;
        return a;
    }
    double substract(double b){
        a -= b;
        return a;
    }
    double multiply(double b){
        a *= b;
        return a;
    }
    double divide(double b){
        a /= b;
        return a;
    }
};

int main(void) {
    Calculate cc;
    int i;
    char op;
    double value;
    for (i = 0; i < 10; ++i) {
        cout << "Select math operator(+,-,*,/): ";
        cin >> op;
        cout << "Enter a real number for the math: ";
        cin >> value;

        switch (op) {
            case '+':
                cout << cc.getValue() << " + " << value;
                cout << " = " << cc.add(value) << endl;
                break;
            case '-':
                cout << cc.getValue() << " - " << value;
                cout << " = " << cc.substract(value) << endl;
                break;
            case '*':
                cout << cc.getValue() << " * " << value;
                cout << " = " << cc.multiply(value) << endl;
                break;
            case '/':
                cout << cc.getValue() << " / " << value;
                cout << " = " << cc.divide(value) << endl;
                break;
        }
    }
    return 0;
}