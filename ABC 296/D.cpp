 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
 typedef long long ll;


signed main(){
 	ll n, m;
	cin >> n >> m;
	if(n * n < m) {
		cout << -1 << endl;
		return 0;
	}
	else if(m <= n){
		cout << m << endl;
		return 0;
	}
	ll ans = n * n;
	
	for (int k = (m - 1) / n + 1; k <= n; ++k){
		ll x = (m - 1) / k + 1;
		//cout << x << endl;
		if(x <= n && k <= n)ans = min(ans, k * x);
		if(x < k) break;
	}
	cout  << ans << endl;
	return 0;
 }
 /*
 1000000 1000000000000
 
 */
