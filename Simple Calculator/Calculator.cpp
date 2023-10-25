#include<iostream>
using namespace std;


int main()


{
float num1 , num2;
char op;

cout<<endl;
cout<<"Enter first Number "<<endl;
cin>>num1;

cout<<"What Do You Want: + , - , * , / "<<endl;
cin>>op;

cout<<"Enter Second Number "<<endl;
cin>>num2;

switch(op){
case '+':
cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl;
break;
case '-':
cout<<num1<<"-"<<num2<<"="<<num1-num2<<endl;
break;
case'*':
cout<<num1<<"*"<<num2<<"="<<num1*num2<<endl;
break;
case '/':
cout<<num1<<"/"<<num2<<"="<<num1/num2<<endl;
break;

return 0;
}

}
