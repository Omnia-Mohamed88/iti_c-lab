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

    void print() {
        cout << "(" << x << "," << y << ")" << endl;
    }

    int get_x() const {
        return x;
    }

    int get_y() const {
        return y;
    }
};

class Line1 {
    Point p1, p2;

public:
    Line1() : p1(20, 50), p2(100, 30) {}

    void draw() {
        p1.print();
        p2.print();
    }

    void drawLine() {
        initwindow(600, 300, "Graphics Window");
        line(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
        getch();
        closegraph();
    }
};

class Line2 {
    Point *p1;
    Point *p2;

public:
    Line2() : p1(NULL), p2(NULL) {}

    void setPoints(Point *pa, Point *pb) {
        p1 = pa;
        p2 = pb;
    }

    void draw() {
        p1->print();
        p2->print();
    }

    void drawLine() {
        initwindow(600, 300, "Graphics Window");
        line(p1->get_x(), p1->get_y(), p2->get_x(), p2->get_y());
        getch();
        closegraph();
    }
};

class Line3 {
    Point p1, p2;

public:
    Line3(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : p1(x1, y1), p2(x2, y2) {}

    void draw() {
        p1.print();
        p2.print();
    }

    void drawLine() {
        initwindow(600, 300, "Graphics Window");
        line(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
        getch();
        closegraph();
    }
};

int main() {
    Line1 l1;
    l1.drawLine();

    Line2 l2;
    Point p1(1, 3);
    Point p2(2, 6);
    l2.setPoints(&p1, &p2);
    l2.drawLine();

    Line3 l3(10, 20, 50, 60);
    l3.drawLine();

    return 0;
}

