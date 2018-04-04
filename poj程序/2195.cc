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
using namespace std;
const int Maxn = 105;
const int INF = (1<<30)-1;
int g[Maxn][Maxn];
int lx[Maxn],ly[Maxn];
int match[Maxn];
bool visx[Maxn],visy[Maxn];
int slack[Maxn];
int n;
bool dfs(int cur){
     visx[cur] = true;
     for(int y=1;y<=n;y++){
         if(visy[y])   continue;
         int t=lx[cur]+ly[y]-g[cur][y];
         if(t==0){
            visy[y] = true;
            if(match[y]==-1||dfs(match[y])){
                match[y] = cur;
                return true;
            }
         }
         else if(slack[y]>t){
                 slack[y]=t;
         }
     }
     return false;
}
int KM(){
    memset(match,-1,sizeof(match));
    memset(ly,0,sizeof(ly));
    for(int i=1 ;i<=n;i++){
         lx[i]=-INF;
       for(int j=1;j<=n;j++)
           if(g[i][j]>lx[i])   lx[i]=g[i][j];
   }
   for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++)  slack[i]=INF;
        while(true){
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(dfs(x))
                break;
            int d=INF;
            for(int i=1;i<=n;i++){
               if(!visy[i]&&d>slack[i])     d=slack[i];
            }
            for(int i=1;i<=n;i++){
               if(visx[i])
                    lx[i]-=d;
            }
            for(int i=1;i<=n;i++){
               if(visy[i])
                   ly[i]+=d;
               else
                   slack[i]-=d;
            }
        }
   }
    int result = 0;
    for(int i = 1; i <=n; i++)
    if(match[i]>-1)
        result += g[match[i]][i];
    return result;
}
struct  Position {
    int x;
    int y;
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//ACM//input.txt","r",stdin);
#endif
    char str[Maxn][Maxn];
    int x,y;
    while(~scanf("%d%d",&x,&y)) {
        if(x == 0&&y==0)
            break;
        for (int i = 0; i < x; ++i) {
            scanf("%s",str[i]);
        }
        n = 0;
        Position M[Maxn];
        Position H[Maxn];
        int m = 0;
        int h = 0;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (str[i][j] == 'H') {
                    H[h].x = i+1;
                    H[h].y = j+1;
                    h++;
                }
                if (str[i][j] == 'm') {
                    M[m].x = i+1;
                    M[m].y = j+1;
                    m++;
                }
            }
        }
        n = m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = -(abs(H[i-1].x-M[j-1].x)+abs(H[i-1].y-M[j-1].y));
            }
        }
        /*for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("%d ",g[i][j]);
            }
            puts("");
        }*/
        printf("%d\n",-KM());
    }
    return 0;
}
