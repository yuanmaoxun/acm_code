
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

#define Maxn 100005
#define Maxm 5005
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
int Day1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int Day2[12]={31,29,31,30,31,30,31,31,30,31,30,31};

int Year(int y){
if(((y%4==0) && y % 100 !=0)|| y%400==0 )
        return 1;
    else
        return 0;
}


int judge (char st[]) {
    int i;
    //puts(st);
    char temp = st[10];
    char temp1 = st[9];
    for(i = 10; i >=0; i--) {
        if(st[i] != temp)
            break;
    }
    if(i < 6)
        return 1;
/*-----------------------------------*/
    int flag = 0;
    if(temp1 > temp)
        flag = 1;
    for(i = 10; i >= 6; i--) {
        if(st[i] != temp)
            break;
        else{
            if(flag)
                temp = temp+1;
            else
                temp = temp -1;
        }
    }
    if(i < 6)
        return 1;

/*-----------------------------------*/
int year = 0;
for(i = 3;i <= 6; i++) {
    year = year *10+st[i]-'0';
}
int mon = 10*(st[7] -'0') + st[8] - '0';
int day = 10*(st[9] -'0') + st[10] - '0';
if(year >= 1980 && year < 2017){
    if(Year(year)==1 && mon <=12 &&mon>=1&&day <= Day2[mon-1] && day>=1)
        return 1;
    else
        if(Year(year)==0 && mon <=12 &&mon>=1&&day <= Day1[mon-1] && day>=1)
            return 1;
    else
        return 0;
}
else
    return 0;
return 0;
}



int main(){
    int i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn][15];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    int a,b;

    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d",&n);
            scanf("%d%d",&a,&b);
            for(i = 0; i < n;i++) {
                scanf("%s",str[i]);
            }
            ll Count = 0;
            for(i = 0; i < n; i++) {
                if(judge(str[i]) == 1){
                    Count++;
                    //cout <<i<<endl;
                }
            }
            //cout <<Count <<endl;
            sum = a*Count+b*(n-Count);
            printf("%lld\n",sum);
        }
    }
return 0;
}





