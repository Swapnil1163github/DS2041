#include<iostream.h>
#include<conio.h>
class Complex{
private:
		int real, imag;
public:
		Complex(int r=0, int i=0){
			real = r;
			imag = i;
		}
		Complex operator+(Complex const &obj){
			Complex result;
			result.real = real + obj.real;
			result.imag = imag + obj.imag;
			return result;
		}
		void print(){
			cout<<"\n\nRESULT = "<<real<<"+"<<imag<<"i";
		}

};

int main(){
int a[4], i;
clrscr();
	for(i = 0; i<4; i++){
		cout<<"ENTER REAL PART OF COMPLEX NUMBER: ";
		cin>>a[i];
		cout<<"ENTER IMAGINARY PART OF COMPLEX NUMBER: ";
		cin>>a[++i];
	}
Complex n1(a[0], a[1]), n2(a[2], a[3]), n3 = n1 + n2;
n3.print();
getch();
return 0;
}
