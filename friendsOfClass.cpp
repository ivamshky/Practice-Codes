#include<iostream>
using namespace std;
class Square;

class Rectangle {
    int h,w;
public:
    Rectangle():w(0),h(0) {}
    Rectangle(int x, int y):w(x),h(y) {}
    int area() {
        return w*h;
    }
    ///// Friend Function of class Rectangle
    friend Rectangle duplicate(const Rectangle&);
    void convert(Square S);
};
Rectangle duplicate(const Rectangle& R){
    Rectangle res;
    res.w = R.w*2;
    res.h = R.h*2;
    return res;
}


class Square
{
    friend class Rectangle; // Rectangle is a friend class of Square.
private:
    int side;
public:
    Square(int a):side(a) {}
};

void Rectangle::convert(Square S)
{
    w = S.side;
    h = S.side;
}

int main(void)
{
    Rectangle foo;
    Rectangle bar(2,3);
    foo = duplicate(bar);
    Square S(4);
    foo.convert(S);
    cout<<foo.area()<<endl;
    return 0;
}
