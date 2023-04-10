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
		int sum = 0;
		fu(i, 1, n) a[i] = read(), sum ^= a[i];
		if(n & 1){
			cout << sum << endl;
		}
		else {
			if(sum == 0) cout << 0 << endl;
			else cout << -1 << endl;
		}
		
	}
}


