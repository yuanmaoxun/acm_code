// BC#86B.cpp
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
#define ll long long  
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define PI 3.1415926535897932626
#define EXIT exit(0);
#define PAUSE system("pause");
#define DEBUG puts("Here is a BUG");
#define SYNC_CLOSE ios::sync_with_stdio(false);
#define what_is(x) cout << #x << " is " << x << endl;
#define CLEAR(name, init) memset(name, init, sizeof(name));
const double eps = 1e-8;
const int Maxn = 200005;
using namespace std; 
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;  
    int num[Maxn];
    int Max[Maxn];  
    while(~scanf("%d",&T)) {
        while(T--)  {  
            int n,m,k;  
            scanf("%d%d%d",&n,&m,&k);  
            ll sum = 0;
            int ans = 0;
            int res = 0;  
            for(int i = 1; i <= n; i++) {  
                scanf("%d",&num[i]);  
                if(ans < k) {   
                    if(num[i] >= m)  {  
                        Max[ans++] = i;  
                    }
                    if(ans == k) {  
                        sum += (n-i+1) * (Max[0]);  
                    }  

                }
                else if(num[i] >= m)  {  
                    Max[ans++]=i; 
                    res = ans - k; 
                    ll right = n-i+1; 
                    ll left = Max[res] - Max[res-1];
                    sum += left*right; 
                    // cout << sum <<endl; 
                }
                  
                  
            }  
            printf("%lld\n",sum);  
        }
    }  
      
    return 0;  
}  