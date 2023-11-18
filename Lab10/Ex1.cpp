#include <iostream>
#include <cstring>

using namespace std;

const int MAX_ACC_NUM = 100;
const int NAME_LEN = 30;

class Account{
private:
    int m_accID;
    int m_balance;
    char * m_cusName;
public:
    Account(int ID, int balance, char *cname){
        m_accID = ID;
        m_balance = balance;
        m_cusName = new char[strlen(cname)+1];
        strcpy(m_cusName, cname);
    }
    
    ~Account(){
        delete []m_cusName;
    }

    int GetAccID(void) const{
        return m_accID;
    }

    void Deposit(int money){
        m_balance += money;
    }

    int Withdraw(int money){
        if (m_balance < money){
            cout << "Insufficient balance" << endl;
            return -1;
        }
        m_balance -= money;
        return 1;
    }
    
    void ShowAccInfo(void) const {
        cout << "Customer Name: " << m_cusName << endl;
        cout << "Account ID: " << m_accID << endl;
        cout << "Account Balance: " << m_balance << endl;
    }
                                                                                                                                                                                                               
    friend class AccountHandler;
};


class AccountHandler{
private: 
    Account* accArr[MAX_ACC_NUM];
    int accNum;
    int GetAccIdx(int id) const;
public:
    AccountHandler() : accNum(0) {
    for (int i = 0; i < MAX_ACC_NUM; ++i) {
        accArr[i] = nullptr;
    }
    }
    ~AccountHandler() {
        for (int i = 0; i < accNum; ++i) {
            delete accArr[i];
        }
    }
    int getAccNum() const { return accNum; } 
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void) const;
    void WithdrawMoney(void) const;
    void ShowAccountInfo(void) const;
    void ShowAllAccInfo(void) const;
    void DeleteAccount(void);

};

void AccountHandler::ShowMenu(void) const{
        cout << "-----Menu-----" << endl;
        cout << "1. Make Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Show All Accounts" << endl;
        cout << "5. Delete Account" << endl;
        cout << "6. Show Account Info" << endl;
        cout << "7. Exit" << endl;
        cout << "Select: ";
    }
    
void AccountHandler::MakeAccount(void){
    if (accNum >= MAX_ACC_NUM) {
            cout << "Account limit reached." << endl;
            return;
        }
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[Make Account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Deposit amount: ";
    cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
    cout << "Account created" << endl << endl;
    
}
    
void AccountHandler::DepositMoney(void) const{
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for(int i = 0; i< accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->Deposit(money);
            cout << "Deposit successful" << endl << endl;
            return;
        }
    }
    cout << "Invalid account ID" << endl << endl;
}
    
void AccountHandler::WithdrawMoney() const {
    int money;
    int id;
    bool accountFound = false;

    cout << "[Withdraw]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdraw amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id) {
            int val = accArr[i]->Withdraw(money);
            accountFound = true;
            break; 
        }
    }

    if (!accountFound) {
        cout << "Invalid account ID" << endl << endl;
    }
}
    
int AccountHandler::GetAccIdx(int id) const{
    for(int i = 0; i< accNum; i++){
        if(accArr[i]->GetAccID() == id){
            return i;
        }
    }
    return -1;
}

void AccountHandler::DeleteAccount(void){
    int id;
    cout << "[Delete Account]" << endl;
    cout << "Account ID: ";
    cin >> id;

    int idx = GetAccIdx(id);
    if(idx == -1){
        cout << "Invalid account ID" << endl << endl;
        return;
    }

    delete accArr[idx];
    int i = idx;
    for(; i< accNum-1; i++){
        accArr[i] = accArr[i+1];
    }
    accNum--;
    cout << "Account deleted" << endl << endl;
}

void AccountHandler::ShowAccountInfo(void) const {
    int id;
    cout << "[Show Account Info]" << endl;
    cout << "Account ID: ";
    cin >> id;

    int idx = GetAccIdx(id);
    if(idx == -1){
        cout << "Invalid account ID" << endl << endl;
        return;
    }

    accArr[idx]->ShowAccInfo();
    cout << endl;
}

void AccountHandler::ShowAllAccInfo(void) const{
    for(int i = 0; i< accNum; i++){
        accArr[i]->ShowAccInfo();
    }
}

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, DELETE_ACCOUNT, SHOW_ACCOUNT_INFO,EXIT };


int main() {
    AccountHandler manager;
    int choice;
    bool run = true;

    while(1){
        manager.ShowMenu();
        cin >> choice;
        cout << endl;

        switch(bank(choice)){
            case bank::MAKE:
                manager.MakeAccount();
                break;
            case bank::DEPOSIT:
                manager.DepositMoney();
                break;
            case bank::WITHDRAW:
                manager.WithdrawMoney();
                break;
            case bank::INQUIRE:
                manager.ShowAllAccInfo();
                break;
            case bank::DELETE_ACCOUNT:
                manager.DeleteAccount();
                break;
            case bank::SHOW_ACCOUNT_INFO:
                manager.ShowAccountInfo();
                break;
            case bank::EXIT:
    
            default:
                cout << "Illegal selection.." << endl << endl;
        }
    }
    return 0;
}
