
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

#define Maxn 55
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

queue <int> Q;
int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];
    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
    freopen("out.out", "w", stdout);
#endif

    while(~scanf("%d",&n)&&n){

        for(i = 1; i <= n; i++) {
            Q.push(i);
        }
        k = 0;
        while(Q.size() != 1) {
            num[k++] = Q.front();
            Q.pop();
            m = Q.front();
            Q.pop();
            Q.push(m);

        }
        cout << "Discarded cards: ";
        for(i = 0; i < k; i++) {
            if(i == k-1)
                cout << num[i];
            else
                cout << num[i] <<", ";
        }
        cout << endl;
        cout << "Remaining card: "<<Q.front()<<endl;
        Q.pop();
    }
return 0;
}

/*
#include<stdio.h>
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
    freopen("out.out", "w", stdout);
#endif
  int n;
  while(cin >> n && n!=0)
  {
    for(int i=0; i < n; i++)
      q.push(i+1);
    cout << "Discarded cards:";
    while(!q.empty())
    {
      if (q.size()==1) break;
      if(q.size()==2)
        cout <<" " << q.front();
      else
        cout <<" " << q.front() << ",";
      q.pop();
      q.push(q.front());
      q.pop();
    }
    cout << endl;
    cout << "Remaining card: "<< q.front() << endl;
    q.pop();
  }
  return 0;
}
*/
