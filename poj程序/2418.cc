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

int main() {
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif
    char str[35];
    map<string,double> tree;
    map<string,double> ::iterator iter;
    tree.clear();
    int sum = 0;
    while(gets(str)) {
        tree[str]++;
        sum++;
    }
    for(iter = tree.begin(); iter!=tree.end();iter++) {
        cout << iter->first <<" ";
        printf("%.4lf\n",(iter->second)*100/sum);
    }
    system("pause");
return 0;
}
