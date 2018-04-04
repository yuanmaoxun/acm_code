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
#define Maxn 1000005
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

int main() {
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int count ;
    scanf("%d", &t);
    for(count = 1; count <= t; count++) {
        scanf("%s", str);
        int len = strlen(str);
        int sf = 0;
        int res = 0;
        int ef = INF;
        bool flag = false;
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;
        for(i = 0; i < len; i++)
            if(str[i]!='f'){
                flag2 = true;
            }
        if(flag2 == false){
            if(len%2 == 0)
                printf("Case #%d: %d\n", count, len/2);
            else
                printf("Case #%d: %d\n", count, len/2+1);
            continue;
        }
        for(i = 0; i < len; i++) {
            //ef = INF;
            if(str[i] != 'c' && str[i] != 'f') {
                flag = true;
                break;
                //debug
            }
            else {
                if(str[i] == 'c') {
                    res ++;
                    if(ef < 2 && flag3 == true) {
                        flag = true;
                        break;
                        //debug
                    }
                    else {
                    ef = 0;
                    flag1 = true;
                    }
                }
                else {
                    if(flag1 == false) {
                        sf++;
                    }
                    else {
                        ef++;
                        //cout <<"ef:" <<ef << endl;
                    }
                }
                if(str[i+1] == 'c')
                    flag3 = true;
            }

        }
        if(flag == false) {
            if(sf + ef < 2)
            //cout << sf+ef <<endl;
            flag = true;
            //debug
        }
        if(flag == true) {
            printf("Case #%d: ", count);
            cout << "-1" << endl;
        }
        else {
            printf("Case #%d: %d", count, res);
            puts("");
        }

    }
    return 0;
}





