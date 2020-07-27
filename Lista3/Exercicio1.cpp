/**
 * class representing rectangle
 * 
 * Author: Arthur Munhoz Amaral
 * Date: 27/07/2020
 * GRR20177243
 * Language: C
 * Programação Orientada a Objeto
 * 
 * Purpose: Learning c++ language
 **/

#include <iostream>
#include <string>

using namespace std;

class Rectangle {
    private:
        float height;
        float width;
        float area;
        float perimeter;
    
    public:
        Rectangle(float, float);
        float Area();
        float Perimeter();
        void PrintRectangle();
};

Rectangle::Rectangle(float a, float b)
{
    height = a;
    width = b;
}

float Rectangle::Area()
{
    area =  width*height;
    return area;
}
float Rectangle::Perimeter()
{
    perimeter = (2*height + 2*width);
    return perimeter;
}

void Rectangle::PrintRectangle()
{
    cout << "Rectangle area = " << this->Area();
    cout << "\n Rectangle perimeter =  "<< this->Perimeter() << "\n";
}

int main()
{
    float width, height;

    cout << "\nEnter enter the width of the rectangle:  ";
    cin >> width;

    cout << "\nEnter the height of the rectangle: ";
    cin >> height;

    Rectangle rec (height, width);
    rec.PrintRectangle();
    
}
