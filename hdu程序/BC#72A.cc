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
    int res, sum, ans, key, len;
    int year, mon, day,num;
    char str[2];
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int nA,nB,nC;
    int T;
    while(~scanf("%d",&T)) {
        while(T--) {
            map <char,int> A;
            map <char,int> B;
            map <char,int> C;
            map <char,int> ::iterator iter,iter1;
            A.clear();B.clear();C.clear();
            scanf("%d%d%d",&nA, &nB, &nC);
            for(i = 0; i < nA; i++) {
                scanf("%s %d",&str[0],&num);
                A[str[0]] = num;
            }
            for(i = 0; i < nB; i++) {
                scanf("%s %d",&str[0],&num);
                B[str[0]] = num;
            }
            for(i = 0; i < nC; i++) {
                scanf("%s %d",&str[0],&num);
                C[str[0]] = num;
            }
            int ansA,ansB;
            bool flag = false;
                for(i = 1; i <= 100;i++) {
                    for(j = 1; j <= 100; j++) {
                            for(iter = C.begin();iter!=C.end();iter++) {
                                //cout << i <<"*"<<A[iter->first]<<" "<<j << "*"<<B[iter->first] <<"=" <<iter->second <<endl;
                                if(i * A[iter->first] + j * B[iter->first] != iter->second){
                                    break;
                                }
                            }
                            if(iter == C.end() && flag == false){
                                ansA = i;
                                ansB = j;
                                flag =true;
                            }

                    }
                }
            if(flag)
                cout <<ansA <<" "<<ansB<<endl;
            else
                cout <<"NO"<<endl;
        }

    }
return 0;
}





