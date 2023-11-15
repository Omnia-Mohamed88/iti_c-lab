#include <iostream>
#include <graphics.h>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}

    void set_x(int _x) {
        x = _x;
    }

    void set_y(int _y) {
        y = _y;
    }

    void set_point(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int get_x() const {
        return x;
    }

    int get_y() const {
        return y;
    }

    void print() const {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class Circle {
    Point center;
    int red;

public:
    Circle() : center(100, 50), red(40) {}

    Circle(int p1x, int p1y, int r) : center(p1x, p1y), red(r) {}

    void draw() const {
        initwindow(400, 300, "Graphics Window");
        circle(center.get_x(), center.get_y(), red);
        getch();
        closegraph();
    }
};

class Circle2 {
    int red;
    Point* p;

public:
    Circle2(int r) : p(nullptr), red(r) {}

    void draw(const Point* pa) const {
        initwindow(400, 300, "Graphics Window");
        circle(pa->get_x(), pa->get_y(), red);
        getch();
        closegraph();
    }
};

class Circle3 {
    int radius;

public:
    Circle3(int r) : radius(r) {}

    void draw(const Point& pa) const {
        initwindow(400, 300, "Graphics Window");
        circle(pa.get_x(), pa.get_y(), radius);
        getch();
        closegraph();
    }
};

int main() {
    Circle c1;
    c1.draw();

    // Point p2(2, 6);
    // Circle2 c2(4);
    // c2.draw(&p2);

    // Point p3(3, 5);
    // Circle3 c3(5);
    // c3.draw(p3);

    return 0;
}




