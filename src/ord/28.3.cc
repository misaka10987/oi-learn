#include <bits/stdc++.h>

using namespace std;


int decomp(int sum, int max) {
    if (sum == 1) return 1;
    int div = min(sum, max);
    int ans = 0;
    for (int i = 1; i < div; i++) {
        for (int j = 1; j < sum / i; j++) {
            ans += decomp(sum - j * i, i - 1);
        }
    }
    return ans + 1;
}

int main() {
    int n;
    cin >> n;
    cout << decomp(n, n) << endl;
}
