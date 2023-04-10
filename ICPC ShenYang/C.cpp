#include <bits/stdc++.h>
using namespace std;

int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}

typedef long long LL;

int n, a[5050], b[5050], d, cnt, tmp[5050];
inline long long slv(int l){
	int r = l+d;
	for(int i = 1; i <= n; ++i){
		if(a[i] < l)tmp[i] = l;
		else if(a[i] > r)tmp[i] = r;
		else tmp[i] = a[i];
	}
	long long res = 0;
	for(int i = 1; i < n; ++i)res += abs(tmp[i+1]-tmp[i]);
	return res;
}
signed main() {
	n = read(), d = read();
	for(int i = 1; i <= n; ++i) a[i] = read(), b[++cnt] = a[i];
	sort(b+1, b+1+n), cnt = unique(b+1, b+1+n)-b-1;
	long long ans = 0;
	for(int i = 1; i <= cnt; ++i)ans = max(ans, slv(a[i]));
	for(int i = 1; i <= cnt; ++i)ans = max(ans, slv(a[i]-d));
	cout << ans << endl;
	return 0;
}
