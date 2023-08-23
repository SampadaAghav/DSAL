#include<iostream>
using namespace std;
#define MAX 10
int find(int,int);
void print(int,int);
int p[MAX],q[MAX],w[10][10],c[10][10],r[10][10],i,j,k,n,m;
char idnt[7][10];

int main()

{
    cout<<"enter a number of identifiers : "<<endl;
    cin>>n;
    cout<<"enter identifiers : "<<endl;
    for(i=1;i<=n;i++)
        cin>>idnt[i];
    cout<<"enter success probability for identifiers : "<<endl;
    for(i=1;i<=n;i++)
        cin>>p[i];
    cout<<"enter failure probability  for identifiers : "<<endl;
    for(i=0;i<=n;i++)
        cin>>q[i];
     cout<<"Weight    Cost    Root \n"<<endl;
    
              

for(i=0;i<=n;i++)
    {
            w[i][i]=q[i];
            c[i][i]=r[i][i]=0;
            cout<<w[i][i]<<"    "<<c[i][i]<<"    "<<r[i][i]<<endl;
            cout<<"-------------------------------------------------------------------------"<<endl;
    }
    for(i=0;i<n;i++)
    {
            j=i+1;
            w[i][j]= p[j]+q[i]+q[j];    
            c[i][j]=q[i]+c[i][j-1]+c[j][j];   
            r[i][j]=j;
            cout<<w[i][j]<<"    "<<c[i][j]<<"    "<<r[i][j]<<endl;
            cout<<"-------------------------------------------------------------------------"<<endl;
    }
    for(m=2;m<=n;m++)
    {
        for(i=0;i<=n-m;i++)
        {
            j=i+m;
            w[i][j]=w[i][j-1]+p[i]+q[j];
            k=find(i,j);
            r[i][j]=k;
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            cout<<w[i][j]<<"    "<<c[i][j]<<"    "<<r[i][j]<<endl;
            cout<<"-------------------------------------------------------------------------"<<endl;
        }
    }
 cout<<"THE FINAL OBST IS :"<<endl;
 print(0,n);
 return 0;
}
int find(int i,int j)
{
    int min=2000,m,l;//c[i][j];
    for(m=i+1;m<=j;m++)
        if(c[i][m-1]+c[m][j]<min)
        {
            min=c[i][m-1]+c[m][j];
            l=m;
        }
    return l;
}
void print(int i,int j)
{
if(i<j)
        cout<<idnt[r[i][j]]<<endl;
    else
        return;
    print(i,r[i][j]-1);
    print(r[i][j],j);
}
