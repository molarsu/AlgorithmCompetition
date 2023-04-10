#include<bits/stdc++.h>
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = (1 << 11) + 5;
const int M = N * 10 * 2;

int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}

int S, T, n, m, tot;
int dis[N], in[N], out[N], L[N], R[N];
int ecnt = 1, head[N], cur[N];
bool vis[N];

struct Edge {
	int v, flow, nxt;
}e[M];

void init_edge() {
	memset(head, -1, (tot + 2) * sizeof head[0]);
	ecnt = 1;
}
int pop_count(int x){
	int res = 0;
	while(x){
		if(x & 1)res++;
		x >>= 1;
	}
	return res;
}
bool cmp(int x, int y){
	int res = 0;
	if(x == y)return 0;
	while(x || y){
		if((x & 1 ) != (y & 1))res++;
		x >>= 1, y >>= 1;
	}
	return res == 1;
}
void add_edge(int u, int v, int flow) {
	ecnt++;
	e[ecnt] = {v, flow, head[u]};
	head[u] = ecnt;
	//cout << ecnt << " " << u << " " << v  << " " << flow << endl;
}
void add2(int u, int v, int flow){
	add_edge(u, v, flow);
	add_edge(v, u, 0);
}

bool dinic_bfs(int s) {
	memset(dis, -1, (tot + 2) * sizeof(dis[0]));
	dis[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int u = que.front(); que.pop();

		for (int i = head[u]; i != -1; i = e[i].nxt) {
			int v = e[i].v;
			if (dis[v] == -1 && e[i].flow) {
				dis[v] = dis[u] + 1;
				que.push(v);
			}
		}
	}

	//for (int i = 1; i <= n; i++)cout << dis[i] << endl;
	return dis[T] != -1;
}
int dinic_dfs(int u, int flow) {
	if (u == T) { return flow; }
	int delta = flow;
	for (int i = cur[u]; i != -1; i = e[i].nxt) {
		cur[u] = i;
		int v = e[i].v;
		if (dis[v] == dis[u] + 1 && e[i].flow) {
			int d = dinic_dfs(v, min(delta, e[i].flow));
			e[i].flow -= d, e[i ^ 1].flow += d;
			delta -= d;
			if (delta == 0)break;
		}
	}
	if (delta == flow)dis[u] = -1;
	return flow - delta;
}
int dinic() {
	int ans = 0;
	while (dinic_bfs(S)) {
		memcpy(cur, head, (tot + 2) * sizeof head[0]);
		ans += dinic_dfs(S, INF);
	}

	return ans;
}

signed main(){

	//n = read(), m = read(), tot = n, S = read(), T = read();
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;cin >> t;
	while(t--){
		int len, num;
		string s1, s2;
		memset(vis, 0, (tot + 2) * sizeof vis[0]);
		
		cin >> len >> num;
		tot = (1 << len) + 3;
		init_edge();
		cin >> s1 >> s2;
	
		S = (1 << len) + 1, T = (1 << len) + 2;
		int p0 = 0;
		fu(i, 0, len - 1) {
			p0 <<= 1;
			if(s1[i] == s2[i]) p0++;
		}
		fu(i, 1, num) {
			string s;
			cin >> s;
			int p = 0;
			fu(j, 0, len - 1){
				p <<= 1;
				if(s[j] == '=')p++;
			}
			vis[p] = 1;
		}
		
		fu(i, 0, (1 << len) - 1) {
			if(vis[i] || i == p0) continue;
			bool f1 = 0;
			if(pop_count(i) & 1) f1 = 1, add2(S, i, 1);
			else add2(i, T, 1);
			fu(j, i + 1, (1 << len) - 1){
				if(vis[j] || j == p0) continue;
				if(cmp(i, j))
					if(f1)add2(i, j, 1);
					else add2(j, i, 1);
			}
		}
		int res1 = dinic();
		init_edge();
		fu(i, 0, (1 << len) - 1) {
			if(vis[i]) continue;
			bool f1 = 0;
			if(pop_count(i) & 1) f1 = 1, add2(S, i, 1);
			else add2(i, T, 1);
			fu(j, i + 1, (1 << len) - 1){
				if(vis[j]) continue;
				if(cmp(i, j))
					if(f1)add2(i, j, 1);
					else add2(j, i, 1);
			}
		}
		
		int res2 = dinic();
		//cout << res1 << " " << res2 << "\n";
		if(res2 > res1) cout << "Alice\n";
		else cout << "Bob\n";
	}
	init_edge();
	
}
