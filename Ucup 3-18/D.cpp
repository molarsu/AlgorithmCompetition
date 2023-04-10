#include<bits/stdc++.h>
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;

const int N = 2e5 + 5;
typedef pair<int, int> P;
int ans, w;

int read() {
	int f = 1, x = 0; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch <= '9' && ch >= '0') { x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}

vector<P> G[N];
int tot;

void read_tree(int fa) {
	tot++;
	int u = tot;
	int w = read(), sons = read();
	G[fa].push_back({ u, w });
	G[tot].push_back({ fa, w });
	fu(i, 1, sons) read_tree(u);
}

int dfs(int u, int fa) {
	vector<int> vec;
	for (auto now : G[u]) {
		int v = now.first;
		if (v == fa) continue;
		int ww = now.second;
		vec.push_back(ww + dfs(v, u));
	}
	for (auto& x : vec) {
		if (x > w) ans += x / w, x %= w;
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	fu(i, 0, vec.size() - 1) {
		if (sum + vec[i] <= w) sum += vec[i];
		else {
			ans += vec.size() - i;
			break;
		}
	}
	//cout << u << " " << sum << endl;
	return sum;
}

int main() {
	w = read();
	read_tree(0);
	int num = dfs(0, 0);
	if(num)ans += (num - 1) / w + 1;
	cout << ans << endl;
	return 0;
}
/*
7
5 2
7 0
2 0
*/

