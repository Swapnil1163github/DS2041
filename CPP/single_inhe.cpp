#include <iostream>
using namespace std;

class Person {
private:
  int age;
  char name[50], div[5];

public:
  Person() {
    cout << "Enter name of student: ";
    cin.getline(name, 50);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter division: ";
    cin >> div;
  }
  void Name() { cout << "\nNAME: " << name; }
  void Age() { cout << "\nAGE: " << age; }
  void Div() { cout << "\nDIVISION: " << div; }
};
class Student : public Person {
private:
  int Roll, marks;
  long long int URN;

public:
  Student() {
    cout << "Enter your URN number: ";
    cin >> URN;
    cout << "Enter your roll number: ";
    cin >> Roll;
    cout << "Enter your marks in CPP: ";

    cin >> marks;
  }
  void urn() { cout << "\nURN NO.: " << URN; }
  void roll() { cout << "\nROLL NO.: " << Roll; }
  void mark() { cout << "\nYOUR MARKS IN CPP: " << marks; }
};
int main() {
  Student obj;
  obj.Name();
  obj.Age();
  obj.Div();
  obj.roll();
  obj.urn();
  obj.mark();
  return 0;
}
