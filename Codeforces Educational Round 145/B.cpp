#include<bits/stdc++.h>
#define ri register int
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
		int n = read();
		int x = sqrt(n), x1, x2;
		if(x & 1){
			x1 = x;
			x2 = x + 1;
		}
		else {
			x1 = x + 1;
			x2 = x;
		}
		while((x2 + 1) * (x2 + 1) >= n && x2 >= 0)x2 -= 2;
		x2 += 2;
		while((x1 + 1) * (x1 + 1) >= n && x1 > 0)x1 -= 2;
		x1 += 2;
		cout << min(x1, x2 ) << endl;
	}
}


