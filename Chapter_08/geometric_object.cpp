// Inheritance
// PArent class
// Child classes

import std;
using namespace std;

// Geometric Object
class GeometricObject
{
private:
    string color;
    bool filled;

public:
    GeometricObject(
        string color = "green",
        bool filled = true)
        : color(color), filled(filled)
    {
    }

    string getColor() const
    {
        return color;
    }

    void setColor(const string &color)
    {
        this->color = color;
        // class(x, y):
        // this.
        // self.
    }

    bool isFilled() const
    {
        return filled;
    }

    void setFilled(bool filled)
    {
        this->filled = filled;
    }

    string toString() const
    {
        return "color: " + color +
               " and filled: " +
               (filled ? "true" : "false");
    }
};

class Circle : public GeometricObject
{
private:
    double radius;

public:
    Circle(double radius)
        : GeometricObject(), radius(radius)
    {
    }

    double getRadius() const
    {
        return radius;
    }

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    double getArea() const
    {
        return radius * radius * numbers::pi;
    }

    double getDiameter() const
    {
        return 2 * radius;
    }

    double getPerimeter() const
    {
        return 2 * radius * numbers::pi;
    }

    void printCircle() const
    {
        cout << toString()
             << " radius: " << radius
             << '\n';
    }
};

class Rectangle : public GeometricObject
{
private:
    double width;
    double height;

public:
    Rectangle(double width, double height)
        : GeometricObject(), width(width), height(height)
    {
    }

    double getWidth() const
    {
        return width * width;
    }

    double getHeight() const
    {
        return height;
    }

    double getArea() const
    {
        return width * height;
    }

    double getPerimeter() const
    {
        return 2 * (width + height);
    }
};

int main()
{
    Circle circle(5.0); // circle

    circle.printCircle(); // Access member function

    cout << "Area: "
         << circle.getArea() << '\n';

    cout << "Diameter: "
         << circle.getDiameter() << '\n';

    cout << "Perimeter: "
         << circle.getPerimeter() << '\n';

    // Rectangle
    Rectangle rectangle(4.0, 6.0); // rectangle
    print("Rectangle area: {}\n", rectangle.getArea());
    print("Rectangle perimeter: {}\n", rectangle.getPerimeter());
    print("Rectangle width: {}\n", rectangle.isFilled());

    return 0;
}