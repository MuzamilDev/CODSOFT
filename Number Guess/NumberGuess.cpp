#include<iostream>
#include<ctime>

using namespace std;

int main(){

    int roll;
    int number;
    int check;

          srand(time(0));
          roll=rand()%100+20;

          do{
          check++;
          cout<<"Enter Your Guess Number "<<endl;
          cin>>number;

          if(number == roll){
            cout<<"You Did it ! Congratulations"<<endl;
          }
          else if(number < roll){
            cout<<"You are Little bit narrow in term of small "<<endl;
          }
          else if(number > roll){
            cout<<"You are little bit narrow in term of Big "<<endl;
          }

          }while(number != roll);
          return 0;
}
