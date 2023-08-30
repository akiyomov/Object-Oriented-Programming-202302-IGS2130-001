#include <iostream>

using namespace std;

int main() {
    int country, city;

    cout << "Select a country" << endl;
    cout << "(1) Korea, (2) Japan, (3) Australia" << endl;
    cin >> country;

    switch (country) {
        case 1:
            cout << "Select a city: (1) Seoul, (2) Incheon" << endl;
            cin >> city;

            if (city == 1)
                cout << "You selected Seoul, Korea." << endl;
            else
                cout << "You selected Incheon, Korea." << endl;
            break;

        case 2:
            cout << "Select a city: (1) Osaka, (2) Tokyo" << endl;
            cin >> city;

            if (city == 1)
                cout << "You selected Osaka, Japan." << endl;
            else
                cout << "You selected Tokyo, Japan." << endl;
            break;
        case 3:
            cout << "Select a city: (1) Canberra, (2) Sydney";
            cin >> city;

            if (city == 1)
                cout<< "You selected Canberra, Australia.";
            else    
                cout<<"You selected Sydney,Australia";
            break;
        default:
            cout << "Please select 1, 2for 3 the country." << endl;
            break;
    }

    return 0;
}
