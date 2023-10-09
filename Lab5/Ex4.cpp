#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    // Constructor to initialize the Person object
    Person(const string& name, const string& gender, int age, const string& email)
        : name(name), gender(gender), age(age), email(email) {}

    // Function to introduce the person
    void introduceMyself() {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << email << endl;
    }

private:
    string name;
    string gender;
    int age;
    string email;
};

int main() {
    // Create Person objects for Ryu and Laura
    Person ryu = {"Victor Ryu", "male", 30, "IGS2130v1@inha.ac.kr"};
    Person laura = {"Laura Lee", "female", 23, "IGS2130v2@inha.ac.kr"};

    // Call the introduceMyself function for each person
    ryu.introduceMyself();
    cout << endl;
    laura.introduceMyself();

    return 0;
}
