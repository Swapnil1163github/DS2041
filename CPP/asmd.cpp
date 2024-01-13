#include<iostream>

class Operation{
private:
	float a, b;
public:
	float add(float x, float y){
		a = x;
		b = y;
		return a+b;
	}
	float sub(float x, float y){
		a = x;
		b = y;
		return a-b;
	}
	float mult(float x, float y){
		a = x;
		b = y;
		return a*b;
	}
	float div(float x, float y){
		a = x;
		b = y;
		return a/b;
	}
};
int main(){
int choice, p, q, check = 1;
Operation obj;
cout<<"ENTER 2 NUMBERS: ";
cin>>p>>q;
while(check){
cout<<"WHICH OPERATION DO YOU WANT TO PERFORM\n1 ADDITION \n2 SUBTRACTION \n3 MULTIPLICATION \n4 DIVIVSION \n----> ";
cin>>choice;
check = 0;
cout<<"ANSWER IS: ";
	switch(choice){
	case 1:
		cout<<obj.add(p, q)<<"\n";
	break;
	case 2:
		cout<<obj.sub(p, q)<<"\n";
	break;
	case 3:
		cout<<obj.mult(p, q)<<"\n";
	break;
	case 4:
		cout<<obj.div(p, q);
	break;
	default:
	cout<<"ENTER VALID CHOICE !! \n";
	check = 1;
	}
}
return 0;
}
