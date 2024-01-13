#include<iostream>
using namespace std;

class shape {
public:
    double a, b;
    float area;

    virtual void get_data(double x, double y ) {
        a = x;
        b = y;
    }

    virtual void display_area() {
        area = a * b;
        cout << "Area of Rectangle is: " << area << endl;
    }
};

class triangle : virtual public shape {
public:
    void display_area() override {
        area = 0.5 * a * b;
        cout << "Area of Triangle is: " << area << endl;
    }
};

class rectangle : virtual public shape {
public:

};

int main() {
    double x, y;
    triangle t;
    rectangle r;
    
    cout << "Enter Height and Base of Triangle: " << endl;
    cin >> x >> y;
    t.get_data(x, y);
    t.display_area();

    cout << "Enter length and breadth of rectangle: " << endl;
    cin >> x >> y;
    r.get_data(x, y);
    r.display_area(); 

    return 0;
}

