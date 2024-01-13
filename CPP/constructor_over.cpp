#include<iostream.h>
#include<conio.h>

class shape {
private:
    float result;

public:
    // Constructor
    shape() {
        cout << "Shape object created." << endl;
    }

    // Destructor
    ~shape() {
        cout << "Shape object destroyed." << endl;
    }

    void area(int r) {
        result = 3.14 * r * r;
        cout << "THE AREA OF CIRCLE IS:" << result << "\n";
    }

    void area(int h, int b) {
        result = (h * b) / 2;
        cout << "THE AREA OF TRIANGLE IS:" << result << "\n";
    }

    void area(int x, int y, float z) {
        z = z * x * y;
        cout << "THE AREA OF ELLIPSE IS:" << z << "\n";
    }
};

int main() {
    shape sp;
    int a, b, c, choice;
    clrscr();

    do {
        cout << "PLEASE ENTER YOUR CHOICE:-\n1.AREA OF CIRCLE\n2.AREA OF TRIANGLE\n3.AREA OF ELLIPSE\n4.EXIT\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "ENTER RADIUS OF CIRCLE:\n";
            cin >> a;
            sp.area(a);
            break;

        case 2:
            cout << "ENTER HEIGHT AND BASE OF TRIANGLE:\n";
            cin >> a >> b;
            sp.area(a, b);
            break;

        case 3:
            cout << "ENTER X AXIS & Y AXIS OF ELLIPSE:\n";
            cin >> a >> b;
            sp.area(a, b, 3.14f);
            break;

        case 4:
            cout << "EXIT\n";
            break;

        default:
            cout << "ENTER VALID CHOICE\n";
        }
    } while (choice != 4);

    getch();
    return 0;
}
