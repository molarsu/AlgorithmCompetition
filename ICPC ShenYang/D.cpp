#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
	cin >> s;
	
	int a1 = 0, a2 = 0;
	for(char c: s) {
		if(c == 'T') ++a1;
		else if(c == 'D') ++a2;
	}
	if(a1 > a2) puts("T1");
	else puts("DRX");
	
	return 0;
}
