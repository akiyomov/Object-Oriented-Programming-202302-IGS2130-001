#include <iostream>

using namespace std;

class Calculate {
private:
    double a;
    struct Operation {
        char op;
        double value;
    };
    Operation operations[5];
    int count;
public:
    // default constructor
    Calculate() {
        a = 0;
        count = 0;
    }
    // copy constructor
    Calculate(const Calculate &oldCalc) {
        a = oldCalc.a;
        count = 0; // Resetting count for the new object
    }
    double getValue() {
        return a;
    }
    double add(double b) {
        a += b;
        saveOperation('+', b);
        return a;
    }
    double subtract(double b) {
        a -= b;
        saveOperation('-', b);
        return a;
    }
    double multiply(double b) {
        a *= b;
        saveOperation('*', b);
        return a;
    }
    double divide(double b) {
        a /= b;
        saveOperation('/', b);
        return a;
    }
    void saveOperation(char op, double value) {
        if (count < 5) {
            operations[count].op = op;
            operations[count].value = value;
            count++;
        } else {
            for (int i = 0; i < 4; i++) {
                operations[i] = operations[i + 1];
            }
            operations[4].op = op;
            operations[4].value = value;
        }
    }
    bool lastOperation(char &op, double &value) {
        if (count == 0) {
            return false;
        }
        op = operations[count - 1].op;
        value = operations[count - 1].value;
        return true;
    }
    void undo() {
        if (count > 0) {
            count--;
            Operation last = operations[count];
            switch (last.op) {
                case '+':
                    a -= last.value;
                    break;
                case '-':
                    a += last.value;
                    break;
                case '*':
                    a /= last.value;
                    break;
                case '/':
                    a *= last.value;
                    break;
            }
        }
    }
};

int main(void) {
    Calculate cc;
    int i;
    char op;
    double value;
    bool flag;
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
                cout << " = " << cc.subtract(value) << endl;
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

    Calculate dd{cc};

    cout << endl << endl;

    for (i = 0; i < 10; ++i) {
        cout << "Stored the last math operation:";
        flag = dd.lastOperation(op, value);
        if (!flag)
            cout << "None" << endl;
        else
            cout << op << "," << value << endl;
        if (flag) {
            dd.undo();
            cout << "Undo the last math operation..." << endl;
            cout << "Value inside the class object:" << dd.getValue() << endl;
        }
    }

    cout << "Value inside the class object:" << dd.getValue() << endl;
    return 0;
}
