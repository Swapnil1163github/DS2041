#include<iostream.h>
#include<conio.h>

class Student{
    private:
        int rNo, marks[5];
        long Urn;
    public:
        Student(){            //Constructor
            rNo = 2044;
            Urn = 22031086;
            marks[0]=62;
            marks[1]=90;
            marks[2]=70;
            marks[3]=90;
            marks[4]=75;
        }
        ~Student(){           //Destructor

        }
        float percentage(){   //Percentage method
            return (marks[0] + marks[1] +  marks[2] + marks[3] + marks[4])/5.0f;
        }
        char grade(){         //Grade method
             if(percentage()>=90) return 'A';
             else if(percentage()>=80 && percentage()<90) return 'B';
             else if(percentage()>=70 && percentage()<80) return 'C';
             else if(percentage()>=60 && percentage()<70) return 'D';
             else if(percentage()>=50 && percentage()<60) return 'E';
             else return 'F';
        }
};
int main(){
clrscr();
Student rushikesh;
cout<<"Percentage: "<<rushikesh.percentage()<<"\n";
cout<<"Grade: "<<rushikesh.grade();
getch();
return 0;
}
