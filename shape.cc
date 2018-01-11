#include <iostream>

using namespace std;

class Shape{
public:
  Shape()  {};
  ~Shape() {};
  virtual void Draw() = 0;//const { cout << "error! cannot draw shape\n"; }
  // virtual void Draw() = 0 means this is a pure virtual function
  // and becomes an Abstract Data Type.
private:
};

class Square : public Shape {
public:
  Square() { itsSide = 3; }
  virtual void Draw();
private:
  int itsSide;
};

void Square::Draw()
{
  cout << "Draw square\n";
}

int main(void)
{
  Square mysquare;
  //  Shape myshape;

  mysquare.Draw();
  //myshape.Draw();

  return 0;
}
