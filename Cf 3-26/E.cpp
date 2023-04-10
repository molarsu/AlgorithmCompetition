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
int n;
void slv(){
	n = read();
	vector<int> a(n + 1);
	vector<int> testNum(n + 1), maxSuf(n + 1);
	fu(i, 1, n) a[i] = read();
	// testNum[i] 为 从 i + 1 到 n 一共有多少个合适的值 
	// 下一个合适的位置， testNum[i] = testNum[nxt] + 1;
	testNum[n] = 0;
	fd(i, n - 1, 0){
		int nxt = i + 1 + a[i + 1];
		if(nxt > n) testNum[i] = -1;
		else testNum[i] = testNum[nxt] > -1 ? testNum[nxt] + 1 : -1;
		maxSuf[i] = max(maxSuf[i + 1], testNum[i]);
	}
	// i 修改一个 i + 1 -- n 所能到达的最大test数 
	// 若为修改 i + 1 的值， 那么 只需要 取所有 i + 2 -- n里所有的样例数 最大的即可 
	// 若修改后面的值 maxTest[i] = maxTest[nxt] + 1 
	
	// maxTest[i] = max(testNum[i + 1 to n] + 1, maxTest[nxt] + 1 );
	vector<int> maxTest(n + 1); 
	maxTest[n] = 0;
	fd(i, n - 1, 0){
		int nxt = i + 1 + a[i + 1];
		if(nxt > n)maxTest[i] = maxSuf[i + 1] + 1;
		else  maxTest[i] = max(maxSuf[i + 1] + 1, maxTest[nxt] + 1 );
	}
	fu(i, 1, n - 1){
		if(a[i] == testNum[i])printf("0 ");
		else if(testNum[i] != -1 || a[i] <= maxTest[i])printf("1 ");
		else printf("2 ");
	}
	printf("\n");
}
int main(){
	int t = read();
	while(t--){
		slv();
		
	}
	return 0; 
}

/*
1
7
1  1  4  2 7 1 1
0  1  2  3  4 5 6 7
   1  1  4  2 7 1 1
testNum
2 -1 1 -1 -1 1 -1 0


*/
