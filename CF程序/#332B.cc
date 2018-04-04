#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define Maxn 100005

using namespace std;


int main(){
    int i, j, k , m , n;
    int fi[Maxn], bi[Maxn];
    int flag[Maxn];
    int flag2[Maxn];
    memset(flag, 0,sizeof(flag));
    int flag3,flag4,flag5;
    flag3 = flag4 = flag5 =0;
    cin >> n >> m;
    for(i = 0; i < n; i++){
        cin >> fi[i];
        flag[fi[i]]++;
        flag2[fi[i]] = i+1;
    }
    for(i = 0; i < m; i++)
        cin >> bi[i];
    bool flag1 = false;
    for(i = 0; i < m ; i++) {
        if(flag[bi[i]] == 0) {
            //cout << "Impossible" <<endl;
            flag5 = 1;

        }

        else
            if(flag[bi[i]] >1 ) {
                //cout << "Ambiguity" <<endl;
                flag4 = 1;

            }
        else {
            flag3 = 1;
        }
    }
    if(flag5 == 1)
        cout << "Impossible" <<endl;
    else {
        if(flag4 == 1) {
            cout << "Ambiguity" <<endl;
        }
        if(flag3 == 1 && flag4 == 0 && flag5 == 0) {
            for(i = 0; i < m; i++) {
                if(flag1 == false){
                        cout << "Possible" <<endl;
                        flag1 = true;
                    }
                    if(i == 0) {
                        cout << flag2[ bi[i] ];
                    }
                    else {
                        cout << " " <<flag2[bi[i]];
                    }
            }
        }
    }
    cout << endl;
return 0;
}
