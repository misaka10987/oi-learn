#include <bits/stdc++.h>

using namespace std;

int solve(int* data, int len, int highest = 65535) {
    if (len <= 0) return 0;
    if (data[0] > highest) return solve(data + 1, len - 1, highest);
    return max(solve(data + 1, len - 1, data[0]) + 1, solve(data + 1, len - 1, highest));
}

int main() {
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    cout << solve(data, n) << endl;
}
