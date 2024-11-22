#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>&& data) {
    int done = true;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == 0) continue;
        done = false;
        int term = i;
        for (int j = i; j < data.size(); j++) {
            if (data[j] == 0) break;
            term = j;
        }
        for (int j = i; j < term; j++) data[j]--;
        i = term;
    }
    if (done) return 0;
    return solve(move(data)) + 1;
}

int main() {
    int n; cin >> n;
    vector<int> data = vector<int>(n);
    for (auto& i : data) cin >> i;
    cout << solve(move(data)) << endl;
}
