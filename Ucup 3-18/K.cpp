#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
//typedef __int128 LLL;

int read() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') c == '-' ? f = -1: 0, c = getchar();
	while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
    return x * f;
}

int f[1000050][2];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
    int a = read(), b = read(), n = read();
    LL lcm = 1ll * a * b / gcd(a, b);
    
    if(lcm >= n) printf("%d\n", n / a + n / b);
    else {
        int dayAB = n + 10, dayBA = n + 10;
        // AB
        int lsta = -1, lstb = 0;
        for(int i = 1; i <= n; ++i) {
            if(i - lsta == a) lsta = i;
            if(i - lstb == b) lstb = i;
            if(lsta == lstb) {
                dayAB = i;
                break;
            }
        }
        
        //BA
        lsta = 0, lstb = -1;
        for(int i = 1; i <= n; ++i) {
            if(i - lsta == a) lsta = i;
            if(i - lstb == b) lstb = i;
            if(lsta == lstb) {
                dayBA = i;
                break;
            }
        }
        
        for(int i = 0; i < dayAB; ++i) f[i][0] = (i + 1) / a + i / b;
        for(int i = 0; i < dayBA; ++i) f[i][1] = i / a + (i + 1) / b;
        
        for(int i = 0; i <= n; ++i) {
            if(i >= dayAB)
                f[i][0] = min(f[i - dayAB][0], f[i - dayAB][1]) + (dayAB + 1) / a + dayAB / b;
            if(i >= dayBA)
                f[i][1] = min(f[i - dayBA][0], f[i - dayBA][1]) + dayBA / a + (dayBA + 1) / b;
        }
        
        printf("%d\n", min(f[n - lcm][0], f[n - lcm][1]) + lcm / a + lcm / b);
    }
    return 0;
}

