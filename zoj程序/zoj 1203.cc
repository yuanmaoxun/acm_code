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

double sumweight;
int father[Maxn];

struct edge {
    double u,v;
    double w;
}edges[Maxm];

bool cmp( edge a, edge b) {
    return a.w < b.w;
}
int find_set(int n) {
    return father[n] == n ? n : father[n] = find_set(father[n]);
}
void Union (int R1, int R2) {
    int r1 = find_set(R1);
    int r2 = find_set(R2);

}

void Kruskal(int len) {
    sumweight = 0;
    for(int i = 0; i < len; i++) {
        int x = find_set(edges[i].u);
        int y = find_set(edges[i].v);
        if(x != y) {
            sumweight += edges[i].w;
            father[y]=x;
            //cout <<"select edges" <<edges[i].w <<endl;
        }
    }
}
int main(){
    int i, t, j, k, m, n;
    double res, sum, ans, key, len, flag;
    int year, mon, day;
    char str[Maxn];
    double x[Maxn], y[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int count = 1;
    while(~scanf("%d",&n)) {
        if(n == 0){
            break;
            }
        for(i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        for(i = 0; i < n; i++)
            father[i] = i;
        k = 0;
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++) {
                double len = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
                edges[k].u = i;
                edges[k].v = j;
                edges[k].w = len;
                k++;
            }

        }

        sort(edges, edges + k, cmp);
        Kruskal(k);
        if(count > 1){
            cout << endl;
            printf("Case #%d:\nThe minimal distance is: %.2lf\n", count, sumweight);

        }
        else{
            printf("Case #%d:\nThe minimal distance is: %.2lf\n", count, sumweight);
        }
        count++;
    }
return 0;
}





