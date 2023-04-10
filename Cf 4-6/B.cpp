#include<bits/stdc++.h>
#define int long long
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

signed main(){
	int t = read();
	while(t--){
		int x = read(), y = read();
		if(x > y) swap(x, y);
		int ans = 0x3f3f3f3f3f3f3f3f;
		int c = 1;
		for (int l = 1, r; l <= y; l = r + 1){
			if(x % a == 0){
				int b = x / a;
				for (; c * c <= y && c * x <= a * y; c++){
					if(y % c == 0){
						ans = min(ans, a - 1 + c + y / c);
					}
				}
			}
		}
		cout << ans << endl;
	}
}


