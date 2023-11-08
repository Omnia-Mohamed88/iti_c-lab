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
};

complexx subtocomplex(complexx c1, complexx c2);
complexx addtocomplex(complexx c1, complexx c2);

int main() {
    complexx c;
    c.set_real(4);
    c.set_imagine(5);
    //c.printcomplex();

    complexx c2;
    c2.set_real(2);
    c2.set_imagine(8);
    //complexx c3 = c2.add(c);
    //complexx c3 = addtocomplex(c,c2);
    //c3.printcomplex();

    complexx c5;
    c5.set_real(2);
    c5.set_imagine(8);
    //complexx c6 = c5.sub(c);
    complexx c6 = subtocomplex(c,c2);
    c6.printcomplex();



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

















