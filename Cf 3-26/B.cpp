#include<bits/stdc++.h>
#define ri register int
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;

const int N = 5e4;

int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}
bool vis[N];
int main(){
	int t = read();
	while(t--){
		int m = read();
		vector<vector<int> > a;
		vector<int> b(1);
		a.push_back(b);
		fu(i, 1, m){
			int n = read();
			vector<int> b(n + 1);
			fu(i, 1, n) b[i] = read();
			a.push_back(b);
		}
		bool ok = 1;
		vector<int> ans(m + 1);
		fd(i, m, 1){
			fd(j, a[i].size() -  1, 1){
				if(!vis[a[i][j]]){
					vis[a[i][j]] = 1;
					ans[i] = a[i][j];
				}
			}
			if(!ans[i]) {
				ok = 0;
				break;
			}
		}
		if(ok )fu(i, 1, m) printf("%d ", ans[i]);
		else printf("-1");
		printf("\n");
		fd(i, m, 1) fu(j, 1, a[i].size() - 1) vis[a[i][j]] = 0;
		
	}
	return 0; 
}
/*
3
3
4
1 2 4 8
3
2 9 1
2
1 4


*/

