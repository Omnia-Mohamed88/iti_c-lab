#include <iostream>
#include <graphics.h>

using namespace std;

const int MAX = 100;

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
};

class shape {
protected:
    Point p1;
    Point p2;
    int color;

public:
    shape() {}

    shape(int p1x, int p1y, int p2x = 0, int p2y = 0, int _color = 0) : p1(p1x, p1y), p2(p2x, p2y), color(_color) {}

    void draw() const {
        cout << "draw" << endl;
    }
};

class Linee : public shape {
public:
    Linee() {}

    Linee(int p1x, int p1y, int p2x, int p2y, int _color) : shape(p1x, p1y, p2x, p2y, _color) {}

    void draw() const {
        setcolor(color);
        line(p1.x, p1.y, p2.x, p2.y);
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

    void draw() const {
        setcolor(color);
        rectangle(p1.x, p1.y, p2.x, p2.y);
    }

    friend istream& operator>>(istream& in, rectaangle& r) {
        cout << "Enter the first point:" << endl;
        in >> r.p1;
        cout << "Enter the second point:" << endl;
        in >> r.p2;
        cout << "Enter the color:" << endl;
        return in >> r.color;
    }
};

class ciircle : public shape {
    int radius;

public:
    ciircle() {}

    ciircle(int p1x, int p1y, int r, int _color) : shape(p1x, p1y), radius(r) {
        color = _color;
    }

    void draw() const {
        setcolor(color);
        circle(p1.x, p1.y, radius);
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
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    Linee l[MAX];
    rectaangle rec[MAX];
    ciircle cir[MAX];

    int counters[3] = {0, 0, 0};
    int num_Shape, type;

    cout << "Enter the number of shapes: ";
    cin >> num_Shape;

    for (int i = 0; i < num_Shape; i++) {
        cout << "Enter the type of shape (line: 1, rectangle: 2, circle: 3): ";
        cin >> type;

        switch (type) {
            case 1: {
                Linee m;
                cin >> m;
                l[counters[0]] = m;
                counters[0]++;
                break;
            }
            case 2: {
                rectaangle r;
                cin >> r;
                rec[counters[1]] = r;
                counters[1]++;
                break;
            }
            case 3: {
                ciircle c;
                cin >> c;
                cir[counters[2]] = c;
                counters[2]++;
                break;
            }
            default:
                cout << "You entered another number." << endl;
        }
    }

    for (int i = 0; i < counters[0]; i++) {
        l[i].draw();
    }

    for (int i = 0; i < counters[1]; i++) {
        rec[i].draw();
    }

    for (int i = 0; i < counters[2]; i++) {
        cir[i].draw();
    }

    getch();
    closegraph();
    return 0;
}


