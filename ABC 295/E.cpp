#include<bits/stdc++.h>
#define fu(i, a, b) for(int i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(int i = (a), ed = (b); i >= ed; --i)
using namespace std;

const int N = 2e5 + 5;
const int P = 998244353;
inline int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}
typedef long long int ll;
// n是底数 m 是 指数 p 是取模值
ll fast_power(ll a, ll b) {
	int p = P;
	ll ans = 1;
	a %= p;
	while (b) {
		if (b & 1)ans = (ans * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ans;
}

int main(){
	int t = 1;
	while(t--){
		int n = read(), m =  read(), k = read();
		vector<int> cnt(m + 1), sum(m + 1);
		fu(i, 1, n) cnt[read()]++;
		fu(i, 1, m) sum[i] = sum[i - 1] + cnt[i];
		ll all = fast_power(m, cnt[0]);
		all = fast_power(all, P - 2);
		ll ans = 0;
		fu(i, 1, m){
			int cntL = sum[i - 1], cntR = sum[m] - sum[i];
			if(cntL > k || cntR > n - k + 1)continue;
			fu(j, 0, cnt[i] - 1){
				int Li = j, Ri = cnt[i] - 1 - j;
				
				if(cntL + Li <= k && cntR + Ri <= n - k + 1){
					int Lneed = k - cntL - Li - 1, Rneed = cnt[0] - Lneed;
					//cout << i << " " <<  Lneed << " " << Rneed << endl;
					if(Rneed < 0) continue;
					ans += fast_power(i, Lneed) * fast_power(m - i + 1, Rneed) % P * i % P;
					ans %= P;
				}
			}
			if(!cnt[i]) {
				int now0 = cnt[0] - 1;
				if(now0 < 0) continue;
				int Lneed = k - cntL - 1, Rneed = now0 - Lneed;
				if(Lneed < 0 || Rneed < 0) continue;
				ans += fast_power(i, Lneed) * fast_power(m - i + 1, Rneed) % P * i % P;
				ans %= P;
			}
			cout << i << " " ;
			cout << ans << endl;
		}
		ans = ans * all % P;
		printf("%lld\n", ans);
	}
}

/*
3 5 2
2 0 4
*/
