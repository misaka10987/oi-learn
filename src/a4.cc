#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>&& data) {
    int len = data.size();
    if (len == 1) return data[0];
    if (len == 2) return max(data[0], data[1]);
    if (len == 3) return data[0] + data[1] + data[2];
    int ans = min(data[0] + data[1] + data[len - 1] + data[len - 2], data[1] + data[0] + data[len - 1] + data[1]);
    data.pop_back(); data.pop_back();
    ans += solve(move(data));
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> data = vector<int>(n);
        sort(data.begin(), data.end());
        for (auto& i : data) cin >> i;
        cout << solve(move(data)) << endl;
    }
}
