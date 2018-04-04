#include <iostream>
#include <string.h>
using namespace std;
const  int max1=201316;
#define  mod   530600414
long long     c[max1+5],l[max1+5],s[max1+5],r[max1+5];
int main()
{   memset(c,0,sizeof(c));
    memset(l,0,sizeof(l));
    memset(s,0,sizeof(s));
    memset(r,0,sizeof(c));
    int i;
    c[1]=1;
    c[2]=0;
    c[3]=1;
    c[4]=1;
    c[5]=2;
    c[6]=3;
    c[7]=5;
    for( i=8;i<=max1;i++)
    c[i]=(c[i-1]+c[i-2])%mod;

    l[1]=1;
    l[2]=2;
    l[3]=3;
    for(int i=4;i<=max1;i++)
    {
        l[i]=(l[i-1]+l[i-2])%mod;
    }
    s[1]=0;
    s[2]=0;
    s[3]=0;
    s[4]=2;
    s[5]=5;
    for(i=6;i<max1;i++)
    {
        s[i]=(((s[i-2]+(l[i-2]*c[i-1])%mod)%mod)+s[i-1])%mod;
    }

   /* for(i=4;i<=10;i++)
    {
        cout<<c[i]<<" "<<l[i]<<" "<<s[i]<<endl;
    }
*/
    r[3]=0;
    r[4]=0;
    r[5]=5;
    r[6]=16;
    for(i=7;i<=max1;i++)
    {
        int  v=(r[i-2]+r[i-1])%mod;
        int  u=((((l[i-2]*c[i-1]%mod)+s[i-1])%mod)*c[i-2])%mod;
        int  y=-((s[i-2]*c[i-1])%mod);
        r[i]=((u+v)%mod+y+mod)%mod;
    }



    int t,n;
    cin>>t;
    int  cas;
    for(cas=1;cas<=t;cas++)
    {
        cin>>n;
        cout<<"Case #"<<cas<<": ";
        cout<<r[n]<<endl;
    }
    return 0;
}

