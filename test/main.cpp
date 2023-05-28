#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

class A{
    public:
        void cos(){cout << "cos\n";}
};
class B : virtual public A{
    public:
        void cos(){cout<<"COS2\n";};
};
class C :virtual public A{};

class D : public C, public B{};

int main(){
    B b;
    b.cos();
    C c;
    c.cos();

    D d;
    d.cos();



}