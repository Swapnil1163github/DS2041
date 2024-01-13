#include <iostream>
using namespace std;

class Person {
private:
  char name[50], code[50];

public:
  void create_Person() {
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter code: ";
    cin >> code;
  }
  void show_Person() {
    cout << "NAME: " << name;
    cout << "\nCODE: " << code;
  }
};
class Account : public virtual Person {
private:
  int pay;

public:
  void create_Account() {
    cout << "Enter your salery: ";
    cin >> pay;
  }

  void show_Account() { cout << "\nSALERY: " << pay; }
};
class Admin : public virtual Person {
private:
  int experience;

public:
  void create_Admin() {
    cout << "Enter your experience: ";
    cin >> experience;
  }
  void show_Admin() { cout << "\nEXPERIENCE: " << experience; }
};
class Master : public Account, virtual public Admin {
public:
  void create() {
    create_Person();
    create_Account();
    create_Admin();
    cout << "\n";
  }
  void update() {
    create_Person();
    create_Account();
    create_Admin();
    cout << "\n";
  }
  void display() {
    show_Person();
    show_Account();
    show_Admin();
    cout << "\n";
  }
};

int main() {
  Master obj;
  int ch;
  do {
    cout << "\nENTER YOUR CHOICE?\n1 CREATE\n2 UPDATE\n3 DISPLAY\n4 EXIT\n ";
    cin >> ch;
    switch (ch) {
    case 1:
      obj.create();
      break;
    case 2:
      obj.update();
      break;
    case 3:
      obj.display();
      break;
    case 4:
      cout << "EXIT";
    }
  } while (ch < 4);
  return 0;
}
