#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<time.h>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<map>
//#define ONLINE_JUDGE
#define eps 1e-8
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define FOR(i,a) for((i)=0;i<(a);(i)++)
#define MEM(a) (memset((a),0,sizeof(a)))
#define sfs(a) scanf("%s",a)
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define pf(a) printf("%d\n",a)
#define pfI(a) printf("%I64d\n",a)
#define pfs(a) printf("%s\n",a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c)scanf("%d%d%d",&a,&b,&c)
#define for1(i,a,b) for(int i=(a);i<b;i++)
#define for2(i,a,b) for(int i=(a);i<=b;i++)
#define for3(i,a,b)for(int i=(b);i>=a;i--)
#define MEM1(a) memset(a,0,sizeof(a))
#define MEM2(a) memset(a,-1,sizeof(a))
#define ll __int64
const double PI=acos(-1.0);
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
using namespace std;
int n,m;
#define N 20010
#define Mod 1000000007
#define maxn 1010
char ch[110];
ll a[N];
void Init(){
    for(ll i=1;i<N;i++){
        a[i] = 3*i*(i-1)+1;
    }
}
bool check1(){
    for(int i=1;i<N;i++)
        if(a[i] == m)
            return true;
    return false;
}
bool check2(){
    for(int i=1,j=N-1;i<N&&a[i]<m;i++){
        while(j>0 && a[i]+a[j]>m) {
            j--;
        }
        if(j>0 && a[i]+a[j] == m) {
            return true;
        }
    }
    return false;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
#endif
   int t;
   Init();
   sf(t);
   while(t--){
       sf(m);
       if(check1())
           printf("1\n");
       else if(check2()){
           printf("2\n");
       }else{
           int ans;
           for(int i=3;i<10;i++){
               if((m-i)%6 == 0){
                   ans = i;
                   break;
               }
           }
           printf("%d\n",ans);
       }
   }
return 0;
}
