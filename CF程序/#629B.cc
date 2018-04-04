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

struct Friend {
    int l;
    int r;
    char sex;
}Fri[Maxn];

int main(){
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    char str;
    int l,r,n;
    while(~scanf("%d",&n)) {
        getchar();
        for(int i = 0; i < n; i++) {
            scanf("%c %d %d",&str,&l,&r);
            getchar();
            Fri[i].sex = str;
            Fri[i].l = l;
            Fri[i].r = r;
        }
        int M[370],F[370];
        Clear(M,0);
        Clear(F,0);
        for(int i = 1; i <= 366; i++) {
            for(int j = 0; j < n; j++) {
                if(Fri[j].l<=i && Fri[j].r>=i) {
                    if(Fri[j].sex == 'F') {
                        F[i]++;
                    }
                    else
                        M[i]++;
                }
            }
        }
        int Max = -1;
        for(int i = 1; i <= 366; i++) {
            Max = max(Max,min(M[i],F[i]));
        }
        printf("%d\n",2*Max);
    }
return 0;
}





