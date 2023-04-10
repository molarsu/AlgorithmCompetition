#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	if(k>=(n&-n))cout << "Impossible\n";
        else {
            for(int i=1; i<=k; ++i)
                for(int j=0; j<n; ++j){
                	printf("%d",(j ^ i) + 1);
                	if(j == n - 1) printf("\n");
                	else printf(" ");
				}
        }
	}
    return 0;
}
