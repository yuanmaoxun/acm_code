#include <iostream>
#include <string.h>
using namespace std;
#define maxnum 10
char num1[maxnum],num2[maxnum];
int a[maxnum],b[maxnum];
void fun()
{
 int i;
 for(i=0;i<4;i++)
 {
  a[i]=num1[i]-'0';
  b[i]=num2[i]-'0';
 }
}
int main()
{
 int t,i,j;
 int flag1,flag2;
 cin>>t;
 while(t--)
 {
  cin>>num1>>num2;
  fun();
  flag1=0;
  flag2=0;
  for(i=0;i<4;i++)
   for(j=0;j<4;j++)
   {
    if(a[i]==b[j]&&i!=j)
     flag2++;
    if(a[i]==b[j]&&i==j)
     flag1++;
   }
  cout<<flag1<<"A"<<flag2<<"B"<<endl;
 }
 return 0;
}
