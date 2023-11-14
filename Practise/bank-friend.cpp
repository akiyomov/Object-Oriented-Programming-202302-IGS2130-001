#include <iostream>
using namespace std;

class Bank{
    int account;
    double balance;
public:
    Bank(int a, double b): account(a),balance(b){cout<<"Created with account with num: "<<account<<endl;}

    void DisplayAccountInfo() const{
        cout << "Account Number: " << account << std::endl;
        cout << "Balance: $" << balance << std::endl;
    }
    friend void TransferMoney(Bank& fromA,Bank& toA,double amount);
};

void TransferMoney(Bank& fromA,Bank& toA,double amount){
    if (amount > 0 && amount<= fromA.balance){
        fromA.balance -= amount;
        toA.balance += amount;
    cout << "Transfer successful!" << endl;
    } else {
        cout << "Insufficient funds for the transfer." <<endl;
    }
}

int main() {
    Bank account1(12345, 1000.0);
    Bank account2(54321, 500.0);
    std::cout << "Account 1 (Before Transfer):" << std::endl;
    account1.DisplayAccountInfo();
    std::cout << "\nAccount 2 (Before Transfer):" << std::endl;
    account2.DisplayAccountInfo();

    // Transfer money from account1 to account2
    TransferMoney(account1, account2, 200.0);
    
    // Display updated account information
    std::cout << "\nAccount 1 (After Transfer):" << std::endl;
    account1.DisplayAccountInfo();
    std::cout << "\nAccount 2 (After Transfer):" << std::endl;
    account2.DisplayAccountInfo();
    return 0;
}
