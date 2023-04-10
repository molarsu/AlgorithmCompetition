#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef pair<int,int> P;
vector<P> G[3];
bool vis[3][3][N];
char str[] = "win";
int main(){
	int t;
	cin >> t;
	while(t--){
		for (int i = 0; i < 3; i++)G[i].clear();
		int n;
		cin >> n;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)for (int k = 0; k <= n; k++)vis[i][j][k] = 0;
		int edges = 0;
		for(int i = 1; i <= n; i++) { 
			int cnt[3] = {0};
			for (int j = 1; j <= 3; j++) {
				char ch; cin >> ch;
				if(ch == 'w')cnt[0]++;
				else if(ch == 'i') cnt[1]++;
				else if(ch == 'n') cnt[2]++;
			}	
			for (int j = 0; j < 3; j++){
				for (int k = 0; k < 3; k++){
					if(cnt[k] == 0 && cnt[j] >= 2) G[j].push_back({k, i}), edges++;
				}
			}
		}
		vector<pair<int, char> > vec;
		int ans = 0;
		for (int u = 0; u < 3; u++){
			for (auto nxt : G[u]){
				int v = nxt.first, num = nxt.second;
				if(vis[u][v][num])continue;
				for (auto nxtt: G[v]){
					int vv = nxtt.first, num2 = nxtt.second;
					
					if(vis[v][vv][num2])continue;
					if(vv == u) {
						vec.push_back({num, str[u]});
						vec.push_back({num2, str[v]});
						vis[u][v][num] = 1;
						vis[v][vv][num2] = 1;
						edges -= 2;
						ans++;
						break;
					}
				}
			}
		}
		ans += edges / 3 * 2;
		for (int u = 0; u < 3; u++){
			for (auto nxt : G[u]){
				int v = nxt.first, num = nxt.second;
				if(vis[u][v][num])continue;
				for (auto nxtt: G[v]){
					int vv = nxtt.first, num2 = nxtt.second;
					if(vis[v][vv][num2])continue;
					for (auto nxttt: G[vv]){
						int 
					}
				}
			}
		}
		cout << ans << endl;
		
	}
}
/*
1
4
win
www
iii
nnn

*/
