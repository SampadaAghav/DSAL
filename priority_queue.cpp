#include<iostream>
using namespace std;

struct item {
 string name;
 int id;
 int priority;
};
item pr[100000];
int size = -1;
void enqueue()
{
 size++;
 int value,n;
 string name;
 cout<<"Enter name :";
 cin>>name;
 pr[size].name=name;
 cout<<"Enter id:";
 cin>>value;
 pr[size].id = value;
 cout<<"1.Serious\n2.Non-serious\n3.Checkup\n";
 cout<<"Enter choice";
 cin>>n;
 switch(n)
 {
 case 1:
 pr[size].priority=3;
 break;
 case 2:
 pr[size].priority=2;
 break;
 case 3:
 pr[size].priority=1;
 break;
 }
}
void dequeue()
{
 int ind = -1;
 for (int i = ind; i < size; i++)
 {
 pr[i] = pr[i + 1];
 }
 size--;
}
int main()
{
 int n,ind;
 cout<<"Enter number of paitents:";
 cin>>n;
 for(int i=0;i<n;i++)
 {
 enqueue();
 }
 cout<<"Serious paitents:"<<endl;
 for(int i=0;i<n;i++)
 {
 if(pr[i].priority==3)
 cout << "Name:"<<pr[i].name << endl<<"Id:"<<pr[i].id<<endl;
 }
 cout<<"Non-serious paitents:"<<endl;
 for(int i=0;i<n;i++)
 {
 if(pr[i].priority==2)
 cout << "Name:"<<pr[i].name << endl<<"Id:"<<pr[i].id<<endl;
 }
 cout<<"Checkup paitents:"<<endl;
 for(int i=0;i<n;i++)
 {
 if(pr[i].priority==1)
 cout << "Name:"<<pr[i].name << endl<<"Id:"<<pr[i].id<<endl;
 }

 return 0;
} 
