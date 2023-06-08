
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node 
{
 char name[20];
 node *next;
 node *down;
 int flag;
};
class Book
{
  char ch[20];
  int n,i;
  node *head=NULL,*temp=NULL,*t1=NULL,*t2=NULL;
  public:
  node *create();
  void insertb();
  void insertc();
  void inserts();
  void insertss();
  void displayb();
};
node *Book::create()
{
  node *p=new(struct node);
  p->next=NULL;
  p->down=NULL;
  p->flag=0;
  cout<<"\n Enter the name:";
  cin>>p->name;
  return p;
}
void Book::insertb()
{
  if(head==NULL)
  { 
    t1=create();
    head=t1;
  }
  else
  {
  cout<<"\n Book exist:";
  }
}
void Book::insertc()
{
 if(head==NULL)
 { 
  cout<<"\n There is no book!";
 }
 else
 { 
  cout<<"\n How many chapters you want to insert:";
  cin>>n;
  for(i=0;i<n;i++)
  {
   t1=create();
   if(head->flag==0)
   {  
    head->down=t1; head->flag=1; 
   }
   else
   { 
    temp=head;
    temp=temp->down;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=t1;
   }
  }
 }
}
void Book::inserts()
{
 if(head==NULL)
 {
  cout<<"\n There is no book!";
 }
 else
 {  
  cout<<"\n Enter the name of chapter on which  you want to enter the section:";
  cin>>ch;
  temp=head; 
  if(temp->flag==0)
  { 
   cout<<"\n Their are no chapters on in book!";
  }
  else
  { 
   temp=temp->down;
   while(temp!=NULL)
   { 
    if(!strcmp(ch,temp->name))
    {
     cout<<"\n How many sections you want to enter:";
     cin>>n;
     for(i=0;i<n;i++)
     {
      t1=create();
      if(temp->flag==0)
      {
       temp->down=t1;
       temp->flag=1; cout<<"\n******";
       t2=temp->down;
      }
      else
      {
       cout<<"\n#####";
       while(t2->next!=NULL)
       {
        t2=t2->next;
       }
       t2->next=t1;
      }
     }
     break;
    }
    temp=temp->next;
   }
  }
 }
}
void Book::insertss()
{
 if(head==NULL)
 {
  cout<<"\n There is no book!";
 }
 else
 {
  cout<<"\n Enter the name of chapter on which you want to enter the section:";
  cin>>ch;
  temp=head;
  if(temp->flag==0)
  {
   cout<<"\n Their are no chapters on in book!";
  }
  else
  {
   temp=temp->down;
   while(temp!=NULL)
   {
    if(!strcmp(ch,temp->name))
    {
     cout<<"\n Enter name of section in which you want to enter the sub section:";
     cin>>ch;
     if(temp->flag==0)
     {
      cout<<"\n Their are no sections!";
     }
     else
     {
      temp=temp->down;
      while(temp!=NULL)
      {
       if(!strcmp(ch,temp->name))
       {
        cout<<"\n How many subsections you want to enter:";
        cin>>n;
        for(i=0;i<n;i++)
        {
         t1=create();
         if(temp->flag==0)
         {
          temp->down=t1;
          temp->flag=1; cout<<"\n******";
          t2=temp->down;
         }
         else
         {
          cout<<"\n#####";
          while(t2->next!=NULL)
          {
           t2=t2->next;
          }
          t2->next=t1;
          }
         }
         break;
        }
        temp=temp->next;
       }
      }
     }
     temp=temp->next;
    }
   }
  }
}
void Book::displayb()
{
 if(head==NULL)
 { 
  cout<<"\n book not exist!";
 }
 else
 {
  temp=head;
  cout<<"\n NAME OF BOOK: "<<temp->name;
  if(temp->flag==1)
  {
   temp=temp->down;
   while(temp!=NULL)
   {
    cout<<"\n\t\tNAME OF CHAPTER: "<<temp->name;
    t1=temp;
    if(t1->flag==1)
    {
     t1=t1->down;
     while(t1!=NULL)
     {
      cout<<"\n\t\t\t\tNAME OF SECTION: "<<t1->name;
      t2=t1;
      if(t2->flag==1)
      {
        t2=t2->down;
       while(t2!=NULL)
      {
        cout<<"\n\t\t\t\t\t\tNAME OF SUBSECTION: "<<t2->name;
        t2=t2->next;
       }
      }
      t1=t1->next;
     }
    }
    temp=temp->next;
   }
  }
 }
 }
int main()
{
 Book obj;
 int ch;
 
 do
 {
  cout<<"\n 1.Insert Book";
  cout<<"\n 2.Insert Chapter";
  cout<<"\n 3.Insert Section";
  cout<<"\n 4.Insert Subsection";
  cout<<"\n 5.Display Book";
  cout<<"\n 6.Exit";
  cout<<"\n Enter Your Choice:";
  cin>>ch;
   
   switch(ch)
   {
    case 1: obj.insertb();
            break;
    case 2: obj.insertc();
            break;
    case 3: obj.inserts();
            break;
    case 4: obj.insertss();
            break;
    case 5: obj.displayb();
            break;
   }
  }while(ch!=6);
 return 0;
}
