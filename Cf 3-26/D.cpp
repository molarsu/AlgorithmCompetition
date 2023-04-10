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
int __lcm(int x, int y){
	return x * y / __gcd(x, y);
}
signed main(){
	int t = read();
	while(t--){
		int n = read();
		vector<int> a(n + 1), b(n + 1);
		fu(i, 1, n)a[i] = read(), b[i] = read();
		int g = 0, lcm = 1;
		int num = 0;
		fu(i, 1, n){
			if(i > 1 && g % b[i] == 0 && a[i] * b[i] % lcm == 0){
				g = __gcd(g, a[i] * b[i]);
				lcm = __lcm(lcm, b[i]);
			}
			else {
				num++;
				g = a[i] * b[i];
				lcm = b[i];
			}
		}
		printf("%d\n", num);
	}
}


