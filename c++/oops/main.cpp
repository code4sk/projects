#include <iostream>

using namespace std;

struct Check{
    int a=8, b;
};

class Car{
public:
    int a, b;

    Car(){
        a = 3;
        b = 10;
    }

    Car(int a, int b){
        this->a = a;
        this->b = b;
    }
    ~Car(){
        cout<<"destructor\n";
    }

    Car(const Check &c){
        a = c.a;
        b = c.b;
        cout<<"copy constructor\n";
    }

private:
    inline friend void outsideFunc(const Car &c);
    void printCar(){
        cout<<"car->>\n";
    }

    int z = 0;
public:
    int l;
};

class Electric: public Car{

};

void outsideFunc(const Car & a){
    Car d;
    cout<<a.a<<" "<<a.b<<endl;
}

int main()
{
    Car a;
    Car b = a;
    b.a = -1;
    cout<<a.a<<endl;
    return 0;
}
