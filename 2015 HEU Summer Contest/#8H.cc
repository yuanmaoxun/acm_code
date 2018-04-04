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
#include <functional>#include <ios>
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
#define Maxm 10
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
int number[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4,  //A~I
                5, 5, 5, 6, 6, 6, 7, 7, 7,   //J~R
                7, 8, 8, 8, 9, 9, 9, 9};  //S ~Z
bool comp(char *p1,char *p2) {
        return strcmp(p1,p2);
}
int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn][Maxm];
    char num[80];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", num);
        int len = strlen(num);
        k = 0;
        for(j = 0; j < len; j++) {
            if(k == 3) {
                str[i][k] = '-';
                k++;
            }
            if(num[j] >= 'A' && num[j]<= 'Z') {
                str[i][k]=number[num[j] - 'A'] +'0';
                //cout << num[j] - 'A' <<endl;
                k++;
            }
            else if(num[j]>='0' && num[j] <= '9') {
                str[i][k] = num[j];
                k++;
            }
            else if(num[j]=='-') {
                continue;
            }
        }
    }
    qsort(str, n, 10, strcmp);
    for(i = 0; i < n ; i++)
        puts(str[i]);
    int cnt = 1;
    bool flag = false;
    for(i=1; i<n; i++){//检查重复次数，输出结果
        if(strcmp(str[i], str[i-1]) == 0){
            cnt++;
            flag = 1;
        }
        else{
            if(cnt > 1){
                printf("%s %d\n", str[i-1], cnt);
            }
            cnt = 1;
        }
    }
    if(cnt > 1){
        printf("%s %d\n", str[i-1], cnt);
    }
    if(!flag)
        printf("No duplicates.\n");
return 0;
}
