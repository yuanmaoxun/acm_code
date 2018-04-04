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
#define INF 0x7fffffff
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


struct People {
    string name;
    int region;
    int score;
};

People p[Maxn];

bool cmp(People a,People b) {
    if(a.region != b.region)
        return a.region < b.region;
    else
        return a.score > b.score;
}


int main() {
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//ACM//input.txt","r",stdin);
#endif
    int T;
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 0; i < n; i++) {
            cin >> p[i].name >> p[i].region >>p[i].score;
        }
        sort(p,p+n,cmp);

        int k = 1;
        for(int i = 0; i < n; i++) {
            if(p[i].region == k && p[i+1].region == k && p[i+2].region == k) {
                int s1 = p[i].score;
                int s2 = p[i+1].score;
                int s3 = p[i+2].score;
                if(s2==s3) {
                    printf("?\n");
                }
                else {
                    cout <<p[i].name <<" "<<p[i+1].name<<endl;
                }
                k++;
            }
            else if(p[i].region == k && p[i+1].region == k && p[i+2].region != k){
                cout <<p[i].name <<" "<<p[i+1].name<<endl;
                k++;
            }
        }
    }
return 0;
}





