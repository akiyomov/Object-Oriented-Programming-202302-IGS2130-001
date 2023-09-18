#include<iostream>

using namespace std;

void count_int(int a, int b);
void count_int(int a);

int main(){
    count_int(100);
    count_int(100,8);
    count_int(100,10);
    count_int(100,16);
    count_int(100,20);

}

void count_int(int a){
    cout << a << '\n';
}

void count_int(int a, int b){
    if (b == 8)
        cout << oct << a << '\n';
    else if (b == 10)
        cout << dec << a << '\n';
    else if (b == 16)
        cout << hex << a << '\n';
    else
        cout <<"Error: Unknown Base"<< '\n';
}

