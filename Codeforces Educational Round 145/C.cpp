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
int a[N];
int main(){
	int t = read();
	while(t--){
		int n = read(), k = read();
		int x = 0;
		while(x * (x + 1) / 2 < k)x++;
		if(x * (x + 1) / 2 == k){
			fu(i, 1, x)cout << "2 ";
			fu(i, x + 1, n) cout << "-1000 ";
			cout << "\n";
		}
		else {
			x--;
			fu(i, 1, x)cout << "2 ";
			int res = (x + 1) * (x + 2) / 2 - k;
			
			cout << -(res * 2) + 1 << " ";
			fu(i, x + 2, n)cout << "-1000 ";
			cout << "\n";
		}
	} 
}


