#include <iostream>

using namespace std;

enum KindofPolygon { POLY_PLAIN, POLY_RECT, POLY_TRIANG };

class Polygon {
  protected:
    string name;
    float width;
    float height;
    KindofPolygon polytype;

  public:
    Polygon(string theName, float theWidth, float theHeight) {
      name = theName;
      width = theWidth;
      height = theHeight;
      polytype = POLY_PLAIN;
    }

    KindofPolygon getPolytype() {
      return polytype;
    }

    void setPolytype(KindofPolygon value) {
      polytype = value;
    }

    string getName() { return name; }

    virtual float calArea() = 0;

    void printWidthHeight( ) {
      cout << "Width = " << width << " Height = " << height;
    }
};

class Rectangle: public Polygon {
  public:
    Rectangle(string theName, float theWidth, float theHeight): Polygon(theName, theWidth, theHeight) {
      polytype = POLY_RECT;
    }

    float calArea() {
      return width * height;
    }
};

class Triangle: public Polygon {
  public:
    Triangle(string theName, float theWidth, float theHeight): Polygon(theName, theWidth, theHeight) {
      polytype = POLY_TRIANG;
    }

    float calArea() {
      return 0.5 * width * height;
    }
};

class TestPolygon {
  public:
    static void printArea(Polygon* p) {
      float area = p->calArea();
      cout << "Area of polygon: " << area << endl;
    }
};

int main() {
  Polygon* r = new Rectangle("rectangle", 10, 10);
  Polygon* t = new Triangle("triangle", 10, 10);
  TestPolygon::printArea(r);
  TestPolygon::printArea(t);
}
