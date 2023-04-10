#include<bits/stdc++.h>
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;
#define int long long
const int N = 505;

int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}
int G[N][N], f[N][N];
signed main(){
	int n = read(), m = read();
	memset(G, 0x3f, sizeof G);
	memset(f, 0x3f, sizeof f);
	fu(i, 1, m) {
		int u = read(), v = read();
		G[u][v] = G[v][u] = min(read(), G[u][v]);
	}
	fu(i, 1, n) f[1][i] = G[1][i];
	// f[i][v] 表示 走 i 个 (从起点开始算)点 
	fu(i, 1, n)G[i][i] = 0;
	fu(i, 1, n){
		fu(u, 1, n){
			fu(v, 1, n){
				f[i + 1][v] = min(f[i][u] + G[u][v], f[i + 1][v]);
			}
		}
		
	}
	int q = read();
	fu(i, 1, q){
		int t = read();
		vector<int> w(n + 1);
		fu(j, 1, n - 1) w[j] = read();
		int sum = 0;
		int ans = 0x3f3f3f3f3f3f3f3f;
		fu(j, 1, n - 1) sum += w[j], ans = min(ans, f[j][t] + sum);
		printf("%lld\n", ans);
	}
	
}


