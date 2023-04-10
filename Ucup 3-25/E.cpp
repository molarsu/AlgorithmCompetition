#include<bits/stdc++.h>
#define int long long
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;

const int N = 2e5 + 5;

int read() {
	int f = 1, x = 0; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch <= '9' && ch >= '0') { x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}
int n, m;
int a[N], d[N];
bool check(int x) {
	if (x == 0)return true;
	fu(i, 1, n) {
		d[i] = (x - 1) / a[i] + 1;
	}
	int res = 0;
	int last = 0;
	fu(i, 1, n) {
		int now = d[i] - last;
		if (now <= 0) { if(i < n)res += 1;  last = 0; }
		else res += (now * 2 - 1), last = now - 1;
	}
	return res <= m;
}

signed main() {
	int t = read();
	while (t--) {
		n = read(), m = read();
		fu(i, 1, n) a[i] = read();
		int l = 0, r = 1e17 + 1;
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (check(mid)) l = mid;
			else r = mid;
		}
		printf("%lld\n", l);
	}
}
/*
1
2 3
1 2
*/

