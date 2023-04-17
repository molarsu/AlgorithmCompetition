#include<bits/stdc++.h>
using namespace std;

namespace edge {
	const int maxn = 7e3 + 5;
	const int maxm = 2e4 + 5;
	int head[maxn], ecnt;
	struct edge {
		int nxt, v;
	}e[maxm];
	void add_edge(int u, int v) {
		ecnt++;
		e[ecnt].v = v;
		e[ecnt].nxt = head[u];
		head[u] = ecnt;
	}
	void init_edge() {
		memset(head, -1, sizeof head);
		ecnt = 1;
	}
}
using namespace edge;
namespace Tarjan {
	int dfn[maxn], low[maxn], SCC_num, BCC_num, num, belong[maxn];
	stack<int> stk;
	vector<int> scc[maxn], bcc[maxn];
	vector<pair<int,int> > bridge;
	bool instk[maxn];
	bool is_cut[maxn], is_cut_e[maxn];
	void init_Tarjan() {
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		BCC_num = 0; SCC_num = 0; num = 0;
		//scc->clear(); bcc->clear();
		while (!stk.empty())stk.pop();
		memset(instk, 0, sizeof instk);
		memset(is_cut, 0, sizeof is_cut);
	}
	// 有向边,可以求解强连通分量的个数（可以理解为环交为一个强连通分量，不论是点交，还是边交），缩点
	void SCC(int u) {
		dfn[u] = low[u] = ++num;
		stk.push(u);
		instk[u] = true;
		for (int i = head[u]; i != -1; i = e[i].nxt) {
			int v = e[i].v;
			if (!dfn[v]) {
				SCC(v);
				low[u] = min(low[u], low[v]);
			}
			else if (instk[v]) {
				// 这里是一个向前的边，也就是构成了环，因为只要不是在他到根的路径上的话，就一定不在栈中。
				low[u] = min(dfn[v], low[u]);
			}
		}
		if (dfn[u] == low[u]) {
			SCC_num++;
			while (!stk.empty()) {
				int tmp = stk.top();
				instk[tmp] = 0;
				stk.pop();
				scc[SCC_num].push_back(tmp);
                belong[tmp] = SCC_num;
				if (tmp == u)break;
			}
		}
	}
}
using namespace Tarjan;
vector<int> G1[maxn], G2[maxn];
int deg[maxn];
int col[maxn], ans[maxn];
int tot_col = 0;
void solve(int u){
    bool fi = 0;
    
    for (int v: G2[u]){
        if(col[v]){
            col[u] = col[v];
            continue;
        }
        if(!fi) col[v] = col[u], solve(v), fi = 1;
        else col[v] = ++tot_col, solve(v), col[u] = col[v]; 
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
    init_edge();
    init_Tarjan();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        G1[u].push_back(v);
    }
    for (int i = 1; i <= n; i++){
        if(!dfn[i]) SCC(i);
    }
    for (int i = 1; i <= n; i++){
        for (int j : G1[i]){
            int u = belong[i], v = belong[j];
            if(u == v)continue;
            G2[u].push_back(v), deg[v]++;
        }
    }
    for (int i = 1; i <= SCC_num; i++){
        if(!deg[i])col[i] = ++ tot_col, solve(i);
    }
    map<int,int> mp;
    int rr = 0;
    for (int i = 1; i <= n; i++){
        ans[i] = col[belong[i]];
        if(!mp.count(ans[i])) {
            rr++;
            mp[ans[i]] = rr;
        }
        cout << mp[ans[i]] << " ";
    }
    cout << endl;
}
/*
5 5
1 2
2 3
1 4
4 5
3 5



*/