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
		string s;
		cin >> s;
		map<int,int> mp;
		fu(i, 0, 3){
			mp[s[i]]++;
		}
		if(mp.size() == 1)cout << "-1\n";
		else if(mp.size() == 2){
			if(mp[s[0]] == 2) cout << "4\n";
			else cout << "6\n";
		}
		else {
			cout << "4\n";
		}
	}
	
}


