//kengkeng
#include<bits/stdc++.h>
#define Maxn 100005
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
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n;
    while(~scanf("%d",&n)) {
        vector <string> Name;
        map<string,int> Judge;
        for(int i = 0; i < n; i++){
            string name;
            cin >> name;
            Name.push_back(name);
        }
        for(int i = Name.size()-1;i>=0;i--){
            if(!Judge.count(Name[i]))
                cout << Name[i] <<endl;
            Judge[Name[i]] = 1;
        }
    }
return 0;
}





