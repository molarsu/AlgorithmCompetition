#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		int pos = 0, mi = 0x3f3f3f3f;
		for (int i = n - 1; i >= 0; i--){
			if(mi > s[i] - 'a') mi = s[i] - 'a', pos = i;
		}
		string s1 = s.substr(0, pos);
		string s2 = s.substr(pos + 1);
		string ans = "";
		ans.push_back(s[pos]);
		ans += s1 + s2;
		cout << ans << endl;
	}
}
/*

dccbcb

*/
