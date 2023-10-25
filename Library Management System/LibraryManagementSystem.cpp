#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;






//structure for declaration of variable
struct person{
int id;
char title[50];
char author[50];
int cost;

};

//Global Variables
const int books=10;
int arra;
person obj[books]; //create object of person structure



//Function Started
  showMenu(){
  cout<<"------------------------------"<<endl;
  cout<<" LIBRARY MANAGEMENT SYSTEM    "<<endl;
  cout<<"------------------------------"<<endl;
  }




void addBook(){
if(arra < books){
    cout<<"--------Enter Book Record-------- "<<endl;

    cout<<"Enter Book ID "<<endl;
    cin>>obj[arra].id;

    cout<<"Enter Title "<<endl;
    cin>>obj[arra].title;

    cout<<"Enter Author Name "<<endl;
    cin>>obj[arra].author;

    cout<<"Enter Cost of Book "<<endl;
    cin>>obj[arra].cost;
    arra++;
}
else
{
    cout<<"No more space for Books "<<endl;
}
}


void displayBook(){

for(int i=0; i<arra; i++){
     cout<<"--------Books Details---------- "<<endl;
     cout<<"Book ID "<<obj[i].id<<endl;
     cout<<"Book Title "<<obj[i].title<<endl;
     cout<<"Book Author "<<obj[i].author<<endl;
     cout<<"Book Cost "<<obj[i].cost<<endl;
}

}


void searchBook(){
 char searchbook[50];
 cout<<"Enter Book Author Name "<<endl;
 cin>>searchbook;
 int i=0;

 while(i<arra){
    if(strcmp(searchbook, obj[i].author)==0){
      cout<<endl;
      cout<<"Book ID "<<obj[i].id<<endl;
      cout<<"Book Title "<<obj[i].title<<endl;
      cout<<"Book Author "<<obj[i].author<<endl;
      cout<<"Book Cost "<<obj[i].cost<<endl;
      i++;
    }
 }
}

int main(){

    int choice;
    char input;


    do
    {
    showMenu();
    cout<<endl;
    cout<<endl;
    cout<<"------------What Do You Want----------------"<<endl;
    cout<<"\n\t1 Add New Book "<<endl;
    cout<<"\n\t2 Display All Book "<<endl;
    cout<<"\n\t3 Search Book "<<endl;
    cout<<"\n\t4 Total Number of Books "<<endl;
    cout<<"\n\t5 Exit "<<endl;
    cout<<"Enter Choice "<<endl;
    cin>>choice;

    switch(choice){

    case 1: addBook();
    break;

    case 2: displayBook();
    break;

    case 3:searchBook();
    break;

    case 4:cout<<"Total Number of books are "<<arra<<endl;
    break;

    case 5:
           exit(0);
    break;

    default:
          cout<<"Invalid Choice "<<endl;
    }

          cout<<"Are You want to contineou , enter y or Y "<<endl;
          cin>>input;
}

while(input =='y' || input == 'Y');

return 0;

}
