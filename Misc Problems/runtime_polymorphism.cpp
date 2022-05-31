#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void printArea()
    {
        cout << "shape has no dimensions\n";
    }
};

class Rectangle : public Shape
{
public:
    int width, height, area;
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }
    Rectangle()
    {
        width = 0;
        height = 0;
    }

    void printArea()
    {
        area = height * width;
        cout << "Area of rectangle: " << area << "\n";
    }
    void printArea(int nh, int nw)
    {
        cout << "Area of new rectangle: " << nh * nw << "\n";
    }
};

class Circle : public Shape
{
public:
    int radius;
    Circle(int r)
    {
        radius = r;
    }
    void printArea()
    {
        cout << "Area of circle: " << 3.14 * radius * radius << "\n";
    }
};

int main()
{
    Shape *s;
    Rectangle r = Rectangle(5, 10);
    Circle c = Circle(5);
    s = &r;
    s->printArea();
    s = &c;
    s->printArea();
    r.printArea();
    r.printArea(2, 10);
}