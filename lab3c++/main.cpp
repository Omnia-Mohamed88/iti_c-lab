
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
     if (t<(Size-1)){
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


 ~stackk(){
     //cout<<"deconstructor"<<endl;
     delete[] arr;



 }


 };
void pop_func(stackk s1);
void pop_func2(stackk& s1);

int main()
{

    stackk s(5);
    s.pop();//empty
    s.push(1);//1
    s.push(5);//5
    s.push(6);//6
    s.pop();//6
    pop_func(s);
    //pop_func2(s);//5
    s.pop();//1

    s.push(5);
    s.pop();

    //s.pop();
    //s.push(7);
    //s.pop();
    //s.pop();
    //s.pop();
    //s.push(7);
    //s.pop();
//int v = s.pop();
  //  int b = s.pop();
   // cout<<v<<" "<<b;
    return 0;
}
void pop_func(stackk s1){
      s1.pop();
}

void pop_func2(stackk& s1){
     s1.pop();
}
