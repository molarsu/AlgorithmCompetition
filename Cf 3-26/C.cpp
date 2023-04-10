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
	int t = read();
	while(t--){
		int n = read();
		vector<int> a(n + 1);
		int cnt0 = 0;
		int mi = 0x3f3f3f3f, mx = -0x3f3f3f3f;
		map<int,int> mp;
		fu(i, 1, n) {
			a[i] = read();
			mi = min(a[i], mi);
			mx = max(a[i], mx);
			if(!a[i])cnt0++;
			else mp[a[i]]++;
		}
		if(cnt0 == n) {
			printf("No\n"); 
			continue;
		}
		printf("Yes\n");
		fu(i, 1, cnt0){
			printf("0 ");
		}
		int R = mx - mi;
		int Smi = 0, Smx = 0;
		int sum = 0;
		fu(i, 1, n - cnt0){
			auto p = mp.lower_bound(Smi + R - sum);
			int x = p->first;
			printf("%lld ", x);
			mp[x]--;
			if(mp[x] == 0) mp.erase(x);
			sum += x;
		}
		printf("\n");
	}
	return 0;
}


