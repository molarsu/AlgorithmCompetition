#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
// dp[i][0] 表示 第 i 个点 为根的子树 翻转 偶数次 的最大值， 做树上背包。
int dp[maxn][2];

int a[maxn];
void dfs(int u, int fa) {
    int f[2];  f[1] =  f[0] = 0;
    int temp[2] = { 0 };
    bool ff = 0;
    for (int v : G[u]) {
        if (v == fa)continue;
        dfs(v, u);
        if (ff)temp[1] = max(f[1] + dp[v][0], f[0] + dp[v][1]);
        else temp[1] = f[0] + dp[v][1];
        if (ff)temp[0] = max(f[0] + dp[v][0], f[1] + dp[v][1]);
        else temp[0] = dp[v][0];
        f[1] = temp[1], f[0] = temp[0];
        ff = 1;
    }
    dp[u][0] = f[0] + (a[u] == 1);
    dp[u][1] = f[1] + (a[u] == 0);

}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}