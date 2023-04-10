#include<bits/stdc++.h>
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;
#define int long long
const int N = 2e5 + 5;

int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}


signed main(){
	int t = read();
	while(t--){
		int n = read(), m = read();
		vector<int> k(n + 1);
		fu(i, 1, n) k[i] = read();
		sort(k.begin() + 1, k.end());
		bool f = 1;
		int l = -1e9, r = 1e9;
		
		fu(i, 1, m){
			int a = read(), b = read(), c = read();
			if(c <= 0) { printf("No\n"); continue; }
			int sqx = (int) (0.5 + 2.0 * sqrt(1.0 * a * c));
			int ll = b - sqx, rr = b + sqx;
			while((ll - b) * (ll - b) >= 4 * a * c){ 
				if(ll > b)ll--;
				else ll++;
			}
			if((rr - b) * (rr - b) >= 4 * a * c){ 
				if(rr > b) rr--;
				else rr++;
			}
			auto p = lower_bound(k.begin() + 1, k.end(), ll);
			if(p == k.end() || *p > rr){ printf("No\n"); continue; }
			else {
				printf("Yes\n%lld\n", *p);
			}
		}
		
	}
	return 0;
}


