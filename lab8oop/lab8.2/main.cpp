#include <iostream>

using namespace std;
template<class T>
class List{
protected:
    T *item;
    int Size,currentindex;
public:
    List()
    {
        Size =10;
        item = new int[Size];
        currentindex =-1;
    }
    List(int Size){
        item = new T[Size];
        this->Size=Size;
        currentindex=-1;

    }
    void add(T data){
        if(currentindex==Size-1)
            Extend();
        currentindex++;
        item[currentindex]=data;

    }
    void Extend()
    {
        T *temp = new T (Size*2);
        for(int index =0;index<Size;index++){
            temp[index]=item[index];
        }
        delete item;
        item=temp;
        Size*=2;
    }


};

int main()
{
    List <int> mylist;
    mylist.add(3);
    return 0;
}
