#include <iostream>

using namespace std;

class Rectangle{
private:
    int width{0};
    int height{0};
public:
    Rectangle() = default;
    void Display(){
        cout << "Width: " << width << " ";
        cout << "Height: " << height << endl;
    }
    Rectangle& setWidth(int w){
        width = w;
        return *this;
    }
    Rectangle& setHeight(int h){
        height = h;
        return *this;
    }

};


int main(){
    Rectangle rect;
    rect.Display();
    rect.setWidth(10).setHeight(20).Display();
    return 0;
}