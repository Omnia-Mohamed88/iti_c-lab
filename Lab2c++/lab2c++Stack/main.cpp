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
        return(x);
     }
     else {
        cout<<"stack is empty"<<endl;
     }

 }

 ~stackk(){
     //cout<<"deconstructor"<<endl;
     delete[] arr;


 }

 };
int main()
{

    stackk s(5);
    s.pop();
    s.push(1);
    s.push(5);
    s.push(6);
    s.pop();
    s.pop();
    s.push(7);
    s.pop();
    s.pop();
    s.pop();
    s.push(7);
    s.pop();
//int v = s.pop();
  //  int b = s.pop();
   // cout<<v<<" "<<b;
    return 0;
}



