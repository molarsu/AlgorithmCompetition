#include<bits/stdc++.h>
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;

int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}
const int N = 2005;
int n;
int id[N], rk[N];

int a[N];
int stk[N];
int f[N][N];

int query(int x, int y){
	if(f[x][y]) return f[x][y] - 1;
	cout << "? " << x << " " << y << endl;
	int res; cin >> res;
	f[x][y] = res + 1;
	return res;
}
//void add(int i, int v) {
//	for(; i <= n; i += (i & -i)) a[i] += v;
//}
//int qry(int i, int r = 0) {
//	for(; i; i -= (i & -i)) r += a[i];
//	return r;
//}

int query2(int x, int y){
//	int res = 0;
//	for (int i = x; i <= y; i++){
//		res += qry(rk[i]);
//		add(rk[i], 1);
//	}
//	for (int i = x; i <= y; i++) add(rk[i], -1);
//	return res & 1;
	int res = 0;
	// x [x + 1, y]
	for(int i = x + 1; i <= y; ++i)
		res ^= (rk[i] < rk[x]);
	return res;
	
}
// check 为真表示 x 比 y 大 
bool check(int x, int y){
	int f = query(x, y);
	if(x + 1 == y) return f;
	int f1 = query(x + 1, y);
	
	return f ^ f1 ^ query2(x, y -1);
}
int main(){
	cin >> n;
	if(n == 1) {cout << "! 1" << endl; return 0;}
	id[1] = 1, rk[1] = 1;
	for (int i = 2; i <= n; i++){
		
		int l = 1, r = i - 1;
		while(l < r) {
			int mid = l + r >> 1;
			
			if(check(id[mid], i)) r = mid;
			else l = mid + 1;
		}
		
//		while(r - l > 1){
//			int mid = (l + r) >> 1;
//			// check 为真表示 mid 比 i 大 
//			if(check(id[mid], i)) r = mid;
//			else l = mid; 
//		}
		if(r == i - 1) {
			if(!check(id[i - 1], i)) ++r;
		}
		
		int top = 0;
		for(int j = 1; j <= r - 1; ++j) stk[++top] = id[j];
		stk[++top] = i;
		for(int j = r; j <= i - 1; ++j) stk[++top] = id[j];
		
		for(int j = 1; j <= top; ++j) {
			id[j] = stk[j], rk[stk[j]] = j;
		}
	}
	
	cout << "! ";
	for(int i = 1; i <= n; ++i) cout << rk[i] << ' ';
	cout << endl;
}


