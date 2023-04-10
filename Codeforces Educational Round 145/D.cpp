#include<bits/stdc++.h>
#define ri register int
#define int long long
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;

const int N = 3e5 + 5;
int f[N][3];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int c_r = 1e12 + 1;
		int c_s = 1e12;
		int n = s.size();
		fu(i, 0, n + 2)f[i][0] = f[i][1] = f[i][2] = 0x3f3f3f3f3f3f3f3f;
		f[0][0] = 0;
		fu(i, 1, n){
			if(s[i - 1] == '0'){
				f[i][0] = f[i - 1][0];
				f[i][1] = f[i - 1][1] + c_s;
				f[i][2] = f[i - 1][2] + c_r; 
			}
			else if(s[i - 1] == '1'){
				f[i][0] = f[i - 1][0] + c_r;
				f[i][1] = min(f[i - 1][1] + c_r, f[i - 1][0]);
				f[i][2] = min(f[i - 1][1], f[i - 1][2]);
			}
			//cout << min(f[i][0], min(f[i][1], f[i][2])) << endl;
		}	
		cout << min(f[n][0], min(f[n][1], f[n][2])) << endl;	
	}
}
/*
1
00101101
*/

