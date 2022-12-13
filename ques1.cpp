#include<iostream>
#include<unistd.h>
#include<sys/types.h>
// #include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void partA(){
    pid_t pid, p;
    p=fork();
    pid = getpid();
    if(p<0) cout<<"Fork Failed"<<endl;
    cout<<"Take task by Parent and Child both"<<endl;
    cout << "Fork ID = " << p << endl;
    cout << "Process ID = " << pid << endl;
    exit(0);
}
void partB(){
    pid_t pid, p;
    p=fork();
    pid= getpid();
    if(p<0) cout<<"Fork Failed"<<endl;
    else if(p==0) cout<<"Child Process"<<endl;
    else  cout<<"Parent Process"<<endl;
        cout << "Fork ID = " << p << endl;
        cout << "Process ID = " << pid << endl;
        exit(0);
}


void partC(){
    pid_t pid, p;
    p=fork();
    if(p<0) cout<<"Fork Failed"<<endl;
    else if(p==0){
        cout<<"Child Process"<<endl;
        cout<<"Process ID : " <<  getpid() << "\nParent Process ID : " << getppid() << endl;
        for(int i=0; i<10000000000; i++){
            //takes time & delay
        }
    }
    else{
        cout<<"Wait for Child to Finish"<<endl;
        wait(0);
        cout<<"Parent Process"<<endl;
        cout<<"Process ID : " <<  getpid() << "\nParent Process ID : " << getppid() << endl;
        exit(0);
    }
}

int main(){
    int choice;
    cout<<"1. partA- Same program, same code"<<endl;
    cout<<"2. partB- Same program, differ code"<<endl;
    cout<<"3. partC- before terminate, parent wait for child to finish its task"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    if(choice==1){
        partA();
    }
    else if(choice==2){
        partB();
    }
    else if(choice==3){
        partC();
    }
    else{
        cout<<"!!Invalid Choice!!";
    }
    return 0;
}