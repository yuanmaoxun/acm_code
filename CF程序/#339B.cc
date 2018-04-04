
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


int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len,len1;
    int year, mon, day;
    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    char str1[Maxn];
    scanf("%d",&n);

        int flag = 0;
        int Count;
        sum = 0;
        for(i = 0; i < n; i++) {
            //debug
            Count = 0;
            scanf("%s",str);
            int len = strlen(str);
            if(str[0] != '1' && str[0] != '0') {
                strcpy(str1,str);
                //debug
                continue;
                }
                if(str[0] == '0'){
                    flag = 1;
                    break;
                }

            for(j = 1; j < len;  j++) {
                if(str[j] != '0') {
                    Count = 0;
                    strcpy(str1,str);
                }
                else
                    Count++;
            }
            sum+=Count;
            //cout <<sum <<endl;
        }
        if(flag == 1) {
            cout <<"0" <<endl;
        }
        else {
            len1 = strlen(str1);
            for(i = 0; i < len1; i++)
                putchar(str1[i]);
            for(i = 1; i <= sum; i++)
                putchar('0');
            cout <<endl;
           //debug
        }

return 0;
}




