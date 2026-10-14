#include <iostream>
using namespace std;

class Rectangle{
    private:
        double width, length;
        
    public:
        void setWidth(const double &width){
            this->width = width;
        }
        void setlength(const double &length){
            this->length = length;
        }
        double getWidth()const{
            return width;
        }
        double getlength() const{
            return length;
        }
        double calculateArea(){
            return length*width;
        }
        double calculatePerimeter(){
            return 2*(length+width);
        }
};

int main()
{
    Rectangle R1;
    R1.setlength(5.0);
    R1.setWidth(3.0);
    cout<<"The area of the first rectangle R1 is "<< R1.calculateArea()<< " and its perimeter is "<<R1.calculatePerimeter()<<".\n";
    Rectangle R2;
    R2.setlength(13.8);
    R2.setWidth(7.2);
    cout<<"The area of the second rectangle R2 is "<< R2.calculateArea()<< " and its perimeter is "<<R2.calculatePerimeter()<<".\n";

    return 0;
}
