#include "bits/stdc++.h"

using namespace std;
using i64 = long long;

void solve() {
  i64 n, m;
  cin >> n >> m;
  bool change = 0;
  i64 sum = n * (n + 1) / 2 * m * (m + 1) / 2;
  if (sum % 2 == 1) {
    cout << "No" << '\n';
    return;
  }
  if (((n + 1) * n / 2) % 2 == 0) {
    swap(n, m);
    change = 1;
  }
  i64 tmp = m * (m - 1) / 2;
  i64 tmpm = m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> p;
  auto get = [&](i64 x) {
    i64 num = sqrtl(x);
    while (x - num * num < tmpm - num) {
      num--;
    }
    return num;
  };
  while (tmp) {
    if (tmpm == tmp) {
      while (tmp) {
        p.push_back(1);
        tmp--;
      }
      break;
    }
    i64 num = get(tmp);
    tmp -= num * num;
    tmpm -= num;
    p.push_back(num);
  }
  int now = 1;
  int tot = 0;
  for (int i = 0; i < (int)p.size(); i++) {
    for (int j = 0; j < p[i]; j++) {
      for (int k = 0; k < n; k++) {
        a[k][tot + j] = now;
      }
    }
    now ^= 1;
    tot += p[i];
  }
  cout << "Yes" << '\n';
  if (change) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[j][i] << " \n"[j == n - 1];
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << " \n"[j == m - 1];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
