#include <iostream>

using namespace std;

class complexx {
    int real;
    int imagine;

public:
    void set_real(int r) {
        real = r;
    }
    void set_imagine(int m) {
        imagine = m;
    }

    int get_real() {
        return real;
    }
    int get_imagine() {
        return imagine;
    }
    complexx(int Real=0,int Imagine=0){
        real=Real;
         imagine=Imagine;


         }
         friend ostream & operator << (ostream &out , const complexx &c);
         friend istream & operator >> (istream &in , complexx &c);




    void printcomplex() {
        cout << "Number = " << real;
        if (imagine < 0) {
            cout << imagine << "j";
        } else if (imagine > 0) {
            cout << "+" << imagine << "j";
        }
        cout << endl;
    }

    complexx add(complexx c1) {
        complexx result;
        result.real = c1.get_real() + real;
        result.imagine = c1.get_imagine() + imagine;
        return result;
    }

    complexx sub(complexx c4) {
        complexx resultsub;
        resultsub.real = real - c4.get_real();
        resultsub.imagine = imagine - c4.get_imagine();
        return resultsub;
    }
    complexx operator + (const complexx & c){
        complexx res(real+c.real , imagine+c.imagine);
        return res;

    }
    complexx operator - (const complexx & c){
        complexx result(real-c.real , imagine-c.imagine );
        return result;

    }
    complexx operator == (const complexx &c){
        if (real == c.real && imagine == c.imagine){
            return 1;
        }
        return 0;

    }
    complexx operator ++(){
        real=real+1;
        return *this;
    }

    complexx operator ++(int){
        complexx temp = *this;
        real=real+1;
        return temp;
    }
    complexx operator += (const complexx &c) {
        complexx res ;
        this->real = this->real +c.real;
        this->imagine = this->imagine+c.imagine;
        return *this;
    }
    operator float(){
        return real;
    }
    int operator[](int index){
        if(index==0){
            return real;
        }
        else if (index ==1){
            return imagine;
        }
    }
};
ostream & operator << (ostream &out,const complexx &c){
    out<< c.real;
    out<<"+i"<<c.imagine<<endl;
    return out;


}
istream & operator >> (istream &in, complexx &c){
    cout<<"enter real";
    in>>c.real;
    cout<<"enter imagine";
    in>>c.imagine;
    return in;
}

complexx subtocomplex(complexx c1, complexx c2);
complexx addtocomplex(complexx c1, complexx c2);

int main() {

   complexx c1(1,5);
   complexx c2(2,3);
   //c2[1];
   complexx c3;
   c3=c1+c2;
   c3.printcomplex();
   complexx c4 ;
   c4=c2-c1;
   c4.printcomplex();
   complexx c5;
   c5==c4;
   c5.printcomplex();
   complexx c6(5,6);
   ++c6;
   c6.printcomplex();
   complexx c7(7,5);
   complexx c8;
   c8=c7++;
   c8.printcomplex();
   complexx c9(2,5);
   c9+=c1;
   c9.printcomplex();
   (float)c9;
   complexx s1;
   cin>>s1;
   cout<<"complex is";
   cout<<s1;


    return 0;
}

complexx addtocomplex(complexx c1, complexx c2) {
    int realSum = c1.get_real() + c2.get_real();
    int imaginesum = c1.get_imagine() + c2.get_imagine();
    complexx c;
    c.set_real(realSum);
    c.set_imagine(imaginesum);
    return c;
}

complexx subtocomplex(complexx c1, complexx c2) {
    int realsub = c1.get_real() - c2.get_real();
    int imaginesub = c1.get_imagine() - c2.get_imagine();
    complexx c;
    c.set_real(realsub);
    c.set_imagine(imaginesub);
    return c;
}
 void standaloneprint(complexx c){
 cout<<c.get_real();
 if(c.get_imagine()>0){
        cout<<"+"<<c.get_imagine()<<"j";

 }
 else if (c.get_imagine()<0){
        cout<<c.get_imagine()<<"j";

 }
 }
