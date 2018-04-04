#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define PI  3.1415926535898
using namespace std;
struct Tree {
    int x;
    int a;
}treeplus[105],treeminus[105];
bool comp1(Tree a,Tree b) {
    return a.x < b.x;
}
bool comp2(Tree b,Tree c) {
    return b.a < c.a;
}
bool comp3(Tree a,Tree b) {
    return a.x > b.x;
}
int main() {
    int Minus[105],Add[105];
    int i, j, k, m, n, x, a;
    int num;
    cin >> num ;
    j = k = 0;
    for(i = 0; i < num ; i++) {
        scanf("%d %d",&m,&n);
        if(m < 0) {
            j++;
            treeminus[j].x = m;
            treeminus[j].a = n;

        }
        else {
            k++;
            treeplus[k].x = m;
            treeplus[k].a = n;

        }
    }
    sort(treeminus+1, treeminus + j+1, comp3);
    sort(treeplus+1 , treeplus + k+1, comp1);
    int sum = 0;
    if (j < k) {
        for(i = 1; i <= j+1 ; i++)
            sum += treeplus[i].a;
        for(i = 1; i <= j ; i++)
            sum += treeminus[i].a;
    }
    else {
        for(i = 1; i <= k+1 ; i++)
            sum += treeminus[i].a;
        for(i = 1; i <= k ; i++)
            sum += treeplus[i].a;
    }
    cout << sum <<endl;
return 0;
}
