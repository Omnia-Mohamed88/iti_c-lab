#include <iostream>

using namespace std;

void swap1(int &x, int &y);
void swap2(int x, int y);
void swap3(int *x, int *y);

int main() {
    int x = 4;
    int y = 3;
    cout << "before swapping" << " " << x << " " << y << "\n";
    swap1(x, y);
    cout << "after swap1" << " " << x << " " << y << "\n";

    x = 4;
    y = 3;
    cout << "before swapping" << " " << x << " " << y << "\n";
    swap2(x, y);
    cout << "after swap2" << " " << x << " " << y << "\n";

    x = 4;
    y = 3;
    cout << "before swapping" << " " << x << " " << y << "\n";
    swap3(&x, &y);
    cout << "after swap3" << " " << x << " " << y << "\n";
    return 0;
}

void swap1(int &x, int &y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

void swap2(int x, int y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

void swap3(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

