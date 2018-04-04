
//kengkeng
#include <ios>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cstdio>
#include <cwchar>
#include <iosfwd>
#include <limits>
#include <locale>
#include <memory>
#include <string>
#include <vector>
#include <cassert>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cwctype>
#include <fstream>
#include <iomanip>
#include <istream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <valarray>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <streambuf>
#include <functional>
#define Maxn 105
#define Maxm 500
#define INF 0xffff;
#define ll long long
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));

using namespace std;

struct order {
    char d;
    int p, q;
    int count;
}S[1005],B[1005];

bool cmp(order a, order b) {
    return a.p > b.p;
}
int main(){
    int i, t, j, k, m, n, x ,y;
    int res, sum, ans, key, len;
    int year, mon, day;
    char s[Maxn];
    int num[Maxm];
    char temp;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int a[Maxn],b[Maxn];
     while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        res=sum=ans=0;
        for(i=0;i<n;i++) {
            scanf("%s%d%d",&s,&x,&y);
            if(s[0]=='S'){
                a[x]+=y;
                ans=max(ans,x);
            }
            else {
                b[x]+=y;
                res=max(res,x);
            }
        }
        for(i=0,sum=0;i<=ans&&sum<m;i++)
            if(a[i]>0){
                sum++;
            }
        for(;i>=0;i--)
            if(a[i]>0)
            printf("S %d %d\n",i,a[i]);
        for(i=res,sum=0;sum<m&&i>=0;i--)
            if(b[i]>0){
            sum++;
            printf("B %d %d\n",i,b[i]);
        }
    }
return 0;
}




