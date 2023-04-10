#include<bits/stdc++.h>
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;

const int N = 2e5 + 5;

int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}

int main(){
	string s;
	cin >> s;
	int n = s.size();
	vector<int> sum(n + 1);
	map<int,long long> mp;
	mp[0]++;
	fu(i, 1, n){
		int now = s[i - 1] - '0';
		sum[i] = sum[i - 1] ^ (1 << now);
		mp[sum[i]]++;
	}
	long long ans = 0;
	fu(i, 0, (1 << 10) - 1){
		ans += mp[i] * (mp[i] - 1) / 2;
		
	}
	cout << ans << endl;
}


