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
int a[N], b[N];
int main(){
	int t = read();
	while(t--){
		int n = read();
		
		fu(i, 1, n)a[i] =read();
		fu(i, 1, n) b[i] = read();
		fu(i, 1, n)if(a[i] > b[i])swap(a[i], b[i]);
		if(a[n] == *max_element(a + 1, a + 1 + n) && b[n] == *max_element(b + 1, b + 1 + n)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}


