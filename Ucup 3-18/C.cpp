#include<bits/stdc++.h>
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;
#define int long long
const int N = 5e3 + 5;
const double eps = 1e-6;
const int INF = 0x3f3f3f3f3f3f3f3f;
int read() {
	int f = 1, x = 0; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch <= '9' && ch >= '0') { x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}

double dis[N][N];
struct Node {
	int x, y, rk, sz;
}a[N];
bool vis[N];

signed main() {
	int n = read();
	vector<int> vec;
	fu(i, 1, n) a[i].x = read(), a[i].y = read(), a[i].rk = i, a[i].sz = 1, vec.push_back(i);

	fu(i, 1, n) fu(j, 1, n) dis[i][j] = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
	int tot = n;
	fd(_, n - 1, 1) {
		int x = 0, y = 0;
		double mi = INF;
		fu(i, 0, signed (vec.size()) - 1) {
			int u = a[vec[i]].rk;
			fu(j, i + 1, signed (vec.size()) - 1) {
				int v = a[vec[j]].rk;
				if (mi - 1.0 * dis[u][v] / a[u].sz / a[v].sz > eps) x = i, y = j, mi = dis[u][v] / a[u].sz / a[v].sz;
			}
		}
		//cout << x << ' ' << y << endl;
		tot++;
		int u = vec[x], v = vec[y];
		a[tot].sz = a[u].sz + a[v].sz;
		a[tot].rk = tot;
		
		vec.erase(vec.begin() + y);
		vec.erase(vec.begin() + x);
		fu(i, 0, signed(vec.size()) - 1) {
			int now = a[vec[i]].rk;
			dis[now][tot] = dis[tot][now] = dis[now][u] + dis[now][v];
		}
		
		vec.push_back(tot);
		printf("%lld\n", a[tot].sz);

	}
	return 0;
}
