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
int n, m, h1[10], h2[10], a1[10], a2[10], f1[10], f2[10];
double p1, p2, p0;
int check(int n, int *h, int *f){
	int mn = 100;
	fu(i, 1, n)if(h[i] > 0 && f[i] < mn)mn = f[i];
	fu(i, 1, n)if(h[i] > 0 && f[i] == mn)return i;
	return 0;
}
void dfs(int x, int y, int f, double p){
//	puts("-------------------");
//	fu(i, 1, n)cout << h1[i] << " ";cout << endl;
//	fu(i, 1, m)cout << h2[i] << " ";cout << endl;	
//	fu(i, 1, n)cout << f1[i] << " ";cout << endl;
//	fu(i, 1, m)cout << f2[i] << " ";cout << endl;	
	x = check(n, h1, f1);
	y = check(m, h2, f2);
//	cout << x << " " << y << " " << f<< endl;
	
	
	if(!x && !y){ p0 += p; return; }
	if(!x){ p2 += p; return; }
	if(!y){ p1 += p; return;}
	if(f == 1){
		int cnt = 0;
		fu(i, 1, m)if(h2[i] > 0)++cnt;
		fu(i, 1, m){
			if(h2[i] <= 0)continue;
			h1[x] -= a2[i];
			h2[i] -= a1[x];
			++f1[x];
			dfs(x + 1, y, 3 - f, p/cnt);
			h1[x] += a2[i];
			h2[i] += a1[x];
			--f1[x];
		}
	}
	else {
		int cnt = 0;
		fu(i, 1, n)if(h1[i] > 0)++cnt;
		fu(i, 1, n){
			if(h1[i] <= 0)continue;
			h2[y] -= a1[i];
			h1[i] -= a2[y];
			++f2[y];
			dfs(x, y + 1, 3 - f, p/cnt);
			h2[y] += a1[i];
			h1[i] += a2[y];
			--f2[y];
		}
	}
}

int main(){
	n = read(), m = read();
	fu(i, 1, n) h1[i] = a1[i] = read();
	fu(i, 1, m) h2[i] = a2[i] = read();
	h1[n + 1] = h2[m + 1] = 1e9;
	if(n > m)dfs(1, 1, 1, 1);
	else if(m > n) dfs(1, 1, 2, 1);
	else dfs(1, 1, 1, 0.5), dfs(1, 1, 2, 0.5);
	printf("%.15lf\n%.15lf\n%.15lf\n", p1, p2, p0);
}

