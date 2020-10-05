#include<conio.h>
#include<iostream>
#include<string>

using namespace std;
bool check = true;

struct node   
{
 char name[50];
 int iukl_id;
 char phone[50];// to accept +97...................+ is input as char
 char email[50];
 char address[50];
 node *next;
}*head,*lastptr;

void add()    //Adds record of student//
{
 node *p;
 p = new node;
 cout<<"Enter the Student's details"<<endl;
 cout<<"Enter Name: "<<endl;
 gets(p->name);
 cout<<"Enter IUKL id: "<<endl;
 //gets(p->iukl_id);
 cin>>p->iukl_id;
 cout<<"Enter Phone number: "<<endl;
 getchar();
 gets(p->phone);
 cout<<"Enter E-mail id: "<<endl;
 gets(p->email);
 cout<<"Enter Address: "<<endl;
 gets(p->address);
 
 p->next=NULL;

 if(check)
 {
  head = p;
  lastptr = p;
  check = false;
 }
 else
 {
  lastptr->next=p;
  lastptr=p;
 }
 cout<<endl<<"Recoreded successfully!"<<endl;
 getch();
}

 //method to modify the records of student.
void modify()  
{
 node *ptr;
 node *prev=NULL;
 node *current=NULL;
 int iukl_no;
 cout<<"Enter IUKL_ID Number to Edit/ Modift the data:"<<endl;
 cin>>iukl_no;
 //gets(iukl_no);
 prev=head;
 current=head;
 while(current->iukl_id!=iukl_no)
 {
  prev=current;
  current=current->next;
 }
 ptr=new node;
 fflush(stdin);
 cout<<"Enter the Student's details"<<endl;
 cout<<"Enter Name: "<<endl;
 gets(ptr->name);
 cout<<"Enter IUKL id: "<<endl;
 cin>>ptr->iukl_id;
 //gets(ptr->iukl_id);
 cout<<"Enter Phone number: "<<endl;
 getchar();
 gets(ptr->phone);
 cout<<"Enter E-mail id: "<<endl;
 gets(ptr->email);
 cout<<"Enter Address: "<<endl;
 gets(ptr->address);

 prev->next=ptr;
 ptr->next=current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Data changed successfully!"<<endl;
 getch();
}

//Method to search the data of students
void search() 
{
 node *prev=NULL;
 node *current=NULL;
 int iukl_no;
 cout<<"Enter iukl_id to search: "<<endl;
 cin>>iukl_no;
 //gets(iukl_no);
 prev=head;
 current=head;
 while(current->iukl_id!=iukl_no)
 {
  prev=current;
  current=current->next;
 }
 cout<<"\nname: ";
 puts(current->name);
 cout<<"\nIUKL_ID: ";
 //puts(current->iukl_id);
 cout<<current->iukl_id;
 cout<<"\nPhone Number: ";
 puts(current->phone);
 cout<<"\Email: ";
 puts(current->email);
 cout<<"\nAddress: ";
 puts(current->address);
 getch();
}

//Method to delete the record of students.
void remove()    
{
 node *ptr=NULL;
 node *prev=NULL;
 node *current=NULL;
 int iukl_no;
 cout<<"Enter iukl_id to Delete the data: "<<endl;
 cin>>iukl_no;
 //gets(iukl_no);
 prev=head;
 current=head;
 while(current->iukl_id!=iukl_no)
 {
  prev=current;
  current=current->next;
 }
 prev->next = current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Recored Deleted"<<endl;
 getch();
}

//method to display the student details.
void display()
{
    struct node *current;
    current = head;
    if(current==NULL)
    {
    	cout<<"No any records to display"<<endl;
    }
    else
    {
    	cout<<"The Student REcords are"<<endl;
    	cout<<"**********************************"<<endl;
        while(current!=NULL)
        {
            cout<<"\nname: ";
            puts(current->name);
            cout<<"IUKL_NUMBER: ";
            //puts(current->iukl_id);
            cout<<current->iukl_id;
            cout<<"\nPhone Number: ";
            puts(current->phone);
            cout<<"\Email: ";
            puts(current->email);
            cout<<"\nAddress: ";
            puts(current->address);
            getch();
            current = current->next;
        }
        cout<<endl;
	}
    
}

int main()
{
 char x;
 cout<<"\t\t \t\t********************************* \t\t\t\t"<<endl;
 cout<<"\t\t \t\t**SUNWAY STUDENT RECORD SYSTEM**\t\t \t\t\t"<<endl;
 cout<<"\t\t \t\t********************************* \t\t\t\t\t"<<endl;
 cout<<"\n\n\t\t\t\tPress Any Key To Continue . . . ."<<endl;
 getch();
 do
 {
  cout<<"1). Press '1' to add New record:"<<endl;
  cout<<"2). Press '2' to search a record:"<<endl;
  cout<<"3). Press '3' to modify a record:"<<endl;
  cout<<"4). Press '4' to delete a record:"<<endl;
  cout<<"5). Press '5' to display all records:"<<endl;
  cout<<"6). Press '6' to EXIT:"<<endl;
  x=getch();
  if(x=='1')
  {
   //system("cls");
   add();
  }
  else if(x=='2')
  {
   //system("cls");
   search();
  }
  else if(x=='3')
  {
   //system("cls");
   modify();
  }
  else if(x=='4')
  {
   //system("cls");
   remove();
  }
  else if(x=='5')
  {
   //system("cls");
   display();
  }
  else if(x=='6')
  {
   exit(0);
  }
  else
  {
  }
 }while(x != 30);
 getch();
}
