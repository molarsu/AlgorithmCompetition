#include<bits/stdc++.h>
#define ri register int
#define int long long
#define fu(i, a, b) for(ri i = (a), ed = (b); i <= ed; ++i)
#define fd(i, a, b) for(ri i = (a), ed = (b); i >= ed; --i)
using namespace std;

const int N = 2e5 + 5;
int pow10[20];
int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch > '9' || ch < '0'){ 	if(ch == '-')f = -1; ch = getchar(); }
	while(ch <= '9' && ch >= '0'){ x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar(); }
	return x * f;
}
int strToInt(const string &x){
	int res = 0;
	fu(i, 1, x.size()){
		res = (res << 1) + (res << 3) + (x[i - 1] ^ 48);
	}
	//cout << res << endl;
	return res;
	
}
string intToStr(int x){
	string s = "";
	while(x){
		s.push_back(char(x % 10 + '0'));
		x /= 10;
	}
	reverse(s.begin(), s.end());
	//cout << s << endl;
	return s;
}
int slv(const string &x,const string &R){
	if(R == "0") return 0;
	int n = R.size();
	int m = x.size();
	
	int num = strToInt(x);
	bool f0 = (x[0] == '0');
	int res = 0;
	fu(i, 0, n - 1){
		string t = R.substr(i, m);
		
		if(t.size() < x.size())break;
		int num2 = strToInt(t);
		if(i == 0 && (num > num2 || f0))continue;
		//cout << t << endl;
		string LL = R.substr(0, i);
		string RR = R.substr(i + m);
		//cout << LL << " " << RR << endl;
		int len_R = RR.size();
		
		int Lx = strToInt(LL), Rx = strToInt(RR);
		if(num2 == num) { 
			res += Lx * pow10[len_R] + Rx + 1;
		}
		else if(num2 > num){
			res += (Lx + 1) * pow10[len_R];
			//cout << res << endl;
			
		}
		else if(num2 < num){
			
			res += Lx * pow10[len_R];
		}
		if(f0) res -= pow10[len_R];
		//cout << res << endl;
	}
	return res;
}
void get_pw10(){
	pow10[0] = 1;
	fu(i, 1, 18) pow10[i] = pow10[i - 1] * 10;
}
signed main(){
	get_pw10();
	int t = read();
	while(t--){
		string S, L, R;
		cin >> S >> L >> R;
		string LL = intToStr(strToInt(L) - 1);
		//cout << LL << endl;
		int res1 = slv(S, LL);
		int res2 = slv(S, R);
		cout << res2 - res1 << endl;
	}
}
/*
1 
099 1 1000
10 20 30 40  50 60 70 80 90 100

*/

