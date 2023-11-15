#include <iostream>

using namespace std;
 class stackk {
 int *arr;
 int t;
 int Size;


 public:
 stackk(int _size=5){
     Size=_size;
     t=-1;
     arr=new int[Size]{0};

 }

 int get_t (){
     return t;
 }

 void push(int data){
     if (t<=(Size-1)){
            t++;
            arr[t]=data;


     }
     else{
        cout<<"stack is full"<<endl;
     }


 }
 int pop(){
     if(t!=-1){
        int x = arr[t];
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

stackk operator = (const stackk &c){
    t=c.t;
    Size=c.Size;
    delete[]arr;
    arr = new int[Size];
     for (int i = 0; i <= c.t; i++) {
        arr[i] = c.arr[i];
    }


}





 ~stackk(){
     //cout<<"deconstructor"<<endl;
     delete[] arr;



 }


 };
void pop_func(stackk s1);
void pop_func2(stackk& s1);

int main()
{

    stackk s(20);
    s.push(8);
    s.push(5);
    s.push(8);
    s.push(3);
    s.push(1);
    stackk s2(10);
    s2.push(1);
    s2.push(4);
    s2.push(8);
    s2.push(9);
    s2.push(1);
    s=s2;//
    s.push(7);
    //pop_func2(s);
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();




    return 0;
}
void pop_func(stackk s1){
      s1.pop();
}

void pop_func2(stackk& s1){
     s1.pop();
}
