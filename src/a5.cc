#include <bits/stdc++.h>

using namespace std;

int min_of(int* head, int len) {
    int ans = 65535;
    for (int i = 0; i < len; i++) ans = min(ans, head[i]);
    return ans;
}

int max_of(int* head, int len) {
    int ans = 0;
    for (int i = 0; i < len; i++) ans = max(ans, head[i]);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int w[n];
    for (int i = 0; i < n; i++) cin >> w[i];
    if (n < m) {
        cout << max_of(w, n) << endl;
        return 0;
    }
    int curr = m;
    int tap[m];
    for (int i = 0; i < m; i++) tap[i] = w[i];
    int ans = 0;
    while (curr < n) {
        int fastest = min_of(tap, m);
        ans += fastest;
        for (int i = 0; i < m; i++) tap[i] -= fastest;
        for (int i = 0; i < m; i++) {
            if (tap[i] == 0 && curr < n) {
                tap[i] = w[curr];
                curr++;
            }
        }
    }
    ans += max_of(tap, m);
    cout << ans << endl;
}
