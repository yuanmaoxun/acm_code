
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
#define Maxn 150005
#define Maxm 5005
#define INF 0xffff
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
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//�����ĵ�//input.txt","r",stdin);
#endif
    int T;
    int n,k,q;
    int num[Maxn];
    int id,m;
    while(~scanf("%d%d%d",&n,&k,&q)) {
        set <int> S;
        set<int> :: iterator iter;
        for(int i = 0; i < n; i++) {
            scanf("%d",&num[i]);
        }
        for(int i = 0; i < q; i++) {
            scanf("%d %d",&id,&m);
            if(id == 1) {
                if(S.size() < k) {
                    S.insert(num[m-1]);
                }
                else {
                    if((*S.begin()) < num[m-1]){
                        S.erase(S.begin());
                        S.insert(num[m-1]);
                    }
                }
            }
            else {
                if(S.count(num[m-1])) {
                    printf("YES\n");
                }
                else
                    printf("NO\n");
            }
            //cout << *S.begin() <<endl;
        }
    }
return 0;
}




