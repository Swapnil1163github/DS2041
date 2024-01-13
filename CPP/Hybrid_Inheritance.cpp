//HYBRID INHERITANCE
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

class D: public B, public C
{
    private:
    int a,b;
    public:
    float div(int x, int y)
    {
        return x/y;
    }
};

int main()
{
    D obj;
    int x1,y1;
    cout<<"Enter any two numbers:"<<endl;
    cin>>x1>>y1;

    cout<<"\nAccessing public part of class A,B,C through class D:";
    //cout<<"\nAddition:"<<obj.add(x1,y1);
    cout << "\nAddition from class B (using scope resolution operator): " << obj.B::add(x1, y1);
    cout << "\nSubtraction: " << obj.sub(x1, y1);
    cout << "\nMultiplication: " << obj.mul(x1, y1);
    cout<<"\nDivision:"<<obj.div(x1,y1);

    return 0;
}