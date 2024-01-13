// HIRARCHICAL INHERITANCE
#include<iostream>
using namespace std;

class A
{
    private:
    int a,b;
    public:
    int add(int x, int y)
    {
        return x+y;
    }
};

class B: public A
{
    private:
    int a,b;
    public:
    int sub(int x, int y)
    {
        return x-y;
    }
};

class C: public A
{
    private:
    int a,b;
    public:
    int mul(int x, int y)
    {
        return x*y;
    }
};

class D: public B
{
    private:
    int a,b;
    public:
    int div(int x, int y)
    {
        return x/y;
    }
};

class E: public B
{
    private:
    int a,b;
    public:
    int increment(int x)
    {
        return x++;
    }
};

class F: public C
{
    private:
    int a,b;
    public:
    int decrement(int x)
    {
        return x--;
    }
};

class G: public C
{
    private:
    int a,b;
    public:
    int modulus(int x, int y)
    {
        return x%y;
    }

};

int main()
{
    E obj1;
    F obj2;
    int x1,y1;
    cout<<"Enter any two numbers:"<<endl;
    cin>>x1>>y1;

    cout<<"\nAccessing public part of class A,B through class E:";
    cout<<"\nAddition:"<<obj1.add(x1,y1);
    cout<<"\nSubstraction:"<<obj1.sub(x1,y1);
    //cout<<"Division:"<<obj1.div(x1,y1);
    cout<<"\nIncrement:"<<obj1.increment(x1);

    cout<<"\n\nAccessing public part of class A,C through class F:";
    cout<<"\nAddition:"<<obj2.add(x1,y1);
    cout<<"\nMultiplication:"<<obj2.mul(x1,y1);
    //cout<<"Modulus:"<<obj2.modulus(x1,y1);
    cout<<"\nDecrement:"<<obj2.decrement(y1);

    return 0;
}