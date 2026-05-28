#include<iostream>
using namespace std;
class Shape{
    public:
        int area;
        int volume;
};

class Cube : public Shape{ //inheritance
    public:
        double side;
    Cube(double side){ // này là construction
        this->side = side;
        this->area = side * side * 6;
        this->volume = side * side * side;
    }
};

class Sphere : public Shape{
    public:
        double radius;
    Sphere(double radius){
        this->radius = radius;
        this->area = 4 * 3.14159 * ( radius * radius);
        this->volume = (4/3.0) * 3.14159 * ( radius * radius * radius);
    }
};
int main() {
    Cube cube(10);
    

    cout << cube.area;
    return 0;
}