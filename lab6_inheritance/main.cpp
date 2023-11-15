#include <iostream>
#include <graphics.h>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int _x, int _y) : x(_x), y(_y) {}

    friend istream& operator>>(istream& in, Point& p) {
        cout << "Enter the point (x y): ";
        return in >> p.x >> p.y;
    }

    void set_x(int _x) {
        x = _x;
    }

    void set_y(int _y) {
        y = _y;
    }

    int get_x() const {
        return x;
    }

    int get_y() const {
        return y;
    }
};

class shape {
protected:
    Point p1;
    Point p2;
    int color;

public:
    shape() {}

    shape(int p1x, int p1y, int p2x = 0, int p2y = 0, int _color = 0) : p1(p1x, p1y), p2(p2x, p2y), color(_color) {}

    virtual void draw() const {
        cout << "draw" << endl;
    }
};

class Linee : public shape {
public:
    Linee() {}

    Linee(int p1x, int p1y, int p2x, int p2y, int _color) : shape(p1x, p1y, p2x, p2y, _color) {}

    void drawline() {
        cout << "drawline" << endl;
    }

    void draw() const override {
        setcolor(color);
        line(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
    }

    friend istream& operator>>(istream& in, Linee& l) {
        cout << "Enter the first point:" << endl;
        in >> l.p1;
        cout << "Enter the second point:" << endl;
        in >> l.p2;
        cout << "Enter the color:" << endl;
        return in >> l.color;
    }
};

class rectaangle : public shape {
public:
    rectaangle() {}

    rectaangle(int p1x, int p1y, int p2x, int p2y, int _color) : shape(p1x, p1y, p2x, p2y, _color) {}

    void drawline() {
        cout << "drawrec" << endl;
    }

    // Custom operator>> for rectangle
    friend istream& operator>>(istream& in, rectaangle& r) {
        cout << "Enter the first point:" << endl;
        in >> r.p1;
        cout << "Enter the second point:" << endl;
        in >> r.p2;
        cout << "Enter the color:" << endl;
        return in >> r.color;
    }

    void draw() const override {
        setcolor(color);
        rectangle(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
    }
};

class ciircle : public shape {
    int radius;

public:
    ciircle() {}

    ciircle(int p1x, int p1y, int r, int _color) : shape(p1x, p1y), radius(r) {
        color = _color;
    }

    void drawcircle() {
        cout << "drawcircle" << endl;
    }

    void draw() const override {
        setcolor(color);
        circle(p1.get_x(), p1.get_y(), radius);
    }

    friend istream& operator>>(istream& in, ciircle& c) {
        cout << "Enter the center point:" << endl;
        in >> c.p1;
        cout << "Enter the radius:" << endl;
        in >> c.radius;
        cout << "Enter the color:" << endl;
        return in >> c.color;
    }
};

int main() {
    int numberOfShapes;
    cout << "Please enter the number of shapes to draw: ";
    cin >> numberOfShapes;

    shape *shapes[numberOfShapes];
    for (int i = 0; i < numberOfShapes; i++) {
        int shapeNumber;
        cout << "Please enter the number of the shape you want to appear from this list:" << endl
             << "(1) Line" << endl
             << "(2) Rectangle" << endl
             << "(3) Circle" << endl;
        cin >> shapeNumber;

        switch (shapeNumber) {
            case 1: {
                Linee *l = new Linee;
                cin >> *l;
                shapes[i] = l;
                break;
            }
            case 2: {
                rectaangle *r = new rectaangle;
                cin >> *r;
                shapes[i] = r;
                break;
            }
            case 3: {
                ciircle *c = new ciircle;
                cin >> *c;
                shapes[i] = c;
                break;
            }
            default:
                cout << "Invalid shape number. Exiting program." << endl;
                return 1;
        }
    }

    initwindow(800, 600, "Graphics Window");
    for (int i = 0; i < numberOfShapes; i++) {
        shapes[i]->draw();
    }
    getch();
    closegraph();

    return 0;
}



