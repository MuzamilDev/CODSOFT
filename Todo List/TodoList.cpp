#include<iostream>
#include<string>
#include<fstream>
using namespace std;


struct todo{
  int id;
  string task;
};

int Main;


void showMenu();
void beginTask();
void showTask();
int searchTask();
void removeTask();




int main()
{
    system("cls");
    while(true)
    {
         showMenu();
         cout<<"\n\t1 .Add Task "<<endl;
         cout<<"\n\t2 .Display Tasks "<<endl;
         cout<<"\n\t3 .Search Task "<<endl;
         cout<<"\n\t4 .Delete Task "<<endl;

     int choice;
     cout<<"Enter Your Choice "<<endl;
     cin>>choice;

     switch(choice)
     {
     case 1:
        beginTask();
        break;

     case 2:
        showTask();
        break;

     case 3:
        searchTask();
        break;

     case 4:
        removeTask();
        break;
     }
    }

    return 0;
}

void showMenu(){
         cout<<endl;
         cout<<"*******************************"<<endl;
         cout<<"          TODO LIST            "<<endl;
         cout<<"*******************************"<<endl;

}

void beginTask(){

   system("cls");
   showMenu();
   todo object;

   cout<<"Enter New Task: "<<endl;
   cin.get();
   getline(cin,object.task);
   char save;
   cout<<"Do You Want to Save it (y/n) ? "<<endl;
   cin>>save;
   if(save == 'y'){
   Main++;
   ofstream f;
   f.open("todotasklist.txt");
   f<<"\n"<<Main;
   f<<"\n"<<object.task;
   f.close();

    char addmore;
    cout<<"Can Add Multiple task (y/n) "<<endl;
    cin>>addmore;
    if(addmore == 'y'){
        beginTask();
    }
    else{
        system("cls");
        cout<<" Added ! " <<endl;
        return;
    }
   }
   system("cls");
}


void showTask(){
system("cls");
showMenu();
todo object;
ifstream fOne;
fOne.open("todotasklist.txt");
cout<<"TASK PROVIDED: "<<endl;
while(!fOne.eof()){
    fOne>>object.id;
    fOne.ignore();
    getline(fOne,object.task);
    if(object.task != ""){
        cout<<"\t"<<object.id<<":"<<object.task<<endl;
    }
    else{
        cout<<"\t Empty! "<<endl;
    }
}
fOne.close();
char out;
cout<<"Exit ? (y/n) "<<endl;
cin>>out;
if(out != 'y'){
    showMenu();
}
system("cls");
}



int searchTask(){
system("cls");
showMenu();

int id;
cout<<"Enter Id of Task "<<endl;
cin>>id;
todo object;
ifstream ftwo("todotasklist.txt");
while(!ftwo.eof()){
    ftwo>>object.id;
    ftwo.ignore();
    getline(ftwo,object.task);
    if(object.id == id){
        system("cls");
        cout<<"\t" <<object.id<<":"<<object.task<<endl;
        return id;
    }
}
 system("cls");
 cout<<"Not Found "<<endl;
 return 0;
}





void removeTask(){
system("cls");
  int id = searchTask();
  if(id != 0){
    char del;
    cout<<"\n\tDo You Want to delete Task (y/n) ? ";
    cin>>del;
    if(del == 'y'){
        todo objj;
        ofstream tempVar;
        tempVar.open("temporary.txt");
        ifstream fthree;
        fthree.open("todotasklist.txt");


        int parse = 1;
        while(!fthree.eof()){
            fthree>>objj.id;
            fthree.ignore();
            getline(fthree,objj.task);
            if(objj.id == id){
                tempVar<<"\n"<<id;
                tempVar<<"\n"<<objj.task;
                parse++;
                Main--;
            }
        }
        fthree.close();
        tempVar.close();
        //remove and rename functions
        remove("todotasklist.txt");
        rename("todotasklist.txt","temporary.txt");
        system("cls");
        cout<<"Deleted Permanetly "<<endl;
    }
    else{
        system("cls");
        cout<<"Not Deleted Yet ! "<<endl;
    }
}
}
