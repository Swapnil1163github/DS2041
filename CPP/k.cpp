#include<iostream>
using namespace std;

double division(int x,int y){
	if(y==0){
	throw"ATTEPT TO DIVIDE BY ZERO";
		
	}
    return  (x/y);
}

int main(){
	int a,b,k;
    cout<<"ENTER FIRST NUMBER\n";
    cin>>a;
    cout<<"ENTER SECOND NUMBER\n";
    cin>>b;
	 try {
	 k=division(a,b);
	 cout<<"THE DIVISION IS  "<<k<<endl;
	 }catch (const char*e){
	 	cout<<e<<endl;
	 }
	
	return 0;
}