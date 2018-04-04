// #706D.cpp
#include <bits/stdc++.h>
#define LL long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define PI 3.1415926535897932626
#define EXIT exit(0);
#define PAUSE system("pause");
#define DEBUG puts("Here is a BUG");
#define SYNC_CLOSE ios::sync_with_stdio(false);
#define what_is(x) cout << #x << " is " << x << endl;
#define CLEAR(name, init) memset(name, init, sizeof(name));
#define Maxn 2
const double eps = 1e-8;


using namespace std;

typedef struct TrieNode
{
	// int nCount;  // 该节点前缀 出现的次数
	int num; //用于标记该节点是否被删除
	struct TrieNode *next[Maxn]; //该节点的后续节点
	TrieNode() {
		num = 0;
		for (int i = 0; i < Maxn; ++i) {
			next[i] = NULL;
		}
	}
} TrieNode;

TrieNode *root;
//初始化一个节点。nCount计数为1， next都为null

void insertTrie(TrieNode * proot, LL num, int v)
{
	for (int i = 30; i >= 1; --i) {
		int k = (num>>(i-1))&1;
		if (proot->next[k] == NULL) {
			TrieNode * tmp = new TrieNode();
			proot->next[k] = tmp;
			proot = proot -> next[k];
			proot->num += v;
		}
		else {
			proot = proot->next[k];
			proot->num += v;
		}
	}
}

LL searchTrie(TrieNode * root, LL num)
{
	LL ans = 0;
	for (int i = 30; i >= 1; --i) {
		int k = (num >> (i-1))&1;
		if(root->next[1-k]!=NULL&&root->next[1-k]->num>0) {
			root = root->next[1-k];
			ans += 1LL<<(i-1);
		}
		else if(root->next[k]!=NULL){
			root = root->next[k];
		}
	}
	return ans;
}


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n;
    char str[2];
    LL num;
	while(~scanf("%d",&n)) {
		TrieNode *root = new TrieNode();
		insertTrie(root, 0, 1);
		for (int i = 0; i < n; ++i) {
			scanf("%s %lld",str,&num);

			if (str[0] == '+') {
				insertTrie(root,num,1);
			}
			else if(str[0] == '-') {
				insertTrie(root,num,-1);
			}
			else {
				LL res = searchTrie(root, num);
				printf("%lld\n", res);
			}
		}
	}
	return 0;
}
