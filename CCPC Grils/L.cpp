#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n, k;
inline int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}

vector<int> G[N];
int sz[N], big[N];
int cnt[N], mx, ans[N], col[N], sum[N], cur, is_big[N];

inline void dfs1(int u, int fa){
	sz[u] = 1;
	for (ri &v: G[u]){
		if(v == fa)continue;
		dfs1(v, u);
		if(sz[v] >= sz[big[u]])big[u] = v;
		sz[u] += sz[v];
	}
}

inline void add(int u){
	int w = col[u];
	sum[cnt[w]]--;
	cnt[w]++;
	sum[cnt[w]]++;
	if(mx < cnt[w])mx = cnt[w];
}

inline void del(int u){
	int w = col[u];
	sum[cnt[w]]--;
	cnt[w]--;
	sum[cnt[w]]++;
	if(!sum[mx])mx--;
}

inline void update(int u, int fa, int val){
	if(val > 0)add(u); else del(u);
	
	for (ri &v: G[u]){
		if(v != fa && !is_big[v] ) update(v, u, val);
	}
}

inline void dfs2(int u, int fa, bool keep){
	for (ri &v: G[u]){
		if(v != fa && v != big[u]) dfs2(v, u, 0);
	}
	if(big[u])dfs2(big[u], u, 1), is_big[ big[u] ] = 1;
	
	update(u, fa, 1);
	is_big[ big[u] ] = 0;
	ans[u] = sz[u] - (mx - 1) - 1;
	
	if(!keep)update(u, fa, -1);
	
}

int main(){
	n = read(), k = read();
	for (int i = 1; i <= n; i++)col[i] = read();
	for (int i = 1; i < n; i++){
		int u = read(), v = read();
		G[u].push_back(v), G[v].push_back(u);
	}
	
	dfs1(1, 0);
	
	dfs2(1, 0, 1);
	int q = read();
	for (int i = 1; i <= q; i++){
		printf("%d ", ans[read()]);
	}
	printf("\n");
}


