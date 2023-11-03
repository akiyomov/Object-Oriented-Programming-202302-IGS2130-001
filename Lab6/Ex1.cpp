#include<iostream>

using namespace std;

int main(){
    return 0;
}

class Point{
    private:
        double x, y;
    public:
        // Constructor to initialize x and y (member variables)
        Point(double xVal, double yVal) : x(xVal), y(yVal) {}

        // Member function to display the posittion of (x,y)
        void display(){
            cout << "x = " << x << ", y = " << y << endl;
        }

        // inference function to get x position
        double getX(){
            return x;
        }

        // inference function to get y position
        double getY(){
            return y;
        }

        // inference function to get both x and y position
        void get(double &xVal, double &yVal){
            xVal = x;
            yVal = y;
        }

};