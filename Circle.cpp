#include <iostream>
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int x,int y, double r)
{
    (*this).x = x;
    (*this).y = y;
    (*this).r = r;
}

double Circle::area() const {
    return 3.14*r*r;
}

double Circle::operator+(const Circle & c) const
{
    return (*this).area() + c.area();

}

Circle & Circle::operator++()
{
    r++;

  return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  r++;

  return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{
    out << c.area() << endl;
  return out;
}

istream & operator>>(istream &in, Circle &c)
{
    int inx,iny;
    double inr;
    cout << "What is the X coordinent of the circle? ";
    in >> inx;
    cout << "What is the Y coordinent of the circle? ";
    in >> iny;
    cout << "What is the radius of the circle? ";
    in >> inr;
    c = Circle(inx,iny,inr);
  return in;
}


void Circle::print() const
{
  cout << "Circle = (" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
  Circle a;
  Circle b(2,3,3.0);

  a.print();
  b.print();
  
  cout << "The area a + b is: " << a+b << endl;
  ++a;
  a.print();

  a++;
  a.print();

  cout << a;

  cin >> a;
  cout <<a;

  return 0;

}
