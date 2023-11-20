/*#include <iostream>

using namespace std;

template<class T>
class stackk {
    T *arr;
    int t;
    int Size;

public:
    stackk(int _size = 5) : Size(_size), t(-1), arr(new T[Size]{0}) {}

    int get_t() const {
        return t;
    }

    void push(T data) {
        if (t < (Size - 1)) {
            t++;
            arr[t] = data;
        } else {
            cout << "stack is full" << endl;
        }
    }

    T& pop() {
        if (t != -1) {
            T& x = arr[t];
            t--;
            cout << "pop: " << x << endl;
            return x;
        } else {
            cout << "stack is empty" << endl;
            return arr[0];
        }
    }

    void display() const {
        if (t == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        for (int i = 0; i <= t; i++) {
            cout << arr[i] << endl;
        }
    }

    ~stackk() {
        delete[] arr;
    }
};

int main() {
    stackk<char> c;
    c.push('c');
    c.display();


    return 0;
}*/
#include <iostream>
using namespace std;
template<class T>

 class stackk {
 T *arr;
 int t;
 int Size;


 public:
 stackk(int _size=5){
     Size=_size;
     t=-1;
     arr=new T[Size]{0};

 }

 int get_t (){
     return t;
 }

 void push(T data){
     if (t<=(Size-1)){
            t++;
            arr[t]=data;


     }
     else{
        cout<<"stack is full"<<endl;
     }


 }
 T pop(){
     if(t!=-1){
        T x = arr[t];
        t--;
    cout<<"pop"<<x<<" "<<endl;
        return(x);
     }
     else {
        cout<<"stack is empty"<<endl;
     }

 }

stackk(stackk& obj1) {//stack s=c;
    Size = obj1.Size;
    t = obj1.t;
    arr = new int[Size];

    for (int i = 0; i <= obj1.t; ++i) {
        arr[i] = obj1.arr[i];
    }
}
void display() const {
        if (t == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        for (int i = 0; i <= t; i++) {
            cout << arr[i] << endl;
        }
    }

    ~stackk() {
        delete[] arr;
    }
};

int main() {
    stackk<char> c;
    c.push('c');
    c.display();
    stackk<char *> l;
    l.push("omnia");
    l.display();
    stackk<int>d;
    d.push(5);
    d.display();



    return 0;
}


