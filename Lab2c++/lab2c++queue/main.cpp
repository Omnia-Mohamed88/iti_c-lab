#include <iostream>
using namespace std;

class stackk {
    int Size;
    int top;
    int endd;
    int *arr;

public:
    stackk() {
        Size = 5;
        top = -1;
        endd = -1;
        arr = new int[Size]();
    }

    stackk(int _size) {
        Size = _size;
        top = -1;
        endd = -1;
        arr = new int[Size]();
    }

    int get_t() {
        return top;
    }

    void enqueue(int element) {
        if (endd == (Size - 1)) {
            cout << "Queue is full" << endl;
        } else {
            if (top == -1) {
                top = 0;
            }
            endd++;
            arr[endd] = element;
        }
    }

    int dequeue() {
        if (top == -1 || top > endd) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int element = arr[top];
        top++;
        return element;
    }
};

int main() {
    stackk s(5);
    s.dequeue();
    s.enqueue(5);
    s.enqueue(7);
    s.enqueue(10);
    s.dequeue();
    s.dequeue();
    s.enqueue(11);
    s.dequeue();
    s.dequeue();
    s.dequeue();

   // cout << s.dequeue() << endl;
   // cout << s.dequeue() << endl;
   // cout << s.dequeue() << endl;

    return 0;
}

